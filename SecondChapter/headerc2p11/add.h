// Thhis is the content of the .h file which is where the declarations go
//
// We now add a header guard in the form of a preprocessor directive
// namely a define if clause:
// This will avoid double inclution of the same definitions
// The header guard naming can quickly become an issue in bigger projects
// since there might be header files with the same names
// Therefore several naming conventions exist:
// <PROJECT>_<PATH>_<FILE>_H, <FILE>_<LARGE RANDOM NUMBER>_H or <FILE>_<CREATION DATE>_H
// 
// HEADER GUARDS will only prevent double inclusion (and definition) inside one code file,
// in a multifile project a double inclusion can still occur, since the pre-
// processor directives only have a file wide scope
//
// Usually this would be avoided by putting no definitions inside the header 
// files, but this can not always be avoided entirely since user defined type
// definitions live inside the header files sometimes, therefore we need the 
// HEADER GUARDS
// Best practice: dont use #pragma once for compatibility reasons!
#ifndef ADD_070722_H
#define ADD_070722_H

int add(int x, int y); //function prototype for add.cpp

#endif
