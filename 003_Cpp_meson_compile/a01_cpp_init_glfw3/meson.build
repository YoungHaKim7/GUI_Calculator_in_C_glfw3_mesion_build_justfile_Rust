project(
  'my_project', 'cpp',
  version : '0.1',
  default_options : [
    'buildtype=debugoptimized', # Equivalent to -O3
    'cpp_std=c++20',               # Use C11 standard (commonly used with -pedantic) or c17
    'warning_level=3',         # Equivalent to -Wall -Wextra
    'b_lto=true',              # Enable Link-Time Optimization (optional, for -O3)
    'b_pie=true',              # Enable Position Independent Executable (optional)
])

# default_options : ['warning_level=everything', 'buildtype=release','cpp_std=c++17'])
# warning_level {0, 1, 2, 3, everything}
# buildtype {plain, debug, debugoptimized, release, minsize, custom}
# cpp_std = none, c++98, c++03, c++11, c++14, c++17, c++20 c++2a, c++1z, gnu++03, gnu++11, gnu++14, gnu++17, gnu++1z, gnu++2a, gnu++20, vc++14, vc++17, vc++20, vc++latest

my_project_name = meson.current_source_dir().split('/').get(-1)

# Define the GLFW and OpenGL dependencies
glfwdep = dependency('glfw3')
opengldep = dependency('gl')

src_files = [
  'src/main.cpp'
]

# Build the executable(폴더 src로 넣어서 깔끔하게)
executable(my_project_name,
          src_files,
          dependencies : [glfwdep, opengldep],
          c_args: [
            '-pedantic',       # Enable pedantic warnings
            '-pedantic-errors', # Treat pedantic warnings as errors
            '-ggdb'           # Generate debug information for GDB
])
