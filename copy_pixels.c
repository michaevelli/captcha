//name: michael
//date: 20170410
//copy bounds to smaller array
//lab07 work

#include <stdio.h>
#include "captcha.h"

void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]){

    for(int i = 0; i < copy_height; i++){
        for(int j = 0; j < copy_width; j++){
            copy[i][j] = pixels[start_row+i][start_column+j];
        }
    }

}
