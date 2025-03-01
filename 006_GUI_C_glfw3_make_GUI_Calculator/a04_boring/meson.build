project(
  'my_project', 'c',
  version : '0.1',
  default_options : [
    'buildtype=debugoptimized', # Equivalent to -O3
    'c_std=c11',               # Use C11 standard (commonly used with -pedantic) or c17
    'warning_level=1',         # Equivalent to -Wall -Wextra
    'b_lto=true',              # Enable Link-Time Optimization (optional, for -O3)
    'b_pie=true',              # Enable Position Independent Executable (optional)
])

# default_options : ['warning_level=everything', 'buildtype=release','c_std=c17'])
# warning_level {0, 1, 2, 3, everything}
# buildtype {plain, debug, debugoptimized, release, minsize, custom}
# c_std=none, c89, c99, c11, c17, c18, c2x, c23, c2y, gnu89, gnu99, gnu11, gnu17, gnu18, gnu2x, gnu23, gnu2y

compiler = meson.get_compiler('c')
openGLDep = dependency('gl')
glfwDep = dependency('glfw3', required: false)
threadDep = dependency('threads')
XrandrDep = dependency('Xrandr', required: false)
XiDep = dependency('Xi', required: false)
dlDep = dependency('dl', required: false)
x11Dep = dependency('x11', required: false)
Xxf86vmDep = dependency('Xxf86vm', required :false)
XineramaDep = dependency('Xinerama', required: false)
XcursorDep = dependency('Xcursor', required: false)

libsPath = '/usr/lib/x86_64-linux-gnu/'
if not glfwDep.found()
  glfwDep = compiler.find_library('glfw3', dirs: libsPath)
endif
if not XrandrDep.found()
  XrandrDep = compiler.find_library('Xrandr', dirs: libsPath)
endif
if not XiDep.found()
  XiDep = compiler.find_library('Xi', dirs: libsPath)
endif
if not dlDep.found()
  dlDep = compiler.find_library('dl', dirs: libsPath)
endif
if not x11Dep.found()
  x11Dep = compiler.find_library('x11', dirs: libsPath)
endif
if not Xxf86vmDep.found()
  Xxf86vmDep = compiler.find_library('Xxf86vm', dirs: libsPath)
endif
if not XineramaDep.found()
  XineramaDep = compiler.find_library('Xinerama', dirs: libsPath)
endif
if not XcursorDep.found()
  XcursorDep = compiler.find_library('Xcursor', dirs: libsPath)
endif

my_project_name = meson.current_source_dir().split('/').get(-1)

# Define the GLFW and OpenGL dependencies
glfwdep = dependency('glfw3')
opengldep = dependency('gl')

src_files = [
  'src/main.c',
  'src/glad.c'
]

inc = include_directories('include')

# Build the executable(폴더 src로 넣어서 깔끔하게)
executable(my_project_name,
          src_files,
          dependencies : [glfwdep, opengldep],
          include_directories : inc,
          c_args: [
            '-pedantic',       # Enable pedantic warnings
            '-pedantic-errors', # Treat pedantic warnings as errors
            '-ggdb'           # Generate debug information for GDB
])
