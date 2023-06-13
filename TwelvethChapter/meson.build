project('TwelvethChapter', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])
subdir('src/')
exe = executable('c12p1', sources,
  install : true)
exe = executable('c12q1', sources,
  install : true)

test('basic', exe)
