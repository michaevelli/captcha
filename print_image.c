//name: michael
//date: 20170410
//print pbm
//lab07 work

#include <stdio.h>
#include "captcha.h"

void print_image(int height, int width, int pixels[height][width]){

    for(int i = height-1; i >= 0; i--){
        for(int j = 0; j < width; j++){
            if(pixels[i][j] == 1){
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

}
