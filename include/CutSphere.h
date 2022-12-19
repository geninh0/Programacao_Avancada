#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include <FiguraGeometrica.h>


class CutSphere : public FiguraGeometrica
{
public:
    int xcenter, ycenter, zcenter, radius;
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
    void draw(Sculptor &s);
};

#endif // CUTSPHERE_H
