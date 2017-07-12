//name: michael
//date: 20170422
//create a border of blank pixels
//floodfill exterior pixels for easier analysis

void createborder(int height, int width, int pixels[height][width],
                 int copy[height+2][width+2]){
    for(int i = 0; i < height+2; i++){         //initilises copy array to 0
        for(int j = 0; j < width+2; j++){      //provides a blank canvass
            copy[i][j] = 0;
        }
    }
    for(int i = 0; i < height; i++){          //copies the pixels rray to copy from (1, 1)
        for(int j = 0; j < width; j++){       //this results in a "0" pixel border around the pixels array
            copy[i+1][j+1] = pixels[i][j];    //it joins the whitespace in each corner and side of the image
        }
    }

}



void floodfill(int imax, int jmax, int node[imax][jmax], int i, int j){    //standard floodfill algorithm
    if(i >= imax            //if the (i,j) coordinates provided are outside the range of the node array, or the given coordinates point to a black pixel , stop the function
            || i < 0
            || j >= jmax
            || j < 0){
        return;
    } else if(node[i][j] == 1){
        return;
    } else {
        node[i][j] = 1;     //otherwise, turn the white to a black pixel

        //floodfill recursion: perform floodfill around the pixel that was provided;
        floodfill(imax, jmax, node, i-1, j-1);  //iterate floodfill to NW
        floodfill(imax, jmax, node, i-1, j  );  //iterate floodfill to N
        floodfill(imax, jmax, node, i-1, j+1);  //iterate floodfill to NE
        floodfill(imax, jmax, node, i  , j-1);  //iterate floodfill to W
        floodfill(imax, jmax, node, i  , j+1);  //iterate floodfill to E
        floodfill(imax, jmax, node, i+1, j-1);  //iterate floodfill to SW
        floodfill(imax, jmax, node, i+1, j  );  //iterate floodfill to S
        floodfill(imax, jmax, node, i+1, j+1);  //iterate floodfill to SE
    }


    return;
}