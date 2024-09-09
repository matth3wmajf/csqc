# C²
## Introduction
The C² language is a low-level programming language based on the C programming language, with the purpose of incorporating higher-level features, such as automated memory management, all while allowing for the use of C-style syntax, and optional low-level & unsafe code.
## Difference(s)
There are differences between C² and C. The C programming language uses a very weird & inconsistent method of naming types, which is something C² aims to fix. For example, the `char` type is named `byte`, the `short` type is named `word`, the `int` type is named `dword`, and the `long` type is named `qword`. C² also gets rid of naming conventions such as `long long int`, or `short int`. Instead, users simply use the single-token types.
Although it is true that names such as `word` can have different bitwidths in different architectures, C² will ignore this, and follow this convention, architecture-independent:
+========+==========+
| Type   | Bitwidth |
+========+==========+
| byte   | 8        |
| word   | 16       |
| dword  | 32       |
| qword  | 64       |
+========+==========+