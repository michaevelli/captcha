//name: michael
//date: 20170410
//find attributes of digit

#include <stdio.h>
#include <math.h>
#include "captcha.h"

//lab07 work
double get_horizontal_balance(int height, int width, int pixels[height][width]){

    double horizontal_balance;
    int n_black_pixels = 0;
    int column_sum = 0;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(pixels[i][j] == 1){
                n_black_pixels++;
                column_sum += j;
            }
        }
    }
    horizontal_balance = ((double)column_sum/n_black_pixels + 0.5)/width;
    return horizontal_balance;
}

//extrapolated from lab07 work. Swapped column for row sum and width for height
double get_vertical_balance(int height, int width, int pixels[height][width]){

    double vertical_balance;
    int n_black_pixels = 0;
    int row_sum = 0;

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(pixels[i][j] == 1){
                n_black_pixels++;
                row_sum += i;
            }
        }
    }
    vertical_balance = ((double)row_sum/n_black_pixels + 0.5)/height;
    return vertical_balance;
}

//tallness = height/width of bounding box
double get_tallness(int height, int width){
    double tall = (double)height/width;
    return tall;
}

//find density. density = amount_of_black_pixels/area of bounding box
double density(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int black = 0;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 1){          //counts number of black pixels
                black++;
            }
        }
    }
    return (double)black/(width*height);
}

//find density. density = amount_of_black_pixels/area of bounding box
double densitybot(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int black = 0;
    for(int i = 0; i < width/2; i++){
        for(int j = 0; j < height; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 1){          //counts number of black pixels
                black++;
            }
        }
    }
    return (double)black/(width*(height/2));
}

//find density. density = amount_of_black_pixels/area of bounding box
double densityrig(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int black = 0;
    for(int i = 0; i < width; i++){
        for(int j = height/2; j < height; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 1){          //counts number of black pixels
                black++;
            }
        }
    }
    return (double)black/((width/2)*height);
}

//find density. density = amount_of_black_pixels/area of bounding box
double densitylef(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int black = 0;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height/2; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 1){          //counts number of black pixels
                black++;
            }
        }
    }
    return (double)black/((width/2)*height);
}

//find density. density = amount_of_black_pixels/area of bounding box
double densitytop(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int black = 0;
    for(int i = width/2; i < width; i++){
        for(int j = 0; j < height; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 1){          //counts number of black pixels
                black++;
            }
        }
    }
    return (double)black/(width*(height/2));
}

//find density. density = amount_of_black_pixels/area of bounding box
double densityNW(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int black = 0;
    for(int i = 0; i < width/2; i++){
        for(int j = 0; j < height/2; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 1){          //counts number of black pixels
                black++;
            }
        }
    }
    return (double)black/(width*(height/2));
}

//find density. density = amount_of_black_pixels/area of bounding box
double densityNE(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int black = 0;
    for(int i = width/2; i < width; i++){
        for(int j = height/2; j < height; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 1){          //counts number of black pixels
                black++;
            }
        }
    }
    return (double)black/((width/2)*height);
}

//find density. density = amount_of_black_pixels/area of bounding box
double densitySW(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int black = 0;
    for(int i = 0; i < width/2; i++){
        for(int j = height/2; j < height; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 1){          //counts number of black pixels
                black++;
            }
        }
    }
    return (double)black/((width/2)*height);
}

//find density. density = amount_of_black_pixels/area of bounding box
double densitySE(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int black = 0;
    for(int i = width/2; i < width; i++){
        for(int j = height/2; j < height; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 1){          //counts number of black pixels
                black++;
            }
        }
    }
    return (double)black/(width*(height/2));
}

//find hole_density. uses a floodfilled array. holeDensity = Amount_of_White_pixels_in_holes(white pixels of floodfill array)/area_of_bounding_box
double holedensity(int width, int height, int pixels[width][height]){ //width and height are technically mixed up but they are called correctly
    int white = 0;
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){    //nested loop to run through every pixel in array
            if(pixels[i][j] == 0){          //counts number of white (holes) pixels
                white++;
            }
        }
    }
    return (double)white/((width-2)*(height-2));
}

//scans array from top to bottom and looks for a pattern of (hole)(not a hole)(hole)(not a hole) and counts the number of times it encounters this
int hashole(int imax, int jmax, int pixels[imax][jmax]){
    int skip = 0;
    int end = 0, start = imax;
    for(int i = 0; i < imax; i++){
        int trigger = 0;                    //trigger 0 by default. 0 means the line does not have any holes
        for(int j = 0; j < jmax; j++){
            if(pixels[i][j] == 0){
                trigger = 1;                //If there is a "0" in the line, the line is part of a hole and so trigger = 1
                break;
            }
        }
        if(trigger || skip > 0){             //first hole
            if(skip == 0){                      //the first time it passes this statement, it adds one to "skip"
                skip++;                         //automatically passes this if statement after passing it once. same applies to following if statements
            }
            if(!trigger || skip > 1){        //intermediate
                if(skip == 1){                  //the first time it passes this statement, it adds one to "skip"
                    skip++;
                    end = i;                    //value of i for end of first hole. used to detect spacing between multiple holes
                }
                if(trigger || skip > 2){     //second hole
                    if(skip == 2){              //the first time it passes this statement, it adds one to "skip"
                        skip++;
                        start = i;              //value of i for start of second hole. used to detect spacing between multiple holes
                    }
                    if(!trigger){             //over
                        if(skip == 3){          //the first time it passes this statement, it adds one to "skip"
                            skip++;
                        }
                    }
                }
            }
        }
    }

    //so skip now holds the number of changes from hole->notHole or notHole -> hole

    if(start-end < 2 && skip == 4){  //if the spacing between the two holes is less than 2, consider them as one hole
        skip -= 2;                   //so subtract 2 from skip
    }
    return skip/2;
}

//horizontal balance of hole with respect to bounding box
double hole_horizontal_balance(int height, int width, int pixels[height][width]){
    double horizontal_balance;
    int n_white_pixels = 0;
    int column_sum = 0;

    for(int i = 1; i < height-1; i++){
        for(int j = 1; j < width-1; j++){
            if(pixels[i][j] == 0){
                n_white_pixels++;
                column_sum += j-1;
            }
        }
    }
    if(n_white_pixels == 0){
        return 0;
    }
    horizontal_balance = ((double)column_sum/n_white_pixels + 0.5)/(width-2);
    return horizontal_balance;
}

//vertical balance of hole with respect to bounding box
double hole_vertical_balance(int height, int width, int pixels[height][width]){
    double vertical_balance;
    int n_white_pixels = 0;
    int row_sum = 0;

    for(int i = 1; i < height-1; i++){
        for(int j = 1; j < width-1; j++){
            if(pixels[i][j] == 0){
                n_white_pixels++;
                row_sum += i-1;
            }
        }
    }
    if(n_white_pixels == 0){
        return 0;
    }
    vertical_balance = ((double)row_sum/n_white_pixels + 0.5)/(height-2);
    return vertical_balance;
}

//tallness of the hole
double hole_tallness(int height, int width, int pixels[height][width]){
    int start_row = 0, start_column = 0, box_height = 0, box_width = 0;
    hole_bounding_box(height, width, pixels,
                  &start_row, &start_column, &box_height, &box_width);
    if(box_width == 0 || box_height == 0){
        return 0;
    }
    return (double)box_height/box_width;
}

//ratio of blank pixels on the right side of the image compared to the area
double white_left_ratio(int height, int width, int pixels[height][width]){
    int copy[height][width];
    int white = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            copy[i][j] = pixels[i][j];
        }
    }
    floodfill(height, width, copy, 0, width-1);
    floodfill(height, width, copy, height-1, width-1);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            if(copy[i][j] == 0){
                white++;
            }
        }
    }

    return (double)white/(height*width);

}

//number of times a vertical line will cut the image at a given column
//Only appied to non hole numbers as holes will give an equivilant value for numbers with holes
int get_cuts(int height, int width, int array[height][width], int x ){

    int count = 0;
    for(int i = 0; i < height; i++){
        if(array[i][x] == 1 && i < height-1){
            if(array[i+1][x] == 0){
                count++;
            }
        }
    }
    return count;
}

//same as above but horizontal
int get_hori_cut(int height, int width, int array[height][width], int x){
    int count = 0;
    for(int j = 0; j < width; j++){
        if(array[x][j] == 1 && j < width-1){
            if(array[x][j+1] == 0){
                count++;
            }
        }
    }
    return count;
}
