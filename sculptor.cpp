#include "sculptor.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <cmath>
int Nvertices = 0;
int Nfaces = 0;

Sculptor::Sculptor(int _nx, int _ny, int _nz) {

  nx = _nx;
  ny = _ny;
  nz = _nz;

  v = (Voxel ***)new Voxel [nx];
  v[0] = (Voxel **)new Voxel [nx * ny];
  v[0][0] = new Voxel[nx * ny * nz];

  for (int i = 1; i < nx; i++)
    v[i] = v[i - 1] + ny;

  for (int j = 1; j < nx * ny; j++)
    v[0][j] = v[0][j - 1] + nz;
}

Sculptor::~Sculptor() {
  delete[] v[0][0];
  delete[] v[0];
  delete v;
}

void Sculptor::setColor(float r, float g, float b, float a) {
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}

void Sculptor::putVoxel(int x, int y, int z) {
    if(v[x][y][z].show == 1){
          v[x][y][z].show = 0;
          Nvertices -= 8;
          Nfaces -= 6;

  }

    if((x >= 0 && x <= nx) && (y >= 0 && y <= ny) && (z >= 0 && z<=nz)){
          v[x][y][z].show = 1;
          v[x][y][z].r = r;
          v[x][y][z].g = g;
          v[x][y][z].b = b;
          Nvertices += 8;
          Nfaces += 6;
}


}
void Sculptor::writeOFF(const char *filename) {
    std::ofstream fout;
    fout.open(filename);
    int plus8 = 0;
    if(!fout.is_open()){
        std::cout << "arquivo não executado" << std::endl;
        exit(1);

    }else{
        std::cout << "Arquivo rodando" << std::endl;
        fout << "OFF" << std::endl;

        fout << Nvertices << " " << Nfaces << " " << 0 << std::endl;

        for(int i = 0; i < nx;i++)
            for(int j = 0; j < ny; j++)
                for(int k = 0; k < nz; k++){
                    if(v[i][j][k].show == 1){

                        fout << i+0.5 << ' ' << j+0.5 << ' ' << k+0.5 << std::endl;
                        fout << i+0.5 << ' ' << j+0.5 << ' ' << k-0.5 << std::endl;
                        fout << i+0.5 << ' ' << j-0.5 << ' ' << k+0.5 << std::endl;
                        fout << i+0.5 << ' ' << j-0.5 << ' ' << k-0.5 << std::endl;
                        fout << i-0.5 << ' ' << j+0.5 << ' ' << k+0.5 << std::endl;
                        fout << i-0.5 << ' ' << j+0.5 << ' ' << k-0.5 << std::endl;
                        fout << i-0.5 << ' ' << j-0.5 << ' ' << k+0.5 << std::endl;
                        fout << i-0.5 << ' ' << j-0.5 << ' ' << k-0.5 << std::endl;
                    }

                }


        for(int i = 0; i < nx;i++)
            for(int j = 0; j < ny; j++)
                for(int k = 0; k < nz; k++){
                    if(v[i][j][k].show == 1){

                        fout << 4 << ' '  << 0 + 8*plus8 << ' ' << 2 + 8*plus8 << ' '  << 3 + 8*plus8 << ' '  << 1 + 8*plus8
                        << ' ' << v[i][j][k].r << ' ' <<  v[i][j][k].g  << ' '<< v[i][j][k].b << ' '<< v[i][j][k].a << std::endl;

                        fout << 4 << ' '  << 0 + 8*plus8 << ' '  << 1 + 8*plus8 << ' '  << 5 + 8*plus8 << ' '  << 4 +  8*plus8
                        << ' ' << v[i][j][k].r << ' ' <<  v[i][j][k].g  << ' '<< v[i][j][k].b << ' '<< v[i][j][k].a << std::endl;

                        fout << 4 << ' '  << 0 + 8*plus8 << ' '  << 2 + 8*plus8 << ' '  << 6 + 8*plus8 << ' '  << 4 + 8*plus8
                        << ' ' << v[i][j][k].r << ' ' <<  v[i][j][k].g  << ' '<< v[i][j][k].b << ' '<< v[i][j][k].a << std::endl;

                        fout << 4 << ' '  << 7 + 8*plus8 << ' '  << 5 + 8*plus8 << ' '  << 1 + 8*plus8 << ' '  << 3 + 8*plus8
                        << ' ' << v[i][j][k].r << ' ' <<  v[i][j][k].g  << ' '<< v[i][j][k].b << ' '<< v[i][j][k].a << std::endl;

                        fout << 4 << ' '  << 7 + 8*plus8 << ' '  << 3 + 8*plus8 << ' '  << 2 + 8*plus8 << ' '  << 6 + 8*plus8
                        << ' ' << v[i][j][k].r << ' ' <<  v[i][j][k].g  << ' '<< v[i][j][k].b << ' '<< v[i][j][k].a << std::endl;

                        fout << 4 << ' '  << 7 + 8*plus8 << ' '  << 6 + 8*plus8 << ' '  << 4 + 8*plus8 << ' '  << 5 + 8*plus8
                        << ' ' << v[i][j][k].r << ' ' <<  v[i][j][k].g  << ' '<< v[i][j][k].b << ' '<< v[i][j][k].a << std::endl;

                        plus8 +=1;
                 }
           }

    }

    std::cout << "Fechando fluxo" << std::endl;
    fout.close();
}

void Sculptor::cutVoxel(int x, int y, int z){
    if(((x >= 0 && x <= nx) && (y >= 0 && y <= ny) && (z >= 0 && z<=nz)) &&v[x][y][z].show == 1){
        v[x][y][z].show = 0;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
        Nvertices -=8;
        Nfaces -=6;
    }
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){

    if((x0 >= 0 && x1<= nx) && (y0 >= 0 && y1<=ny) && (z0 >= 0 && z1<=nz)){
        for(int i = x0; i < x1; i++)
            for(int j = y0; j < y1; j++)
                for(int k = z0; k < z1; k++){
                    putVoxel(i,j,k);


                }
    }

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){

    if((x0 >= 0 && x1<= nx) && (y0 >= 0 && y1<=ny) && (z0 >= 0 && z1<=nz)){
        for(int i = x0; i < x1; i++)
            for(int j = y0; j < y1; j++)
                for(int k = z0; k < z1; k++){
                    cutVoxel(i,j,k);


                }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){

    // equação (x - x0)^2 + (y - y0)^2 + (z - z0)^2 = r^2

    for(int i =0; i < nx; i++)
        for(int j = 0; j < ny; j++)
            for(int k = 0; k < nz; k++)
                if( (float)(std::pow(i - xcenter,2) + std::pow(j - ycenter,2) + std::pow(k - zcenter,2)) <= (float)std::pow(radius,2)   )
                       putVoxel(i,j,k);


}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){

    for(int i =0; i < nx; i++)
        for(int j = 0; j < ny; j++)
            for(int k = 0; k < nz; k++)
                if( (float)(std::pow(i - xcenter,2) + std::pow(j - ycenter,2) + std::pow(k - zcenter,2)) <= (float)std::pow(radius,2)   )
                       cutVoxel(i,j,k);


}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){


    for(int i = 0; i < nx; i++)
        for(int j = 0; j < ny; j++)
            for(int k = 0; k < nz; k++)
                if(std::pow(i - xcenter,2)/std::pow(rx,2) + std::pow(j - ycenter,2)/std::pow(ry,2) + std::pow(k - zcenter,2)/std::pow(rz,2) <= 1)
                    putVoxel(i,j,k);


}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){

    for(int i = 0; i < nx; i++)
        for(int j = 0; j < ny; j++)
            for(int k = 0; k < nz; k++)
                if(std::pow(i - xcenter,2)/std::pow(rx,2) + std::pow(j - ycenter,2)/std::pow(ry,2) + std::pow(k - zcenter,2)/std::pow(rz,2) <= 1)
                    cutVoxel(i,j,k);

}
