# ERA Project Assembly
## Build

In order to build and compile, you need to install `CMake` plus the toolchain of your choice, e.g. `MSBuild with MSVC` or `make with gcc`. After you setup [CMake](https://cmake.org/install) with your toolchain of choice, build the project as follows:

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

In order to execute, check `bin` folder in project directory for binaries. The assembly code to process is taken from `input.txt`, the resulting binary code is put into `output.txt`.

In order to test, you need to execute the corresponding test file from `test` folder.
