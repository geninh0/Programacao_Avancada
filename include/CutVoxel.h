#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include <FiguraGeometrica.h>


class CutVoxel : public FiguraGeometrica
{
    public:
        int x, y, z;
        CutVoxel(int x, int y, int z);
        void draw(Sculptor &s);
};

#endif // CUTVOXEL_H
