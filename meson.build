project('gui_c_glfw3', 'c')

# Ensure pkg-config is available
pkg = import('pkgconfig')

# Define the GLFW and OpenGL dependencies
glfwdep = dependency('glfw3')
opengldep = dependency('gl')

# Build the executable
executable('target_run', 'main.c', dependencies : [glfwdep, opengldep])
