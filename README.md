# GUI_Calculaor_in_C


<hr />

# build

```bash
pkg-config --static --libs glfw3 -lglfw -lrt -lm -ldl
```

- meson.build
  - https://www.glfw.org/docs/3.3/build_guide.html
  - https://stackoverflow.com/questions/78353973/meson-wrap-install-of-glfw3-is-not-able-to-find-libglfw3-3-dll-when-running-comp

- 간단하게 build(glfw3)

```bash
project('gui_c_glfw3', 'c')

# Ensure pkg-config is available
pkg = import('pkgconfig')

# Define the GLFW and OpenGL dependencies
glfwdep = dependency('glfw3')
opengldep = dependency('gl')

# Build the executable
executable('target_run', 'main.c', dependencies : [glfwdep, opengldep])
```

- 약간 응용

```bash
project('project', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++14'])

glfw_dep = dependency('glfw3')
lua_dep = dependency('lua')

src_files = ['axolotl.cpp', 'Window.cpp']

executable('project',
           src_files,
           win_subsystem: 'windows',
           dependencies: [glfw_dep, lua_dep],
           install : true)
```

<hr />

# Install

- https://www.glfw.org/


```bash
# arch linux
pacman -S glfw ttf-roboto-mono

# ubuntu
sudo apt install libwayland-dev libxkbcommon-dev xorg-dev

```

- To install GLFW3 on Ubuntu Linux, use the command `sudo apt-get install libglfw3-dev` in your terminal, which will install the necessary GLFW development libraries, allowing you to link against GLFW in your projects; if you only need the runtime libraries, use `sudo apt-get install libglfw3`
- https://stackoverflow.com/questions/52579597/why-cant-g-cannot-find-the-glfw3-library-correctly-in-ubuntu

<hr />


# (240513)Make a GUI Calculator in C like a real Chad | Cococry
- https://youtu.be/2oJTEpc9qmc?si=FieNrs_jZnEYRSNO
