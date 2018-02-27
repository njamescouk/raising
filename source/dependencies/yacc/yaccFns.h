// yaccFns.h
#ifndef have_yaccFns
#define have_yaccFns

extern int yylineno;
#include <stdio.h>

/* C++ wants prototypes, you 'just know' the declarations */
int yylex();
int yyparse();
void yyerror (char *s);
extern char g_curToken[BUFSIZ]; // assign to this when lexing
                                     // declare in .y

void scanString(const char *s);

extern FILE *yyin, *yyout;
extern int yydebug;

// #define YYDEBUG 1
#endif // have_yaccFns
