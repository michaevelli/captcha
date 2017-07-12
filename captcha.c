//name: michael
//date: 20170430
//captcha related functions

#include "captcha.h"
#include <stdio.h>
#include <math.h>

//split the captcha into 4 parts, each with one digit in it
void split(int height, int width, int array[height][width],
        int array1[height][width],
        int array2[height][width],
        int array3[height][width],
        int array4[height][width]){

    //put into array the number of black pixels in each column
    int black = 0;
    int arrblack[width];
    for(int j = 0; j < width; j++){
        black = 0;
        for(int i = 0; i < height; i++){
            if(array[i][j] == 1){
                black++;
            }
        }
        arrblack[j] = black;
    }

    //searches for a blank line (no black pixels) after a line with black pixels
    //this location will be where a digit ends
    int skip = 0;
    int k = 0;
    int newdig[4] = {0};
    for(int i = 0; i < width; i++){
        if(arrblack[i] != 0 && i < width-1){
            if(arrblack[i+1] == 0){
                newdig[k] = i+1;
                k++;
            }
        }
    }

    //assign start values for readabilty
    int startx1 = 0;
    int startx2 = newdig[0];
    int startx3 = newdig[1];
    int startx4 = newdig[2];

    //copy part of the captcha array into a new array
    //the part copied depens on the start positions assigned above
    //each array will hold one number
    for(int j = 0; j < (startx2-startx1); j++){
        for(int i = 0; i < height; i++){
            array1[i][j] = array[i][j + startx1];
        }
    }
    for(int j = 0; j < (startx3-startx2); j++){
        for(int i = 0; i < height; i++){
            array2[i][j] = array[i][j + startx2];
        }
    }
    for(int j = 0; j < (startx4-startx3); j++){
        for(int i = 0; i < height; i++){
            array3[i][j] = array[i][j + startx3];
        }
    }
    for(int j = 0; j < (width-startx4); j++){
        for(int i = 0; i < height; i++){
            array4[i][j] = array[i][j + startx4];
        }
    }
}

//crack digit
int crack_digit(int box_height, int box_width, int box_pixels[box_height][box_width],
            int x, int y, double z){

        int hole, holeheight, holewidth, fhol;
        double hBal, vBal, tall, dens, hDen, hhBl, hvBl, hTal, wlSp, bden, rden, lden, tden, ohhB, ohvB, ohTa, den1, den2, den3, den4;
        double fnho;
        int cuts, hcut;

        hBal = get_horizontal_balance(box_height, box_width, box_pixels);   //assign attributes to variables
        vBal = get_vertical_balance(box_height, box_width, box_pixels);
        tall = get_tallness(box_height, box_width);

        //initilise an array for use with floodfill.c
        holeheight = box_height+2;
        holewidth = box_width+2;
        int holetest[holeheight][holewidth];
        createborder(box_height, box_width, box_pixels, holetest);

        //these two function utilise a borderd array and so these values must be determined before the array is flood filled
        cuts = get_cuts(holeheight, holewidth, holetest, holewidth/2);
        hcut = get_hori_cut(holeheight, holewidth, holetest, holeheight/2);


        floodfill(holeheight, holewidth, holetest, 0, 0);

        //assign properties to variables
        hole = hashole(holeheight, holewidth, holetest);
        dens = density(box_height, box_width, box_pixels);
        hDen = holedensity(holeheight, holewidth, holetest);

        //new attributes not provided in spec sheet
        hhBl = hole_horizontal_balance(holeheight, holewidth, holetest);
        hvBl = hole_vertical_balance(holeheight, holewidth, holetest);
        hTal = hole_tallness(holeheight, holewidth, holetest);

        wlSp = white_left_ratio(box_height, box_width, box_pixels);

        bden = densitybot(box_height, box_width, box_pixels);
        rden = densityrig(box_height, box_width, box_pixels);
        lden = densitylef(box_height, box_width, box_pixels);
        tden = densitytop(box_height, box_width, box_pixels);

        den1 = densityNW(box_height, box_width, box_pixels);
        den2 = densityNE(box_height, box_width, box_pixels);
        den3 = densitySW(box_height, box_width, box_pixels);
        den4 = densitySE(box_height, box_width, box_pixels);

        fhol = -1;
        ohhB = -1;
        ohvB = -1;
        ohTa = -1;
        fnho = -1;

        //create a fake hole for digits 1, 2, 3, 5, 7 by drawing vertical line
        int fakehole[holeheight][holewidth];
        createborder(box_height, box_width, box_pixels, fakehole);
        if(hole == 0){
            //int fakehole[holeheight][holewidth];
            //createborder(box_height, box_width, box_pixels, fakehole);
            drawline(holeheight, holewidth, fakehole);
            //print_image(holeheight, holewidth, fakehole);
            floodfill(holeheight, holewidth, fakehole, 0, 0);
            fhol = hashole(holeheight, holewidth, fakehole);
            ohhB = hole_horizontal_balance(holeheight, holewidth, fakehole);
            ohvB = hole_vertical_balance(holeheight, holewidth, fakehole);
            ohTa = hole_tallness(holeheight, holewidth, fakehole);
            fnho = holedensity(holeheight, holewidth, fakehole);
        }

        //create and assign an array of the averages for attributes for each digit
        double avg[x][y];
        average(x, y, avg);

        //create and assign an array of the standard deviation for attributes for each digit
        double stdd[x][y];
        standardd(x, y, stdd);


        //create and initilise array for the deviation of attribute from the mean for each digit
        double rule[x][y];
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                rule[i][j] = -1;
            }
        }

        //create and initilise array of z scores
        double zsc[x][y];
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                zsc[i][j] = -1;
            }
        }

        //put deviation into array
        deviation(vBal, hBal, tall, dens, hDen, hole, hhBl, hvBl, hTal, wlSp, cuts, hcut, bden, rden, lden, tden, fhol, ohhB, ohvB, ohTa, fnho, den1, den2, den3, den4,
                x, y, rule, avg, z, stdd);

        //put z scores into array
        zscore(x, y, stdd, avg, rule, zsc);


        int num;

        if(hole == 2){                          //only 8s have 2 holes
            num = 8;
        } else if(fhol == 0){                    //1 (and some very skewed 7s) are the only numbers that can't have a fake hole drawn with one line
            num = 1;
        } else if(fnho < 0.001 && fnho >= 0){   //It is only posisble to have a tiny fake hole on a 2 by making a hole in the sharp corner
            num = 2;
        } else {
            num = points(x, y, zsc, rule); //run the points system to return best digit match
        }

        return num;

}