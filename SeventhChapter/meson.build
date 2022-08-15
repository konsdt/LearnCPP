project('ControlFlowAndErrorHandling', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++20'])
subdir('src/')
exe = executable('c7p1', sources,
  install : true)

exe = executable('c7p6', sources1,
  install : true)

exe = executable('c7p10', sources2,
  install : true)

exe = executable('c7p17', sources3,
  install : true)

headers = include_directories('headers')

exe = executable('c7px', sources4, include_directories: headers,
  install : true)

exe = executable('c7px3', sources5,
  install : true)

test('basic', exe)
