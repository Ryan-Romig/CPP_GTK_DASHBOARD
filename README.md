dashboard application written in C++
designed to act as front end for headless unit.
halted development, this repo serves as somewhat of a reference 


project created using gtk builder. 

build instructions :
dependencies : 
    Meson
    ninja-build
    gettext
    libgtk-4-dev
    desktop-file-utils


from project root, run `meson setup build` - build being whatever name you want to use for your build dir

cd into the build dir and run `meson compile`

the binary exists at build/src/melodia-launcher