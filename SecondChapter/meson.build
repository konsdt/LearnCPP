project('c2p1', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

exe = executable('c2p1', 'c2p1.cpp',
  install : true)

exe1 = executable('c2p2', 'c2p2.cpp',
  install : true)

exe2 = executable('c2p3', 'c2p3.cpp',
install : true)

exe3 = executable('c2p4', 'c2p4.cpp',
install : true)

exe4 = executable('c2p5', 'c2p5.cpp',
install : true)

exe5 = executable('c2p7', 'c2p7.cpp',
install : true)

subdir('src')
exe6 = executable('c2p8', sources,
install : true)

subdir('src2p10')
exe6 = executable('c2p10', sources10,
install : true)




test('basic', exe)
