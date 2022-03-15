project('HelloWorld', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
		     'cpp_std=c++17',
		     'buildtype=release',
                     'b_ndebug=true', # Disable all asserts
                     'b_lto=true', # Enable link time optimization
		    ])

exe = executable('helloworld', 'helloworld.cpp',
  install : true)

test('basic', exe)
