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