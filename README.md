# PES Project 1 README

## Contributors: Troy Davis, Jack Campbell

## Organization:
Each program is organized by a subdirectory containing a CMake config and include/source dirs.
To build and run the programs using Makefiles, navigate to the root directory and run these commands.

This requires CMake 3.14 installed.
To get this version on Ubuntu, call:
```sudo apt-get install cmake```

Compilation instructions:
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

Improvements could be made:
- Refactoring print_numerical_representations in program 1 to be less verbose. Maybe replace switch statements
  with jump tables?
- Replace raw bit manipulations with macros
- Accept command line input

## ASCII type criteria for Program 2:
As requested in the project, the criteria we use for what constitutes an uppercase, lowercase,
digit, white space, or special ASCII digit is based on the helper functions available in ctype.h.
"Special" is designated as any character that is not alphanumeric or whitespace.
