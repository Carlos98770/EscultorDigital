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



    Sculptor teste(350,350,350);

    //eixo de coordenadas
    teste.setColor(1,0,0,1);
    teste.putBox(0,300,0,1,0,1);
    teste.setColor(0,1,0,1);
    teste.putBox(0,1,0,300,0,1);
    teste.setColor(0,0,1,1);
    teste.putBox(0,1,0,1,0,300);

    teste.setColor(135/255.0,206/255.0,250/255.0,1);
    teste.putBox(0,300,299,300,0,300);
    teste.putBox(0,1,0,300,0,300);

    teste.setColor(1,1,1,1);

    teste.putBox(80,180,299,300,150,170);
    teste.putBox(100,160,299,300,170,180);
    teste.putBox(120,140,299,300,180,200);



    teste.putBox(1,2,60,160,190,210);
    teste.putBox(1,2,80,140,210,220);
    teste.putBox(1,2,100,120,220,240);

    teste.putBox(1,2,180,280,140,160);
    teste.putBox(1,2,200,260,160,170);
    teste.putBox(1,2,220,240,170,190);

    //desenho
    //terreno
    teste.setColor(50/255.0,205/255.0,50/255.0,1);
    teste.putBox(0,300,0,300,0,1);

    //corpo
    teste.setColor(30/255,144/255.0,1,1);
    teste.putBox(50,70,50,120,50,140);
    teste.cutBox(51,69,51,119,51,139);

    //cabeça
    teste.setColor(244/255.0,164/255.0,96/255.0,1);
    teste.putBox(40,80,50,120,140,200);
    teste.cutBox(41,79,51,119,141,199);

    //boca
    teste.setColor(139/255.0,69/255.0,19/255.0,1);
    teste.putBox(79,80,60,112,140,150);
    teste.putBox(79,80,60,73,150,158);
    teste.putBox(79,80,99,112,150,158);
    teste.setColor(0,0,0,1);
    teste.putBox(79,80,60,112,148,150);
    teste.putBox(79,80,60,112,140,142);
    teste.putBox(79,80,60,62,140,150);
    //teste.putBox(79,80,73,75,140,150);
    //teste.putBox(79,80,86,88,140,150);
    //teste.putBox(79,80,99,101,140,150);
    teste.putBox(79,80,110,112,140,150);
    teste.setColor(139/255.0,69/255.0,19/255.0,1);
    teste.putBox(79,80,60,73,148,150);
    teste.putBox(79,80,99,113,148,150);
    teste.setColor(0,0,0,1);
    teste.putBox(79,80,60,62,150,158);
    teste.putBox(79,80,60,73,156,158);
    teste.putBox(79,80,71,73,150,158);
    teste.putBox(79,80,99,101,150,158);
    teste.putBox(79,80,99,112,156,158);
    teste.putBox(79,80,110,112,150,158);

    //nariz
    teste.setColor(160/255.0,82/255.0,45/255.0,1);
    teste.putBox(79,80,73,99,156,165);
    teste.setColor(0,0,0,1);
    teste.putBox(79,80,73,75,156,165);
    teste.putBox(79,80,97,99,156,165);
    teste.putBox(79,80,73,99,156,158);
    teste.putBox(79,80,73,99,163,165);
    teste.putBox(79,80,85,87,156,165);

    //olhos
    teste.setColor(1,1,1,1);
    teste.putBox(79,80,58,78,165,175);
    teste.putBox(79,80,94,114,165,175);
    teste.setColor(0,0,1,1);
    teste.putBox(79,80,70,78,165,175);
    teste.putBox(79,80,94,103,165,175);
    teste.setColor(0,0,0,1);
    teste.putBox(79,80,58,60,165,175);
    teste.putBox(79,80,76,78,165,175);
    teste.putBox(79,80,58,78,165,167);
    teste.putBox(79,80,58,78,173,175);
    teste.putBox(79,80,94,96,165,175);
    teste.putBox(79,80,112,114,165,175);
    teste.putBox(79,80,94,114,165,167);
    teste.putBox(79,80,94,114,173,175);

    //cabelo
    teste.setColor(160/255.0,82/255.0,45/255.0,1);
    teste.putBox(79,80,50,120,180,200);
    teste.putBox(40,80,50,120,199,200);
    teste.putBox(40,41,50,120,140,200);
    teste.putBox(40,80,49,50,140,200);
    teste.putBox(40,80,119,120,140,200);
    teste.setColor(244/255.0,164/255.0,96/255.0,1);
    teste.putBox(79,80,60,110,180,190);
    teste.putBox(60,80,49,50,140,170);
    teste.putBox(50,60,49,50,140,170);
    teste.putBox(60,80,119,120,140,170);
    teste.putBox(50,60,119,120,140,170);

    //pernas
    teste.setColor(65/255.0,105/255.0,225/255.0,1);
    diagonalY(teste,50,70,95,120,0,50,0);
    diagonalY(teste,50,70,50,75,0,50,1);

    //braços
     teste.setColor(244/255.0,164/255.0,96/255.0,1);
     diagonalY(teste,50,70,25,50,90,140,0);
     diagonalY(teste,50,70,120,145,90,140,1);
     teste.setColor(30/255,144/255.0,1,1);
     diagonalY(teste,50,70,25,50,120,140,0);
     diagonalY(teste,50,70,120,145,120,140,1);

     //bau
     teste.setColor(184/255.0,134/255.0,11/255.0,1);
     teste.putBox(190,300,190,300,0,100);
     teste.cutBox(191,298,191,298,1,98);
     teste.setColor(0,0,0,1);

     teste.putBox(295,300,295,300,0,100);
     teste.putBox(295,300,190,195,0,100);
     teste.putBox(295,300,190,300,0,5);
     teste.putBox(295,300,190,300,95,100);
     teste.putBox(190,195,190,300,95,100);
     teste.putBox(190,195,190,300,0,5);
     teste.putBox(190,300,190,195,95,100);
     teste.putBox(190,300,295,300,95,100);
     teste.putBox(190,195,295,300,0,100);
     teste.putBox(190,195,190,195,0,100);
     teste.putBox(190,300,190,195,0,5);
     teste.putBox(190,300,295,300,0,5);
     teste.putBox(190,300,190,195,70,80);
     teste.putBox(190,195,190,300,70,80);
     teste.putBox(190,300,190,195,70,80);
     teste.putBox(190,195,190,195,70,80);
     teste.setColor(1,1,1,1);
     teste.putBox(235,255,180,190,65,90);




    teste.writeOFF("/home/eduardo/Documentos/Desenhos/Boneco.off");
    return 0;
}

