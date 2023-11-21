project('FifteenthChapter', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])
subdir('src')
subdir('src/c15x9/src')
incdir = include_directories('src/c15x9/header')
exe = executable('c15p1', sources,
  install : true)
exe = executable('c15p2', sources1,
  install : true)
exe = executable('c15p3', sources2,
  install : true)
exe = executable('c15p6', sources3,
  install : true)
exe = executable('c15p7', sources4,
  install : true)
exe = executable('c15p8', sources5,
  install : true) 
exe = executable('c15x91', sources6,
  install : true)
exe = executable('c15x92', sources7, include_directories : incdir,
  install : true)
exe = executable('c15x', sourcesx,
  install : true)  
test('basic', exe)
