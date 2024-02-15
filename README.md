# Raylib GUI

A simple gui framework for raylib.

## Requirements

- gcc
- raylib

## Usage

- Build the library:
```console
cc nobuild.c -o nobuild
./nobuild
```
This will compile the library and put the output (libraygui.a) in build/.
- Use the library:
    - Include the header files from the ```src``` directory in your project's include folder.
    - Copy the ```build/libraygui.a``` from the ```build``` directory to your project's lib folder.
    - Compile your project with ```g++ -Iinclude -Llib ... -lraygui```.

## Example

```console
cc nobuild.c -o nobuild 
./nobuild example
```
This will compile the library, place the example executable in build/, and run it as to show off the library's features.
