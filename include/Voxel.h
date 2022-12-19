#ifndef VOXEL_H
#define VOXEL_H

struct Voxel
{
    float r,g,b; // Cores (r = red, g = green, b = blue).
    float a; // Transparencia
    bool show; // Incluido ou nao (ativacao do voxel)
};

#endif // VOXEL_H
