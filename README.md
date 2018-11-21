# MosquitoBorneDisease

[![Travis](https://travis-ci.com/ben18785/MosquitoBorneDisease.svg?branch=master)](https://travis-ci.com/ben18785/MosquitoBorneDisease)
[![AppVeyor](https://ci.appveyor.com/api/projects/status/xsl6oivbxq8gvrlr?svg=true)](https://ci.appveyor.com/project/fcooper8472/mosquitobornedisease)

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
todo: fill this in