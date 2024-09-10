# C²
## Introduction
The C² language is a low-level programming language based on the C programming language, with the purpose of incorporating higher-level features, such as automated memory management, all while allowing for the use of C-style syntax, and optional low-level & unsafe code. The syntax of the C² language is in Backus-Naur form, as seen below.
## Roadmap
- [x] Is the scanner implemented?
- [ ] Is the parser implemented?
- [ ] Is semantic analysis implemented?
- [ ] Is code generation implemented?
## Syntax
### Expressions
An expression can be either a number, or two expressions (which could be numbers), separated by an operator. When working with expressions that work with operators, exponents are evaluated first, followed by multiplication and division, and finally addition and subtraction.
```
<expression> : <number>
             : <expression> ^ <expression>
             : <expression> * <expression>
             : <expression> / <expression>
             : <expression> + <expression>
             : <expression> - <expression
```