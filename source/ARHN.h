#ifndef have_ARHN
#define have_ARHN

#pragma warning( disable : 4996 )

#include <string>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cfloat>

std::string intToStr(long i);
std::string doubleToStr(double d, int numDp = 5);

class Px
{
    int m_value;

public:
    Px() : m_value(-1) {}
    Px(int i) : m_value(i) {}
    ~Px(){}

    bool operator< (const Px &rhs) const
    {
        return m_value < rhs.m_value;
    }
};

class Normal
{
    double m_xComponent;
    double m_yComponent;

public:
    Normal(double x, double y)
        : m_xComponent(x)
        , m_yComponent(y)
    {
    }

    double getX()
    {
        return m_xComponent;
    }

    double getY()
    {
        return m_yComponent;
    }

    double modsq()
    {
        return m_xComponent*m_xComponent + m_yComponent*m_yComponent;
    }

    std::string toCsv()
    {
        char buf[BUFSIZ];

        sprintf(buf, "%f,%f", m_xComponent, m_yComponent);

        return std::string(buf);
    }
};

class ARHN
{
    double m_arcLength;
    int m_radius;
    int m_height;
    Normal m_normal;

    static bool ltHeight(const ARHN lhs, const ARHN rhs)
    {
        return lhs.m_height < rhs.m_height;
    }

    /*
        thickness is in direction of normal
        find x component of thickness

        xComp^2 + yComp^2 = |normal|^2
        and

    */
    double thickX(int initialThicknessPx)
    {
        double res = 0;

        double rThick = raisedThickness(initialThicknessPx);

        res = rThick * (m_normal.getX() / sqrt(m_normal.modsq()));

        return res;
    }

    double thickY(int initialThicknessPx)
    {
        double res = 0;

        double rThick = raisedThickness(initialThicknessPx);

        res = rThick * (m_normal.getY() / sqrt(m_normal.modsq()));

        return res;
    }

public:

    static bool gtHeight(const ARHN lhs, const ARHN rhs)
    {
        return lhs.m_height > rhs.m_height;
    }

    ARHN()
        : m_arcLength(-1)
        , m_radius(-1)
        , m_height(-1)
        , m_normal(0, 0)
    {}

    ARHN(int r, int h)
        : m_arcLength(-1)
        , m_radius(r)
        , m_height(h)
        , m_normal(0, 0)
    {}

    ~ARHN() {}

    bool operator< (const ARHN &rhs) const
    {
        return m_height < rhs.m_height;
    }

    int getRadius()
    {
        return m_radius;
    }

    double getOutsideRadius(int initialThickness)
    {
        return m_radius + thickX(initialThickness);
    }

    int getHeight()
    {
        return m_height;
    }

    double getArcLength()
    {
        return m_arcLength;
    }

    void setArcLength(double d)
    {
        m_arcLength = d;
    }

    void setNormal(Normal n)
    {
        assert (!(fabs(n.getX()) < DBL_EPSILON && fabs(n.getY()) < DBL_EPSILON));
        m_normal = n;
    }

    double raisedThickness(int initialThickness)
    {
        double res = initialThickness;

        if (m_radius > 0)
        {
            res = m_arcLength*initialThickness / m_radius;
        }

        return res;
    }

    std::string insidePath(int maxHeight, int topMarginPx)
    {
        /* use maxHeight - height since svg y increases down the page */
        std::string res = intToStr(m_radius) 
                          + "," 
                          + intToStr((maxHeight + topMarginPx-m_height));

        return res;
    }

    std::string outsidePath(int maxHeight, int initialThicknessPx, int topMarginPx)
    {
        double xComponent = thickX(initialThicknessPx);
        double yComponent = thickY(initialThicknessPx);
        /* use maxHeight - height since svg y increases down the page */
        std::string res = doubleToStr((m_radius + xComponent), 0) 
                          + "," 
                          + doubleToStr((maxHeight + topMarginPx-(m_height + yComponent)), 1);

        return res;
    }

    void write (FILE *fp, int initialThicknessPx)
    {
        fprintf (fp, 
                 "%11.5f,%9d,%9d,%21s,%12.5f,%9.5f,%9.5f\n", 
                 m_arcLength, 
                 m_radius, 
                 m_height, 
                 m_normal.toCsv().c_str(), 
                 raisedThickness(initialThicknessPx),
                 thickX(initialThicknessPx),
                 thickY(initialThicknessPx));
    }
};


#endif // have_ARHN
