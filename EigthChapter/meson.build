project('TypeConversionAndFunctionOverloading', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])
subdir('src/')

exe = executable('c8p1', sources,
  install : true)
exe = executable('c8p6', sources1,
  install : true)


test('basic', exe)
