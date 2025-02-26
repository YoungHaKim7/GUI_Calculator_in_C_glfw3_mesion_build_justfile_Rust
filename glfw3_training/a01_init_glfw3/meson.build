# Set the project name
project('test_x' , 'c')

# Ensure pkg-config is available
pkg = import('pkgconfig')

# Define the GLFW and OpenGL dependencies
glfwdep = dependency('glfw3')
opengldep = dependency('gl')

# Build the executable
executable('a01_init_glfw3', 'src/main.c', dependencies : [glfwdep, opengldep])
