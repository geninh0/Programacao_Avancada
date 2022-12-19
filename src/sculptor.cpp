#include "Sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "FiguraGeometrica.h"
#include "Voxel.h"

// CONSTRUTOR
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx;
    ny = _ny;
    nz = _nz;
    r = g = b = 0.5;
    a = 1;

    //ALOCACAO DINAMICA
    v = new Voxel * *[nx];
    for (int x = 0; x < nx; x++)
    {
        v[x] = new Voxel * [ny];
        for (int y = 0; y < ny; y++)
        {
            v[x][y] = new Voxel[nz];
        }
    }

    //INICIALIZAR OS PARAMETROS
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                v[x][y][z].show = false;
                v[x][y][z].r = r;
                v[x][y][z].g = g;
                v[x][y][z].b = b;
                v[x][y][z].a = a;
            }
        }
    }
}

// DESTRUTOR
Sculptor::~Sculptor()
{

    //LIBERACAO
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            delete[] v[x][y];
        }
    }
    for (int x = 0; x < nx; x++)
    {
        delete[] v[x];
    }
    delete[] v;
    nx = ny = nz = 0;
}

// DEFINE A COR DO VOXEL
void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = alpha;
}


// INSERIR VOXEL
void Sculptor::putVoxel(int x, int y, int z)
{
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
    v[x][y][z].show = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    }
}
// REMOVER VOXEL
void Sculptor::cutVoxel(int x, int y, int z)
{
    if(x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz){
      v[x][y][z].show = false;
    }
}


// INSERIR BOX DE VOXEL
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i < x1; i++)
    {
        for (int j = y0; j < y1; j++)
        {
            for (int k = z0; k < z1; k++)
            {
                v[i][j][k].show = true;
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
            }
        }
    }
}
// REMOVER BOX DE VOXEL
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i < x1; i++)
    {
        for (int j = y0; j < y1; j++)
        {
            for (int k = z0; k < z1; k++)
            {
                v[i][j][k].show = false;
            }
        }
    }
}

// INSERIR ELLIPSOID DE VOXEL
void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    double _rx, _ry, _rz;

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                _rx = (double)(i - xcenter) * (double)(i - xcenter) / (rx * rx);
                _ry = (double)(j - ycenter) * (double)(j - ycenter) / (ry * ry);
                _rz = (double)(k - zcenter) * (double)(k - zcenter) / (rz * rz);

                if (_rx + _ry + _rz < 1)
                {
                    v[i][j][k].show = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}
// REMOVER ELLIPSOID DE VOXEL
void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    double _rx, _ry, _rz;

    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                _rx = (double)(i - xcenter) * (double)(i - xcenter) / (rx * rx);
                _ry = (double)(j - ycenter) * (double)(j - ycenter) / (ry * ry);
                _rz = (double)(k - zcenter) * (double)(k - zcenter) / (rz * rz);

                if (_rx + _ry + _rz < 1)
                {
                    v[i][j][k].show = false;
                }
            }
        }
    }
}

// INSERIR SPHERE DE VOXEL
void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    double rx, ry, rz, raio;

    raio = (double)radius * (double)radius;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                rx = (double)(i - xcenter) * (double)(i - xcenter);
                ry = (double)(j - ycenter) * (double)(j - ycenter);
                rz = (double)(k - zcenter) * (double)(k - zcenter);

                if (rx + ry + rz < raio)
                {
                    v[i][j][k].show = true;
                    v[i][j][k].r = r;
                    v[i][j][k].g = g;
                    v[i][j][k].b = b;
                    v[i][j][k].a = a;
                }
            }
        }
    }
}
// REMOVER SPHERE DE VOXEL
void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    double rx, ry, rz, raio;

    raio = (double)radius * (double)radius;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            for (int k = 0; k < nz; k++)
            {
                rx = (double)(i - xcenter) * (double)(i - xcenter);
                ry = (double)(j - ycenter) * (double)(j - ycenter);
                rz = (double)(k - zcenter) * (double)(k - zcenter);

                if (rx + ry + rz < raio)
                {
                    v[i][j][k].show = false;
                }
            }
        }
    }
}


// GERACAO DO ARQUIVO .OFF
void Sculptor::writeOFF(const char* filename)
{
    int voxels_on, ponto;
    std::ofstream arquivo;
    voxels_on = 0;
    arquivo.open(filename);

    if (arquivo.is_open())
    {
        std::cout << "Arquivo aberto para escrita!\n";
    }
    else
    {
        std::cout << "FALHA\n";
    }
    arquivo << "OFF\n";
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                if (v[x][y][z].show == true)
                {
                    voxels_on++;
                }
            }
        }
    }
    arquivo << voxels_on * 8 << " " << voxels_on * 6 << " 0 " << "\n";
    float lado = 0.5;

    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                if (v[x][y][z].show == true)
                {
                    arquivo << x - lado << " " << y + lado << " " << z - lado << "\n";
                    arquivo << x - lado << " " << y - lado << " " << z - lado << "\n";
                    arquivo << x + lado << " " << y - lado << " " << z - lado << "\n";
                    arquivo << x + lado << " " << y + lado << " " << z - lado << "\n";
                    arquivo << x - lado << " " << y + lado << " " << z + lado << "\n";
                    arquivo << x - lado << " " << y - lado << " " << z + lado << "\n";
                    arquivo << x + lado << " " << y - lado << " " << z + lado << "\n";
                    arquivo << x + lado << " " << y + lado << " " << z + lado << "\n";
                }
            }
        }
    }

    voxels_on = 0;
    for (int x = 0; x < nx; x++)
    {
        for (int y = 0; y < ny; y++)
        {
            for (int z = 0; z < nz; z++)
            {
                if (v[x][y][z].show == true)
                {
                    ponto = voxels_on * 8;
                    arquivo << std::fixed;

                    arquivo << 4 << " " << ponto + 0 << " " << ponto + 3 << " " << ponto + 2 << " " << ponto + 1 << " ";
                    arquivo << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " << std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].a << "\n" << std::flush;
                    arquivo << 4 << " " << ponto + 4 << " " << ponto + 5 << " " << ponto + 6 << " " << ponto + 7 << " ";
                    arquivo << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " << std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].a << "\n" << std::flush;
                    arquivo << 4 << " " << ponto + 0 << " " << ponto + 1 << " " << ponto + 5 << " " << ponto + 4 << " ";
                    arquivo << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " << std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].a << "\n" << std::flush;
                    arquivo << 4 << " " << ponto + 0 << " " << ponto + 4 << " " << ponto + 7 << " " << ponto + 3 << " ";
                    arquivo << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " << std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].a << "\n" << std::flush;
                    arquivo << 4 << " " << ponto + 7 << " " << ponto + 6 << " " << ponto + 2 << " " << ponto + 3 << " ";
                    arquivo << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " << std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].a << "\n" << std::flush;
                    arquivo << 4 << " " << ponto + 1 << " " << ponto + 2 << " " << ponto + 6 << " " << ponto + 5 << " ";
                    arquivo << std::setprecision(2) << v[x][y][z].r << " " << std::setprecision(2) << v[x][y][z].g << " " << std::setprecision(2) << v[x][y][z].b << " " << std::setprecision(2) << v[x][y][z].a << "\n" << std::flush;

                    voxels_on++;
                }
            }
        }
    }
    arquivo.close();
}
