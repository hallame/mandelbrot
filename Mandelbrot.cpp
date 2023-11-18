#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "graphics.h"

int main() {
    int num=50;
    int R=2;
    double sc =200;
    double stp = 400;

    int gd, gm;
    initgraph(&gd, &gm, "");

    for(int i=-getmaxx(); i<=getmaxx(); i++){ //цикл по различным x и y,
        for(int j=-getmaxy(); j<=getmaxy(); j++){// которые выводим с масштабом шаг которого меньше 1

            double x=i/sc; //после смотрим удовлетворяет ли комплексное число нашим условиям
            double y=j/sc;
            double zDey=0, zMnim=0;
            bool pruf=true; //цикл - проверка условий принадлежности числа к множеству
            for(int k=0; k<num; k++){ //чтобы понять удовлетворяет ли комплексное число условию, считаем отдельно мнимую часть считаем для z^2
                double zDey_2 = zDey*zDey - zMnim*zMnim; // считаем для z^2 действительную часть
                double zMnim_2 = zDey*zMnim + zDey*zMnim; // считаем для z^2 мнимую часть
                zDey = zDey_2+x;// прибавляем с
                zMnim = zMnim_2+y; // действительная часть для нового z
                double z_i = sqrt(pow(zDey,2)+pow(zMnim,2)); // считаем модуль z
                if(z_i>=R){// если число больше чем R, то число не подходит,
                    pruf=false;// последовательность расходится
                    break;} }
            if(pruf==true){
                putpixel(i+stp,j+stp, 9);}}}
    getch();
    closegraph();
}
