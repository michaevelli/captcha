//name: michael
//date: 20170425
//array assignment related code dump to make main function neater

#include <stdio.h>
#include <stdlib.h>
#include "captcha.h"
#include <math.h>
#include <string.h>


void average(int x, int y, double array[x][y]){ //Assign preset averages for digits for attributes to array for easy access
    FILE *fp = fopen("average.txt", "r");
    char line[7];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            fgets(line, 7, fp);
            array[i][j] = atof(line);
        }
    }
    fclose(fp);
}

void standardd(int x, int y, double array[x][y]){ //Assign preset averages for digits for attributes to array for easy access
    FILE *fp = fopen("stdev.txt", "r");
    char line[7];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            fgets(line, 7, fp);
            array[i][j] = atof(line);
        }
    }
    fclose(fp);
}



void deviation(double vBal, double hBal, double tall, double dens, double hDen, int hole, double hhBl, double hvBl, double hTal, double wlSp, int cuts, double hcut, double bden, double rden, double lden, double tden, int fhol, double ohhB, double ohvB, double ohTa, double fnho, double den1, double den2, double den3, double den4,
        int x, int y, double rule[x][y], double avg[x][y], double z,
        double stdd[x][y]){
    if(hole == 2){
            //printf("8"); //unnecessary to check further for 8 or assing values as only 2 holes have 8
        } else if(hole == 1){

            if(hBal >= avg[0][0] - z*stdd[0][0] && hBal <=  avg[0][0] + z*stdd[0][0]           //If the horizontal balance is inside a specific range
                    && vBal >= avg[0][1] - z*stdd[0][1] && vBal <= avg[0][1] + z*stdd[0][1]    //If the vertical balance is inside a specific range
                    && tall >= avg[0][2] - z*stdd[0][2] && tall <= avg[0][2] + z*stdd[0][2]    //etc.
                    && dens >= avg[0][3] - z*stdd[0][3] && dens <= avg[0][3] + z*stdd[0][3]    //these min-max values were extracted from the datset
                    && hDen >= avg[0][4] - z*stdd[0][4] && hDen <= avg[0][4] + z*stdd[0][4]    //values used depend on max determined zscore and standard deviation
                    && hhBl >= avg[0][5] - z*stdd[0][5] && hhBl <= avg[0][5] + z*stdd[0][5]
                    && hvBl >= avg[0][6] - z*stdd[0][6] && hvBl <= avg[0][6] + z*stdd[0][6]
                    && hTal >= avg[0][7] - z*stdd[0][7] && hTal <= avg[0][7] + z*stdd[0][7]
                    && wlSp >= avg[0][8] - z*stdd[0][8] && wlSp <= avg[0][8] + z*stdd[0][8]){
                //printf("0");
                rule[0][0] = fabs(avg[0][0] - hBal);  //assign deviation from the mean
                rule[0][1] = fabs(avg[0][1] - vBal);  //for every attribute of a digit
                rule[0][2] = fabs(avg[0][2] - tall);  //to an array
                rule[0][3] = fabs(avg[0][3] - dens);  //this only occurs if the attributes are within range for a digit (aka, a possibility)
                rule[0][4] = fabs(avg[0][4] - hDen);  //otherwise, the array is left untouched with an initilised value of "-1"
                rule[0][5] = fabs(avg[0][5] - hhBl);
                rule[0][6] = fabs(avg[0][6] - hvBl);
                rule[0][7] = fabs(avg[0][7] - hTal);
                rule[0][8] = fabs(avg[0][8] - wlSp);
                rule[0][9] = fabs(0.0);               //These propeties are not used for digits without holes
                rule[0][10] = fabs(0.0);              //So they are set to 0
                rule[0][11] = fabs(0.0);
                rule[0][12] = fabs(0.0);
                rule[0][13] = fabs(0.0);
                rule[0][14] = fabs(0.0);
                rule[0][15] = fabs(0.0);
                rule[0][16] = fabs(0.0);
                rule[0][17] = fabs(0.0);
                rule[0][18] = fabs(0.0);
                rule[0][19] = fabs(0.0);
                rule[0][20] = fabs(0.0);

            }
            if(hBal >= avg[4][0] - z*stdd[4][0] && hBal <=  avg[4][0] + z*stdd[4][0]
                    && vBal >= avg[4][1] - z*stdd[4][1] && vBal <= avg[4][1] + z*stdd[4][1]
                    && tall >= avg[4][2] - z*stdd[4][2] && tall <= avg[4][2] + z*stdd[4][2]
                    && dens >= avg[4][3] - z*stdd[4][3] && dens <= avg[4][3] + z*stdd[4][3]
                    && hDen >= avg[4][4] - z*stdd[4][4] && hDen <= avg[4][4] + z*stdd[4][4]
                    && hhBl >= avg[4][5] - z*stdd[4][5] && hhBl <= avg[4][5] + z*stdd[4][5]
                    && hvBl >= avg[4][6] - z*stdd[4][6] && hvBl <= avg[4][6] + z*stdd[4][6]
                    && hTal >= avg[4][7] - z*stdd[4][7] && hTal <= avg[4][7] + z*stdd[4][7]
                    && wlSp >= avg[4][8] - z*stdd[4][8] && wlSp <= avg[4][8] + z*stdd[4][8]){
                //printf("4");
                rule[4][0] = fabs(avg[4][0] - hBal);
                rule[4][1] = fabs(avg[4][1] - vBal);
                rule[4][2] = fabs(avg[4][2] - tall);
                rule[4][3] = fabs(avg[4][3] - dens);
                rule[4][4] = fabs(avg[4][4] - hDen);
                rule[4][5] = fabs(avg[4][5] - hhBl);
                rule[4][6] = fabs(avg[4][6] - hvBl);
                rule[4][7] = fabs(avg[4][7] - hTal);
                rule[4][8] = fabs(avg[4][8] - wlSp);
                rule[4][9] = fabs(0.0);
                rule[4][10] = fabs(0.0);
                rule[4][11] = fabs(0.0);
                rule[4][12] = fabs(0.0);
                rule[4][13] = fabs(0.0);
                rule[4][14] = fabs(0.0);
                rule[4][15] = fabs(0.0);
                rule[4][16] = fabs(0.0);
                rule[4][17] = fabs(0.0);
                rule[4][18] = fabs(0.0);
                rule[4][19] = fabs(0.0);
                rule[4][20] = fabs(0.0);
            }
            if(hBal >= avg[6][0] - z*stdd[6][0] && hBal <=  avg[6][0] + z*stdd[6][0]
                    && vBal >= avg[6][1] - z*stdd[6][1] && vBal <= avg[6][1] + z*stdd[6][1]
                    && tall >= avg[6][2] - z*stdd[6][2] && tall <= avg[6][2] + z*stdd[6][2]
                    && dens >= avg[6][3] - z*stdd[6][3] && dens <= avg[6][3] + z*stdd[6][3]
                    && hDen >= avg[6][4] - z*stdd[6][4] && hDen <= avg[6][4] + z*stdd[6][4]
                    && hhBl >= avg[6][5] - z*stdd[6][5] && hhBl <= avg[6][5] + z*stdd[6][5]
                    && hvBl >= avg[6][6] - z*stdd[6][6] && hvBl <= avg[6][6] + z*stdd[6][6]
                    && hTal >= avg[6][7] - z*stdd[6][7] && hTal <= avg[6][7] + z*stdd[6][7]
                    && wlSp >= avg[6][8] - z*stdd[6][8] && wlSp <= avg[6][8] + z*stdd[6][8]){
                //printf("6");
                rule[6][0] = fabs(avg[6][0] - hBal);
                rule[6][1] = fabs(avg[6][1] - vBal);
                rule[6][2] = fabs(avg[6][2] - tall);
                rule[6][3] = fabs(avg[6][3] - dens);
                rule[6][4] = fabs(avg[6][4] - hDen);
                rule[6][5] = fabs(avg[6][5] - hhBl);
                rule[6][6] = fabs(avg[6][6] - hvBl);
                rule[6][7] = fabs(avg[6][7] - hTal);
                rule[6][8] = fabs(avg[6][8] - wlSp);
                rule[6][9] = fabs(0.0);
                rule[6][10] = fabs(0.0);
                rule[6][11] = fabs(0.0);
                rule[6][12] = fabs(0.0);
                rule[6][13] = fabs(0.0);
                rule[6][14] = fabs(0.0);
                rule[6][15] = fabs(0.0);
                rule[6][16] = fabs(0.0);
                rule[6][17] = fabs(0.0);
                rule[6][18] = fabs(0.0);
                rule[6][19] = fabs(0.0);
                rule[6][20] = fabs(0.0);
            }
            if(hBal >= avg[9][0] - z*stdd[9][0] && hBal <=  avg[9][0] + z*stdd[9][0]
                    && vBal >= avg[9][1] - z*stdd[9][1] && vBal <= avg[9][1] + z*stdd[9][1]
                    && tall >= avg[9][2] - z*stdd[9][2] && tall <= avg[9][2] + z*stdd[9][2]
                    && dens >= avg[9][3] - z*stdd[9][3] && dens <= avg[9][3] + z*stdd[9][3]
                    && hDen >= avg[9][4] - z*stdd[9][4] && hDen <= avg[9][4] + z*stdd[9][4]
                    && hhBl >= avg[9][5] - z*stdd[9][5] && hhBl <= avg[9][5] + z*stdd[9][5]
                    && hvBl >= avg[9][6] - z*stdd[9][6] && hvBl <= avg[9][6] + z*stdd[9][6]
                    && hTal >= avg[9][7] - z*stdd[9][7] && hTal <= avg[9][7] + z*stdd[9][7]
                    && wlSp >= avg[9][8] - z*stdd[9][8] && wlSp <= avg[9][8] + z*stdd[9][8]){
                //printf("9");
                rule[9][0] = fabs(avg[9][0] - hBal);
                rule[9][1] = fabs(avg[9][1] - vBal);
                rule[9][2] = fabs(avg[9][2] - tall);
                rule[9][3] = fabs(avg[9][3] - dens);
                rule[9][4] = fabs(avg[9][4] - hDen);
                rule[9][5] = fabs(avg[9][5] - hhBl);
                rule[9][6] = fabs(avg[9][6] - hvBl);
                rule[9][7] = fabs(avg[9][7] - hTal);
                rule[9][8] = fabs(avg[9][8] - wlSp);
                rule[9][9] = fabs(0.0);
                rule[9][10] = fabs(0.0);
                rule[9][11] = fabs(0.0);
                rule[9][12] = fabs(0.0);
                rule[9][13] = fabs(0.0);
                rule[9][14] = fabs(0.0);
                rule[9][15] = fabs(0.0);
                rule[9][16] = fabs(0.0);
                rule[9][17] = fabs(0.0);
                rule[9][18] = fabs(0.0);
                rule[9][19] = fabs(0.0);
                rule[9][20] = fabs(0.0);
            }
        } else {                                               //repeat the previous if code but for digits without holes
            if(hBal >= avg[1][0] - z*stdd[1][0]  && hBal <= avg[1][0] + z*stdd[1][0]
                    && vBal >= avg[1][1] - z*stdd[1][1] && vBal <= avg[1][1] + z*stdd[1][1]
                    && tall >= avg[1][2] - z*stdd[1][2] && tall <= avg[1][2] + z*stdd[1][2]
                    && dens >= avg[1][3] - z*stdd[1][3] && dens <= avg[1][3] + z*stdd[1][3]
                    && wlSp >= avg[1][8] - z*stdd[1][8] && wlSp <= avg[1][8] + z*stdd[1][8]
                    && cuts >= 1                        && cuts <= 2/*3*/
                    && hcut == 1
                    && bden >= avg[1][9] - z*stdd[1][9] && bden <= avg[1][9] + z*stdd[1][9]
                    && rden >= avg[1][10] - z*stdd[1][10] && rden <= avg[1][10] + z*stdd[1][10]
                    && lden >= avg[1][11] - z*stdd[1][11] && lden <= avg[1][11] + z*stdd[1][11]
                    && tden >= avg[1][12] - z*stdd[1][12] && tden <= avg[1][12] + z*stdd[1][12]
                    && (fhol == 0 || fhol == 1)
                    && ohhB >= avg[1][13] - z*stdd[1][13] && ohhB <= avg[1][13] + z*stdd[1][13]
                    && ohvB >= avg[1][14] - z*stdd[1][14] && ohvB <= avg[1][14] + z*stdd[1][14]
                    && ohTa >= avg[1][15] - z*stdd[1][15] && ohTa <= avg[1][15] + z*stdd[1][15]
                    && fnho >= avg[1][16] - z*stdd[1][16] && fnho <= avg[1][16] + z*stdd[1][16]
                    && den1 >= avg[1][17] - z*stdd[1][17] && den1 <= avg[1][17] + z*stdd[1][17]
                    && den2 >= avg[1][18] - z*stdd[1][18] && den2 <= avg[1][18] + z*stdd[1][18]
                    && den3 >= avg[1][19] - z*stdd[1][19] && den3 <= avg[1][19] + z*stdd[1][19]
                    && den4 >= avg[1][20] - z*stdd[1][20] && den4 <= avg[1][20] + z*stdd[1][20]
                    ){
                //printf("1");
                rule[1][0] = fabs(avg[1][0] - hBal);
                rule[1][1] = fabs(avg[1][1] - vBal);
                rule[1][2] = fabs(avg[1][2] - tall);
                rule[1][3] = fabs(avg[1][3] - dens);
                rule[1][4] = fabs(0.0);
                rule[1][5] = fabs(0.0);
                rule[1][6] = fabs(0.0);
                rule[1][7] = fabs(0.0);
                rule[1][8] = fabs(avg[1][8] - wlSp);
                rule[1][9] = fabs(avg[1][9] - bden);
                rule[1][10] = fabs(avg[1][10] - rden);
                rule[1][11] = fabs(avg[1][11] - lden);
                rule[1][12] = fabs(avg[1][12] - tden);
                rule[1][13] = fabs(avg[1][13] - ohhB);
                rule[1][14] = fabs(avg[1][14] - ohvB);
                rule[1][15] = fabs(avg[1][15] - ohTa);
                rule[1][16] = fabs(avg[1][16] - fnho);
                rule[1][17] = fabs(avg[1][17] - den1);
                rule[1][18] = fabs(avg[1][18] - den2);
                rule[1][19] = fabs(avg[1][19] - den3);
                rule[1][20] = fabs(avg[1][20] - den4);

            }
            if(hBal >= avg[2][0] - z*stdd[2][0]  && hBal <= avg[2][0] + z*stdd[2][0]
                    && vBal >= avg[2][1] - z*stdd[2][1] && vBal <= avg[2][1] + z*stdd[2][1]
                    && tall >= avg[2][2] - z*stdd[2][2] && tall <= avg[2][2] + z*stdd[2][2]
                    && dens >= avg[2][3] - z*stdd[2][3] && dens <= avg[2][3] + z*stdd[2][3]
                    && wlSp >= avg[2][8] - z*stdd[2][8] && wlSp <= avg[2][8] + z*stdd[2][8]
                    && cuts >= 2                        && cuts <= 3/*4*/
                    //&& hcut == 1
                    && bden >= avg[2][9] - z*stdd[2][9] && bden <= avg[2][9] + z*stdd[2][9]
                    && rden >= avg[2][10] - z*stdd[2][10] && rden <= avg[2][10] + z*stdd[2][10]
                    && lden >= avg[2][11] - z*stdd[2][11] && lden <= avg[2][11] + z*stdd[2][11]
                    && tden >= avg[2][12] - z*stdd[2][12] && tden <= avg[2][12] + z*stdd[2][12]
                    //&&(fhol == 1 || fhol == 2)
                    && ohhB >= avg[2][13] - z*stdd[2][13] && ohhB <= avg[2][13] + z*stdd[2][13]
                    && ohvB >= avg[2][14] - z*stdd[2][14] && ohvB <= avg[2][14] + z*stdd[2][14]
                    && ohTa >= avg[2][15] - z*stdd[2][15] && ohTa <= avg[2][15] + z*stdd[2][15]
                    && fnho >= avg[2][16] - z*stdd[2][16] && fnho <= avg[2][16] + z*stdd[2][16]
                    && den1 >= avg[2][17] - z*stdd[2][17] && den1 <= avg[2][17] + z*stdd[2][17]
                    && den2 >= avg[2][18] - z*stdd[2][18] && den2 <= avg[2][18] + z*stdd[2][18]
                    && den3 >= avg[2][19] - z*stdd[2][19] && den3 <= avg[2][19] + z*stdd[2][19]
                    && den4 >= avg[2][20] - z*stdd[2][20] && den4 <= avg[2][20] + z*stdd[2][20]
                    ){
                //printf("2");
                rule[2][0] = fabs(avg[2][0] - hBal);
                rule[2][1] = fabs(avg[2][1] - vBal);
                rule[2][2] = fabs(avg[2][2] - tall);
                rule[2][3] = fabs(avg[2][3] - dens);
                rule[2][4] = fabs(0.0);
                rule[2][5] = fabs(0.0);
                rule[2][6] = fabs(0.0);
                rule[2][7] = fabs(0.0);
                rule[2][8] = fabs(avg[2][8] - wlSp);
                rule[2][9] = fabs(avg[2][9] - bden);
                rule[2][10] = fabs(avg[2][10] - rden);
                rule[2][11] = fabs(avg[2][11] - lden);
                rule[2][12] = fabs(avg[2][12] - tden);
                rule[2][13] = fabs(avg[2][13] - ohhB);
                rule[2][14] = fabs(avg[2][14] - ohvB);
                rule[2][15] = fabs(avg[2][15] - ohTa);
                rule[2][16] = fabs(avg[2][16] - fnho);
                rule[2][17] = fabs(avg[2][17] - den1);
                rule[2][18] = fabs(avg[2][18] - den2);
                rule[2][19] = fabs(avg[2][19] - den3);
                rule[2][20] = fabs(avg[2][20] - den4);
            }
            if(hBal >= avg[3][0] - z*stdd[3][0]  && hBal <= avg[3][0] + z*stdd[3][0]
                    && vBal >= avg[3][1] - z*stdd[3][1] && vBal <= avg[3][1] + z*stdd[3][1]
                    && tall >= avg[3][2] - z*stdd[3][2] && tall <= avg[3][2] + z*stdd[3][2]
                    && dens >= avg[3][3] - z*stdd[3][3] && dens <= avg[3][3] + z*stdd[3][3]
                    && wlSp >= avg[3][8] - z*stdd[3][8] && wlSp <= avg[3][8] + z*stdd[3][8]
                    && cuts >= 2                        && cuts <= 3
                    && hcut != 3
                    && bden >= avg[3][9] - z*stdd[3][9] && bden <= avg[3][9] + z*stdd[3][9]
                    && rden >= avg[3][10] - z*stdd[3][10] && rden <= avg[3][10] + z*stdd[3][10]
                    && lden >= avg[3][11] - z*stdd[3][11] && lden <= avg[3][11] + z*stdd[3][11]
                    && tden >= avg[3][12] - z*stdd[3][12] && tden <= avg[3][12] + z*stdd[3][12]
                    //&&(fhol == 1 || fhol == 2)
                    && ohhB >= avg[3][13] - z*stdd[3][13] && ohhB <= avg[3][13] + z*stdd[3][13]
                    && ohvB >= avg[3][14] - z*stdd[3][14] && ohvB <= avg[3][14] + z*stdd[3][14]
                    && ohTa >= avg[3][15] - z*stdd[3][15] && ohTa <= avg[3][15] + z*stdd[3][15]
                    && fnho >= avg[3][16] - z*stdd[3][16] && fnho <= avg[3][16] + z*stdd[3][16]
                    && den1 >= avg[3][17] - z*stdd[3][17] && den1 <= avg[3][17] + z*stdd[3][17]
                    && den2 >= avg[3][18] - z*stdd[3][18] && den2 <= avg[3][18] + z*stdd[3][18]
                    && den3 >= avg[3][19] - z*stdd[3][19] && den3 <= avg[3][19] + z*stdd[3][19]
                    && den4 >= avg[3][20] - z*stdd[3][20] && den4 <= avg[3][20] + z*stdd[3][20]
                    ){
                //printf("3");
                rule[3][0] = fabs(avg[3][0] - hBal);
                rule[3][1] = fabs(avg[3][1] - vBal);
                rule[3][2] = fabs(avg[3][2] - tall);
                rule[3][3] = fabs(avg[3][3] - dens);
                rule[3][4] = fabs(0.0);
                rule[3][5] = fabs(0.0);
                rule[3][6] = fabs(0.0);
                rule[3][7] = fabs(0.0);
                rule[3][8] = fabs(avg[3][8] - wlSp);
                rule[3][9] = fabs(avg[3][9] - bden);
                rule[3][10] = fabs(avg[3][10] - rden);
                rule[3][11] = fabs(avg[3][11] - lden);
                rule[3][12] = fabs(avg[3][12] - tden);
                rule[3][13] = fabs(avg[3][13] - ohhB);
                rule[3][14] = fabs(avg[3][14] - ohvB);
                rule[3][15] = fabs(avg[3][15] - ohTa);
                rule[3][16] = fabs(avg[3][16] - fnho);
                rule[3][17] = fabs(avg[3][17] - den1);
                rule[3][18] = fabs(avg[3][18] - den2);
                rule[3][19] = fabs(avg[3][19] - den3);
                rule[3][20] = fabs(avg[3][20] - den4);
            }
            if(hBal >= avg[5][0] - z*stdd[5][0]  && hBal <= avg[5][0] + z*stdd[5][0]
                    && vBal >= avg[5][1] - z*stdd[5][1] && vBal <= avg[5][1] + z*stdd[5][1]
                    && tall >= avg[5][2] - z*stdd[5][2] && tall <= avg[5][2] + z*stdd[5][2]
                    && dens >= avg[5][3] - z*stdd[5][3] && dens <= avg[5][3] + z*stdd[5][3]
                    && wlSp >= avg[5][8] - z*stdd[5][8] && wlSp <= avg[5][8] + z*stdd[5][8]
                    && cuts >= 2                        && cuts >= 3
                    && bden >= avg[5][9] - z*stdd[5][9] && bden <= avg[5][9] + z*stdd[5][9]
                    && rden >= avg[5][10] - z*stdd[5][10] && rden <= avg[5][10] + z*stdd[5][10]
                    && lden >= avg[5][11] - z*stdd[5][11] && lden <= avg[5][11] + z*stdd[5][11]
                    && tden >= avg[5][12] - z*stdd[5][12] && tden <= avg[5][12] + z*stdd[5][12]
                    //&&(fhol == 1 || fhol == 2)
                    && ohhB >= avg[5][13] - z*stdd[5][13] && ohhB <= avg[5][13] + z*stdd[5][13]
                    && ohvB >= avg[5][14] - z*stdd[5][14] && ohvB <= avg[5][14] + z*stdd[5][14]
                    && ohTa >= avg[5][15] - z*stdd[5][15] && ohTa <= avg[5][15] + z*stdd[5][15]
                    && fnho >= avg[5][16] - z*stdd[5][16] && fnho <= avg[5][16] + z*stdd[5][16]
                    && den1 >= avg[5][17] - z*stdd[5][17] && den1 <= avg[5][17] + z*stdd[5][17]
                    && den2 >= avg[5][18] - z*stdd[5][18] && den2 <= avg[5][18] + z*stdd[5][18]
                    && den3 >= avg[5][19] - z*stdd[5][19] && den3 <= avg[5][19] + z*stdd[5][19]
                    && den4 >= avg[5][20] - z*stdd[5][20] && den4 <= avg[5][20] + z*stdd[5][20]
                    ){
                //printf("5");
                rule[5][0] = fabs(avg[5][0] - hBal);
                rule[5][1] = fabs(avg[5][1] - vBal);
                rule[5][2] = fabs(avg[5][2] - tall);
                rule[5][3] = fabs(avg[5][3] - dens);
                rule[5][4] = fabs(0.0);
                rule[5][5] = fabs(0.0);
                rule[5][6] = fabs(0.0);
                rule[5][7] = fabs(0.0);
                rule[5][8] = fabs(avg[5][8] - wlSp);
                rule[5][9] = fabs(avg[5][9] - bden);
                rule[5][10] = fabs(avg[5][10] - rden);
                rule[5][11] = fabs(avg[5][11] - lden);
                rule[5][12] = fabs(avg[5][12] - tden);
                rule[5][13] = fabs(avg[5][13] - ohhB);
                rule[5][14] = fabs(avg[5][14] - ohvB);
                rule[5][15] = fabs(avg[5][15] - ohTa);
                rule[5][16] = fabs(avg[5][16] - fnho);
                rule[5][17] = fabs(avg[5][17] - den1);
                rule[5][18] = fabs(avg[5][18] - den2);
                rule[5][19] = fabs(avg[5][19] - den3);
                rule[5][20] = fabs(avg[5][20] - den4);
            }
            if(hBal >= avg[7][0] - z*stdd[7][0]  && hBal <= avg[7][0] + z*stdd[7][0]
                    && vBal >= avg[7][1] - z*stdd[7][1] && vBal <= avg[7][1] + z*stdd[7][1]
                    && tall >= avg[7][2] - z*stdd[7][2] && tall <= avg[7][2] + z*stdd[7][2]
                    && dens >= avg[7][3] - z*stdd[7][3] && dens <= avg[7][3] + z*stdd[7][3]
                    && wlSp >= avg[7][8] - z*stdd[7][8] && wlSp <= avg[7][8] + z*stdd[7][8]
                    && cuts >= 1                        && cuts <= 2/*3*/
                    && hcut == 1
                    && bden >= avg[7][9] - z*stdd[7][9] && bden <= avg[7][9] + z*stdd[7][9]
                    && rden >= avg[7][10] - z*stdd[7][10] && rden <= avg[7][10] + z*stdd[7][10]
                    && lden >= avg[7][11] - z*stdd[7][11] && lden <= avg[7][11] + z*stdd[7][11]
                    && tden >= avg[7][12] - z*stdd[7][12] && tden <= avg[7][12] + z*stdd[7][12]
                    //&&(fhol == 0 || fhol == 1)
                    && ohhB >= avg[7][13] - z*stdd[7][13] && ohhB <= avg[7][13] + z*stdd[7][13]
                    && ohvB >= avg[7][14] - z*stdd[7][14] && ohvB <= avg[7][14] + z*stdd[7][14]
                    && ohTa >= avg[7][15] - z*stdd[7][15] && ohTa <= avg[7][15] + z*stdd[7][15]
                    && fnho >= avg[7][16] - z*stdd[7][16] && fnho <= avg[7][16] + z*stdd[7][16]
                    && den1 >= avg[7][17] - z*stdd[7][17] && den1 <= avg[7][17] + z*stdd[7][17]
                    && den2 >= avg[7][18] - z*stdd[7][18] && den2 <= avg[7][18] + z*stdd[7][18]
                    && den3 >= avg[7][19] - z*stdd[7][19] && den3 <= avg[7][19] + z*stdd[7][19]
                    && den4 >= avg[7][20] - z*stdd[7][20] && den4 <= avg[7][20] + z*stdd[7][20]
                    ){
                //printf("7");
                rule[7][0] = fabs(avg[7][0] - hBal);
                rule[7][1] = fabs(avg[7][1] - vBal);
                rule[7][2] = fabs(avg[7][2] - tall);
                rule[7][3] = fabs(avg[7][3] - dens);
                rule[7][4] = fabs(0.0);
                rule[7][5] = fabs(0.0);
                rule[7][6] = fabs(0.0);
                rule[7][7] = fabs(0.0);
                rule[7][8] = fabs(avg[7][8] - wlSp);
                rule[7][9] = fabs(avg[7][9] - bden);
                rule[7][10] = fabs(avg[7][10] - rden);
                rule[7][11] = fabs(avg[7][11] - lden);
                rule[7][12] = fabs(avg[7][12] - tden);
                rule[7][13] = fabs(avg[7][13] - ohhB);
                rule[7][14] = fabs(avg[7][14] - ohvB);
                rule[7][15] = fabs(avg[7][15] - ohTa);
                rule[7][16] = fabs(avg[7][16] - fnho);
                rule[7][17] = fabs(avg[7][17] - den1);
                rule[7][18] = fabs(avg[7][18] - den2);
                rule[7][19] = fabs(avg[7][19] - den3);
                rule[7][20] = fabs(avg[7][20] - den4);
            }
        }
}

void zscore(int x, int y,
        double stdd[x][y], double avg[x][y], double rule[x][y], double zsc[x][y]){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(rule[i][j] != -1){
            if(stdd[i][j] == 0){
                    zsc[i][j] = 0;
                } else {
                    zsc[i][j] = rule[i][j]/stdd[i][j]; //assign values to z score array from formulae
                }
            }
        }
    }
}

