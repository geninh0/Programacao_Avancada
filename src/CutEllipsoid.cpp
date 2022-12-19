#include "CutEllipsoid.h"

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    //CONSTRUTOR
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> rx = rx;
    this -> ry = ry;
    this -> rz = rz;
}

void CutEllipsoid::draw(Sculptor &s)
{
    double _rx, _ry, _rz;

    for (int i = xcenter - rx; i < xcenter + rx; i++)
    {
        for (int j = ycenter - ry; j < ycenter + ry; j++)
        {
            for (int k = zcenter - rz; k < zcenter + rz; k++)
            {
                _rx = (double)(i - xcenter) * (double)(i - xcenter) / (rx * rx);
                _ry = (double)(j - ycenter) * (double)(j - ycenter) / (ry * ry);
                _rz = (double)(k - zcenter) * (double)(k - zcenter) / (rz * rz);

                if (_rx + _ry + _rz < 1)
                {
                    s.cutVoxel(i,j,k);
                }
            }
        }
    }
}

