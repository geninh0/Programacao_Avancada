#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include <FiguraGeometrica.h>


class PutSphere : public FiguraGeometrica{

public:
    int xcenter, ycenter, zcenter, radius;
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
    void draw(Sculptor &s);
};

#endif // PUTSPHERE_H
