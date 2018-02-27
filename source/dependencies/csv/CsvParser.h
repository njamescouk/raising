// CsvParser.h
#ifndef have_CsvParser
#define have_CsvParser

#include <vector>
#include <string>
#include "ParsedCsv.h" 

class CsvParser
{
    ParsedCsv m_csv;

public:
    CsvParser();
    virtual ~CsvParser();

    ParsedCsv getParsedCsv()
    {
        return m_csv;
    }

    bool parse(std::string filename);
    bool parse(FILE *fp);

    bool isRectangular()
    {
        return m_csv.isRectangular();
    }

    void writeHtml(FILE *fp)
    {
        return m_csv.writeHtml(fp);
    }
};



#endif // have_CsvParser

