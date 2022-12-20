#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "FiguraGeometrica.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "sculptor.h"


int main()
{
    Sculptor *s;
    //FiguraGeometrica *fig[100];
    std::vector <FiguraGeometrica*> fig;
    std::ifstream fin;
    std::string str;
    int nx, ny, nz;
    int xcenter, ycenter, zcenter, radius, rx, ry, rz;
    int x0, x1, y0, y1, z0, z1, x, y, z;
    float r, g, b, a;

    fin.open("semaforo.txt");

    if(!fin.is_open()){
        std::exit(0);
    } else{
        std::cout << "Arquivo aberto para leitura!\n";
    }

    while(fin.good()){
        fin >> str;

        if(!fin.good()){
            break;
        }
        std::cout << "str = " << str << std::endl;
        if(str.compare("dim") == 0){

            fin >> nx >> ny >> nz;
            s = new Sculptor(nx,ny,nz);

        } else if(str.compare("putvoxel") == 0){

            fin >> x >> y >> z >> r >> g >> b >> a;
            fig.push_back(new PutVoxel(x,y,z,r,g,b,a));

        } else if(str.compare("cutvoxel") == 0){

            fin >> x >> y >> z;
            fig.push_back(new CutVoxel(x,y,z));

        } else if(str.compare("putbox") == 0){

            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            fig.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));

        } else if(str.compare("cutbox") == 0){

            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            fig.push_back(new CutBox(x0,x1,y0,y1,z0,z1));

        } else if(str.compare("putsphere") == 0){

            fin >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            fig.push_back(new PutSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));

        } else if(str.compare("cutsphere") == 0){

            fin >> xcenter >> ycenter >> zcenter >> radius;
            fig.push_back(new CutSphere(xcenter,ycenter,zcenter,radius));

        } else if(str.compare("putellipsoid") == 0){

            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            fig.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));

        } else if(str.compare("cutellipsoid") == 0){

            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            fig.push_back(new CutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));

        }
    }

    for(size_t i = 0; i < fig.size(); i++){
        std::cout << "passou " << i << "\n";
        fig[i] -> draw(*s);
    }

    for(size_t i = 0; i < fig.size(); i++){
        delete fig[i];
    }

    s -> writeOFF("semaforo.off");

    return 0;
}
