/*
 *	                         .d8888b.    o    .d8888b.                         
 *	                        d88P  Y88b  d8b  d88P  Y88b                        
 *	                        888    888 d888b        888                        
 *	                        888       d8P"Y8b     .d88P                        
 *	                        888               .od888P"                         
 *	                        888    888       d88P"                             
 *	                        Y88b  d88P       888"                              
 *	                         "Y8888P"        888888888                         
 *	 Copyright (C) 2024-2025, Matthew E. Majfud-Wilinski. All Rights Reserved. 
 */

#include <inttypes.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include <csqc/scanner.h>
#include <csqc/parser.h>

/*
 *	The level, a number that indicates how deep the parser is in terms of
 *	recursion.
 */
intmax_t g_level;

/* ... */
int parser_parse_symbol(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_ellipsis(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_equal_to(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_not_equal_to(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_less_than_or_equal_to(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_greater_than_or_equal_to(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_logical_and(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_logical_or(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_left_shift(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_right_shift(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_add(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_subtract(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_multiply(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_divide(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_multiply_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_divide_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_modulo_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_addition_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_subtraction_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_left_shift_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_right_shift_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_bitwise_and_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_bitwise_xor_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_bitwise_or_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_less_than(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_greater_than(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_logical_not(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_bitwise_and(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_bitwise_or(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_bitwise_xor(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_bitwise_not(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_open_parenthesis(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_close_parenthesis(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_open_brace(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_close_brace(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_open_bracket(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_close_bracket(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_semicolon(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_comma(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_period(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_modulo(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_conditional(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_colon(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_increment(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_decrement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_symbol_arrow(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_auto(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_break(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_case(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_byte(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_const(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_continue(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_default(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_do(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_else(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_enum(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_extern(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_for(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_goto(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_if(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_register(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_return(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_signed(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_sizeof(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_static(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_struct(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_switch(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_typedef(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_union(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_unsigned(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_void(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_volatile(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_keyword_while(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_literal(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_literal_float(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_literal_int(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_literal_char(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_literal_string(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_translation_unit(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_external_declaration(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_function_definition(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_declaration_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_declaration(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_storage_class_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_type_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_struct_or_union_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_struct_or_union(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_struct_declaration(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_specifier_qualifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_specifier_qualifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_struct_declarator_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_struct_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_pointer(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_type_qualifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_direct_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_direct_declarator_tail(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_constant_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_conditional_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_logical_or_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_logical_and_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_inclusive_or_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_exclusive_or_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_and_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_equality_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_relational_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_shift_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_additive_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_multiplicative_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_cast_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_unary_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_postfix_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_primary_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_constant(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_assignment_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_assignment_operator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_unary_operator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_type_name(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_parameter_type_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_parameter_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_parameter_declaration(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_abstract_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_direct_abstract_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_direct_abstract_declarator_tail(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_enum_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_enumerator_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_enumerator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_typedef_name(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_declaration(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_init_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_initializer(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_initializer_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_compound_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_labeled_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_expression_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_selection_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_iteration_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_rule_jump_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

/* ... */
int parser_parse_identifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index);

#define LOG_STARTED fprintf(stderr, "debug: Status for parsing rule `%-32s` (status: `%-7s`, level: `%jd`).\n", &__func__[13], "started", (intmax_t)g_level);
#define LOG_FAILURE fprintf(stderr, "debug: Status for parsing rule `%-32s` (status: `%-7s`, level: `%jd`).\n", &__func__[13], "failure", (intmax_t)g_level);
#define LOG_SUCCESS fprintf(stderr, "debug: Status for parsing rule `%-32s` (status: `%-7s`, level: `%jd`).\n", &__func__[13], "success", (intmax_t)g_level);

/* ... */
int parser_parse_symbol(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;
	
/* Re-size the object buffer. */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* Define a pointer to the new object we're working with. */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_ellipsis(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_ELLIPSIS)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_ELLIPSIS;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_equal_to(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_EQUAL_TO)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_EQUAL_TO;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;
	
/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_not_equal_to(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_NOT_EQUAL_TO)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_NOT_EQUAL_TO;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_less_than_or_equal_to(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_LESS_THAN_OR_EQUAL_TO)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LESS_THAN_OR_EQUAL_TO;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_greater_than_or_equal_to(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;
	
/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_GREATER_THAN_OR_EQUAL_TO)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_GREATER_THAN_OR_EQUAL_TO;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_logical_and(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_LOGICAL_AND)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LOGICAL_AND;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:

/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_logical_or(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_LOGICAL_OR)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LOGICAL_OR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_left_shift(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_LEFT_SHIFT)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LEFT_SHIFT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_right_shift(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_RIGHT_SHIFT)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_RIGHT_SHIFT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_add(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_ADD)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_ADD;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_subtract(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_SUBTRACT)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_SUBTRACT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_multiply(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_MULTIPLY)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_MULTIPLY;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_divide(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_DIVIDE)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_DIVIDE;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_multiply_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_MULTIPLY_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_MULTIPLY_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_divide_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_DIVIDE_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_DIVIDE_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_modulo_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_MODULO_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_MODULO_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_addition_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_ADDITION_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_ADDITION_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_subtraction_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_SUBTRACTION_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_SUBTRACTION_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_left_shift_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_LEFT_SHIFT_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LEFT_SHIFT_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_right_shift_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_RIGHT_SHIFT_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_RIGHT_SHIFT_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_bitwise_and_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_BITWISE_AND_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_BITWISE_AND_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_bitwise_xor_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_BITWISE_XOR_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_BITWISE_XOR_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_bitwise_or_assign(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_BITWISE_OR_ASSIGN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_BITWISE_OR_ASSIGN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_less_than(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_LESS_THAN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LESS_THAN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_greater_than(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_GREATER_THAN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_GREATER_THAN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_logical_not(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_LOGICAL_NOT)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LOGICAL_NOT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_bitwise_and(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_BITWISE_AND)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_BITWISE_AND;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_bitwise_or(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_BITWISE_OR)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_BITWISE_OR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_bitwise_xor(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_BITWISE_XOR)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_BITWISE_XOR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_bitwise_not(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_BITWISE_NOT)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_BITWISE_NOT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_open_parenthesis(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_OPEN_PARENTHESIS)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LEFT_PARENTHESIS;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_close_parenthesis(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_CLOSE_PARENTHESIS)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_RIGHT_PARENTHESIS;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_open_brace(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_OPEN_BRACE)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LEFT_BRACE;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_close_brace(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_CLOSE_BRACE)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_RIGHT_BRACE;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_open_bracket(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_OPEN_BRACKET)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_LEFT_BRACKET;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_close_bracket(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_CLOSE_BRACKET)) l_index++;
	else goto j_failure;

j_success:
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_RIGHT_BRACKET;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_semicolon(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_SEMICOLON)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_SEMICOLON;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_comma(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_COMMA)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_COMMA;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_period(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_PERIOD)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_PERIOD;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_modulo(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_MODULO)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_MODULO;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_conditional(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_CONDITIONAL)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_CONDITIONAL;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_colon(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_COLON)) l_index++;
	else goto j_failure;

j_success:
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_COLON;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_increment(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_INCREMENT)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_INCREMENT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_decrement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_DECREMENT)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_DECREMENT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_symbol_arrow(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_SYMBOL && (pt_input_token_buffer[l_index].t_value.t_symbol == SYMBOL_ARROW)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_SYMBOL_ARROW;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_auto(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_AUTO)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_AUTO;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_break(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_BREAK)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_BREAK;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_case(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_CASE)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_CASE;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_byte(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_BYTE)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_BYTE;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_const(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_CONST)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;
	
/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_CONST;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_continue(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_CONTINUE)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_CONTINUE;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_default(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_DEFAULT)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_DEFAULT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_do(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_DO)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_DO;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_else(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_ELSE)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_ELSE;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_enum(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_ENUM)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_ENUM;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_extern(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_EXTERN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_EXTERN;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_for(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_FOR)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_FOR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_goto(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_GOTO)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_GOTO;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_if(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_IF)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_IF;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_register(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_REGISTER)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_REGISTER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_return(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_RETURN)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_RETURN;

/* ... */
	g_level--;
	
/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_signed(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_SIGNED)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_SIGNED;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_sizeof(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_SIZEOF)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_SIZEOF;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_static(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_STATIC)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_STATIC;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_struct(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_STRUCT)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_STRUCT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_switch(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_SWITCH)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_SWITCH;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_typedef(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_TYPEDEF)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_TYPEDEF;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_union(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_UNION)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_UNION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_unsigned(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_UNSIGNED)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_UNSIGNED;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_void(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_VOID)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_VOID;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_volatile(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_VOLATILE)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_VOLATILE;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_keyword_while(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_KEYWORD && (pt_input_token_buffer[l_index].t_value.t_keyword == KEYWORD_WHILE)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_KEYWORD_WHILE;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_literal(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && (pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_INT8_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_UINT8_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_INT16_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_UINT16_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_INT32_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_UINT32_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_INT64_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_UINT64_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_FLOAT32_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_FLOAT64_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_CHARACTER8_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_STRING8_LITERAL)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_LITERAL;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_literal_float(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && (pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_FLOAT32_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_FLOAT64_LITERAL)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_LITERAL_FLOAT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_literal_int(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && (pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_INT8_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_UINT8_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_INT16_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_UINT16_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_INT32_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_UINT32_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_INT64_LITERAL || pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_UINT64_LITERAL)) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;
	
/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_LITERAL_INTEGER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_literal_char(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_CHARACTER8_LITERAL) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_LITERAL_CHARACTER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/* ... */
int parser_parse_literal_string(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;
	
/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_STRING8_LITERAL) l_index++;
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_LITERAL_STRING;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
}

/*
 *	The translation unit rule, which serves as the root of the entire code.
 *	Translation units can be made up of multiple external declaration(s), or
 *	nothing at all, as seen in the following grammar specification...
 *
 *	<translation_unit> ::= {<external_declaration>}*
 */
int parser_parse_rule_translation_unit(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result;

/* ... */
	do
	{
/* ... */
		l_result = parser_parse_rule_external_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	} while(l_result >= 0);

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/*
 *	Append the object representing the translation unit as a rule, into the
 *	object buffer.
 */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_TRANSLATION_UNIT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The external declaration rule, which trickles down as either a declaration
 *	rule, or a function definition rule, as seen in the following grammar
 *	specification...
 *
 *	<external_declaration> ::= <function_definition>
 */
int parser_parse_rule_external_declaration(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_function_definition(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		
/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_EXTERNAL_DECLARATION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The function definition rule, which is much more complicated than the
 *	previous rules.
 *	This rule consists of a larger sequence of rules, those being one or more
 *	optional declaration specifiers, a declarator specifier, one or more
 *	declarations, and a compound statement, as seen in the following grammar
 *	specification...
 *
 *	<function_definition> ::= {<declaration_specifier>}* <declarator> {<declaration>}* <compound_statement>
 */
int parser_parse_rule_function_definition(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	uintmax_t l_saved_object_size = *pt_output_object_buffer_size;

/* ... */
	while(parser_parse_rule_declaration_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index) >= 0) { }

/* ... */
	int l_result = parser_parse_rule_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	if(l_result < 0) goto j_failure;

/* ... */
	if(*pt_output_object_buffer_size > l_saved_object_size)
	{
/* ... */
		object_t *pl_last_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];

/* ... */
		if(pl_last_object->t_object_type == OBJECT_TYPE_IDENTIFIER)
		{
/* ... */
			token_t *pl_identifier_token = &pt_input_token_buffer[l_index - 1];
			const char *pl_name = pl_identifier_token->t_value.pt_identifier;
			uintmax_t l_name_length = pl_identifier_token->t_value.t_buffer_size;

/* ... */
			(*pt_name_buffer_size)++;
			*ppt_name_buffer = realloc(*ppt_name_buffer, *pt_name_buffer_size * sizeof(name_t));

/* ... */
			name_t *pl_new_name = &(*ppt_name_buffer)[*pt_name_buffer_size - 1];

/* ... */
			pl_new_name->pt_name = malloc(l_name_length + 1);
			strncpy(pl_new_name->pt_name, pl_name, l_name_length);
			pl_new_name->pt_name[l_name_length] = '\0';
			pl_new_name->t_type = NAME_TYPE_FUNCTION;
			pl_new_name->t_scope_identifier = 0;
		}
	}

/* ... */
	while(parser_parse_rule_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index) >= 0) { }

/* ... */
	l_result = parser_parse_rule_compound_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	if(l_result < 0) goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_FUNCTION_DEFINITION;

/* ... */
	*pt_index = l_index;

/* ... */
	g_level--;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	*pt_output_object_buffer_size = l_saved_object_size;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, l_saved_object_size * sizeof(object_t));

/* ... */
	g_level--;

/* ... */
	return -1;
}

/*
 *	The declaration specifier rule, which trickles down to either a storage
 *	class specifier rule, a type specifier rule, or a type qualifier rule, as
 *	seen in the following grammar specification...
 *
 *	<declaration_specifier> ::= <storage_class_specifier>
 *	                          | <type_specifier>
 *	                          | <type_qualifier>
 */
int parser_parse_rule_declaration_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_storage_class_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_type_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		
/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_rule_type_qualifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
			
/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_DECLARATION_SPECIFIER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The storage class specifier rule, which simply consists of the `auto`,
 *	`register`, `static`, `extern`, and `typedef` keywords, as seen in the
 *	following grammar specification...
 *
 *	<storage_class_specifier> ::= "auto"
 *	                            | "register"
 *	                            | "static"
 *	                            | "extern"
 *	                            | "typedef"
 */
int parser_parse_rule_storage_class_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_keyword_auto(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_keyword_register(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_keyword_static(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_keyword_extern(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0)
				{
/* ... */
					l_result = parser_parse_keyword_typedef(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
			}
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_STORAGE_CLASS_SPECIFIER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The type specifier rule, which trickles down to a `void`, `byte`,
 *	`signed`, or `unsigned` keyword, or a struct or union specifier, an enum
 *	specifier, or a typedef name, as seen in the following grammar
 *	specification...
 *
 *	<type_specifier> ::= "void"
 *	                   | "byte"
 *	                   | "signed"
 *	                   | "unsigned"
 *	                   | <struct_or_union_specifier>
 *	                   | <enum_specifier>
 *	                   | <typedef_name>
 */
int parser_parse_rule_type_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;
	uintmax_t l_saved_object_size = *pt_output_object_buffer_size;

/* ... */
	int l_result;

/* ... */
	if((l_result = parser_parse_keyword_void(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index)) >= 0 || (l_result = parser_parse_keyword_byte(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index)) >= 0 || (l_result = parser_parse_keyword_signed(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index)) >= 0 || (l_result = parser_parse_keyword_unsigned(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index)) >= 0 || (l_result = parser_parse_rule_struct_or_union_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index)) >= 0 || (l_result = parser_parse_rule_enum_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index)) >= 0) goto j_success;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_IDENTIFIER)
	{
/* ... */
		const char *pl_name = pt_input_token_buffer[l_index].t_value.pt_identifier;
		uintmax_t l_name_length = pt_input_token_buffer[l_index].t_value.t_buffer_size;

/* ... */
		bool l_is_typedef = false;

/* ... */
		for(uintmax_t l_i = 0; l_i < *pt_name_buffer_size; l_i++)
		{
/* ... */
			name_t *pl_name_entry = &(*ppt_name_buffer)[l_i];
			if(pl_name_entry->t_type == NAME_TYPE_TYPEDEF && pl_name_entry->t_scope_identifier == 0 && strncmp(pl_name_entry->pt_name, pl_name, l_name_length) == 0 && strlen(pl_name_entry->pt_name) == l_name_length)
			{
/* ... */
				l_is_typedef = true;

/* ... */
				break;
			}
		}

/* ... */
		if(l_is_typedef)
		{
/* ... */
			l_result = parser_parse_rule_typedef_name(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
			if(l_result >= 0) goto j_success;
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	*pt_output_object_buffer_size = l_saved_object_size;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, l_saved_object_size * sizeof(object_t));

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_TYPE_SPECIFIER;

/* ... */
	*pt_index = l_index;

/* ... */
	g_level--;

/* ... */
	return 0;
}

/*
 *	The struct or union specifier rule, which this time is a much more complex
 *	rule. It represents a definition of a struct or union.
 *	Because this rule is a bit more complex, we'll simply provide it's
 *	grammar specification with some examples instead explaining it in detail...
 *
 *	<struct_or_union_specifier> ::= <struct_or_union> <identifier> "{" {<struct_declaration>}+ "}"
 *	                              | <struct_or_union> "{" {<struct_declaration>}+ "}"
 *	                              | <struct_or_union> <identifier>
 */
int parser_parse_rule_struct_or_union_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_struct_or_union(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result < 0) goto j_failure;

/* ... */
	l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_open_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_struct_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result < 0) goto j_failure;

/* ... */
			do
			{
/* ... */
				l_result = parser_parse_rule_struct_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
			} while (l_result >= 0);

/* ... */
			l_result = parser_parse_symbol_close_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
			
/* ... */
			if(l_result >= 0) goto j_success;
		}
		else if(l_result < 0) goto j_success;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_symbol_open_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		
/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_struct_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
			
/* ... */
			if(l_result < 0) goto j_failure;

/* ... */
			do
			{
/* ... */
				l_result = parser_parse_rule_struct_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
			} while (l_result >= 0);

/* ... */
			l_result = parser_parse_symbol_close_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
			
/* ... */
			if(l_result >= 0) goto j_success;
		}
		else if(l_result < 0) goto j_success;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_STRUCT_OR_UNION_SPECIFIER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The struct or union rule, which is a simple rule trickling down to two
 *	keywords, those being `struct` or `union`, as seen in the following grammar
 *	specification...
 *
 *	<struct_or_union> ::= "struct" | "union"
 */
int parser_parse_rule_struct_or_union(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_keyword_struct(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_keyword_union(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		
/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_STRUCT_OR_UNION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The struct declaration rule, which consists of an optional specifier
 *	qualifier, or multiple specifier qualifiers, followed by a mandatory
 *	struct declarator list, as seen in the following grammar specification...
 *
 *	<struct_declaration> ::= {<specifier_qualifier>}* <struct_declarator_list>
 */
int parser_parse_rule_struct_declaration(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result;

/* ... */
	do
	{
/* ... */
		l_result = parser_parse_rule_specifier_qualifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	} while(l_result >= 0);

/* ... */
	l_result = parser_parse_rule_struct_declarator_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	if(l_result >= 0) goto j_success;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_STRUCT_DECLARATION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The specifier qualifier rule, which simply trickles down to either a type
 *	specifier, or a type qualifier, as seen in the following grammar
 *	specification...
 *
 *	<specifier_qualifier> ::= <type_specifier> | <type_qualifier>
 */
int parser_parse_rule_specifier_qualifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_type_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_type_qualifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_SPECIFIER_QUALIFIER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The struct declarator list rule, which trickles down to either a struct
 *	declarator, or another struct declarator list, a comma, and a struct
 *	declarator, as seen in the following grammar specification...
 *
 *	<struct_declarator_list> ::= <struct_declarator>
 *	                           | <struct_declarator_list> "," <struct_declarator>
 */
int parser_parse_rule_struct_declarator_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_struct_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_struct_declarator_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_comma(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
			
/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_struct_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_STRUCT_DECLARATOR_LIST;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The struct declarator rule, which is slightly more complicated, but is
 *	seen in the following grammar specification...
 *
 *	<struct_declarator> ::= <declarator>
 *	                      | <declarator> ":" <constant_expression>
 *	                      | ":" <constant_expression>
 */
int parser_parse_rule_struct_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_colon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		
/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_constant_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result < 0) goto j_failure;

/* ... */
			goto j_success;
		}
		else if(l_result < 0) goto j_success;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_symbol_colon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result < 0) goto j_failure;

/* ... */
		l_result = parser_parse_rule_constant_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result < 0) goto j_failure;

/* ... */
		goto j_success;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_STRUCT_DECLARATOR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The declarator rule, which consists of an optional pointer and a mandatory
 *	direct declarator, as seen in the following grammar specification...
 *
 *	<declarator> ::= {<pointer>}? <direct_declarator>
 */
int parser_parse_rule_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	uintmax_t l_saved_object_size = *pt_output_object_buffer_size;

/* ... */
	int l_result = parser_parse_rule_pointer(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	if(l_result < 0) l_index = *pt_index;

/* ... */
	l_result = parser_parse_rule_direct_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	if(l_result < 0) goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_DECLARATOR;

/* ... */
	*pt_index = l_index;

/* ... */
	g_level--;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;
/* ... */
	*pt_output_object_buffer_size = l_saved_object_size;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, l_saved_object_size * sizeof(object_t));

/* ... */
	g_level--;

/* ... */
	return -1;
}

/*
 *	The pointer rule, which trickles down to a mandatory asterisk symbol,
 *	optional or multiple type qualifier(s), and another optional pointer, as
 *	seen in the following grammar specification...
 *
 *	<pointer> ::= "*" {<type_qualifier>}* {<pointer>}?
 */
int parser_parse_rule_pointer(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_symbol_multiply(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0)
	{
/* ... */
		do
		{
/* ... */
			l_result = parser_parse_rule_type_qualifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		} while(l_result >= 0);

/* ... */
		parser_parse_rule_pointer(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		goto j_success;
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_POINTER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The type qualifier rule, which simply trickles down to either a `const` or
 *	`volatile` keyword, as seen in the following grammar specification...
 *
 *	<type_qualifier> ::= "const" | "volatile"
 */
int parser_parse_rule_type_qualifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_keyword_const(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_keyword_volatile(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		
/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_TYPE_QUALIFIER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The direct declarator rule, which is much more complex, and is seen in the
 *	following grammar specification as...
 *
 *	<direct_declarator> ::= <identifier>
 *	                      | "(" <declarator> ")"
 *	                      | <direct_declarator> "[" {<constant_expression>}? "]"
 *	                      | <direct_declarator> "(" <parameter_type_list> ")"
 *	                      | <direct_declarator> "(" {<identifier>}* ")"
 *
 *	I didn't describe this rule in detail because it's too complex, and I
 *	believe it's better & more easily represented by the backus-naur form
 *	representation of the grammar.
 */
int parser_parse_rule_direct_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_rule_direct_abstract_declarator_tail(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_DIRECT_DECLARATOR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The direct declarator tail rule, which is a rule added for compatibility
 *	in order for our recursive-descent parser to work with the direct
 *	declarator rule.
 */
int parser_parse_rule_direct_declarator_tail(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	LOG_STARTED;

/* ... */
	g_level++;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_symbol_open_bracket(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		parser_parse_rule_constant_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		l_result = parser_parse_symbol_close_bracket(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		
/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_direct_declarator_tail(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_parameter_type_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_direct_declarator_tail(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
					
/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0)
			{
/* ... */
				do
				{
/* ... */
					l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
				} while(l_result >= 0);

/* ... */
				l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_direct_declarator_tail(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_DIRECT_DECLARATOR_TAIL;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The constant expression rule, which is a rule that falls back into the
 *	conditional expression rule, as seen in the following syntax specification
 *	as...
 *
 *	<constant_expression> ::= <conditional_expression>
 */
int parser_parse_rule_constant_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_conditional_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_CONSTANT_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/*
 *	The conditional expression rule, which is a rule that either trickles down
 *	into a ternary expression that performs a comparison, or falls back
 *	directly into a logical OR expression. It is seen in the following syntax
 *	specification as...
 *
 *	<conditional_expression> ::= <logical_or_expression>
 *	                           | <logical_or_expression> "?" <expression> ":" <conditional_expression>
 */
int parser_parse_rule_conditional_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_logical_or_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_conditional(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_colon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_conditional_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_success;
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_CONDITIONAL_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_logical_or_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_logical_and_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_logical_or_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_logical_or(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_logical_and_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_LOGICAL_OR_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_logical_and_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_inclusive_or_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_logical_and_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		
/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_logical_and(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_inclusive_or_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_LOGICAL_AND_EXPRESSION;
	
/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

int parser_parse_rule_inclusive_or_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_exclusive_or_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_inclusive_or_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_bitwise_or(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_exclusive_or_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_INCLUSIVE_OR_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_exclusive_or_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_and_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_exclusive_or_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_bitwise_xor(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_and_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_EXCLUSIVE_OR_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_and_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_equality_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_and_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		
/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_bitwise_and(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_equality_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_AND_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_equality_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_relational_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_equality_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_equal_to(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_relational_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_symbol_not_equal_to(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_relational_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_EQUALITY_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

int parser_parse_rule_relational_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_shift_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_relational_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_less_than(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_shift_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_symbol_greater_than(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_shift_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0)
				{
/* ... */
					l_result = parser_parse_symbol_less_than_or_equal_to(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0)
					{
/* ... */
						l_result = parser_parse_rule_shift_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0) goto j_success;
						else if(l_result < 0) goto j_failure;
					}
					else if(l_result < 0)
					{
/* ... */
						l_result = parser_parse_symbol_greater_than_or_equal_to(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0)
						{
/* ... */
							l_result = parser_parse_rule_shift_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
							if(l_result >= 0) goto j_success;
							else if(l_result < 0) goto j_failure;
						}
						else if(l_result < 0) goto j_failure;
					}
				}
			}
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_RELATIONAL_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_shift_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_additive_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_shift_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_left_shift(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_additive_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_symbol_right_shift(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_additive_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
			}
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_SHIFT_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_additive_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_multiplicative_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_additive_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_add(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_multiplicative_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_symbol_subtract(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_multiplicative_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_ADDITIVE_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_multiplicative_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_cast_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_multiplicative_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_multiply(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_cast_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_symbol_divide(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_cast_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0)
				{
/* ... */
					l_result = parser_parse_symbol_modulo(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0)
					{
/* ... */
						l_result = parser_parse_rule_cast_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0) goto j_success;
						else if(l_result < 0) goto j_failure;
					}
					else if(l_result < 0) goto j_failure;
				}
			}
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_MULTIPLICATIVE_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_cast_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_unary_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_type_name(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_cast_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_CAST_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_unary_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_postfix_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_symbol_increment(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_unary_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_symbol_decrement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
			
/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_unary_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_rule_unary_operator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_cast_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0)
					{
/* ... */
						l_result = parser_parse_keyword_sizeof(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0)
						{
/* ... */
							l_result = parser_parse_rule_unary_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
							if(l_result >= 0) goto j_success;
							else if(l_result < 0)
							{
/* ... */
								l_result = parser_parse_rule_type_name(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
								if(l_result >= 0) goto j_success;
								else if(l_result < 0) goto j_failure;
							}
						}
						else if(l_result < 0) goto j_failure;
					}
				}
				else if(l_result < 0) goto j_failure;
			}
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_UNARY_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_postfix_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_primary_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_postfix_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_open_bracket(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_symbol_close_bracket(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0)
				{
/* ... */
					l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
					
/* ... */
					if(l_result >= 0)
					{
/* ... */
						do
						{
/* ... */
							l_result = parser_parse_rule_assignment_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
						} while(l_result >= 0);

/* ... */
						l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0) goto j_success;
						else if(l_result < 0) goto j_failure;
					}
					else if(l_result < 0)
					{
/* ... */
						l_result = parser_parse_symbol_period(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0)
						{
/* ... */
							l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
							if(l_result >= 0) goto j_success;
							else if(l_result < 0) goto j_failure;
						}
						else if(l_result < 0)
						{
/* ... */
							l_result = parser_parse_symbol_arrow(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
							if(l_result >= 0)
							{
/* ... */
								l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
								if(l_result >= 0) goto j_success;
								else if(l_result < 0) goto j_failure;
							}
							else if(l_result < 0)
							{
/* ... */
								l_result = parser_parse_symbol_increment(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
								if(l_result >= 0) goto j_success;
								else if(l_result < 0)
								{
/* ... */
									l_result = parser_parse_symbol_decrement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
									if(l_result >= 0) goto j_success;
									else if(l_result < 0) goto j_failure;
								}
							}
						}
					}
				}
			}
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_POSTFIX_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_primary_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_constant(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_literal_string(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{

/* ... */
					l_result = parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
					if(l_result >= 0)
					{
/* ... */
						l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0) goto j_success;
						else if(l_result < 0) goto j_failure;
					}
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_PRIMARY_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_constant(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_literal_int(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_literal_char(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_literal_float(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;

/*
 *	Let's support enumeration constants, but only when we know how
 *	to detect them...
 */
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_CONSTANT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_assignment_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_comma(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_assignment_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_assignment_expression(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_conditional_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;

/* ... */
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_unary_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_assignment_operator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_assignment_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_ASSIGNMENT_EXPRESSION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_assignment_operator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_symbol_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_symbol_multiply_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_symbol_divide_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_symbol_modulo_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0)
				{
/* ... */
					l_result = parser_parse_symbol_addition_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0)
					{
/* ... */
						l_result = parser_parse_symbol_subtraction_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0) goto j_success;
						else if(l_result < 0)
						{
/* ... */
							l_result = parser_parse_symbol_left_shift_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
							if(l_result >= 0) goto j_success;
							else if(l_result < 0)
							{
/* ... */
								l_result = parser_parse_symbol_right_shift_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
								if(l_result >= 0) goto j_success;
								else if(l_result < 0)
								{
/* ... */
									l_result = parser_parse_symbol_bitwise_and_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
									if(l_result >= 0) goto j_success;
									else if(l_result < 0)
									{
/* ... */
										l_result = parser_parse_symbol_bitwise_xor_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
										if(l_result >= 0) goto j_success;
										else if(l_result < 0)
										{
/* ... */
											l_result = parser_parse_symbol_bitwise_or_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
											if(l_result >= 0) goto j_success;
											else if(l_result < 0) goto j_failure;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_ASSIGNMENT_OPERATOR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_unary_operator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_symbol_bitwise_and(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_symbol_multiply(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_symbol_add(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_symbol_subtract(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0)
				{
/* ... */
					l_result = parser_parse_symbol_bitwise_not(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0)
					{
/* ... */
						l_result = parser_parse_symbol_logical_not(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0) goto j_success;
						else if(l_result < 0) goto j_failure;
					}
				}
			}
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;
	
/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_UNARY_OPERATOR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_type_name(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_specifier_qualifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		do
		{
/* ... */
			l_result = parser_parse_rule_specifier_qualifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		} while(l_result >= 0);

/* ... */
		parser_parse_rule_abstract_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		goto j_success;
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_TYPE_NAME;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_parameter_type_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_parameter_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	
/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_comma(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_ellipsis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_success;
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_PARAMETER_TYPE_LIST;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_parameter_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_parameter_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_parameter_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_comma(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_parameter_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_PARAMETER_LIST;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_parameter_declaration(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_declaration_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		do
		{
/* ... */
			l_result = parser_parse_rule_declaration_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		} while(l_result >= 0);

/* ... */
		l_result = parser_parse_rule_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_rule_abstract_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_success;
		}
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_PARAMETER_DECLARATION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_abstract_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_pointer(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_rule_direct_abstract_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0) goto j_success;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_direct_abstract_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_ABSTRACT_DECLARATOR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_direct_abstract_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_rule_abstract_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result >= 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_direct_abstract_declarator_tail(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_PARAMETER_TYPE_LIST;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_direct_abstract_declarator_tail(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_symbol_open_bracket(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		parser_parse_rule_constant_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		l_result = parser_parse_symbol_close_bracket(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0) goto j_failure;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			parser_parse_rule_parameter_type_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_DIRECT_ABSTRACT_DECLARATOR_TAIL;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_enum_specifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_keyword_enum(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_open_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_enumerator_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_symbol_close_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_success;
		}
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_symbol_open_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_enumerator_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_symbol_close_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_ENUM_SPECIFIER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_enumerator_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_enumerator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_enumerator_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_comma(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_enumerator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_ENUMERATOR_LIST;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_enumerator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_constant_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_success;
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_ENUMERATOR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_typedef_name(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/*
 *	To resolve ambiguity, we must use a symbol table to store identifiers that
 *	are custom-defined types.
 *	Therefore, we search the symbol table for the identifier.
 */
		for(uintmax_t l_i = 0; l_i < *pt_name_buffer_size; l_i++)
		{
/* ... */
			if(strcmp(pt_input_token_buffer[l_index].t_value.pt_identifier, (*ppt_name_buffer)[l_i].pt_name) == 0) goto j_success;
		}

/* If it isn't found in the symbol table, we assume it isn't valid. */
		goto j_failure;
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_TYPEDEF_NAME;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_declaration(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_declaration_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		do
		{
/* ... */
			l_result = parser_parse_rule_declaration_specifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		} while(l_result >= 0);

/* ... */
		int l_init_declarator_count = 0;

/* ... */
		do
		{
/* ... */
			l_result = parser_parse_rule_init_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) l_init_declarator_count++;
		} while(l_result >= 0);

/* ... */
		l_result = parser_parse_symbol_semicolon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0) goto j_failure;
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_DECLARATION;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_init_declarator(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_declarator(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_assign(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_initializer(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_success;
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_INIT_DECLARATOR;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_initializer(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_assignment_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_symbol_open_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_initializer_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_close_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0)
				{
/* ... */
					l_result = parser_parse_rule_initializer_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0)
					{
/* ... */
						l_result = parser_parse_symbol_close_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0) goto j_success;
						else if(l_result < 0) goto j_failure;
					}
					else if(l_result < 0) goto j_failure;
				}
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_INITIALIZER;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_initializer_list(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_initializer(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_initializer_list(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_comma(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_initializer(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_INITIALIZER_LIST;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_compound_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_symbol_open_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		do
		{
/* ... */
			l_result = parser_parse_rule_declaration(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		} while(l_result >= 0);

/* ... */
		do
		{
/* ... */
			l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);
		} while(l_result >= 0);

/* ... */
		l_result = parser_parse_symbol_close_brace(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0) goto j_failure;
	}
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_COMPOUND_STATEMENT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_rule_labeled_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_rule_expression_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0) goto j_success;
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_rule_compound_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_rule_selection_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0)
				{
/* ... */
					l_result = parser_parse_rule_iteration_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0)
					{
/* ... */
						l_result = parser_parse_rule_jump_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0) goto j_success;
						else if(l_result < 0) goto j_failure;
					}
				}
			}
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_STATEMENT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_labeled_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_colon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_keyword_case(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_constant_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_colon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_keyword_default(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_colon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_LABELED_STATEMENT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_expression_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	int l_result = parser_parse_symbol_semicolon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_EXPRESSION_STATEMENT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_selection_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_keyword_if(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0)
					{
/* ... */
						l_result = parser_parse_keyword_else(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0)
						{
/* ... */
							l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
							if(l_result >= 0) goto j_success;
							else if(l_result < 0) goto j_failure;
						}
						else if(l_result < 0) goto j_success;
					}
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_keyword_switch(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0)
					{
/* ... */
						l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0) goto j_success;
						else if(l_result < 0) goto j_failure;
					}
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_SELECTION_STATEMENT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_iteration_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_keyword_while(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_keyword_do(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_keyword_while(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0)
					{
/* ... */
						l_result = parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0)
						{
/* ... */
							l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
							if(l_result >= 0)
							{
/* ... */
								l_result = parser_parse_symbol_semicolon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
								if(l_result >= 0) goto j_success;
								else if(l_result < 0) goto j_failure;
							}
							else if(l_result < 0) goto j_failure;
						}
						else if(l_result < 0) goto j_failure;
					}
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_keyword_for(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_open_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					l_result = parser_parse_symbol_semicolon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0)
					{
/* ... */
						parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						l_result = parser_parse_symbol_semicolon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
						if(l_result >= 0)
						{
/* ... */
							parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
							l_result = parser_parse_symbol_close_parenthesis(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
							if(l_result >= 0)
							{
/* ... */
								l_result = parser_parse_rule_statement(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
								if(l_result >= 0) goto j_success;
								else if(l_result < 0) goto j_failure;
							}
							else if(l_result < 0) goto j_failure;
						}
						else if(l_result < 0) goto j_failure;
					}
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0) goto j_failure;
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_ITERATION_STATEMENT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_rule_jump_statement(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;

/* ... */
	int l_result = parser_parse_keyword_goto(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0)
	{
/* ... */
		l_result = parser_parse_identifier(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_semicolon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0) goto j_failure;
	}
	else if(l_result < 0)
	{
/* ... */
		l_result = parser_parse_keyword_continue(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
		if(l_result >= 0)
		{
/* ... */
			l_result = parser_parse_symbol_semicolon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0) goto j_success;
			else if(l_result < 0) goto j_failure;
		}
		else if(l_result < 0)
		{
/* ... */
			l_result = parser_parse_keyword_break(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
			if(l_result >= 0)
			{
/* ... */
				l_result = parser_parse_symbol_semicolon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0) goto j_success;
				else if(l_result < 0) goto j_failure;
			}
			else if(l_result < 0)
			{
/* ... */
				l_result = parser_parse_keyword_return(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
				if(l_result >= 0)
				{
/* ... */
					parser_parse_rule_expression(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					l_result = parser_parse_symbol_semicolon(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
					if(l_result >= 0) goto j_success;
					else if(l_result < 0) goto j_failure;
				}
				else if(l_result < 0) goto j_failure;
			}
		}
	}

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	g_level--;

/* ... */
	return -1;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;

/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_RULE_JUMP_STATEMENT;

/* ... */
	g_level--;

/* ... */
	*pt_index = l_index;

/* ... */
	return 0;
}

/* ... */
int parser_parse_identifier(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size, uintmax_t *pt_index)
{
/* ... */
	g_level++;

/* ... */
	LOG_STARTED;

/* ... */
	uintmax_t l_index = *pt_index;
	uintmax_t l_saved_object_size = *pt_output_object_buffer_size;

/* ... */
	if(l_index < *pt_input_token_buffer_size && pt_input_token_buffer[l_index].t_token_type == TOKEN_TYPE_IDENTIFIER)
	{
/* ... */
		l_index++;

/* ... */
		goto j_success;
	}
	else goto j_failure;

/* ... */
j_success:
/* ... */
	LOG_SUCCESS;
/* ... */
	(*pt_output_object_buffer_size)++;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, *pt_output_object_buffer_size * sizeof(object_t));

/* ... */
	object_t *pt_object = &(*ppt_output_object_buffer)[*pt_output_object_buffer_size - 1];
	pt_object->t_object_type = OBJECT_TYPE_IDENTIFIER;

/* ... */
	*pt_index = l_index;

/* ... */
	g_level--;

/* ... */
	return 0;

/* ... */
j_failure:
/* ... */
	LOG_FAILURE;

/* ... */
	*pt_output_object_buffer_size = l_saved_object_size;
	*ppt_output_object_buffer = realloc(*ppt_output_object_buffer, l_saved_object_size * sizeof(object_t));

/* ... */
	g_level--;

/* ... */
	return -1;
}

int parser_main(token_t *pt_input_token_buffer, uintmax_t *pt_input_token_buffer_size, object_t **ppt_output_object_buffer, uintmax_t *pt_output_object_buffer_size, name_t **ppt_name_buffer, uintmax_t *pt_name_buffer_size)
{
/* ... */
	fprintf(stderr, "debug: Parsing the tokens...\n");

/* Set the recursion level to zero. */
	g_level = -1;

/* Set the index to zero. */
	uintmax_t l_index = 0;

/* ... */
	int l_result = parser_parse_rule_translation_unit(pt_input_token_buffer, pt_input_token_buffer_size, ppt_output_object_buffer, pt_output_object_buffer_size, ppt_name_buffer, pt_name_buffer_size, &l_index);

/* ... */
	if(l_result >= 0) goto j_success;
	else if(l_result < 0) goto j_failure;

/* ... */
j_failure:
/* ... */
	return -1;

/* ... */
j_success:
/* Print the object(s). */
	fprintf(stderr, "debug: Iterating through the object buffer...\n");

/* ... */
	for(uintmax_t l_i = 0; l_i < (*pt_output_object_buffer_size); l_i++)
	{
/* ... */
		object_t *pt_object = &(*ppt_output_object_buffer)[l_i];
		
/* Handle the right printing statement for the current object. */
		switch(pt_object->t_object_type)
		{
		default:
			fprintf(stderr, "debug: Iteration %ju, unknown object type.\n", l_i);
			break;
		case OBJECT_TYPE_SYMBOL:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol");
			break;
		case OBJECT_TYPE_SYMBOL_ELLIPSIS:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_ellipsis");
			break;
		case OBJECT_TYPE_SYMBOL_EQUAL_TO:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_equal_to");
			break;
		case OBJECT_TYPE_SYMBOL_NOT_EQUAL_TO:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_not_equal_to");
			break;
		case OBJECT_TYPE_SYMBOL_LESS_THAN_OR_EQUAL_TO:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_less_than_or_equal_to");
			break;
		case OBJECT_TYPE_SYMBOL_GREATER_THAN_OR_EQUAL_TO:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_greater_than_or_equal_to");
			break;
		case OBJECT_TYPE_SYMBOL_LOGICAL_AND:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_logical_and");
			break;
		case OBJECT_TYPE_SYMBOL_LOGICAL_OR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_logical_or");
			break;
		case OBJECT_TYPE_SYMBOL_LEFT_SHIFT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_left_shift");
			break;
		case OBJECT_TYPE_SYMBOL_RIGHT_SHIFT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_right_shift");
			break;
		case OBJECT_TYPE_SYMBOL_ADD:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_add");
			break;
		case OBJECT_TYPE_SYMBOL_SUBTRACT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_subtract");
			break;
		case OBJECT_TYPE_SYMBOL_DIVIDE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_divide");
			break;
		case OBJECT_TYPE_SYMBOL_MULTIPLY:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_multiply");
			break;
		case OBJECT_TYPE_SYMBOL_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_assign");
			break;
		case OBJECT_TYPE_SYMBOL_MULTIPLY_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_multiply_assign");
			break;
		case OBJECT_TYPE_SYMBOL_DIVIDE_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_divide_assign");
			break;
		case OBJECT_TYPE_SYMBOL_MODULO_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_modulo_assign");
			break;
		case OBJECT_TYPE_SYMBOL_ADDITION_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_addition_assign");
			break;
		case OBJECT_TYPE_SYMBOL_SUBTRACTION_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_subtraction_assign");
			break;
		case OBJECT_TYPE_SYMBOL_LEFT_SHIFT_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_left_shift_assign");
			break;
		case OBJECT_TYPE_SYMBOL_RIGHT_SHIFT_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_right_shift_assign");
			break;
		case OBJECT_TYPE_SYMBOL_BITWISE_AND_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_bitwise_and_assign");
			break;
		case OBJECT_TYPE_SYMBOL_BITWISE_XOR_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_bitwise_xor_assign");
			break;
		case OBJECT_TYPE_SYMBOL_BITWISE_OR_ASSIGN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_bitwise_or_assign");
			break;
		case OBJECT_TYPE_SYMBOL_LESS_THAN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_less_than");
			break;
		case OBJECT_TYPE_SYMBOL_GREATER_THAN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_greater_than");
			break;
		case OBJECT_TYPE_SYMBOL_LOGICAL_NOT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_logical_not");
			break;
		case OBJECT_TYPE_SYMBOL_BITWISE_AND:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_bitwise_and");
			break;
		case OBJECT_TYPE_SYMBOL_BITWISE_OR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_bitwise_or");
			break;
		case OBJECT_TYPE_SYMBOL_BITWISE_XOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_bitwise_xor");
			break;
		case OBJECT_TYPE_SYMBOL_BITWISE_NOT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_bitwise_not");
			break;
		case OBJECT_TYPE_SYMBOL_LEFT_PARENTHESIS:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_left_parenthesis");
			break;
		case OBJECT_TYPE_SYMBOL_RIGHT_PARENTHESIS:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_right_parenthesis");
			break;
		case OBJECT_TYPE_SYMBOL_LEFT_BRACE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_left_brace");
			break;
		case OBJECT_TYPE_SYMBOL_RIGHT_BRACE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_right_brace");
			break;
		case OBJECT_TYPE_SYMBOL_LEFT_BRACKET:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_left_bracket");
			break;
		case OBJECT_TYPE_SYMBOL_RIGHT_BRACKET:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_right_bracket");
			break;
		case OBJECT_TYPE_SYMBOL_COMMA:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_comma");
			break;
		case OBJECT_TYPE_SYMBOL_PERIOD:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_period");
			break;
		case OBJECT_TYPE_SYMBOL_MODULO:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_modulo");
			break;
		case OBJECT_TYPE_SYMBOL_SEMICOLON:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_semicolon");
			break;
		case OBJECT_TYPE_SYMBOL_COLON:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_colon");
			break;
		case OBJECT_TYPE_SYMBOL_INCREMENT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_increment");
			break;
		case OBJECT_TYPE_SYMBOL_DECREMENT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_decrement");
			break;
		case OBJECT_TYPE_SYMBOL_ARROW:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_arrow");
			break;
		case OBJECT_TYPE_SYMBOL_CONDITIONAL:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "symbol_conditional");
			break;
		case OBJECT_TYPE_KEYWORD:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword");
			break;
		case OBJECT_TYPE_KEYWORD_AUTO:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_auto");
			break;
		case OBJECT_TYPE_KEYWORD_BREAK:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_break");
			break;
		case OBJECT_TYPE_KEYWORD_CASE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_case");
			break;
		case OBJECT_TYPE_KEYWORD_BYTE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_byte");
			break;
		case OBJECT_TYPE_KEYWORD_CONST:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_const");
			break;
		case OBJECT_TYPE_KEYWORD_CONTINUE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_continue");
			break;
		case OBJECT_TYPE_KEYWORD_DEFAULT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_default");
			break;
		case OBJECT_TYPE_KEYWORD_DO:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_do");
			break;
		case OBJECT_TYPE_KEYWORD_ELSE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_else");
			break;
		case OBJECT_TYPE_KEYWORD_ENUM:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_enum");
			break;
		case OBJECT_TYPE_KEYWORD_EXTERN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_extern");
			break;
		case OBJECT_TYPE_KEYWORD_FOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_for");
			break;
		case OBJECT_TYPE_KEYWORD_GOTO:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_goto");
			break;
		case OBJECT_TYPE_KEYWORD_IF:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_if");
			break;
		case OBJECT_TYPE_KEYWORD_REGISTER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_register");
			break;
		case OBJECT_TYPE_KEYWORD_RETURN:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_return");
			break;
		case OBJECT_TYPE_KEYWORD_SIGNED:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_signed");
			break;
		case OBJECT_TYPE_KEYWORD_UNSIGNED:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_unsigned");
			break;
		case OBJECT_TYPE_KEYWORD_VOID:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_void");
			break;
		case OBJECT_TYPE_KEYWORD_VOLATILE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_volatile");
			break;
		case OBJECT_TYPE_KEYWORD_WHILE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "keyword_while");
			break;
		case OBJECT_TYPE_LITERAL:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "literal");
			break;
		case OBJECT_TYPE_LITERAL_CHARACTER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "literal_character");
			break;
		case OBJECT_TYPE_LITERAL_STRING:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "literal_string");
			break;
		case OBJECT_TYPE_LITERAL_INTEGER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "literal_integer");
			break;
		case OBJECT_TYPE_LITERAL_FLOAT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "literal_float");
			break;
		case OBJECT_TYPE_RULE:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule");
			break;
		case OBJECT_TYPE_RULE_TRANSLATION_UNIT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_translation_unit");
			break;
		case OBJECT_TYPE_RULE_EXTERNAL_DECLARATION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_external_declaration");
			break;
		case OBJECT_TYPE_RULE_FUNCTION_DEFINITION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_function_definition");
			break;
		case OBJECT_TYPE_RULE_DECLARATION_SPECIFIER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_declaration_specifier");
			break;
		case OBJECT_TYPE_RULE_STORAGE_CLASS_SPECIFIER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_storage_class_specifier");
			break;
		case OBJECT_TYPE_RULE_TYPE_SPECIFIER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_type_specifier");
			break;
		case OBJECT_TYPE_RULE_STRUCT_OR_UNION_SPECIFIER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_struct_or_union_specifier");
			break;
		case OBJECT_TYPE_RULE_STRUCT_OR_UNION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_struct_or_union");
			break;
		case OBJECT_TYPE_RULE_STRUCT_DECLARATION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_struct_declaration");
			break;
		case OBJECT_TYPE_RULE_SPECIFIER_QUALIFIER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_specifier_qualifier");
			break;
		case OBJECT_TYPE_RULE_STRUCT_DECLARATOR_LIST:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_struct_declarator_list");
			break;
		case OBJECT_TYPE_RULE_STRUCT_DECLARATOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_struct_declarator");
			break;
		case OBJECT_TYPE_RULE_DECLARATOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_declarator");
			break;
		case OBJECT_TYPE_RULE_POINTER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_pointer");
			break;
		case OBJECT_TYPE_RULE_TYPE_QUALIFIER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_type_qualifier");
			break;
		case OBJECT_TYPE_RULE_DIRECT_DECLARATOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_direct_declarator");
			break;
		case OBJECT_TYPE_RULE_DIRECT_DECLARATOR_TAIL:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_direct_declarator_tail");
			break;
		case OBJECT_TYPE_RULE_CONSTANT_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_constant_expression");
			break;
		case OBJECT_TYPE_RULE_LOGICAL_OR_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_logical_or_expression");
			break;
		case OBJECT_TYPE_RULE_LOGICAL_AND_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_logical_and_expression");
			break;
		case OBJECT_TYPE_RULE_INCLUSIVE_OR_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_inclusive_or_expression");
			break;
		case OBJECT_TYPE_RULE_AND_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_and_expression");
			break;
		case OBJECT_TYPE_RULE_EQUALITY_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_equality_expression");
			break;
		case OBJECT_TYPE_RULE_RELATIONAL_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_relational_expression");
			break;
		case OBJECT_TYPE_RULE_SHIFT_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_shift_expression");
			break;
		case OBJECT_TYPE_RULE_ADDITIVE_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_additive_expression");
			break;
		case OBJECT_TYPE_RULE_MULTIPLICATIVE_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_multiplicative_expression");
			break;
		case OBJECT_TYPE_RULE_CAST_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_cast_expression");
			break;
		case OBJECT_TYPE_RULE_UNARY_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_unary_expression");
			break;
		case OBJECT_TYPE_RULE_POSTFIX_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_postfix_expression");
			break;
		case OBJECT_TYPE_RULE_PRIMARY_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_primary_expression");
			break;
		case OBJECT_TYPE_RULE_CONSTANT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_constant");
			break;
		case OBJECT_TYPE_RULE_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_expression");
			break;
		case OBJECT_TYPE_RULE_ASSIGNMENT_EXPRESSION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_assignment_expression");
			break;
		case OBJECT_TYPE_RULE_ASSIGNMENT_OPERATOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_assignment_operator");
			break;
		case OBJECT_TYPE_RULE_UNARY_OPERATOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_unary_operator");
			break;
		case OBJECT_TYPE_RULE_TYPE_NAME:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_type_name");
			break;
		case OBJECT_TYPE_RULE_PARAMETER_TYPE_LIST:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_parameter_type_list");
			break;
		case OBJECT_TYPE_RULE_PARAMETER_LIST:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_parameter_list");
			break;
		case OBJECT_TYPE_RULE_PARAMETER_DECLARATION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_parameter_declaration");
			break;
		case OBJECT_TYPE_RULE_ABSTRACT_DECLARATOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_abstract_declarator");
			break;
		case OBJECT_TYPE_RULE_DIRECT_ABSTRACT_DECLARATOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_direct_abstract_declarator");
			break;
		case OBJECT_TYPE_RULE_DIRECT_ABSTRACT_DECLARATOR_TAIL:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_direct_abstract_declarator_tail");
			break;
		case OBJECT_TYPE_RULE_ENUM_SPECIFIER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_enum_specifier");
			break;
		case OBJECT_TYPE_RULE_ENUMERATOR_LIST:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_enumerator_list");
			break;
		case OBJECT_TYPE_RULE_ENUMERATOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_enumerator");
			break;
		case OBJECT_TYPE_RULE_TYPEDEF_NAME:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_typedef_name");
			break;
		case OBJECT_TYPE_RULE_DECLARATION:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_declaration");
			break;
		case OBJECT_TYPE_RULE_INIT_DECLARATOR:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_init_declarator");
			break;
		case OBJECT_TYPE_RULE_INITIALIZER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_initializer");
			break;
		case OBJECT_TYPE_RULE_INITIALIZER_LIST:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_initializer_list");
			break;
		case OBJECT_TYPE_RULE_COMPOUND_STATEMENT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_compound_statement");
			break;
		case OBJECT_TYPE_RULE_STATEMENT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_statement");
			break;
		case OBJECT_TYPE_RULE_LABELED_STATEMENT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_labeled_statement");
			break;
		case OBJECT_TYPE_RULE_EXPRESSION_STATEMENT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_expression_statement");
			break;
		case OBJECT_TYPE_RULE_SELECTION_STATEMENT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_selection_statement");
			break;
		case OBJECT_TYPE_RULE_ITERATION_STATEMENT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_iteration_statement");
			break;
		case OBJECT_TYPE_RULE_JUMP_STATEMENT:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_jump_statement");
			break;
		case OBJECT_TYPE_IDENTIFIER:
			fprintf(stderr, "debug: Iteration %ju, object type `%-32s`.\n", l_i, "rule_identifier");
			break;
		}
	}

	return 0;
}