
#include <stdio.h>
void drawline(int holeheight, int holewidth, int holetest[holeheight][holewidth]){
    int x = 0;
    int first = 0;
    for(int i = 0; i < holewidth; i++){
        int count = 0;
        for(int j = 0; j < holeheight; j++){
            if(holetest[j][i] == 1 && j < holeheight-1 && i < holewidth-2){
                if(holetest[j+1][i] == 0){
                    count++;
                }
            }
        }
        if(count > 1){
            if(first == 1){
                x = i;
                break;
            }
            first++;
        }
    }
    for(int i = 1; i < holeheight-1; i++){
        holetest[i][x] = 1;
    }
}