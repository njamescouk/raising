#include <cstdio>
#include "ParsedCsv.h" 


ParsedCsv::ParsedCsv() 
{
}

ParsedCsv::~ParsedCsv() 
{
}


bool ParsedCsv::isRectangular()
{
    if (m_records.size() == 0 || m_records.size() == 1)
        return true;

    size_t numCols = m_records[0].numFields();
    
    size_t i;
    for (i = 1; i < m_records.size(); i++)
    {
        if (m_records[i].numFields() != numCols)
            return false;
    }

    return true;
}

size_t ParsedCsv::maxFields()
{
    if (m_records.size() == 0)
        return 0;

    size_t res = m_records[0].numFields();
    
    size_t i;
    for (i = 1; i < m_records.size(); i++)
    {
        size_t fieldsI = m_records[i].numFields();
        if (fieldsI > res)
            res = fieldsI;
    }

    return res;
}

size_t ParsedCsv::minFields()
{
    if (m_records.size() == 0)
        return 0;

    size_t res = m_records[0].numFields();
    
    size_t i;
    for (i = 1; i < m_records.size(); i++)
    {
        size_t fieldsI = m_records[i].numFields();
        if (fieldsI < res)
            res = fieldsI;
    }

    return res;
}

void ParsedCsv::writeHtml(FILE *fp)
{
    fprintf(fp, "<html>");
    fprintf(fp, "<head>");
    fprintf(fp, "</head>");
    fprintf(fp, "<body>");

    fprintf(fp, "<table border=\"1\">\n");
    size_t i;
    for (i = 0; i < m_records.size(); i++)
    {
        fprintf(fp, "<tr>\n");
        m_records[i].writeHtmlRow(fp);
        fprintf(fp, "</tr>\n");
    }
    fprintf(fp, "</table>\n");

    fprintf(fp, "</body>");
    fprintf(fp, "</html>");
}

void CsvRecord::writeHtmlRow(FILE *fp)
{
    size_t i;
    for (i = 0; i < size(); i++)
    {
        fprintf(fp, "<td><pre>");
        fprintf(fp, "%s", at(i).c_str());
        fprintf(fp, "</pre></td>\n");
    }
}

void ParsedCsv::writePipeEnclosed(FILE *fp)
{
    size_t i;
    for (i = 0; i < m_records.size(); i++)
    {
        m_records[i].writePipeEnclosed(fp);
    }
}

void CsvRecord::writePipeEnclosed(FILE *fp)
{
    fprintf(fp, "|");

    size_t i;
    for (i = 0; i < size(); i++)
    {
        fprintf(fp, "%s", at(i).c_str());
        if (i < size() - 1)
            fprintf(fp, "|");
    }

    fprintf(fp, "|\n");
}


