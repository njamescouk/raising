// ParsedCsv.h
#ifndef have_ParsedCsv
#define have_ParsedCsv

#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "split_string.h"

#pragma warning (disable: 4996)

class CsvField : public std::string
{

public:
    CsvField()
    {
    }

    CsvField(std::string s)
        :std::string(s)
    {
        
    }

    bool getIsIntegral()
    {
        // fprintf(stderr, "%s\n", toString().c_str());
        // return m_isIntegral;
        return (find_first_not_of("0123456789") == std::string::npos);
    }

    bool getIsReal()
    {
        if (find(".") == std::string::npos)
            return false;

        char num[BUFSIZ];
        strcpy(num, c_str());
        char *endP = num;
        strtod(num, &endP);
        return *endP == 0;

        /*
        std::vector<std::string> bits;
        std::string src = *this;
        splitstring::split(src, bits, ".");
        if (bits.size() > 2)
            return false;

        bool firstIsInt = bits[0].find_first_not_of("0123456789") == std::string::npos;
        if (bits.size() == 1)
        {
            return firstIsInt;
        }
        
        if (bits.size() == 2)
        {
            bool secondIsInt = bits[0].find_first_not_of("0123456789") == std::string::npos;
            return firstIsInt && secondIsInt;
        }

        return false;
        */
    }

    bool getIsNumerical()
    {
        // fprintf(stderr, "%s\n", toString().c_str());
        // return m_isIntegral;
        // BUG allows any number of decimal points 
        return (find_first_not_of("0123456789.") == std::string::npos);
    }

    std::string toString()
    {
        std::string res = *this;
        
        if (res.empty())
            res = "\"\"";
        
        res = res + " is ";
                
        if (getIsIntegral())
            res += "integral";
        else if (getIsReal())
            res += "real";
        else
            res += "text";

        return res;
    }
};

class CsvRecord : public std::vector<CsvField>
{
public:
    void writeHtmlRow(FILE *fp);
    void writePipeEnclosed(FILE *fp);

    bool isEmpty()
    {
        bool noFields = (size() == 0);
        bool oneEmptyField = (size() == 1 && at(0).size() == 0);

        return noFields || oneEmptyField;
    }

    bool contains(std::string name)
    {
        size_t i;
        for (i = 0; i < size(); i++)
        {
            if (at(i) == name)
                return true;
        }

        return false;
    }

    size_t numFields()
    {
        return size();
    }

    CsvField getField(size_t i)
    {
        return at(i);
    }

    bool isColIntegral(size_t i)
    {
        if (i < size())
            return at(i).getIsIntegral();

        return true; // non existent field is integral, = 0 . 2015-08-22 09:30:14 not sure about that...
    }

    // need to test column for integral first
    bool isColReal(size_t i)
    {
        if (i < size())
        {
            if (at(i).getIsIntegral())
                return false; // it ain't REAL, it's INTEGRAL
            else
                return at(i).getIsReal();
        }

        return false; // non existent field is not real
    }

    bool isColNumerical(size_t i)
    {
        if (i < size())
            return at(i).getIsNumerical();

        return false; // non existent field is not numerical
    }

    std::string toString()
    {
        std::string res = "";
        size_t i;
        for (i = 0; i < size(); i++)
        {
            if (i != 0)
                res += ", ";

            res += at(i).toString();
        }

        return res;
    }
}
;

class ParsedCsv
{
    std::vector<CsvRecord> m_records;

public:
    ParsedCsv();
    virtual ~ParsedCsv();

    size_t numRecords()
    {
        return m_records.size();
    }

    CsvRecord getRecord(size_t i)
    {
        if (i < m_records.size() && !m_records.empty())
            return m_records[i];

        return CsvRecord();
    }

    bool isRectangular();
    size_t maxFields();
    size_t minFields();
    void writeHtml(FILE *fp);
    void writePipeEnclosed(FILE *fp);

    void push_back(CsvRecord r)
    {
        m_records.push_back(r);
    }

    bool isColIntegral(size_t col, bool ignoreFirstLine)
    {
        bool res = true;

        size_t i = 0;
        if (ignoreFirstLine)
            i = 1;

        for (/* NB */; res && i < m_records.size(); i++)
        {
            res = res && m_records[i].isColIntegral(col);
        }

        return res;
    }

    bool isColReal(size_t col, bool ignoreFirstLine)
    {
        bool res = true;

        size_t i = 0;
        if (ignoreFirstLine)
            i = 1;

        for (/* NB */; res && i < m_records.size(); i++)
        {
            res = res && m_records[i].isColReal(col);
        }

        return res;
    }
};





#endif // have_ParsedCsv

