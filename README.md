# C²
## Introduction
The C² programming language is a programming language designed with the purpose to implement safety & object-oriented constructs as an alternative to C & C++, while still maintaining the organization & consistency of the C programming language.
This repository contains the documentation with C²'s specificationss, as well as the source code for the C² compiler.
## Changes
The C² brings many new (plans for) changes to the table.
It simplifies it's field of primitive types by renaming the `char` type to `byte`, removing the `short`, `int`, `long`, `float`, and `double` keywords, and planning for the standard library to implement bigger-sized types by `typedef`'ing buffer(s) of the `byte` type. This is much cleaner & more consistent than having to have types such as `long long int`, or `short int`, which clutters the programming experience.
C² also plans to incorporate must-have features, such as the ability to have language extensions, some standard, and others community-built. The C² programming language plans to incorporate standard extensions for things like structure packing, custom memory aligning, and even classes (but different to how languages such as C++ and Java handle object-oriented constructs), which would allow for things such as smart pointers, and other safety-related features.
Although like mentioned above, certain types found natively in the C programming language are removed, because the standard library can define them, or extensions can, C² code can still be fairly very backwards-compatible with C, and maybe even C++ code.
## Roadmap
- [x] Is the scanner implemented?
- [X] Is the parser implemented?
- [ ] Is semantic analysis implemented?
- [ ] Is code generation implemented?
In October 8th, I've fixed the parser, and it seems to be working fine now. Now all I've got to do is finish it completely, which means implementing AST generation, something that has not been done yet.