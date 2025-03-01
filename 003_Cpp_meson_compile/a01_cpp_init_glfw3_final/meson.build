project(
  'my_init', ['c','cpp'],
  version : '0.1',
  default_options : [
    'buildtype=debugoptimized',
    'cpp_std=c++17',
    'warning_level=1',
  ])

compiler = meson.get_compiler('cpp')
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

src_files = [
  'src/main.cpp',
  'src/glad.c'
]

#  meson.project_name(),   이렇게 하면됨 (겁나 간단함)

inc = include_directories('include')
executable(my_project_name, src_files,
          include_directories : inc,
          dependencies: [openGLDep, 
                        glfwDep, threadDep,
                        XiDep, XrandrDep,
                        dlDep, x11Dep,
                        Xxf86vmDep,XineramaDep,
                        XcursorDep ])
