project('DataTypes', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

subdir('src')

exe = executable('c4p1', sources1,
  install : true)

exe = executable('c4p9', sources2,
  install : true)

exe = executable('c4p10', sources3,
  install : true)




test('basic', exe)
