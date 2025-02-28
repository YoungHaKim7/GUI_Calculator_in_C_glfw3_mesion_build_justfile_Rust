project(
  'my_project', 'c',
  version : '0.1',
  default_options : [
    'buildtype=debugoptimized', # Equivalent to -O3
    'c_std=c11',               # Use C11 standard (commonly used with -pedantic) or c17
    'warning_level=3',         # Equivalent to -Wall -Wextra
    'b_lto=true',              # Enable Link-Time Optimization (optional, for -O3)
    'b_pie=true',              # Enable Position Independent Executable (optional)
])

# default_options : ['warning_level=everything', 'buildtype=release','c_std=c17'])
# warning_level {0, 1, 2, 3, everything}
# buildtype {plain, debug, debugoptimized, release, minsize, custom}
# c_std=none, c89, c99, c11, c17, c18, c2x, c23, c2y, gnu89, gnu99, gnu11, gnu17, gnu18, gnu2x, gnu23, gnu2y

my_project_name = meson.current_source_dir().split('/').get(-1)

# Define the GLFW and OpenGL dependencies
glfwdep = dependency('glfw3')
opengldep = dependency('gl')

src_files = [
  'src/main.c',
  'src/leif.c'
]
# Link against the custom library (e.g., libleif.a or libleif.so)
# leifdep = meson.get_compiler('c').find_library('leif', required: true)

# Build the executable(폴더 src로 넣어서 깔끔하게)
executable(my_project_name,
          src_files,
          dependencies : [glfwdep, opengldep],
          c_args: [
            '-pedantic',       # Enable pedantic warnings
            '-pedantic-errors', # Treat pedantic warnings as errors
            '-ggdb'           # Generate debug information for GDB
])
