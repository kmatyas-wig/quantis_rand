#!/usr/bin/env python3

from distutils.core import setup, Extension
setup(name = 'quantis_rand', version = '0.1',  \
      ext_modules = [Extension('quantis_rand', ['quantis_rand.c'],\
      include_dirs = ['/usr/local/include'],
      library_dirs = ['/usr/local/lib'],
      libraries = ['Quantis', 'usb-1.0' ]
      )])
