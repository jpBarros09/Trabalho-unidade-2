#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

Sculptor::Sculptor(int nx, int ny, int nz){
    this->nx = nx;
    this->ny = ny;
    this->nz = nz;
    fix = 0.5;
    r = 0.5;
    g = 0.5; 
    b = 0.5;
    a = 0.5;

    v = new Voxel**[nx];
     for (int i =0; i<nx; i++){
      v[i] = new Voxel*[ny];

     for (int j =0; j<ny; j++){
       v[i][j]= new Voxel[nz];
      }
    }
}
Sculptor::~Sculptor(){
    for(int i = 0; i < nx; i++){
        for (int j = 0; j < ny; j++){
               delete[] v[i][j];
            }
        }
        for (int i=0; i <nx; i++){
            delete[] v[i];
        }

        delete[] v;

        nx = 0;
        ny = 0;
        nz = 0;}
void Sculptor::putVoxel(int x, int y, int z){
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;    

}

void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].isOn = false;
}
void Sculptor::setColor(float r, float g, float b, float alpha) // define a cor e transparĂȘncia de cada voxel
{
    this-> r = r;
    this-> g = g;
    this-> b = b;
    a = alpha;
}
void  Sculptor::putBox ( int x0_, int x1_, int y0_, int y1_, int z0_, int z1_){
    for ( int x = x0_; x<x1_; x++){
       for ( int y = y0_; y<y1_; y++){
           for ( int z = z0_; z<z1_; z++){
               v[x][y][z]. isOn = true ;
               v[x][y][z]. r = r;
               v[x][y][z]. g = g;
               v[x][y][z]. b = b;
               v[x][y][z]. a = a;
           }
       }
    }
    
}

void  Sculptor::cutBox ( int x0, int x1, int y0, int y1, int z0, int z1)
{
    for ( int x = x0; x<x1; x++){
       for ( int y = y0 ; y< y1 ; y++){
           for ( int z = z0; z<z1; z++){
               v[x][y][z]. isOn = false ;
           }
       }
    }
}

void  Sculptor::putSphere ( int xcenter, int ycenter, int zcenter, int radius){
  for ( int i = -radius; i<=radius; i++){
      for ( int j = -radius; j<=radius; j++){
          for ( int k = -radius; k<=radius; k++){
         
            if ((i*i+j*j+k*k) < radius*radius){
              putVoxel (i+xcenter,j+ycenter,k+zcenter);
            }
          }
      }
  }

}

void  Sculptor::cutSphere ( int xcenter, int ycenter, int zcenter, int radius){
  for ( int i = -radius; i<radius; i++){
      for ( int j = -radius; j<radius; j++){
          for ( int k = -radius; k<radius; k++){
            if ((i*i+j*j+k*k) < radius*radius){
              cutVoxel (i+xcenter,j+ycenter,k+zcenter);
            }
          }
      }
  }
}

void  Sculptor::putEllipsoid ( int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
   float newx, newy, newz;

    for ( int x = 0 ; x < nx; x++){
        for ( int y = 0 ; y < ny; y++){
            for ( int z = 0 ; z < nz; z++){
            newx = (( float )(x-xcenter)*( float )(x-xcenter))/(rx * rx);
            newy = (( float )(y-ycenter)*( float )(y-ycenter))/(ry * ry);
            newz = (( float )(z-zcenter)*( float )(z-zcenter))/(rz * rz);

            if ((newx + newy + newz) < 1 ){
                putVoxel (x,y,z);
            }
            }
        }
    }
}

void  Sculptor::cutEllipsoid ( int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
   double newx, newy, newz;

    for ( int x = 0 ; x < nx; x++){
        for ( int y = 0 ; y < ny; y++){
            for ( int z = 0 ; z < nz; z++){
            newx = (( float )(x-xcenter)*( float )(x-xcenter))/(rx * rx);
            newy = (( float )(y-ycenter)*( float )(y-ycenter))/(ry * ry);
            newz = (( float )(z-zcenter)*( float )(z-zcenter))/(rz * rz);

            if ((newx + newy + newz) < 1 ){
                cutVoxel (x,y,z);
            }
            }
        }
    }
}
void Sculptor::writeOFF(char *filename){

  std::ofstream f;
  
  f.open(filename);
  if(!f.is_open()){
    exit(1);
  }
  
  int quantvox=0;
  int ref;
  f << "OFF\n";
  
 for (int i = 0; i < nx; i++){
      for (int j = 0; j <ny; j++){
           for (int k = 0; k <nz; k++){
                if(v[i][j][k].isOn == true){
                quantvox++;
                }
           }
       }
  }
   f<<quantvox * 8<<" "<<quantvox * 6 << " " << "0" << "\n";

  for (int a = 0; a < nx; a++){
      for (int b = 0; b < ny; b++){
           for (int c = 0; c < nz; c++){
                if(v[a][b][c].isOn == true){
                f << a - fix << " " << b + fix << " " << c - fix << "\n" << flush;
                  
                f << a - fix << " " << b - fix << " " << c - fix << "\n" << flush;
                  
                f << a + fix << " " << b - fix << " " << c - fix << "\n" << flush;
                  
                f << a + fix << " " << b + fix << " " << c - fix << "\n" << flush;
                  
                f << a - fix << " " << b + fix << " " << c + fix << "\n" << flush;
                  
                f << a - fix << " " << b - fix << " " << c + fix << "\n" << flush;
                  
                f << a + fix << " " << b - fix << " " << c + fix << "\n" << flush;
                  
                f << a + fix << " " << b + fix << " " << c + fix << "\n" << flush;
                }
           }
      }
  }

  quantvox = 0;

  
  for (int a= 0; a<nx; a++){
      for (int b = 0; b<ny; b++){
           for (int c= 0; c<nz; c++){
                if(v[a][b][c].isOn == true){
                ref = quantvox * 8;
                f << fixed; 
                f << "4" << " " << 0+ref << " " << 3+ref << " " << 2+ref << " " << 1+ref << " ";
                f << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

               f << "4" << " " << 4+ref << " " << 5+ref << " " << 6+ref << " " << 7+ref << " ";
                f << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                f << "4" << " " << 0+ref << " " << 1+ref << " " << 5+ref << " " << 4+ref << " ";
                f << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                f << "4" << " " << 0+ref << " " << 4+ref << " " << 7+ref << " " << 3+ref << " ";
                f << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                f << "4" << " " << 3+ref << " " << 7+ref << " " << 6+ref << " " << 2+ref << " ";
                f << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                f << "4" << " " << 1+ref << " " << 2+ref << " " << 6+ref << " " << 5+ref << " ";
                f << setprecision(2)<<v[a][b][c].r << " " << setprecision(2)<<v[a][b][c].g <<" " << setprecision(2)<<v[a][b][c].b << " " << setprecision(2) << v[a][b][c].a << "\n";

                quantvox = quantvox + 1;
                }
           }
       }
  }
  f.close();
} 


