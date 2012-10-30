import platform
import os

osName = platform.system()

if osName == 'Windows':
	os.system('set_vs_var.bat')
	os.system('bgcc_build_windows.bat')
elif osName == 'Linux':
	os.system('make -f Makefile')

