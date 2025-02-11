
#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect R1,Rect R2){
    Rect RAns;
    if((R1.x+R1.w) - R2.x > 0){
        RAns.x = R2.x;
        RAns.w = ((R1.x +R1.w) - R2.x);
        if((R1.x + R1.w) > (R2.x + R2.w)){
           RAns.x = R2.x;
           RAns.w = R2.w;
        }
    }
    else {
        RAns.x = 0;
        RAns.w = 0;
    }

    if(R2.y - (R1.y - R1.h) > 0 ){
        RAns.y = R1.y;
        RAns.h = R1.y - (R2.y - R2.h);
        if((R1.y - R1.h) < (R2.y - R2.h) && R1.y > R2.y){
           RAns.y = R2.y;
           RAns.h = R2.h;
        }
    }
    else {
        RAns.y = 0;
        RAns.h = 0;
    }
    return RAns.w*RAns.h;
}