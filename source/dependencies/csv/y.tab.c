/*
02:19:25 Friday 23 February 2018
*/
#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"

/* I:\usr\NIK\dev\csv\CsvParser.cpp line 56 for yydebug */
/* C declarations */
#pragma warning( disable : 4786 )
#pragma warning( disable : 4996 )
#include <stdio.h>
#include "yaccFns.h"
#include "ParsedCsv.h"
#include <vector>
#include <string>

extern int lineno;
void yyerror (char *s);
extern char *yytext;
int parserVersion = 1;
extern ParsedCsv *pgResult;

typedef union 
{
    std::string *csvStr;
    CsvRecord *csvRecord;
} YYSTYPE;
#define COMMA_IN_QUOTE 257
#define COMMA 258
#define END_QUOTE 259
#define ESCAPED_QUOTE 260
#define QUOTE 261
#define STR 262
#define NEWLINE_IN_QUOTE 263
#define NEWLINE 264
#define WS_IN_QUOTE 265
#define WS 266
#define END_OF_FILE 267
#define LEXERR 268
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    8,    8,    7,    7,    6,    6,    6,    6,    6,
    6,    5,    5,    5,    5,    4,    4,    3,    3,    2,
    2,    2,    2,    2,    2,    1,
};
short yylen[] = {                                         2,
    1,    1,    2,    2,    2,    1,    1,    1,    3,    3,
    3,    1,    2,    2,    3,    3,    2,    1,    2,    1,
    1,    1,    1,    1,    1,    0,
};
short yydefred[] = {                                      0,
   23,   22,    0,   21,   25,   24,    0,    0,    7,   18,
    0,    0,    8,    0,    2,    0,   17,   20,    0,    0,
   19,   14,    0,    4,    5,    3,   16,   15,    9,    0,
   11,
};
short yydgoto[] = {                                       8,
    9,   10,   11,   12,   13,   14,   15,   16,
};
short yysindex[] = {                                   -238,
    0,    0, -228,    0,    0,    0, -258,    0,    0,    0,
 -211, -262,    0, -208,    0, -238,    0,    0, -218, -261,
    0,    0, -238,    0,    0,    0,    0,    0,    0, -211,
    0,
};
short yyrindex[] = {                                   -201,
    0,    0,    0,    0,    0,    0, -251,    0,    0,    0,
 -200, -196,    0,    0,    0,    1,    0,    0,    0, -189,
    0,    0, -201,    0,    0,    0,    0,    0,    0, -188,
    0,
};
short yygindex[] = {                                      0,
  -15,   -9,   -3,   10,   -5,    0,   14,    0,
};
#define YYTABLESIZE 268
short yytable[] = {                                      19,
    1,   21,    3,   22,   28,   20,   20,   29,   20,   21,
   20,   20,   20,   20,   20,   20,   20,   31,    1,   30,
   21,    2,    3,    4,    5,    0,    6,    7,    1,   26,
   17,    2,    0,    4,    5,    0,    6,   18,    1,    0,
   27,    2,    0,    4,    5,    1,    6,   18,    2,   23,
    4,    5,    0,    6,   18,   24,   26,    6,   25,    0,
    0,   12,   26,    6,    0,   26,    6,   12,   13,   10,
   12,    0,    0,    0,   13,   10,    0,   13,   10,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   26,    0,
    0,    0,    0,    0,   26,    0,    0,   26,
};
short yycheck[] = {                                       3,
    0,   11,  261,  266,  266,  257,  258,   23,  260,   19,
  262,  263,  264,  265,  266,  267,    7,   23,  257,   23,
   30,  260,  261,  262,  263,   -1,  265,  266,  257,   16,
  259,  260,   -1,  262,  263,   -1,  265,  266,  257,   -1,
  259,  260,   -1,  262,  263,  257,  265,  266,  260,  258,
  262,  263,   -1,  265,  266,  264,  258,  258,  267,   -1,
   -1,  258,  264,  264,   -1,  267,  267,  264,  258,  258,
  267,   -1,   -1,   -1,  264,  264,   -1,  267,  267,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,   -1,
   -1,   -1,   -1,   -1,  264,   -1,   -1,  267,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 268
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"COMMA_IN_QUOTE","COMMA",
"END_QUOTE","ESCAPED_QUOTE","QUOTE","STR","NEWLINE_IN_QUOTE","NEWLINE",
"WS_IN_QUOTE","WS","END_OF_FILE","LEXERR",
};
char *yyrule[] = {
"$accept : csv",
"csv : recordList",
"recordList : record",
"recordList : recordList record",
"record : fieldList NEWLINE",
"record : fieldList END_OF_FILE",
"fieldList : field",
"fieldList : emptyField",
"fieldList : quotedFieldAndSpace",
"fieldList : fieldList COMMA emptyField",
"fieldList : fieldList COMMA field",
"fieldList : fieldList COMMA quotedFieldAndSpace",
"quotedFieldAndSpace : quotedField",
"quotedFieldAndSpace : WS quotedField",
"quotedFieldAndSpace : quotedField WS",
"quotedFieldAndSpace : WS quotedField WS",
"quotedField : QUOTE field END_QUOTE",
"quotedField : QUOTE END_QUOTE",
"field : fieldComponent",
"field : field fieldComponent",
"fieldComponent : WS",
"fieldComponent : STR",
"fieldComponent : ESCAPED_QUOTE",
"fieldComponent : COMMA_IN_QUOTE",
"fieldComponent : WS_IN_QUOTE",
"fieldComponent : NEWLINE_IN_QUOTE",
"emptyField :",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
/* user code */

void yyerror (char *s)
{
   fprintf (stderr, "%s at or before line %d:\nreading \"%s\"\n", s, lineno, yytext);
}

/*
int main()
{
    int res = yyparse();
    printf("%d\n", res);
    if (res == 0)
    {
        printf("%s\n", gResult.ToString().c_str());
    }

    return res;
}
*/

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
{
    }
break;
case 2:
{
        if (!yyvsp[0].csvRecord->isEmpty())
            pgResult->push_back(*yyvsp[0].csvRecord);
        
        delete yyvsp[0].csvRecord;
    }
break;
case 3:
{
        if (!yyvsp[0].csvRecord->isEmpty())
             pgResult->push_back(*yyvsp[0].csvRecord);
        
        delete yyvsp[0].csvRecord;
    }
break;
case 4:
{
        yyval.csvRecord = yyvsp[-1].csvRecord;
        
        /* fprintf(stderr, "line: %d\nrecord: fieldList NEWLINE\n", lineno);*/
    }
break;
case 5:
{
        yyval.csvRecord = yyvsp[-1].csvRecord;
        
        /* fprintf(stderr, "line: %d\nrecord: fieldList END_OF_FILE\n", lineno);*/
    }
break;
case 6:
{
        yyval.csvRecord = new CsvRecord;
        yyval.csvRecord->push_back(*yyvsp[0].csvStr);
        
        delete yyvsp[0].csvStr;

        /* fprintf(stderr, "line: %d\nfieldList: field\n", lineno);*/
    }
break;
case 7:
{
        yyval.csvRecord = new CsvRecord;
        yyval.csvRecord->push_back(*yyvsp[0].csvStr);
        
        delete yyvsp[0].csvStr;

        /* fprintf(stderr, "line: %d\nfieldList: emptyField\n", lineno);*/
    }
break;
case 8:
{
        yyval.csvRecord = new CsvRecord;
        yyval.csvRecord->push_back(*yyvsp[0].csvStr);
        
        delete yyvsp[0].csvStr;

        /* fprintf(stderr, "line: %d\nfieldList: quotedFieldAndSpace\n", lineno);*/
    }
break;
case 9:
{
        yyval.csvRecord = yyvsp[-2].csvRecord;
        yyval.csvRecord->push_back(*yyvsp[0].csvStr);
        
        delete yyvsp[0].csvStr;
        
        /* fprintf(stderr, "line: %d\nfieldList: fieldList COMMA emptyField\n", lineno);*/
    }
break;
case 10:
{
        yyval.csvRecord = yyvsp[-2].csvRecord;
        yyval.csvRecord->push_back(*yyvsp[0].csvStr);
        
        delete yyvsp[0].csvStr;
        
        /* fprintf(stderr, "line: %d\nfieldList: fieldList COMMA field\n", lineno);*/
    }
break;
case 11:
{
        yyval.csvRecord = yyvsp[-2].csvRecord;
        yyval.csvRecord->push_back(*yyvsp[0].csvStr);
        
        delete yyvsp[0].csvStr;
        
        /* fprintf(stderr, "line: %d\nfieldList: fieldList COMMA quotedFieldAndSpace\n", lineno);*/
    }
break;
case 12:
{
        yyval.csvStr = yyvsp[0].csvStr;
    }
break;
case 13:
{
        yyval.csvStr = yyvsp[0].csvStr;
    }
break;
case 14:
{
        yyval.csvStr = yyvsp[-1].csvStr;
    }
break;
case 15:
{
        yyval.csvStr = yyvsp[-1].csvStr;
    }
break;
case 16:
{
        yyval.csvStr = yyvsp[-1].csvStr;
        
        /* fprintf(stderr, "line: %d\nquotedField: QUOTE field END_QUOTE\n", lineno);*/
        /* fprintf(stderr, "$$ = >|%s|<\n", $$->c_str());*/
    }
break;
case 17:
{
        yyval.csvStr = new std::string;
        
        /* fprintf(stderr, "line: %d\nquotedField: QUOTE END_QUOTE\n", lineno);*/
        /* fprintf(stderr, "$$ = >|%s|<\n", $$->c_str());*/
    }
break;
case 18:
{
        yyval.csvStr = yyvsp[0].csvStr;
        
        /* fprintf(stderr, "line: %d\nfield: fieldComponent\n", lineno);*/
    }
break;
case 19:
{
        yyval.csvStr = yyvsp[-1].csvStr;
        *yyval.csvStr += *yyvsp[0].csvStr;
        
        delete yyvsp[0].csvStr;
        
        /* fprintf(stderr, "line: %d\nfield: field fieldComponent\n", lineno);*/
    }
break;
case 20:
{
        yyval.csvStr = new std::string;
        *yyval.csvStr = *yyvsp[0].csvStr;
        
        delete yyvsp[0].csvStr;
        
        /* fprintf(stderr, "line: %d\nfieldComponent: WS\n", lineno);*/
    }
break;
case 21:
{
        yyval.csvStr = new std::string;
        *yyval.csvStr = *yyvsp[0].csvStr;
        
        delete yyvsp[0].csvStr;
        
        /* fprintf(stderr, "line: %d\nfieldComponent: STR\n", lineno);*/
    }
break;
case 22:
{
        yyval.csvStr = new std::string;
        *yyval.csvStr = "\"";
        
        /* fprintf(stderr, "line: %d\nfieldComponent: ESCAPED_QUOTE\n", lineno);*/
    }
break;
case 23:
{
        yyval.csvStr = new std::string;
        *yyval.csvStr = ",";
        
        /* fprintf(stderr, "line: %d\nfieldComponent: COMMA_IN_QUOTE\n", lineno);*/
    }
break;
case 24:
{
        yyval.csvStr = new std::string;
        *yyval.csvStr = *yyvsp[0].csvStr;
        
        delete yyvsp[0].csvStr;
        
        /* fprintf(stderr, "line: %d\nfieldComponent: WS_IN_QUOTE\n", lineno);*/
    }
break;
case 25:
{
        yyval.csvStr = new std::string;
        *yyval.csvStr += "\n";
        
        /* fprintf(stderr, "line: %d\nfieldComponent: NEWLINE_IN_QUOTE\n", lineno);*/
    }
break;
case 26:
{
        yyval.csvStr = new std::string;
        
        /* fprintf(stderr, "line: %d\nemptyField: empty\n", lineno);*/
    }
break;
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
