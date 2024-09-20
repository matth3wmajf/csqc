# C²
## Introduction
The C² programming language is a hybrid programming language which combines the efficiency & control of low-level access while allowing for the simplicity of high-level abstractions.
## Changes
The C² language plans for several changes which make it unique from the regular C programming language.
Our first change consists of the plans for the removal of the `short`, `int`, and `long` keywords, and the renaming of `char` to `byte`. The standard library may then define data types as buffers of the `byte` type. Not only does this simplify the amount of keywords that we store, but this also allows to possibly define & store data types that are larger than what the CPU can handle in one instruction.
## Roadmap
- [x] Is the scanner implemented?
- [ ] Is the parser implemented?
- [ ] Is semantic analysis implemented?
- [ ] Is code generation implemented?