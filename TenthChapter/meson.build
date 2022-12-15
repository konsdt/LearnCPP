project('CompoundTypesEnumsAndStructs', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])
subdir('src/')
exe = executable(sources, 'c10p1.cpp',
  install : true)

test('basic', exe)
