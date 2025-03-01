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
imgui_dep = dependency('imgui')

libsPath = '/opt/homebrew/include'
if not glfwDep.found()
  glfwDep = compiler.find_library('glfw3', dirs: libsPath)
endif
if not XrandrDep.found()
  XrandrDep = compiler.find_library('Xrandr', dirs: libsPath)
endif

my_project_name = meson.current_source_dir().split('/').get(-1)

src_files = [
  'src/main.cpp',
  'src/glad.c'
]

inc = include_directories('include')
executable(my_project_name, src_files,
          include_directories : inc,
          dependencies: [openGLDep, 
                        glfwDep, threadDep,
                        imgui_dep
                        ])
