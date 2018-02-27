#include "CsvParser.h" 
#include <stdio.h>
#include "yaccFns.h"
/*
#include <iostream>
#include <fstream>
*/

#pragma warning (disable: 4996)

extern int yydebug;

ParsedCsv *pgResult = 0;

CsvParser::CsvParser() 
{
}

CsvParser::~CsvParser() 
{
}

bool CsvParser::parse(std::string filename) 
{
    /*
    std::ifstream ifs;
    ifs.open(filename);
    if (ifs.fail())
    {
        fprintf(stderr, "error: cannot open %s\n", filename.c_str());
    }
    std::string line;
    std::getline(ifs, line);
    */

    FILE *fp = 0;
    
    std::string err;

    if (filename.empty())
    {
        fp = stdin;
    }
    else
    {
        fp = fopen(filename.c_str(), "rt");
        if (fp == 0)
        {
            err = "CsvParser::parse: cannot open " + filename;
            perror(err.c_str());
            return false;
        }
    }

    bool res = parse(fp);
    
    if(fp != stdin)
    {
        fclose(fp);
    }

    return res;
}

bool CsvParser::parse(FILE *fp) 
{
    if (fp != 0) // shouldn't happen
    {
        yyin = fp;
        pgResult = &m_csv; // pgResult referenced in yyparse
        // yydebug = 1;
        return yyparse() == 0;
    }

    return false;
}

