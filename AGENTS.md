# OOP Practices CMake Rules

This repo uses a consistent, per-project CMake setup. Each practice folder is a
standalone CMake project with its own `CMakeLists.txt` and `CMakePresets.json`.

## Project naming
- Project name is `Pr<N><Title>` where `<N>` is the practice number and
  `<Title>` is the folder name without the numeric prefix and spaces.
- Examples:
  - `Pr1/01 Struct` -> `Pr1Struct`
  - `Pr1/02 Memory` -> `Pr1Memory`
  - `Pr2/01 Classes` -> `Pr2Classes`
  - `Pr2/Zero` -> `Pr2Zero`

## CMakeLists.txt template
Use this template in each project folder and list every `.cpp` source file
explicitly (headers are not listed):

```cmake
cmake_minimum_required(VERSION 3.10.0)
project(PrXName VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(PrXName
    main.cpp
    OtherSource.cpp
)
```

## CMakePresets.json template
Each project folder uses the same presets:
- Generator: Ninja
- Compilers: clang / clang++
- Build dir: `build/<presetName>` under the project folder
- Presets: `debug` and `release`

```json
{
  "version": 4,
  "cmakeMinimumRequired": { "major": 3, "minor": 19, "patch": 0 },
  "configurePresets": [
    {
      "name": "base",
      "hidden": true,
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/build/${presetName}",
      "cacheVariables": {
        "CMAKE_EXPORT_COMPILE_COMMANDS": "ON",
        "CMAKE_C_COMPILER": "clang",
        "CMAKE_CXX_COMPILER": "clang++"
      }
    },
    {
      "name": "debug",
      "inherits": "base",
      "displayName": "Debug (Clang + Ninja)",
      "description": "Debug build with Clang and Ninja",
      "cacheVariables": { "CMAKE_BUILD_TYPE": "Debug" }
    },
    {
      "name": "release",
      "inherits": "base",
      "displayName": "Release (Clang + Ninja)",
      "description": "Release build with Clang and Ninja",
      "cacheVariables": { "CMAKE_BUILD_TYPE": "Release" }
    }
  ],
  "buildPresets": [
    { "name": "debug", "configurePreset": "debug" },
    { "name": "release", "configurePreset": "release" }
  ],
  "testPresets": [
    {
      "name": "debug",
      "configurePreset": "debug",
      "output": { "outputOnFailure": true }
    },
    {
      "name": "release",
      "configurePreset": "release",
      "output": { "outputOnFailure": true }
    }
  ]
}
```

## New practice checklist
1. Create the practice folder.
2. Add `CMakeLists.txt` using the template and correct project name.
3. Add `CMakePresets.json` using the standard template.
4. Run from the project folder:
   - `cmake --preset debug`
   - `cmake --build --preset debug`
