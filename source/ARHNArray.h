#ifndef have_ARHNArray
#define have_ARHNArray

#include "ARHN.h"
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include "float.h"
#include "limits.h"

class ARHNArray : public std::vector<ARHN>
{
    bool m_valid;

    double getMaxWidth(int initialThickness, int *correspondingHeight = 0)
    {
        double res = 0.0;

        size_t i;
        for (i = 0; i < size(); i++)
        {
            if (at(i).getOutsideRadius(initialThickness) > res)
            {
                res = at(i).getOutsideRadius(initialThickness);
                if (correspondingHeight != 0)
                    *correspondingHeight = at(i).getHeight();
            }
        }

        return res;
    }

    int getMaxHeight()
    {
        int res = 0;

        size_t i;
        for (i = 0; i < size(); i++)
        {
            if (at(i).getHeight() > res)
                res = at(i).getHeight();
        }

        return res;
    }

    ARHN getHighest()
    {
        ARHN res;
        int maxHeight = 0;

        size_t i;
        for (i = 0; i < size(); i++)
        {
            if (at(i).getHeight() > maxHeight)
            {
                maxHeight = at(i).getHeight();
                res = at(i);
            }
        }

        return res;
    }

    ARHN getLowest()
    {
        ARHN res;
        int minHeight(INT_MAX);

        size_t i;
        for (i = 0; i < size(); i++)
        {
            if (at(i).getHeight() < minHeight)
            {
                minHeight = at(i).getHeight();
                res = at(i);
            }
        }

        return res;
    }

    double getThickness(int height, int initialThicknessPx)
    {
        double res;
        
        size_t i;
        for (i = 0; i < size(); i++)
        {
            if (at(i).getHeight() == height)
                res = at(i).raisedThickness(initialThicknessPx);
        }

        return res;
    }

    void writeInsidePath(FILE *fp, int maxHeight, int marginPx = 50)
    {
        sortOnHeight();

        std::string res;
        size_t i;
        for (i = 0; i < size(); i++)
        {
            fprintf(fp, "%s\n", at(i).insidePath(maxHeight, marginPx).c_str());
        }
    }

    void writeOutsidePath(FILE *fp, int maxHeight, int initialThickness, int marginPx = 50)
    {
        sortOnHeightDesc();

        std::string res;
        size_t i;
        for (i = 0; i < size(); i++)
        {
            fprintf(fp, "%s\n", at(i).outsidePath(maxHeight, initialThickness, marginPx).c_str());
        }
    }

public:
    ARHNArray(){}

    virtual ~ARHNArray(){}

    bool getValid()
    {
        return m_valid;
    }

    void setValid(bool b)
    {
        m_valid = b;
    }

    void sortOnHeight()
    {
        std::sort(begin(), end());
    }

    void sortOnHeightDesc()
    {
        std::sort(begin(), end(), ARHN::gtHeight);
    }
    
    void computeArcLength()
    {
        if (size() == 0)
            return;

        double arcLengthToDate = 0.0;
        at(0).setArcLength(arcLengthToDate);

        size_t i;
        for (i = 1/*NB*/; i < size(); i++)
        {
            double previousX = at(i-1).getRadius()
                   , previousY = at(i-1).getHeight()
                   , thisX = at(i).getRadius()
                   , thisY = at(i).getHeight()
                   , deltaX = fabs(thisX - previousX)
                   , deltaY = fabs(thisY - previousY)
                   , arcIncr = sqrt(deltaX*deltaX + deltaY*deltaY)
                   ;

            arcLengthToDate += arcIncr;
            at(i).setArcLength(arcLengthToDate);
        }
    }

    /* use points +/- tangentWindow from current point to determine normal */
    void computeNormals(int tangentWindow)
    {
        if (size() == 0)
            return;

        int i;
        for (i = 0; i < (int)size(); i++)
        {
            int loNdx = 0,
                hiNdx = 0;

            if (i + tangentWindow > (int)size() - 1)
                hiNdx = size() - 1;
            else
                hiNdx = i + tangentWindow;

            if (i - tangentWindow < 0)
                loNdx = 0;
            else
                loNdx = i - tangentWindow;

            ARHN next = at(hiNdx);
            ARHN previous = at(loNdx);
            int deltaRadius = next.getRadius() - previous.getRadius();
            int deltaHeight = next.getHeight() - previous.getHeight();
            /* 
                tangent is deltaRadius along, deltaHeight up 
                normal is deltaHeight along -deltaRadius up
            */

            at(i).setNormal(Normal(deltaHeight, -deltaRadius));
        }
    }

    void write(FILE *fp, int initialThickness)
    {
        fprintf (fp, "\"arcLength\", \"radius\", \"height\", \"normalX\", \"normalY\", \"thickness\", \"thickX\", \"thickY\"\n");
        size_t i;
        for (i = 0; i < size(); i++)
        {
            at(i).write(fp, initialThickness);
        }
    }

    void writeSvg(FILE *fp, int initialThickness)
    {
        int marginPx = 50;
        int maxHeight = getMaxHeight();
        int heightAtMaxWidth = 0;
        double maxWidth = getMaxWidth(initialThickness, &heightAtMaxWidth);
        //double thicknessAtMaxWidth = getThickness(heightAtMaxWidth, initialThicknessMM);

        fprintf (fp, 
                 "<svg xmlns=\"http://www.w3.org/2000/svg\"\n    width=\"%.0f\"\n    height=\"%d\">\n",
                 (maxWidth + marginPx),
                 (maxHeight + marginPx));

        fprintf (fp, "<path d=\"M ");
        writeInsidePath(fp, maxHeight);
        writeOutsidePath(fp, maxHeight, initialThickness);
        fprintf (fp, " z\"/>\n");

        fprintf (fp, "</svg>\n");
    }

    void writeInfo(FILE *fp, int initialThicknessPx, const char *filename)
    {
        ARHN highest = getHighest();
        ARHN lowest = getLowest();
        int maxHeight = getMaxHeight();
        int heightAtMaxWidth = 0;
        double maxWidth = getMaxWidth(initialThicknessPx, &heightAtMaxWidth);

        fprintf (fp
                 ,"data for %s with %dpx thick disc\n"
                 ,filename
                 ,initialThicknessPx
                 );

        fprintf (fp
                 ,"\"max height\",%.0d\n"
                 ,(highest.getHeight() - lowest.getHeight())
                 );

        fprintf (fp
                 ,"\"max outside radius\",%.0f\n"
                 ,getMaxWidth(initialThicknessPx)
                 );

        fprintf (fp
                 ,"\"arc length ( = disc radius)\",%.0f\n"
                 ,highest.getArcLength()
                 );

        fprintf (fp
                 ,"\"inside radius at rim\",%d\n"
                 ,highest.getRadius()
                 );

        fprintf (fp
                 ,"\"thickness at rim\",%.1f\n"
                 ,highest.raisedThickness(initialThicknessPx)
                 );
    }
};

#endif // have_ARHNArray
