//name: michael
//date: 20170410
//find bounding box
//lab07 work

#include <stdio.h>
#include "captcha.h"

void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width){

    //Code in this function is written by Andrew Taylor
    int min_row = height - 1;
    int max_row = 0;
    int min_column = width - 1;
    int max_column = 0;
    for (int row = 0; row < height; row++) {
        for (int column = 0; column < width; column++) {
            if (pixels[row][column] == 1) {
                if (row < min_row) {
                    min_row = row;
                }
                if (row > max_row) {
                    max_row = row;
                }
                if (column < min_column) {
                    min_column = column;
                }
                if (column > max_column) {
                    max_column = column;
                }
            }
        }
    }
    if (min_row <= max_row) {
        *start_row = min_row;
        *box_height = max_row -  min_row + 1;
        *start_column = min_column;
        *box_width = max_column -  min_column + 1;
    } else {
        // no black pixels in image
        *start_row = 0;
        *box_height = 0;
        *start_column = 0;
        *box_width = 0;
    }


}

//get the bounding box for the hole in the image. called only to find the tallness of the hole
void hole_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width){
    //bottom border
    int end = 0;
    for(int i = 0; i < height && end == 0; i++){
        for(int j = 0; j < width && end == 0; j++){
            if(pixels[i][j] == 0){
                *start_row = i;
                end = 1;
            }
        }
    }

    //left border
    end = 0;
    for(int i = 0; i < width && end == 0; i++){
        for(int j = 0; j < height && end == 0; j++){
            if(pixels[j][i] == 0){
                *start_column = i;
                end = 1;
            }
        }
    }

    //top border
    end = 0;
    for(int i = height-1; i >= 0 && end == 0; i--){
        for(int j = 0; j < width && end == 0; j++){
            if(pixels[i][j] == 0){
                *box_height = i - *start_row + 1;
                end = 1;
            }
        }
    }

    //right border
    end = 0;
    for(int i = width-1; i >= 0 && end == 0; i--){
        for(int j = 0; j < height && end == 0; j++){
            if(pixels[j][i] == 0){
                *box_width = i - *start_column + 1;
                end = 1;
            }
        }
    }

}