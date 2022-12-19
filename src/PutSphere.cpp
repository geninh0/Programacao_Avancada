#include "PutSphere.h"

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a){
    //CONSTRUTOR
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> radius = radius;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;

}

void PutSphere::draw(Sculptor &s)
{
    double rx, ry, rz, raio;

    raio = (double)radius * (double)radius;
    for (int i = xcenter - radius; i < xcenter + radius; i++)
    {
        for (int j = ycenter - radius; j < ycenter + radius; j++)
        {
            for (int k = zcenter - radius; k < zcenter + radius; k++)
            {
                rx = (double)(i - xcenter) * (double)(i - xcenter);
                ry = (double)(j - ycenter) * (double)(j - ycenter);
                rz = (double)(k - zcenter) * (double)(k - zcenter);

                if (rx + ry + rz < raio)
                {
                    s.setColor(r, g, b, a);
                    s.putVoxel(i, j, k);
                }
            }
        }
    }
}
