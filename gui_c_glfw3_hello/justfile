target := "builddir"

r:
    rm -rf {{target}}
    meson setup {{target}}
    meson compile -C {{target}}
    ./{{target}}/target_run

c:
    rm -rf {{target}}
