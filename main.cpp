#include <iostream>
#include <fstream>
#include <string>
#include "sculptor.h"
using namespace std;

int main()
{
    Sculptor lobo(40,60,40);
   //corpo
   lobo.setColor(79, 79, 79, 1);
   lobo.putBox(7, 13, 13, 18, 14, 30);
   lobo.putBox(6, 14, 12, 19, 10, 18);
   lobo.putBox(9, 11, 17, 18, 30, 36);
   // patas
   lobo.setColor(79, 79, 79, 1);
   lobo.putBox(11, 13, 7, 15, 27, 29);
   lobo.putBox(7, 9, 7, 15, 27, 29);
   lobo.putBox(7, 9, 7, 15, 13, 15);
   lobo.putBox(11, 13, 7, 15, 13, 15);
   lobo.cutBox(7, 9, 8, 10, 13, 15);
   lobo.cutBox(11, 13, 8, 10, 13, 15);
   lobo.cutBox(7, 9, 8, 10, 27, 29);
   lobo.cutBox(11, 13, 8, 10, 27, 29);
   lobo.setColor(168, 168, 168, 1);
   lobo.putBox(7, 9, 8, 10, 13, 15);
   lobo.putBox(11, 13, 8, 10, 13, 15);
   lobo.putBox(7, 9, 8, 10, 27, 29);
   lobo.putBox(11, 13, 8, 10, 27, 29);
  // cabeça
   lobo.setColor(79, 79, 79, 1);
   lobo.putBox(7, 13, 13, 19, 7, 10);
   lobo.putBox(8, 12, 13, 16, 4, 7);
   lobo.putBox(7, 9, 19, 21, 9, 10);
   lobo.putBox(11, 13, 19, 21, 9, 10);
   lobo.cutVoxel(7, 16, 7);
   lobo.cutVoxel(8, 17, 7);
   lobo.cutVoxel(11, 17, 7);
   lobo.cutVoxel(12, 16, 7);
   lobo.setColor(1, 1, 1, 1);
   lobo.putVoxel(7, 16, 7);
   lobo.putVoxel(8, 17, 7);
   lobo.putVoxel(11, 17, 7);
   lobo.putVoxel(12, 16, 7);
   //cores
   lobo.cutBox(8, 12, 13, 14, 4, 7);
   lobo.setColor(0, 0, 0, 9);
   lobo.putBox(8, 12, 13, 14, 4, 7);
   lobo.cutVoxel(8,16,7);
   lobo.cutVoxel(11,16,7);
   lobo.setColor(0, 0, 0, 9);
   lobo.putVoxel(8, 16, 7);
   lobo.putVoxel(11, 16, 7);
   lobo.cutBox(9, 11, 15, 16, 4, 5);
   lobo.setColor(0, 0, 0, 9);
   lobo.putBox(9, 11, 15, 16, 4, 5);
   lobo.cutBox(8, 12, 14, 15, 4, 5);
   lobo.setColor(0.82, 0.70, 0.55, 9);
   lobo.putBox(8, 12, 14, 15, 4, 5);
   lobo.cutVoxel(8,15,4);
   lobo.cutVoxel(11,15,4); 
   lobo.setColor(0.82, 0.70, 0.55, 9);
   lobo.putVoxel(8,15,4);
   lobo.putVoxel(11,15,4);
   lobo.cutBox(9, 11, 15, 16, 5, 7);
   lobo.setColor(0.80, 0.52, 0.24, 1);
   lobo.putBox(9, 11, 15, 16, 5, 7);
   lobo.cutBox(9, 11, 16, 17, 7, 8);
   lobo.setColor(0.54, 0.27, 0.07, 1);
   lobo.putBox(9, 11, 16, 17, 7, 8);
   lobo.cutBox(8, 9, 14, 16, 5, 7);
   lobo.cutBox(11, 12, 14, 16, 5, 7);
   lobo.setColor(1, 0.89, 0.71, 1);
   lobo.putBox(8, 9, 14, 16, 5, 7);
   lobo.putBox(11, 12, 14, 16, 5, 7);
   
   // grama e arvore
      lobo.setColor(0, 0.39, 0, 1);
      lobo.putBox(1, 40, 6, 7, 1, 40);
      lobo.setColor(0.545, 0.27, 0.074, 1);
      lobo.putBox(25, 30, 7, 20, 18, 23);
      lobo.setColor(0, 0.39, 0, 1);
      lobo.putBox(19, 36, 20, 26, 12, 29);
      lobo.putBox(23, 32, 26, 30, 16, 25);
      lobo.putBox(25, 30, 30, 32, 18, 23);

  // bulbasaur
   lobo.setColor(0.196, 0.80, 0.6, 1);
     lobo.putBox(25, 27, 32, 34, 18, 20);
     lobo.putBox(28, 30, 32, 34, 18, 20);
     lobo.putBox(25, 27, 32, 34, 21, 23);
     lobo.putBox(28, 30, 32, 34, 21, 23);
     lobo.putBox(25, 30, 33, 35, 18, 23);
     lobo.putBox(26, 29, 35, 36, 18, 19);
     lobo.putBox(25, 30, 33, 36, 17, 18);
     lobo.putVoxel(25,36,17);
     lobo.putVoxel(29,36,17);
   lobo.setColor(0.196, 0.803, 0.196, 1);
     lobo.putBox(25, 30, 35, 36, 19, 23);
     lobo.putBox(26, 29, 36, 37, 20, 23);
     lobo.cutVoxel(26,34,17);
     lobo.cutVoxel(28,34,17);
   lobo.setColor(0.545, 0, 0, 1);
     lobo.putVoxel(26,34,17);
     lobo.putVoxel(28,34,17);
     lobo.cutVoxel(26,35,17);
     lobo.cutVoxel(28,35,17);
   lobo.setColor(1, 1, 1, 1);
     lobo.putVoxel(26,35,17);
     lobo.putVoxel(28,35,17);
     lobo.cutVoxel(25,34,17);
     lobo.cutVoxel(29,34,17);
  lobo.setColor(1, 1, 1, 1);
     lobo.putVoxel(25,34,17);
     lobo.putVoxel(29,34,17);
     lobo.cutVoxel(27,36,20);
     lobo.cutVoxel(26,36,21);
     lobo.cutVoxel(27,36,22);
     lobo.cutVoxel(28,36,21);
  lobo.setColor(0, 0.39, 0, 1);
     lobo.putVoxel(27,36,20);
     lobo.putVoxel(26,36,21);
     lobo.putVoxel(27,36,22);
     lobo.putVoxel(28,36,21);


  
    lobo.writeOFF((char*)"lobo.off");
}
