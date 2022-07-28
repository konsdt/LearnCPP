project('Operators', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

subdir('src')

exe = executable('O1', sources,
  install : true)


exe = executable('O2', sources1,
  install : true)

exe = executable('O3', sources2,
  install : true)

exe = executable('O4', sources3,
  install : true)

test('basic', exe)
