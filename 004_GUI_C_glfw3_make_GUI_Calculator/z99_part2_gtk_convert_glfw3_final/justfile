target := "target"
project_name := `basename "$(pwd)"`

r:
    rm -rf {{target}}
    meson setup {{target}}
    meson compile -C {{target}}
    ./{{target}}/{{project_name}}

c:
    rm -rf {{target}}
