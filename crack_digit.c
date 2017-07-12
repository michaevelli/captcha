//name: michael
//date: 20170420
//crack digit

#include <stdio.h>
#include "captcha.h"
#include <stdlib.h>
#include <math.h>

#define DIGITS 10
#define ATTRIB 21
#define ZSCMAX 4.2


//a wrapper for crack digit given the bounding box array.
//This is for convienience as it can simply be called 4 times for captchas
int main(int argc, char *argv[]) {
    int height, width, start_row, start_column, box_width, box_height, hole, holeheight, holewidth;
    double hBal, vBal, tall, dens, hDen/*, vert*/;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        return 1;
    }

    if (get_pbm_dimensions(argv[1], &height, &width) != 1) {
        return 1;
    }

    int pixels[height][width];
    if (read_pbm(argv[1], height, width, pixels)) {
        get_bounding_box(height, width, pixels, &start_row, &start_column, &box_height, &box_width);  //code above this line taken from lab07 work

        //initialise array
        int box_pixels[box_height][box_width];
        for(int i = 0; i < box_height; i++){
            for(int j = 0; j < box_width; j++){
                box_pixels[i][j] = 0;
            }
        }
        copy_pixels(height, width, pixels, start_row, start_column, box_height, box_width, box_pixels);

        int num;
        num = crack_digit(box_height, box_width, box_pixels, DIGITS, ATTRIB, ZSCMAX);

        printf("%d\n", num);
                /*         //debugging statements, prints 1 on sucess, 0 on failure
                if(argv[1][6] - '0' == num){
                    printf("1");
                } else {
                    printf("0");
                }*/

    }
    return 0;
}
