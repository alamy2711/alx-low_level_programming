# 0x00-hello_world

![Banner](https://lh3.googleusercontent.com/u/0/drive-viewer/AITFw-w4kzEgUE_Raj1pDH6Fx3EXMbbRH1BgzzTsl9B3jl7kOR4Q24KqIeKAt891cFa16mkwb7xxJYeoAUoA2QC_dI1Fgi0UxQ=w1920-h874)

## Description

This project `0x00-hello_world` is part of the [ALX Low-Level Programming](https://github.com/alamy2711/alx-low_level_programming) curriculum. It focuses on introductory tasks related to the C programming language, covering essential concepts such as preprocessor directives, compiling, assembling, using basic C functions like `printf` and `puts`, and understanding data types and sizes.

## Tasks and Their Files

#### 0-preprocessor
  - **Task:** Write a script that runs a C file through the preprocessor and saves the result into another file.
  - **How to Use:** To execute the script, run `./0-preprocessor` after setting the `$CFILE` environment variable to the name of the C file you want to preprocess.

#### 1-compiler
   - **Task:** Write a script that compiles a C file but does not link.
   - **How to Use:** To execute the script, run `./1-compiler` after setting the `$CFILE` environment variable to the name of the C file you want to compile.

#### 2-assembler
   - **Task:** Write a script that generates the assembly code of a C code and saves it in an output file.
   - How to Use: To execute the script, run `./2-assembler` after setting the `$CFILE` environment variable to the name of the C file you want to generate the assembly code for.

#### 3-name
   - **Task:** Write a script that compiles a C file and creates an executable named `cisfun`.
   - How to Use: To execute the script, run `./3-name` after setting the `$CFILE` environment variable to the name of the C file you want to compile.

#### 4-puts.c
   - **Task:** Write a C program that prints the phrase "Programming is like building a multilingual puzzle" using the `puts` function.
   - How to Use: Compile the C file using `gcc -o 4-puts 4-puts.c` and then run the generated executable `./4-puts`.

#### 5-printf.c
   - **Task:** Write a C program that prints the phrase "with proper grammar, but the outcome is a piece of art," using the `printf` function.
   - How to Use: Compile the C file using `gcc -o 5-printf 5-printf.c` and then run the generated executable `./5-printf`.

#### 6-size.c
   - **Task:** Write a C program that prints the size of various data types on the computer it is compiled and run on.
   - How to Use: Compile the C file using `gcc -o 6-size 6-size.c` and then run the generated executable `./6-size`.

#### 100-intel
   - **Task:** Write a script that generates the assembly code (Intel syntax) of a C code and saves it in an output file.
   - How to Use: To execute the script, run `./100-intel` after setting the `$CFILE` environment variable to the name of the C file you want to generate the assembly code for.

#### 101-quote.c
   - **Task:** Write a C program that prints the phrase "and that piece of art is useful" - Dora Korpar, 2015-10-19, to the standard error.
   - How to Use: Compile the C file using `gcc -o 101-quote 101-quote.c` and then run the generated executable `./101-quote`. The output will be printed to the standard error stream.

> Note: For each task, there is a shell script or a C program with a corresponding number in the filename, which carries out the specified objective. You can use these scripts/programs as shown above to achieve the desired outcomes. Additionally, some tasks require setting an environment variable (`$CFILE`) to specify the C file to be processed or compiled.