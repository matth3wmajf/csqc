# C²
## Introduction
The C² language is a low-level programming language based on the C programming language, with the purpose of incorporating higher-level features, such as automated memory management, all while allowing for the use of C-style syntax, and optional low-level & unsafe code. The syntax of the C² language is in Backus-Naur form, as seen below.
## Roadmap
- [x] Is the scanner implemented?
- [ ] Is the parser implemented?
- [ ] Is semantic analysis implemented?
- [ ] Is code generation implemented?
## Syntax
### Operators
Operators in C² can be either unary, binary, or ternary. Although C² plans to be compatible to C, we currently will implement the very basic operators from C, those simply being some binary operators:
* `+`
* `-`
* `*`
* `/`
* `%`
### Constants
Constants in C² can be either literals, constant identifiers, or constant expressions. Constant expressions should be automatically evaluated by the compiler during the parsing phase, and submitted to the object array as a constant.
Here's the Backus-Naur form for constants:
```
<constant> ::= <literal> | <constant-identifier> | <constant-expression>
```
And here's the Backus-Naur form for constant expressions:
```
<unary-constant-expression> ::= <operator> <constant> | <constant> <operator>
<binary-constant-expression> ::= <constant> <operator> <constant>
<ternary-constant-expression> ::= <constant> <operator> <constant> <operator> <constant>
<constant-expression> ::= <unary-constant-expression> | <binary-constant-expression> | <ternary-constant-expression>
```
### Terms
Unlike constants, the value of terms are mutable. Terms can be either variables, or the return value(s) of a function.
Here's the Backus-Naur form for terms:
```
<term> ::= <variable-identifier> | <function-call-return-value>
```
### Expressions
Expressions consist of two other objects, those being the operands. In order to be an expression, at least one of the operands must be a term. If both are constants, then they will simplify into a constant expression, and therefore will simply result as a constant object, and not an expression.
Here's the Backus-Naur form for expressions:
```
<unary-expression> ::= <operator> <term> | <term> <operator>
<binary-expression> ::= <term> <operator> <term>
<ternary-expression> ::= <term> <operator> <term> <operator> <term>
<expression> ::= <unary-expression> | <binary-expression> | <ternary-expression>
```