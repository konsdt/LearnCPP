project('DataTypes', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

subdir('src')

exe = executable('c4p1', sources1,
  install : true)

exe = executable('c4p9', sources2,
  install : true)

exe = executable('c4p10', sources3,
  install : true)

exe = executable('c4p11', sources4,
  install : true)

exe = executable('c4p12', sources5,
  install : true)

exe = executable('c4p13', sources6,
  install : true)

exe = executable('c4p14', sources7,
  install : true, override_options: ['cpp_std=c++20'])

exe = executable('c4q3', sources8,
  install : true, override_options: ['cpp_std=c++20'])

exe = executable('c4q4', sources9,
  install : true, override_options: ['cpp_std=c++20'])








test('basic', exe)
