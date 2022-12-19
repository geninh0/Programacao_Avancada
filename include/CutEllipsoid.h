#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include <FiguraGeometrica.h>


class CutEllipsoid : public FiguraGeometrica
{
public:
    int xcenter, ycenter, zcenter, rx, ry, rz;
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    void draw(Sculptor &s);
};

#endif // CUTELLIPSOID_H
