//name: michael
//date: 20170420
//crack captcha

#include <stdio.h>
#include "captcha.h"
#include <stdlib.h>
#include <math.h>

#define DIGITS 10
#define ATTRIB 21
#define ZSCMAX 4.2

int main(int argc, char *argv[]) {
    int height, width, start_row, start_column, box_width, box_height, hole, holeheight, holewidth;
    double hBal, vBal, tall, dens, hDen;

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

        //plan:
        //split captcha into 4
        //give each captcha into digit

        //create 4 arrays, one for each digit, and initialise
        int box_pixels1[box_height][box_width];
        int box_pixels2[box_height][box_width];
        int box_pixels3[box_height][box_width];
        int box_pixels4[box_height][box_width];
        for(int i = 0; i < box_height; i++){
            for(int j = 0; j < box_width; j++){
                box_pixels1[i][j] = 0;
                box_pixels2[i][j] = 0;
                box_pixels3[i][j] = 0;
                box_pixels4[i][j] = 0;
            }
        }

        split(box_height, box_width, box_pixels,
                box_pixels1, box_pixels2, box_pixels3, box_pixels4);



        //get bounding box for indidualised arrays
        int start_row1, start_column1, box_height1, box_width1;
        get_bounding_box(box_height, box_width, box_pixels1,
                &start_row1, &start_column1, &box_height1, &box_width1);
        int real_box_pixels1[box_height1][box_width1];
        copy_pixels(box_height, box_width, box_pixels1, start_row1, start_column1, box_height1, box_width1, real_box_pixels1);

        int start_row2, start_column2, box_height2, box_width2;
        get_bounding_box(box_height, box_width, box_pixels2,
                &start_row2, &start_column2, &box_height2, &box_width2);
        int real_box_pixels2[box_height2][box_width2];
        copy_pixels(box_height, box_width, box_pixels2, start_row2, start_column2, box_height2, box_width2, real_box_pixels2);

        int start_row3, start_column3, box_height3, box_width3;
        get_bounding_box(box_height, box_width, box_pixels3,
                &start_row3, &start_column3, &box_height3, &box_width3);
        int real_box_pixels3[box_height3][box_width3];
        copy_pixels(box_height, box_width, box_pixels3, start_row3, start_column3, box_height3, box_width3, real_box_pixels3);

        int start_row4, start_column4, box_height4, box_width4;
        get_bounding_box(box_height, box_width, box_pixels4,
                &start_row4, &start_column4, &box_height4, &box_width4);
        int real_box_pixels4[box_height4][box_width4];
        copy_pixels(box_height, box_width, box_pixels4, start_row4, start_column4, box_height4, box_width4, real_box_pixels4);

        //call crack digit

                //printf("%s   ", argv[1]);  //debugging statement, prints filename
        //printf("%d", crack_digit(box_height1, box_width1, real_box_pixels1, DIGITS, ATTRIB, ZSCMAX));
        //printf("%d", crack_digit(box_height2, box_width2, real_box_pixels2, DIGITS, ATTRIB, ZSCMAX));
        //printf("%d", crack_digit(box_height3, box_width3, real_box_pixels3, DIGITS, ATTRIB, ZSCMAX));
        //printf("%d", crack_digit(box_height4, box_width4, real_box_pixels4, DIGITS, ATTRIB, ZSCMAX));
        //printf("\n");



                          //debuggin statements, prints out how many matching digits of captcha
                int score = 0;
                if((argv[1][8] - '0') == crack_digit(box_height1, box_width1, real_box_pixels1, DIGITS, ATTRIB, ZSCMAX)){
                    score++;
                }
                if((argv[1][9] - '0') == crack_digit(box_height2, box_width2, real_box_pixels2, DIGITS, ATTRIB, ZSCMAX)){
                    score++;
                }
                if((argv[1][10] - '0') == crack_digit(box_height3, box_width3, real_box_pixels3, DIGITS, ATTRIB, ZSCMAX)){
                    score++;
                }
                if((argv[1][11] - '0') == crack_digit(box_height4, box_width4, real_box_pixels4, DIGITS, ATTRIB, ZSCMAX)){
                    score++;
                }
                printf("%d", score);
                

    }
    return 0;
}
