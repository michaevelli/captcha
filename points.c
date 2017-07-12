//name: michael
//date: 20170425
//give points towards possible digit based on percentage deviation from mean

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int points(int x, int y, double array[x][y], double array2[x][y]){
    srand(time(NULL));
    int num = rand()%10;

    double pnt[x];
    for(int i = 0; i < x; i++){             //create and initilise pnt array. This will hole the total score of each digit, or "-1" if the attributes are incompatible
        pnt[i] = -1;
    }

    for(int i = 0; i < x; i++){            //for every digit there is
        int hook = 1;
        //counter = 0;
        for(int j = 0; j < y; j++){        //for every attribute in a digit
            if(array[i][j] == -1){         //if the attribute is incompatible, break
                break;
            } else {
                if(hook){                  //for the first compatible digit for the first time
                    pnt[i] = 0;            //change the value in pnt to "0"
                    hook = 0;
                }
                pnt[i] += (1/sqrt(2*M_PI))*pow(M_E ,(-pow(2,array[i][j]))/2);   //then add and keep adding the weighted percentage difference to the array

            }
        }
    }

    for(int i = 0; i < x; i++){            //find a valid, compatible integer
        if(pnt[i] != -1){
            num = i;
            break;
        }
    }

    for(int i = 0; i < x; i++){            //chooses the integer with the highest score
        if(pnt[num] < pnt[i] && pnt[i] != -1){
            num = i;
        }
    }


    return num;                            //returns the digit
}