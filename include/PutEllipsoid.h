#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include <FiguraGeometrica.h>

class PutEllipsoid : public FiguraGeometrica
{

public:
    int xcenter, ycenter, zcenter, rx, ry, rz;
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
    void draw(Sculptor &s);

};

#endif // PUTELLIPSOID_H
