project('FifteenthChapter', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])
subdir('src')

exe = executable('c15p1', sources,
  install : true)
exe = executable('c15p2', sources1,
  install : true)
exe = executable('c15p3', sources2,
  install : true)

test('basic', exe)
