#include "ARHNArray.h"
#include <cstdio>
#include <map>
#include "CmdLineParser.h" 
#include "CsvParser.h" 

#pragma warning( disable : 4996 )

char *progname = 0;
char *szVersion = "1.0";
 
void usage(FILE *fp);
void version(FILE *fp);

#pragma warning( disable : 4996 )

ARHNArray getRadiusAndHeight(FILE *fp, int tangentWindow);

int main (int argc, char * argv[])
{
    progname = argv[0];
    std::map<std::string, OptionSpec> specs;

    int initialThickness(1);
    int tangentWindow = 1;

    std::string blurb = progname;
    blurb += " csv_file\ncomputes a table of values\n"
             "of radius and path length for the profile_pbm_file\n";

    specs["h"] = OptionSpec(false, "this help");
    specs["v"] = OptionSpec(false, "version");
    specs["d"] = OptionSpec(false, "dump profile data");
    specs["i"] = OptionSpec(false, "write summary info");
    specs["w"] = OptionSpec(true, "interval over which to compute tangent (default " + intToStr(tangentWindow) + ")");
    specs["t"] = OptionSpec(true, "thickness of initial disc (default " + intToStr(initialThickness) + ")");
    CmdLineSpec cls(specs);

    pcldebug = 0;
    CmdLineParser clp(argc, argv, cls);

    Cmdline cmdline = clp.parse();
    if (!cmdline.isValid())
    {
        cls.help(blurb, stdout);
        return 1;
    }

    if (cmdline.hasOption("v"))
    {
        version(stdout);
        return 0;
    }

    if (cmdline.hasOption("h"))
    {
        cls.help(blurb, stdout);
        return 0;
    }

    bool dump = cmdline.hasOption("d");
    bool writeInfo = cmdline.hasOption("i");
    
    if (cmdline.hasOption("t"))
    {
        initialThickness = atoi(cmdline.getOptionValue("t").c_str());
    }
    
    if (cmdline.hasOption("w"))
    {
        tangentWindow = atoi(cmdline.getOptionValue("w").c_str());
    }
    
    FILE *fp = stdin;
    std::string inputFile;
    if (cmdline.numArguments() > 0)
    {
        inputFile = cmdline.getArgument(0);
        fp = fopen(inputFile.c_str(), "rt");
        if (fp == 0)
        {
            std::string msg = progname;
            msg += " attempting to open file \"" + inputFile + "\"";
            perror(msg.c_str());
            return 2;
        }
    }

    ARHNArray arh = getRadiusAndHeight(fp, tangentWindow);
    
    if (fp != stdin)
    {
        fclose(fp);
    }

    if (!arh.getValid())
    {
        return 3;
    }

    if (dump)
        arh.write(stdout, initialThickness);
    else if (writeInfo)
        arh.writeInfo(stdout, initialThickness, inputFile.c_str());
    else
        arh.writeSvg(stdout, initialThickness);

    return 0;
}

ARHNArray getRadiusAndHeight(FILE *fp, int tangentWindow)
{
    ARHNArray res;

    CsvParser cp;
    res.setValid(cp.parse(fp));
    if (!res.getValid())
        return res;

    ParsedCsv pc = cp.getParsedCsv();
    if (pc.numRecords() == 0)
        return res; /* not invalid? */

    bool isRect = pc.isRectangular();
    CsvRecord cr = pc.getRecord(0);
    bool firstLineOk = (cr.size() == 2 && cr[0] == "radius" && cr[1] == "height");

    if (!isRect || !firstLineOk)
    {
        res.setValid(false);
        return res;
    }

    size_t row;
    for (row = 1 /* NB */; row < pc.numRecords(); row++)
    {
        CsvRecord crCur = pc.getRecord(row); /* this has 2 records as csv is rectangular */
        if (!crCur[0].getIsIntegral() || !crCur[1].getIsIntegral())
        {
            res.setValid(false);
            return res;
        }

        int radius = atoi(crCur[0].c_str());
        int height = atoi(crCur[1].c_str());
        res.push_back(ARHN(radius, height));
    }

    res.sortOnHeight();
    res.computeArcLength();
    res.computeNormals(tangentWindow);

    return res;
}

void usage(FILE *fp)
{
    fprintf (fp, "usage %s [-d]  profile_pbm computes a table of values\n", progname);
    fprintf (fp, "of radius and path length for the pbm profile\n");
    fprintf (fp, "-d  dump AHRN\n");
}

void version(FILE *fp)
{
    fprintf (fp, "%s version %s\n", progname, szVersion);
}

std::string intToStr(long i)
{
    char buf[BUFSIZ];
    sprintf(buf, "%ld", i);

    return std::string(buf);
}

std::string doubleToStr(double d, int numDp)
{
    char buf[BUFSIZ];
    sprintf(buf, "%.*f", numDp, d);

    return std::string(buf);
}
