#include <iostream>
#include "sculptor.h"
#include <cmath>
void diagonalX(Sculptor &teste, int x0,int x1,int y0,int y1,int z0, int z1){
    int k =0;
    for(int i =z0; i < z1; i++){
        teste.putBox(x0,x1,y0+k,y1+k,i,i+1);
        k++;
    }

}
void diagonalY(Sculptor &teste, int x0,int x1,int y0,int y1,int z0, int z1,int sentido){
    int k =0;
    if(sentido){
        for(int i = z1; i > z0; i--){
            teste.putBox(x0+k,x1+k,y0,y1,i-1,i);
            k++;

         }
    }
    else{

        for(int i = z1; i > z0; i--){
            teste.putBox(x0-k,x1-k,y0,y1,i-1,i);
            k++;

         }

    }
}




int main(void){
    Sculptor teste(150,150,150);

    teste.setColor(135/255.0,206/255.0,250/255.0,1);
    teste.putBox(0,150,149,150,0,150);
    teste.putBox(0,1,0,150,0,150);

    teste.setColor(1,1,1,1);
    teste.putBox(40,90,149,150,75,85);
    teste.putBox(50,80,149,150,85,90);
    teste.putBox(60,70,149,150,90,100);
    teste.putBox(1,2,30,80,95,105);
    teste.putBox(1,2,40,70,105,110);
    teste.putBox(1,2,50,60,110,120);
    teste.putBox(1,2,90,140,70,80);
    teste.putBox(1,2,100,130,80,85);
    teste.putBox(1,2,110,120,85,95);

    teste.setColor(50/255.0,205/255.0,50/255.0,1);
    teste.putBox(0,150,0,150,0,1);

    teste.setColor(30/255,144/255.0,1,1);
    teste.putBox(25,35,25,60,25,70);
    teste.cutBox(26,34,26,59,26,69);

    teste.setColor(244/255.0,164/255.0,96/255.0,1);
    teste.putBox(20,40,25,60,70,100);
    teste.cutBox(21,39,26,59,71,99);


    teste.setColor(139/255.0,69/255.0,19/255.0,1);
    teste.putBox(39,40,30,56,70,75);
    teste.putBox(39,40,30,36,75,79);
    teste.putBox(39,40,49,56,75,79);

    teste.setColor(0,0,0,1);
    teste.putBox(39,40,30,56,74,75);
    teste.putBox(39,40,30,56,70,71);
    teste.putBox(39,40,30,31,70,75);
    teste.putBox(39,40,55,56,70,75);

    teste.setColor(139/255.0,69/255.0,19/255.0,1);
    teste.putBox(39,40,30,36,74,75);
    teste.putBox(39,40,49,56,74,75);

    teste.setColor(0,0,0,1);
    teste.putBox(39,40,30,31,75,79);
    teste.putBox(39,40,30,36,78,79);
    teste.putBox(39,40,35,37,75,79);
    teste.putBox(39,40,49,51,75,79);
    teste.putBox(39,40,55,56,78,79);
    teste.putBox(39,40,55,56,75,79);


    teste.setColor(160/255.0,82/255.0,45/255.0,1);
    teste.putBox(39,40,36,49,78,81);

    teste.setColor(0,0,0,1);
    teste.putBox(39,40,36,38,78,81);
    teste.putBox(39,40,48,50,78,81);
    teste.putBox(39,40,36,49,78,71);
    teste.putBox(39,40,36,49,81,83);
    teste.putBox(39,40,42,44,78,81);


    teste.setColor(1,1,1,1);
    teste.putBox(39,40,29,39,82,87);
    teste.putBox(39,40,47,57,82,87);

    teste.setColor(0,0,1,1);
    teste.putBox(39,40,35,39,82,87);
    teste.putBox(39,40,47,51,82,87);


    teste.setColor(0,0,0,1);
    teste.putBox(39,40,29,30,82,87);
    teste.putBox(39,40,38,39,82,87);
    teste.putBox(39,40,29,39,82,84);
    teste.putBox(39,40,29,39,86,88);
    teste.putBox(39,40,47,48,82,87);
    teste.putBox(39,40,56,57,82,87);
    teste.putBox(39,40,47,57,82,84);
    teste.putBox(39,40,47,57,86,88);



    teste.setColor(160/255.0,82/255.0,45/255.0,1);
    teste.putBox(39,40,25,60,90,100);
    teste.putBox(20,40,25,60,98,100);
    teste.putBox(20,21,25,60,70,100);
    teste.putBox(20,40,23,25,70,100);
    teste.putBox(20,40,58,60,70,100);

    teste.setColor(244/255.0,164/255.0,96/255.0,1);
    teste.putBox(39,40,30,55,90,95);
    teste.putBox(30,40,23,25,70,85);
    teste.putBox(25,30,23,25,70,85);
    teste.putBox(30,40,58,60,70,85);
    teste.putBox(25,30,58,60,70,85);

    teste.setColor(65/255.0,105/255.0,225/255.0,1);
    diagonalY(teste,25,35,47,60,0,25,0);
    diagonalY(teste,25,35,25,37,0,25,1);

    teste.setColor(244/255.0,164/255.0,96/255.0,1);
    diagonalY(teste,25,35,12,25,45,70,0);
    diagonalY(teste,25,35,60,72,45,70,1);

    teste.setColor(30/255,144/255.0,1,1);
    diagonalY(teste,25,35,12,25,60,70,0);
    diagonalY(teste,25,35,60,72,60,70,1);


    //bau
    teste.setColor(184/255.0,134/255.0,11/255.0,1);
    teste.putBox(95,150,95,150,0,50);
    teste.cutBox(96,149,96,149,1,49);

    teste.setColor(0,0,0,1);
    teste.putBox(147,150,147,150,0,50);
    teste.putBox(147,150,95,97,0,50);
    teste.putBox(147,150,95,150,0,3);
    teste.putBox(147,150,95,150,47,50);
    teste.putBox(95,97,95,150,47,50);
    teste.putBox(95,97,95,150,0,3);
    teste.putBox(95,150,95,97,47,50);
    teste.putBox(95,150,147,150,47,50);
    teste.putBox(95,97,147,150,0,50);
    teste.putBox(95,97,95,97,0,50);
    teste.putBox(95,150,95,97,0,3);
    teste.putBox(95,150,147,150,0,3);
    teste.putBox(95,150,95,97,35,40);
    teste.putBox(95,97,95,150,35,40);
    teste.putBox(95,150,95,97,35,40);
    teste.putBox(95,97,95,97,35,40);

    teste.setColor(1,1,1,1);
    teste.putBox(117,127,90,95,32,45);

    teste.writeOFF("/home/eduardo/Documentos/Desenhos/Bonequin2.off");
    return 0;
}
