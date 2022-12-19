#include "CutSphere.h"

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius){
    //CONSTRUTOR
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> radius = radius;
}

void CutSphere::draw(Sculptor &s)
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
                    s.cutVoxel(i, j, k);
                }
            }
        }
    }
}
