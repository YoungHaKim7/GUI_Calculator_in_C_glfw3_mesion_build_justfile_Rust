# cpp
- https://learnopengl.com/Introduction
- https://learnopengl.com/Getting-started/Hello-Window
- glad/glad.h
  - https://glad.dav1d.de/
  - https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library#glad_.28Multi-Language_GL.2FGLES.2FEGL.2FGLX.2FWGL_Loader-Generator.29

<hr />

- Tutorial정리 잘됨.
  - https://www.khronos.org/opengl/wiki/Getting_Started#Linux

<hr />
 
- LearnOpenGL
  - https://learnopengl.com/
  - https://github.com/Polytonic/Glitter
- khronos
  - https://www.khronos.org/opengl/wiki/Main_Page
  - https://github.com/KhronosGroup

- color
  - https://convertingcolors.com/cmyk-color-0.13_0.13_0.00_0.31.html

<hr />

# 중력 구현 미쳤네
- https://github.com/kavan010/gravity_sim/blob/main/gravity_sim.cpp
  - https://github.com/kavan010/gravity_sim/
  - [위 코드 영상250301 Simulating Gravity in C++ | Kavan](https://youtu.be/_YbGWoUaZg0?si=kU_obTQ1VInqC_Pr)


# small project

- [(230919)I made my own UI library in C++, How to design a complicated system? | Low Level Game Dev](https://youtu.be/hCLjiManL04?si=rr2cIviz3i5YulOT)
  - https://github.com/meemknight/glui


<hr />

# justfile에 컴파일 바꾸기

- 첫줄에 `export`하면 됨.

```justfile
export CC=clang
export CXX=clang++

meson build-clang
```


# meson.build

- https://mesonbuild.com/Builtin-options.html

```meson

# c
# c_std=none, c89, c99, c11, c17, c18, c2x, c23, c2y,
# gnu89, gnu99, gnu11, gnu17, gnu18, gnu2x, gnu23, gnu2y

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


# cpp
# cpp_std=none, c++98, c++03, c++11, c++14, c++17, c++20
# c++2a, c++1z, gnu++03, gnu++11, gnu++14, gnu++17, gnu++1z,
# gnu++2a, gnu++20, vc++14, vc++17, vc++20, vc++latest

project(
  'my_init', ['c','cpp'],
  version : '0.1',
  default_options : [
    'buildtype=debugoptimized',
    'cpp_std=c++17',
    'warning_level=1',
  ])

```

- https://mesonbuild.com/Builtin-options.html#base-options

- 최적화의 종류(주로 debugoptimized, release만 쓰면 될듯)
```meson
buildtype

debug
debugoptimized
release 	
minsize 	
```

# Details for warning_level

- Exact flags per warning level is compiler specific, but there is an approximative table for most common compilers.

|Warning level|GCC/Clang|MSVC|
|-|-|-|
|0| | |		
|1|-Wall||/W2|
|2|-Wall -Wextra|/W3|
|3|	-Wall -Wextra -Wpedantic|/W4|
|everything|-Weverything|/Wall|

<hr />

<br>

