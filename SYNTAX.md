# Syntax
## Scopes
There are four types of scopes, those being functions, file, block, and function prototype.
## Identifiers
Identifiers are only visible within the scope they are declared in, and the scopes that are nested within it.
For identical identifiers under two different, but nested scopes, the identifier in the inner scope will be considered, but only in that inner scope.
For example, the following code is valid:
```c
extern int printf(const char *format, ...);

int main(int argc, const char *argv[])
{
	int x = 5;

	{
		int x = 10;
		printf("%d\n", x);
	}

	printf("%d", x);

	return 0;
}
```
And therefore, will output the following:
```
5
10
```
Identifiers of arguments in a function are considered to be in the function scope, and therefore cannot be used outside the function's body. The function's arguments in a function prototype are considered to be in the function prototype scope.
## Constants
Constants consist of either identifiers which have been declared as constants using the `const` keyword, or literals. Literals consist of either a numeric literal, a character literal, or a string literal (which returns a constant pointer to the first character of the string).
Numeric literals consist of either floating-point numbers, or integers. Floating-point numbers are identified by the presence of a decimal point, and integers are identified by the absence of a decimal point. By default, floating-point literals are 8 bytes in size, however if the suffix `f` is included, the literal becomes of 4 bytes in size. If the suffix `l` is included with the `f` suffix, then the literal is explicitly specified as an 8-byte floating point literal again.