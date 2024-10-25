# The *C²* programming language...
## Why *C²*?
The C² programming language is a statically-typed programming language similarly based on the C programming language, with the goals of achieving performance, safety, and stability.
It combines the syntax of the C programming language with the idea of simplicity; the `char` type is renamed to `byte`, the `short`, `int`, and `long` types are removed, and instead bigger types are defined as arrays of the `byte` type.
It introduces reliability as well; it plans for the support implementation of user-created extensions, some of which may even become standard to the language. This allows for users to be able to define new behaviors in the language.
It also introduces safety; standard extensions allow for programmers to register lambda functions as callbacks to events which can be fired when an object goes out-of-scope, such as a pointer:
```csq
typedef unsigned byte uint64_t[8];
typedef byte int32_t[4];
typedef byte char8_t[1];
typedef void *uintptr_t;

extern int32_t printf(char8_t *format, ...);
extern uintptr_t malloc(uint64_t size);
extern void free(uintptr_t address);

int main()
{
	/* Allocate 16 sets of 32-bit unsigned integers. */
	uint64_t *p = malloc(sizeof(uint64_t) * 16)

	/*
	 *	Tell the compiler to call `free()` with `p` as an argument once `p`
	 *	goes out of scope.
	 */
	static_cleanup(p, free);

	/* Fill out the buffer with data. */
	for(uint64_t i = 0; i < 16; i++) p[i] = i;

	/* Print the buffer's contents. */
	for(uint64_t i = 0; i < 16; i++) printf("%ju ", p[i]);

	/* The `free()` function gets inserted during code-generation. */
	/* ... */

	return 0;
}
```
Standard extensions allow for programmers to create classes:
```csq
typedef unsigned byte uint64_t[8];
typedef void *uintptr_t;

extern uintptr_t malloc(uint64_t size);
extern uintptr_t realloc(uintptr_t address, uint64_t size);
extern void free(uintptr_t address);

typedef class my_class
{
	uintptr_t pointer = 0;
	uint64_t size = (uint64_t)-1;

	my_class(uint64_t _size)
	{
		my_class->size = _size;
		my_class->address = malloc();
	}

	~my_class()
	{
		free(my_class->address);
	}

	void resize(uint64_t _size)
	{
		my_class->size = _size;
		my_class->address = realloc(my_class->address, _size);
	}
} smart_allocator_t;

int main()
{
	/* Create an instance of the `smart_allocator_t` class. */
	smart_allocator_t memory = smart_allocator_t(sizeof(uint64_t) * 16);

	/* Fill out the buffer with data. */
	for(uint64_t i = 0; i < 16; i++) memory[i] = i;

	/* Print the buffer's contents. */
	for(uint64_t i = 0; i < 16; i++) printf("%ju ", p[i]);
	
	/* The class's deconstructor gets called here. */

	return 0;
}
```
And namespaces as well. Although some extensions become part of the standard, users can write their own as well, allowing for a perfectly well-scalable & sustainable programming language.
## Is *C²* ready yet?
No. Not even close to being stable or functional. So far, we've written the scanner successfully, and we are currently working to finish implementing the parser. As of now, many of the features shown above aren't implemented yet, as we are trying to implement the already-existing constructs that the C programming language brings to the table. After we are able to successfully compile our first sample program using this compiler, we'll start implementing the showcased features above.
## Are contributions to *C²* accepted?
Of course! As long as the pull request is reasonable, it'll be inspected & approved into the *C²* project. We look forward to your contribution!