# MosquitoBorneDisease

[![Travis](https://travis-ci.com/ben18785/MosquitoBorneDisease.svg?branch=master)](https://travis-ci.com/ben18785/MosquitoBorneDisease)
[![AppVeyor](https://ci.appveyor.com/api/projects/status/xsl6oivbxq8gvrlr?svg=true)](https://ci.appveyor.com/project/fcooper8472/mosquitobornedisease)
[![BCH compliance](https://bettercodehub.com/edge/badge/ben18785/MosquitoBorneDisease?branch=master)](https://bettercodehub.com/)

todo: add information about the software.

### System requirements

1. A modern C++ compiler. This project is currently tested against
   - [gcc](https://gcc.gnu.org/) 5 and newer
   - [clang](https://clang.llvm.org/) 4 and newer
   - [Xcode](https://developer.apple.com/xcode/) 9.3
   - [Visual Studio](https://visualstudio.microsoft.com/vs/features/cplusplus/) 2017
1. [CMake](https://cmake.org/) 3.6 or newer


### Basic usage

#### Linux and MacOS

```
# Obtain the source code
git clone https://github.com/ben18785/MosquitoBorneDisease.git

# Create a build directory
mkdir /path/to/build/dir
cd /path/to/build/dir

# Configure project with CMake, build with make, and run tests with CTest
cmake /path/to/source/dir
make 
ctest
```


#### Windows
1. Install [Visual Studio](https://visualstudio.microsoft.com/downloads/) (Community edition is free for open source contributors)
1. Obtain the source code for this repository

##### To build from Visual Studio
1. `File | Open | CMake...` and select this repository's `CMakeLists.txt`. CMake will run automatically.
1. You can build and run executables in a number of ways, for instance by right-clicking on `CMakeLists.txt` in the solution explorer and:
    - `Build | mbd_test.exe`
    - `Run Tests`

##### To build from the command prompt
1. Open `Developer Command Prompt for VS 20XX` and navigate to this repository
```
# Create a build directory
mkdir /path/to/build/dir
cd /path/to/build/dir

# Configure and build project with CMake, and run tests with CTest
cmake -G Ninja /path/to/source/dir
cmake --build .
ctest
```
