#include <stdio.h>
#include <string.h>

/*
 * Begining of KEYWORDS
 */
typedef struct Keywords
{
    char *__auto;
    char *__break;
    char *__case;
    char *__char;
    char *__const32;
    char *__continue;
    char *__default;
    char *__do;
    char *__double;
    char *__else;
    char *__enum;
    char *__extern;
    char *__float;
    char *__for;
    char *__goto;
    char *__if;
    char *__int;
    char *__long;
    char *__register;
    char *__return;
    char *__short;
    char *__signed32;
    char *__sizeof;
    char *__static;
    char *__struct;
    char *__switch;
    char *__typedef;
    char *__union;
    char *__unsigned;
    char *__void;
    char *__volatile32;
    char *__while;
} KEYWORDS;
/*
 * End of KEYWORDS
 */


/*
 * Begining of OPERATORS
 */
typedef struct Arithmetic
{
    char *__addition;
    char *__subtraction;
    char *__multiplication;
    char *__division;
    char *__modulus;
    char *__pre_increment;
    char *__post_increment;
    char *__pre_decrement;
    char *__post_decrement;
} ARITHMETIC;

typedef struct Relational
{
    char *__equal;
    char *__not_equal;
    char *__greater;
    char *__lesser;
    char *__greater_or_equal;
    char *__lesser_or_equal;
} RELATIONAL;

typedef struct Logical
{
    char *__and;
    char *__or;
    char *__not;
} LOGICAL;

typedef struct Bitwise
{
    char *__and;
    char *__or;
    char *__not;
    char *__xor;
    char *__left_shift;
    char *__right_shift;
} BITWISE;

typedef struct Assignment
{
    char *__assign;
    char *__add_assign;
    char *__subtract_assign;
    char *__multiply_assign;
    char *__divide_assign;
    char *__modulus_assign;
    char *__left_shift_assign;
    char *__right_shift_assign;
    char *__and_assign;
    char *__or_assign;
    char *__xor_assign;
} ASSIGNMENT;

typedef struct Misc
{
    char *__reference;
    char *__pointer;
    char *__ternary;
    char *__comma;
    char *__semicolon;
    char *__dot;
    char *__arrow;
    char *__type_conversion;
    char *__opening_bracket;
    char *__closing_bracket;
} MISC;

typedef struct Operators
{
    ARITHMETIC arithmetic;
    RELATIONAL relational;
    LOGICAL logical;
    BITWISE bitwise;
    ASSIGNMENT assignment;
    MISC misc;
} OPERATORS;
/*
 * End of OPERATORS
 */


/*
 * Begining of STRINGS
 */
typedef struct Literals
{
    char* __char;
    char* __string;
} LITERALS;
/*
 * End of STRINGS
 */


/*
 * Begining of CONSTANTS
 */
typedef struct Constants
{
    char* _constant;
} CONSTANTS;
/*
 * End of CONSTANTS
 */


/*
 * Begining of SYMBOLS
 */
typedef struct Symbols
{
    char* _symbol;
} SYMBOLS;
/*
 * End of SYMBOLS
 */


/*
 * Begining of IDENTIFIERS
 */
typedef struct Identifiers
{
    char* __identifier;
} IDENTIFIERS;
/*
 * End of IDENTIFIERS
 */


/*
 * Begining of TOKENS
 */
typedef struct Tokens
{
    KEYWORDS keywords;
    OPERATORS operators;
    LITERALS literals;
    CONSTANTS constants;
    SYMBOLS symbols;
    IDENTIFIERS identifiers;
    char* token_list;
} TOKENS;

enum Token_nums
{
    __AUTO__,
    __BREAK__,
    __CASE__,
    __CHAR__,
    __CONST__,
    __CONTINUE__,
    __DEFAULT__,
    __DO__,
    __DOUBLE__,
    __ELSE__,
    __ENUM__,
    __EXTERN__,
    __FLOAT__,
    __FOR__,
    __GOTO__,
    __IF__,
    __INT__,
    __LONG__,
    __REGISTER__,
    __RETURN__,
    __SHORT__,
    __SIGNED__,
    __SIZEOF__,
    __STATIC__,
    __STRUCT__,
    __SWITCH__,
    __TYPEDEF__,
    __UNION__,
    __UNSIGNED__,
    __VOID__,
    __VOLATILE__,
    __WHILE__,
    __ADDITION__,
    __SUBTRACTION__,
    __MULTIPLICATION__,
    __DIVISION__,
    __MODULUS__,
    __PRE_INCREMENT__,
    __POST__INCREMENT__,
    __PRE_DECREMENT__,
    __POST_DECREMENT__,
    __EQUAL__,
    __NOT_EQUAL__,
    __GREATER__,
    __LESSER__,
    __GREATER_OR_EQUAL__,
    __LESSER_OR_EQUAL__,
    __AND__,
    __OR__,
    __NOT__,
    __AND_BITWISE__,
    __OR_BITWISE__,
    __NOT_BITWISE__,
    __XOR_BITWISE__,
    __LEFT_SHIFT_BITWISE__,
    __RIGHT_SHIFT_BITWISE__,
    __ASSIGN__,
    __ADD_ASSIGN__,
    __SUBTRACT_ASSIGN__,
    __MULTIPLY_ASSIGN__,
    __DIVIDE_ASSIGN__,
    __MODULUS_ASSIGN__,
    __LEFT_SHIFT_ASSIGN__,
    __RIGHT_SHIFT_ASSIGN__,
    __AND_ASSIGN__,
    __OR_ASSIGN__,
    __XOR_ASSIGN__,
    __REFERENCE__,
    __POINTER__,
    __TERNARY__,
    __COMMA__,
    __SEMICOLON__,
    __DOT__,
    __ARROW__,
    __TYPE_CONVERSION__,
    __OPENING_BRACKET__,
    __CLOSING_BRACKET__,
    __LITERAL_CHAR__,
    __LITERAL_STRING__,
    __CONSTANT__,
    __SYMBOL__,
    __IDENTIFIER__
};
/*
 * End of TOKENS
 */


// create tokens from a .c source file
TOKENS tokenizer(FILE *file);
