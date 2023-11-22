project('SixteenthChapter', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])
subdir('src/')
exe = executable('c16p1', sources,
  install : true)
exe = executable('c16p4', sources1,
  install : true)

test('basic', exe)
