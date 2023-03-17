project('ArraysStringsAndDynamicAllocation', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

subdir('src/')
exe = executable('c11p1', sources,
  install : true)
exe = executable('c11p2', sources1,
  install : true)
exe = executable('c11p3', sources2,
  install : true)
exe = executable('c11p4', sources3,
  install : true)
exe = executable('c11p5', sources4,
  install : true)
exe = executable('c11p7', sources5,
  install : true)
exe = executable('c11p8', sources6,
  install : true)
exe = executable('c11p9', sources7,
  install : true)
exe = executable('c11p10', sources8,
  install : true)
exe = executable('c11p11', sources9,
  install : true)
exe = executable('c11p11q', sources9q,
  install : true)


test('basic', exe)
