project('ScopeDurationLinkage', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])
subdir('src')

headers = include_directories('headers')

exe = executable('c6p1', sources1, include_directories : headers,
  install : true)

exe = executable('c6p4', sources2, include_directories : headers,
  install : true)

exe = executable('c6p10', sources3, include_directories : headers,
  install : true)

exe = executable('c6q2', sources4, include_directories : headers,
  install : true)

exe = executable('c6q3', sources5,
  install : true)

test('basic', exe)
