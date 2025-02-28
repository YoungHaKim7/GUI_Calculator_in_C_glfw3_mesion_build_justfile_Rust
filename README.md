# GUI_Calculaor_in_C

- (C++)여기에 정리. https://github.com/YoungHaKim7/Cpp_glfw3_mesion_build_justfile
- GLFW3 bindings and idiomatic wrapper for Rust. https://github.com/PistonDevelopers/glfw-rs

<hr />

# link

- [https://www.khronos.org/opengl/wiki/OpenGL_Shading_Language](https://www.khronos.org/opengl/wiki/OpenGL_Shading_Language)

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

- glfw
  - [glfw문서정리 context_guide]()

- [Immediate mode가 왜 안 좋은지 잘 설명됨.](https://learnopengl.com/Getting-started/OpenGL)

<hr />

# 문서 정리(glfw)[|🔝|](#link)
- glfw tutorial eBooks
  - https://www.glfw.org/docs/3.3/quick_guide.html
- context_guide
  - https://www.glfw.org/docs/3.3/context_guide.html

- vulkan_guide
  - https://www.glfw.org/docs/3.3/vulkan_guide.html

- intro API(glfw)
  - https://www.glfw.org/docs/3.3/intro_guide.html


<hr />

# glfw2 -> glfw3 migration guide

- https://www.glfw.org/docs/3.3/moving_guide.html

<hr />

# build[|🔝|](#link)

```bash
pkg-config --static --libs glfw3 -lglfw -lrt -lm -ldl
```

- meson.build
  - https://www.glfw.org/docs/3.3/build_guide.html
  - https://stackoverflow.com/questions/78353973/meson-wrap-install-of-glfw3-is-not-able-to-find-libglfw3-3-dll-when-running-comp

## `meson.build` 간단하게 build(glfw3)[|🔝|](#link)

- C언어
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
- C언어(c_std=c11)

```bash
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
  'src/main.c'
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
```

<hr />

- https://groups.google.com/g/mesonbuild/c/o2NopZrSj5g?pli=1
- If I use `--buildtype=release` it optimizes `-O2` and the executable contains no debug symbol.
- If I use `--buildtype=debug` it does not optimize at all and uses `-g`.
- If I use `--buildtype=debugoptimized` it optimizes `-O2` and uses `-g`.


<hr />

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

## justfile(meson치기 귀찮다.)[|🔝|](#link)

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

## `.clang-format`[|🔝|](#link)

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

# Install[|🔝|](#link)

- https://www.glfw.org/


```bash
# arch linux
pacman -S glfw ttf-roboto-mono

# ubuntu
sudo apt install libwayland-dev libxkbcommon-dev xorg-dev

# macOS
brew install glfw glfw3 mesa-glu && brew install --cask font-roboto-mono
brew install --cask xquartz

```
- https://github.com/zamirmf/OpenGLOnMac
- xquartz https://stackoverflow.com/questions/67373307/macos-m1-fatal-error-glfw-glfw3-h-file-not-found

- To install GLFW3 on Ubuntu Linux, use the command `sudo apt-get install libglfw3-dev` in your terminal, which will install the necessary GLFW development libraries, allowing you to link against GLFW in your projects; if you only need the runtime libraries, use `sudo apt-get install libglfw3`
- https://stackoverflow.com/questions/52579597/why-cant-g-cannot-find-the-glfw3-library-correctly-in-ubuntu

<hr />


# (240513)Make a GUI Calculator in C like a real Chad | Cococry[|🔝|](#link)
- https://youtu.be/2oJTEpc9qmc?si=FieNrs_jZnEYRSNO
