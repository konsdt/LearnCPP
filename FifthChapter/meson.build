project('Operators', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])

subdir('src')

exe = executable('c5p1', sources,
  install : true)

exe = executable('c5p5', sources1,
  install : true)

test('basic', exe)
