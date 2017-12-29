# HttpClient([![Build Status](https://travis-ci.org/emilw/HttpClient.svg?branch=master)](https://travis-ci.org/emilw/HttpClient))
==========
A cross platform HTTP client written in C++ based on raw sockets

## Get started
#### Get started Linux/Mac Os X
- Make sure you have CMake installed
- Git Clone the library
- Go to the project root folder
- cd build
- run ./BuildScriptUnix.sh

#### Get started Windows
- Make sure you have Chocolate package distributor installed
- Retrieve CMake that way(The build script is dependent on that path)
- Run Git Clone to get the project locally
- Go to the project root folder
- Run the PullAndBuildWindows.bat script


## Todo
- Make sure that all code is aligned to CppLint so it's possible to turn that check on when running the Travis builds.
- Add the Catch library for UnitTesting
- Support for SSL, using Open SSL
- Automatic builds for Windows, might be local seems impossible to find free windows build servers
