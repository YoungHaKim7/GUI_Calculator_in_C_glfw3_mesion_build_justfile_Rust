# GUI_Calculaor_in_C

- [외부링크OpenGL 소개: OpenGL, GLFW, GLEW란? [OpenGL E02]OpenGL/GLEW/GLFW](https://kyoungwhankim.github.io/ko/blog/opengl_intro/)
  - [(외부링크_Vertex Shader와 Fragment Shader](https://kyoungwhankim.github.io/ko/blog/opengl_triangle2/)
    - 삼각형을 그릴 때 필요한 셰이더는, 그리고 사실 가장 중요한 셰이더 두 개는 Vertex Shader와 Fragment Shader(또는 Pixel Shader라고도 함)입니다

- [glfw3 install](#install)

- 반복 작업
  - [glfw3 build](#build)
    - [meson.build간단(C언어)](#mesonbuild-간단하게-buildglfw3)
    - [justfile](#justfilemeson치기-귀찮다)
    - [.clang-format](#clang-format)

<hr />

- tutorial
  - [(240513)Make a GUI Calculator in C like a real Chad | Cococry](#240513make-a-gui-calculator-in-c-like-a-real-chad--cococry)

<hr />

# build

```bash
pkg-config --static --libs glfw3 -lglfw -lrt -lm -ldl
```

- meson.build
  - https://www.glfw.org/docs/3.3/build_guide.html
  - https://stackoverflow.com/questions/78353973/meson-wrap-install-of-glfw3-is-not-able-to-find-libglfw3-3-dll-when-running-comp

## `meson.build` 간단하게 build(glfw3)

```bash
project('gui_c_glfw3', 'c')

# Ensure pkg-config is available
pkg = import('pkgconfig')

# Define the GLFW and OpenGL dependencies
glfwdep = dependency('glfw3')
opengldep = dependency('gl')

# Build the executable
# executable('target_run', 'main.c', dependencies : [glfwdep, opengldep])

# Build the executable(폴더 src로 넣어서 깔끔하게)
executable('target_run', 'src/main.c', dependencies : [glfwdep, opengldep])

```

- https://mesonbuild.com/Builtin-options.html

```bash
project(
  'gui_c_glfw3', 'c'
  version : '0.1',
  default_options : ['warning_level=everything', 'c_std=c17'])
  

# Ensure pkg-config is available
pkg = import('pkgconfig')

# Define the GLFW and OpenGL dependencies
glfwdep = dependency('glfw3')
opengldep = dependency('gl')

src_files = [
  'src/main.c'
]

# Build the executable(폴더 src로 넣어서 깔끔하게)
executable('target_run',
           src_files,
           dependencies : [glfwdep, opengldep])

```

- `meson.build` (C++) 약간 응용

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

## justfile(meson치기 귀찮다.)

```justfile
target := "target"

r:
    rm -rf {{target}}
    meson setup {{target}}
    meson compile -C {{target}}
    ./{{target}}/target_run

c:
    rm -rf {{target}}
```

## `.clang-format`

```.clang-format
# BasedOnStyle: WebKit
# LLVM, Google, Chromium, Mozilla, WebKit

BasedOnStyle: WebKit
IndentWidth: 4
ContinuationIndentWidth: 4
IndentCaseLabels: false
IndentCaseBlocks: false
IndentGotoLabels: true
IndentPPDirectives: None
IndentExternBlock: NoIndent

ColumnLimit: 80


```

- Does meson work with vcpkg?
  - https://github.com/Neumann-A/meson-vcpkg
  - https://www.reddit.com/r/meson/comments/m4i9o1/does_meson_work_with_vcpkg/?rdt=59720


<hr />

# Install

- https://www.glfw.org/


```bash
# arch linux
pacman -S glfw ttf-roboto-mono

# ubuntu
sudo apt install libwayland-dev libxkbcommon-dev xorg-dev

# macOS
brew install glfw mesa-glu && brew install --cask font-roboto-mono

```

- To install GLFW3 on Ubuntu Linux, use the command `sudo apt-get install libglfw3-dev` in your terminal, which will install the necessary GLFW development libraries, allowing you to link against GLFW in your projects; if you only need the runtime libraries, use `sudo apt-get install libglfw3`
- https://stackoverflow.com/questions/52579597/why-cant-g-cannot-find-the-glfw3-library-correctly-in-ubuntu

<hr />


# (240513)Make a GUI Calculator in C like a real Chad | Cococry
- https://youtu.be/2oJTEpc9qmc?si=FieNrs_jZnEYRSNO
