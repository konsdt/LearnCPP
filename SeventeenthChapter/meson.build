project('SeventeenthChapter', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])
subdir('src/')
exe = executable('c17p1', sources,
  install : true) 
test('basic', exe)
