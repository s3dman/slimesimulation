#include <iostream>
#include <raylib.h>
#include "render.h"

const int RES = 500;
Color *pixels = (Color *)malloc(500*500*sizeof(Color));

uint hash_func(uint state){
    state ^= 2747636419u;
    state *= 2654435769u;
    state ^= state >> 16;
    state *= 2654435769u;
    state ^= state >> 16;
    state *= 2654435769u;
    return state;
    // max: 4294967295
}

float hash_scale(uint state){
    return state / 4294967295.0;
}

void TexPixDraw(int x,int y, Color col){
    pixels[y*RES+x] = col;
}

void DiffuseTexture(){
    float diffstrength = 3;
    for(int i=0;i<RES;++i){
        for(int j=0;j<RES;++j){
            if(pixels[i*RES+j].r>0){
                pixels[i*RES+j].r -= diffstrength;
                pixels[i*RES+j].g -= diffstrength;
                pixels[i*RES+j].b -= diffstrength;
            }
        }
    }
}