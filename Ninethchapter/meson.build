project('CompoundtypesReferencesAndPointers', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])


subdir('src/')

exe = executable('c9p1', sources,
  install : true)
exe = executable('c9p5', sources1,
  install : true)
exe = executable('c9p6', sources2,
  install : true)
exe = executable('c9p9', sources3,
  install : true)
exe = executable('c9p10', sources4,
  install : true)
exe = executable('c9p11', sources5,
  install : true)






test('basic', exe)
