#include <csquared/string.h>
#include <csquared/vector.h>
#include <csquared/ast.h>
#include <csquared/lex.h>

int ast(vector_t *tokens, vector_t *objects)
{
	for(int l_i = 0; l_i < vector_total(tokens); l_i++)
	{
		int l_j = 0;

		token_t *l_token0 = vector_get(tokens, l_i);
		switch(l_token0->type)
		{
			
		}
	}

	return 0;
}