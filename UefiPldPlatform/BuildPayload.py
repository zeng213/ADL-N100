#!/usr/bin/env python
## @ BuildPayload.py
#
# Copyright (c) 2016 - 2023, Intel Corporation. All rights reserved.<BR>
# This program and the accompanying materials are licensed and made available under
# the terms and conditions of the BSD License that accompanies this distribution.
# The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php.
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
##

##
# Import Modules
#
import os
import sys
import errno
import shutil
import argparse
import subprocess
import multiprocessing

PLATFORMPKG_MAP = {}

def update_platformpkg_map():

    PLATFORMPKG_MAP.clear()

    # traverse through all PlatformPkg folders
    search_dir = os.environ['EDK2PLT_SOURCE']
    board_pkgs = os.listdir (search_dir)
    for pkg in board_pkgs:
        file = os.path.join (search_dir, pkg, 'PlatformPkg.dsc')
        if os.path.exists(file):
            # search PlatformPkg.dsc for the 'SUPPORTED_BOARDS' entry
            with open(file, 'r') as pkgdsc_file:
                for line in pkgdsc_file:
                    if 'SUPPORTED_BOARDS' in line:
                        boards_str = line.split('=')[1].strip()
                        if boards_str:
                            # board names are concatenated with separator '|'
                            for board in boards_str.split('|'):
                                # ensure the mapping is not ambiguous
                                board = board.capitalize()
                                if board in PLATFORMPKG_MAP:
                                    print ('%s is already supported by %s' % (board, PLATFORMPKG_MAP[board]))
                                    sys.exit(1)
                                else:
                                    PLATFORMPKG_MAP.update({board : pkg})

    # print the PLATFORMPKG_MAP
    if 0:
        for key in PLATFORMPKG_MAP:
            print ('%-5s : %s' % (key, PLATFORMPKG_MAP[key]))


def get_file_data (file, mode = 'rb'):
    return open(file, mode).read()

def run_process (arg_list, print_cmd = False, capture_out = False):
    sys.stdout.flush()
    if print_cmd:
        print (' '.join(arg_list))

    exc    = None
    result = 0
    output = ''
    try:
        if capture_out:
            output = subprocess.check_output(arg_list).decode()
        else:
            result = subprocess.call (arg_list)
    except Exception as ex:
        result = 1
        exc    = ex

    if result:
        if not print_cmd:
            print ('Error in running process:\n  %s' % ' '.join(arg_list))
        if exc is None:
            sys.exit(1)
        else:
            raise exc

    return output

def rebuild_basetools ():
	ret = 0
	edk2source = os.environ['EDK2_SOURCE']
	if os.name == 'posix':
		genffs_exe_path = os.path.join(edk2source, 'BaseTools', 'Source', 'C', 'bin', 'GenFfs')
		genffs_exist = os.path.exists(genffs_exe_path)
		if not genffs_exist:
			ret = subprocess.call(['make', '-C', 'BaseTools'])

	elif os.name == 'nt':
		os.environ['PYTHON_HOME'] = sys.exec_prefix
		os.environ['PYTHON_COMMAND'] = sys.executable
		genffs_exe_path = os.path.join(edk2source, 'BaseTools', 'Bin', 'Win32', 'GenFfs.exe')
		genffs_exist = os.path.exists(genffs_exe_path)
		if not genffs_exist:
			print ("Could not find pre-built BaseTools binaries, try to rebuild BaseTools ...")
			ret = subprocess.call(['BaseTools\\toolsetup.bat', 'forcerebuild'])

	if ret:
		print ("Build BaseTools failed, please check required build environment and utilities !")
		sys.exit(1)

		genffs_exist = os.path.exists(genffs_exe_path)
		if not genffs_exist:
				print ("Build python executables failed !")
				sys.exit(1)


def prep_env ():
	workspace = os.path.dirname(os.path.abspath(__file__))
	edk2source = os.path.join(workspace, 'Edk2Open')
	os.chdir(edk2source)
	if os.name == 'posix':
		toolchain = 'GCC49'
		gcc_ver = subprocess.Popen(['gcc', '-dumpversion'], stdout=subprocess.PIPE)
		(gcc_ver, err) = subprocess.Popen(['sed', 's/\\..*//'], stdin=gcc_ver.stdout, stdout=subprocess.PIPE).communicate()
		if int(gcc_ver) > 4:
			toolchain = 'GCC5'

		os.environ['PATH'] = os.environ['PATH'] + ':' + os.path.join(edk2source, 'BaseTools', 'BinWrappers', 'PosixLike')
	elif os.name == 'nt':
		toolchain = ''
		os.environ['PATH'] = os.environ['PATH'] + ';' + os.path.join(edk2source, 'BaseTools', 'Bin', 'Win32')
		os.environ['PATH'] = os.environ['PATH'] + ';' + os.path.join(edk2source, 'BaseTools', 'BinWrappers', 'WindowsLike')
		os.environ['PYTHONPATH'] = os.path.join(edk2source, 'BaseTools', 'Source', 'Python')

		# check new Visual Studio Community version first
		vswhere_path = os.path.join(os.environ['ProgramFiles(x86)'], 'Microsoft Visual Studio', 'Installer', 'vswhere.exe')
		if os.path.exists (vswhere_path):
			cmd = [vswhere_path, '-all', '-property', 'installationPath']
			lines = run_process (cmd, capture_out = True)
			vscommon_paths = []
			for each in lines.splitlines ():
				each = each.strip()
				if each and os.path.isdir(each):
					vscommon_paths.append(each)

			for vs_ver in ['2019', '2017']:
				for vscommon_path in vscommon_paths:
					vcver_file = os.path.join(vscommon_path, 'VC', 'Auxiliary', 'Build', 'Microsoft.VCToolsVersion.default.txt')
					if os.path.exists(vcver_file):
						check_path = '\\Microsoft Visual Studio\\%s\\' % vs_ver
						if check_path in vscommon_path:
							toolchain_ver    = get_file_data (vcver_file, 'r').strip()
							toolchainprefix  = 'VS%s_PREFIX' % (vs_ver)
							toolchain_path   = os.path.join(vscommon_path, 'VC', 'Tools', 'MSVC', toolchain_ver, '')
							os.environ[toolchainprefix] = toolchain_path
							toolchain = 'VS%s' % (vs_ver)
							break
				if toolchain:
					sdk = '10'
					os.environ['WINSDK%s_PREFIX' % sdk] = os.path.join(os.environ['ProgramFiles(x86)'], 'Windows Kits', sdk, 'bin')
					vs_supported_sdks = None
					if vs_ver == '2019':
						vs_supported_sdks = ['10.0.19041.0', '10.0.18362.0']
					elif vs_ver == '2017':
						vs_supported_sdks = ['10.0.17763.0', '10.0.17134.0', '10.0.16299.15', '10.0.15063.0']

					RC_EXE_FDR = None
					sdk_path = os.environ['WINSDK%s_PREFIX' % sdk]
					for sdk_version in vs_supported_sdks:
						if os.path.exists (os.path.join(sdk_path, sdk_version, 'x86')):
							RC_EXE_FDR = "%s" % sdk_version
							break
					if RC_EXE_FDR is None:
						print ("Could not find a supported SDK version for VS%s!" % vs_ver)
						print ("Known supported versions %s" % vs_supported_sdks)
						print ("Check '%s' to confirm your SDK version(s)." % sdk_path)
						sys.exit(1)
					os.environ['WINSDK_PATH_FOR_RC_EXE'] = os.path.join(os.environ['ProgramFiles(x86)'], 'Windows Kits', sdk, 'bin', RC_EXE_FDR, 'x86')
					break

		if toolchain == '':
			vs_ver_list = [
				('2015', 'VS140COMNTOOLS', '81', '8.1'),
				('2013', 'VS120COMNTOOLS', '8',  '8.0'),
				('2012', 'VS110COMNTOOLS', '71', 'v7.1A'),
				('2010', 'VS100COMNTOOLS', '7',  'v7.0A'),
				('2008', 'VS90COMNTOOLS',  '',   'v6.0A'),
				('2005', 'VS80COMNTOOLS',  '',   '')
			]
			for vs_ver, vs_tool, sdkv, sdkd in vs_ver_list:
				if vs_tool in os.environ:
					toolchain='VS%s%s' % (vs_ver, 'x86')
					toolchainprefix = 'VS%s_PREFIX' % (vs_ver)
					os.environ[toolchainprefix] = os.path.join(os.environ[vs_tool], '..', '..', '')
					break
			os.environ['WINSDK%s_PREFIX'    % sdkv] = os.path.join(os.environ['ProgramFiles'], 'Windows Kits', sdkd, 'bin', '')
			os.environ['WINSDK%sx86_PREFIX' % sdkv] = os.path.join(os.environ['ProgramFiles(x86)'], 'Windows Kits', sdkd, 'bin', '')

		if not toolchain:
			print ("Could not find supported Visual Studio version !")
			sys.exit(1)

		if 'NASM_PREFIX' not in os.environ:
			os.environ['NASM_PREFIX'] = "C:\\Nasm\\"
		if 'OPENSSL_PATH' not in os.environ:
			os.environ['OPENSSL_PATH'] = "C:\\Openssl\\"
		if 'IASL_PREFIX' not in os.environ:
			os.environ['IASL_PREFIX'] = "C:\\ASL\\"
	else:
		print ("Unsupported operating system !")
		sys.exit(1)

	# Update Environment vars
	os.environ['EDK2PLT_SOURCE']  = os.path.join(workspace, 'PldPlatform')
	os.environ['EDK2_SOURCE']     = edk2source
	os.environ['EDK_TOOLS_PATH']  = os.path.join(edk2source, 'BaseTools')
	os.environ['BASE_TOOLS_PATH'] = os.path.join(edk2source, 'BaseTools')
	os.environ['WORKSPACE']       = workspace
	os.environ['CONF_PATH']       = os.path.join(os.environ['WORKSPACE'], 'Conf')
	os.environ['TOOL_CHAIN']      = toolchain

class Build(object):
	def __init__(self, args):
		self._workspace           = os.environ['WORKSPACE']
		self.board                = args.board
		self.release              = args.release
		self.coreboot             = args.coreboot
		self.arch64               = args.arch64
		self.userphysicalpresence = args.userphysicalpresence

		if args.define:
			self.define             = ' '.join(['-D%s' % i for i in args.define]).strip()
		else:
			self.define             = ''

	def pre_build(self):
		# Check if BaseTools has been compiled
		rebuild_basetools ()

		# Update search path
		edk2_dir = os.environ['EDK2_SOURCE']
		plt_dir = os.environ['EDK2PLT_SOURCE']
		os.environ['PACKAGES_PATH'] = plt_dir
		if plt_dir != edk2_dir:
			os.environ['PACKAGES_PATH'] += os.pathsep + edk2_dir

		# create conf and build folder if not exist
		if not os.path.exists(os.path.join(self._workspace, 'Conf')):
			os.makedirs(os.path.join(self._workspace, 'Conf'))
		for name in ['target', 'tools_def', 'build_rule']:
			txt_file = os.path.join(self._workspace, 'Conf/%s.txt' % name)
			if not os.path.exists(txt_file):
				shutil.copy (
					os.path.join(edk2_dir, 'BaseTools/Conf/%s.template' % name),
					os.path.join(self._workspace, 'Conf/%s.txt' % name))


	def build(self):
		print ("Build [%s] ..." % self.board)
		# Run pre-build
		self.pre_build()
		dsc_file = os.path.join(os.environ['EDK2PLT_SOURCE'], PLATFORMPKG_MAP[self.board], 'PlatformPkg.dsc')
		if not os.path.exists(dsc_file):
			print ("DSC file %s could not be found!" % dsc_file)
			sys.exit(1)

		build_cmd  = "build"        if os.name == 'posix' else "build.bat"
		build_cmd += " -b RELEASE"  if self.release       else " -b DEBUG"
		build_cmd += " -a X64"      if self.arch64        else " -a IA32 -a X64"
		build_cmd += " -p %s"  % dsc_file
		build_cmd += " -t %s"  % os.environ['TOOL_CHAIN']
		build_cmd += " -n %s"  % str(multiprocessing.cpu_count())
		build_cmd += " -y Report.log"
		build_cmd += " -Y PCD"
		build_cmd += " -Y FLASH"
		build_cmd += " -Y LIBRARY"
		build_cmd += " -D PLATFORM_ARCH=X64"
		build_cmd += " -D BOOTLOADER=COREBOOT"  if self.coreboot else " -D BOOTLOADER=SBL"
		build_cmd += " -D USERPHYSICALPRESENCE=TRUE"  if self.userphysicalpresence else " -D USERPHYSICALPRESENCE=FALSE"
		build_cmd += " %s" % self.define
		print ("build_cmd %s" % build_cmd)

		# Run build
		print (build_cmd)
		x = subprocess.call(build_cmd, shell=True)
		if x: sys.exit(1)

		# Add a marker to indicate it is an internal UEFI payload at 1st DWORD
		pld_bin = '%s/Build/%sX64/%s_%s/FV/UEFIPAYLOAD.fd' % (
									os.environ['WORKSPACE'],
									PLATFORMPKG_MAP[self.board],
									"RELEASE" if self.release else "DEBUG",
									os.environ['TOOL_CHAIN'])

		with open(pld_bin,'r+b') as f:
			f.write(b'UEFI')

		print ("Build [%s] Done!" % self.board)

def main():
	prep_env ()
	board_names  = []

	update_platformpkg_map()
	board_names = list(PLATFORMPKG_MAP.keys())

	ap = argparse.ArgumentParser()
	sp = ap.add_subparsers(help='command')

	def cmd_build(args):
		Build(args).build()

	buildp = sp.add_parser('build', help='build UEFI payload for coreboot or Slim Bootloader')
	buildp.add_argument('-r',    '--release',     action='store_true', help='Release build')
	buildp.add_argument('-cb',   '--coreboot',    action='store_true', help='Build for coreboot,  by default for Slim Bootloader')
	buildp.add_argument('-x64',  '--arch64',      action='store_true', help='Build payload for 64bit bootloader. by default for 32bit bootloader.')
	buildp.add_argument('-D',    '--define',  type=str, action='append', help='Define MACRO to be passed into the build command line')
	buildp.add_argument('board', metavar='board', help='Board Name (%s)' % ', '.join(board_names))
	buildp.add_argument('-pp',    '--userphysicalpresence',     action='store_true', help='Build with user physical presence for test purposes')
	buildp.set_defaults(func=cmd_build)

	def cmd_clean(args):
		workspace = os.environ['WORKSPACE']
		dirs  = ['Build', 'Conf']
		files = [
			os.path.join (workspace, 'Report.log')
		]

		for dir in dirs:
			dirpath = os.path.join (workspace, dir)
			print ('Removing %s' % dirpath)
			shutil.rmtree(dirpath, ignore_errors=True)

		for file in files:
			if os.path.exists(file):
				print ('Removing %s' % file)
				os.remove(file)

		print('Clean Done !')

	cleanp = sp.add_parser('clean', help='clean build dir')
	cleanp.set_defaults(func=cmd_clean)

	args = ap.parse_args()

	if args.func == cmd_build:
		args.board = args.board.capitalize()
		if args.board not in board_names:
			print ("%s not found from boards (%s)" % (args.board, ', '.join(board_names)))
			sys.exit(1)

	args.func(args)

if __name__ == '__main__':
	main()

