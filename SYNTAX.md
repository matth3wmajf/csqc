# Syntax
## Introduction
The C² programming language inherits the syntax of the C programming language. This page documents the syntax of the C² programming language, using a variant of Backus-Naur form.
The logic for our variant of Backus-Naur form is as follows:
* Anything between two double quotes is seen as a string value that can be found in the source code.
* When two items are separated by a vertical bar, it means the object on the left or right can be used.
* To group multiple items, place them in between parentheses.
* When two items are next to each other, it means they are both concatenated.
* When an asterisk follows an item, it means that item's existence can be optional, or it can be repeated multiple times.
* When a plus sign follows an item, it means that item's existence is required at least once, but it can be repeated more than once.
* When a question mark follows an item, it means that item's existence is optional, but cannot be repeated more than once.
## Syntax
### Keywords
```bnf
<keyword> ::= "auto" | "break" | "case" | "byte" | "const" | "continue" | "default" | "do" | "else" | "enum" | "extern" | "for" | "goto" | "if" | "register" | "return" | "signed" | "sizeof" | "static" | "struct" | "switch" | "typedef" | "union" | "unsigned" | "void" | "volatile" | "while"
```
### Symbols
```bnf
<symbol> ::= "+" | "-" | "*" | "/" | "=" | "<" | ">" | "!" | "&" | "|" | "^" | "~" | "(" | ")" | "{" | "}" | "[" | "]" | ";" | "," | "." | "%" | "==" | "!=" | "<=" | ">=" | "&&" | "||" | "<<" | ">>"
```
### Operators
```bnf
<assignment-operator> ::= "=" | "*=" | "/=" | "%=" | "+=" | "-=" | "<<=" | ">>=" | "&=" | "^=" | "|="
<unary-operator> ::= "&" | "*" | "+" | "-" | "~" | "!"
```
### Character literals
```bnf
<character-literal> ::= "'" <character> "'"
<printable-character> ::= "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z" | "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z" | "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" | " " | "!" | "#" | "$" | "%" | "&" | "*" | "+" | "," | "-" | "." | "/" | ":" | ";" | "<" | "=" | ">" | "?" | "@" | "[" | "]" | "^" | "_" | "`" | "{" | "|" | "}" | "~" | "\\\"" | "(" | ")" | "\""
<character> ::= <printable-character> | <escape-sequence>
<escape-sequence> ::= "\\n" | "\\t" | "\\r" | "\\\\" | "\\'"
```
### Numeric literals
```bnf
<digit> ::= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
<integer-literal> ::= <digit>+ ("U" | "L" | "LL" | "UL" | "ULL")*
<float-literal> ::= <digit>+ "." <digit>+ ("f" | "F" | "l" | "L")*
<numeric-literal> ::= <integer-literal> | <float-literal>
```
## Primitive types & type qualifiers
```bnf
<primitive-type> ::= "void" | "byte"
<type-qualifier> ::= "const" | "volatile" | "static" | "extern" | "inline" | "register" | "auto" | "restrict" | "signed" | "unsigned"
```
## Identifiers
```bnf
<letter> ::= "a" | "b" | "c" | "d" | "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" | "t" | "u" | "v" | "w" | "x" | "y" | "z" | "A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K" | "L" | "M" | "N" | "O" | "P" | "Q" | "R" | "S" | "T" | "U" | "V" | "W" | "X" | "Y" | "Z" | "_"
<letter-or-digit> ::= <letter> | <digit>
<identifier> ::= <letter> <letter-or-digit>*
```
## String literals
```bnf
<string-literal> ::= "\"" <character>* "\""
```
## Expressions
```bnf
<constant-expression> ::= <conditional-expression>
<conditional-expression> ::= <logical-or-expression> | <logical-or-expression> "?" <expression> ":" <conditional-expression>
<logical-or-expression> ::= <logical-and-expression> | <logical-or-expression> "||" <logical-and-expression>
<logical-and-expression> ::= <inclusive-or-expression> | <logical-and-expression> "&&" <inclusive-or-expression>
<inclusive-or-expression> ::= <exclusive-or-expression> | <inclusive-or-expression> "|" <exclusive-or-expression>
<exclusive-or-expression> ::= <and-expression> | <exclusive-or-expression> "^" <and-expression>
<and-expression> ::= <equality-expression> | <and-expression> "&" <equality-expression>
<equality-expression> ::= <relational-expression> | <equality-expression> "==" <relational-expression> | <equality-expression> "!=" <relational-expression>
<relational-expression> ::= <shift-expression> | <relational-expression> "<" <shift-expression> | <relational-expression> ">" <shift-expression> | <relational-expression> "<=" <shift-expression> | <relational-expression> ">=" <shift-expression>
<shift-expression> ::= <additive-expression> | <shift-expression> "<<" <additive-expression> | <shift-expression> ">>" <additive-expression>
<additive-expression> ::= <multiplicative-expression> | <additive-expression> "+" <multiplicative-expression> | <additive-expression> "-" <multiplicative-expression>
<multiplicative-expression> ::= <cast-expression> | <multiplicative-expression> "*" <cast-expression> | <multiplicative-expression> "/" <cast-expression> | <multiplicative-expression> "%" <cast-expression>
<cast-expression> ::= <unary-expression> | "(" <type-name> ")" <cast-expression>
<unary-expression> ::= <postfix-expression> | "++" <unary-expression> | "--" <unary-expression> | <unary-operator> <cast-expression> | "sizeof" <unary-expression> | "sizeof" <type-name>
<postfix-expression> ::= <primary-expression> | <postfix-expression> "[" expression "]" | <postfix-expression> "(" <assignment-expression>* ")" | <postfix-expression> "." <identifier> | <postfix-expression> "->" <identifier> | <postfix-expression> "++" | <postfix-expression> "--"
<primary-expression> ::= <identifier> | <numeric-literal> | <character-literal> | <string-literal> | "(" <expression> ")"
<expression> ::= <assignment-expression> | <expression> "," <assignment-expression>
<assignment-expression> ::= <conditional-expression> | <unary-expression> <assignment-operator> <assignment-expression>
```