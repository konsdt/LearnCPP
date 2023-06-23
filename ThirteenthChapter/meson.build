project('Basic Object-oriented Programming', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])
subdir('src/')

exe = executable('c13p1', sources,
  install : true)
exe = executable('c13p3', sources1,
  install : true)

test('basic', exe)
