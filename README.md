# PES Project 1 README

## Contributors: Troy Davis, Jack Campbell

## Project Organization:
Each program is organized by a subdirectory containing a CMake config and include/source dirs.
To build and run the programs using Makefiles, navigate to the root directory and run these commands.

Functions called from `main()` are declared in header files, while private functions used internally
by public functions are only declared and defined in the implementation files. 

This requires CMake 3.14 installed.
To get this version on Ubuntu, call:
```sudo apt-get install cmake```

Compilation instructions. Navigate to the root directory of the repo and run these:
```
mkdir build && cd build
cmake ..
make
```

Execution instructions:
```
./program_1/ecen_5813_project_1_program_1
./program_1/ecen_5813_project_1_program_2
./program_1/ecen_5813_project_1_program_3
```

Inputs are compiled into the executables rather than read from the command line.

## ASCII type criteria for Program 2:
As requested in the project, the criteria we use for what constitutes an uppercase, lowercase,
digit, white space, or special ASCII digit is based on the helper functions available in ctype.h.
"Special" is designated as any character that is not alphanumeric or whitespace.
