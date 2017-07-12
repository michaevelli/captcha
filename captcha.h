//name: michael
//date: 20170410

int read_pbm(char filename[], int height, int width, int pixels[height][width]);
int get_pbm_dimensions(char filename[], int *height, int *width);
void print_image(int height, int width, int pixels[height][width]);
void get_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);
void copy_pixels(int height, int width, int pixels[height][width],
                 int start_row, int start_column, int copy_height, int copy_width,
                 int copy[copy_height][copy_width]);
double get_horizontal_balance(int height, int width, int pixels[height][width]);
double get_vertical_balance(int height, int width, int pixels[height][width]);


void floodfill(int imax, int jmax, int node[imax][jmax], int i, int j);
void createborder(int height, int width, int pixels[height][width],
                 int copy[height+2][width+2]);
int hashole(int imax, int jmax, int pixels[imax][jmax]);


double density(int width, int height, int pixels[width][height]);
double holedensity(int width,int height, int pixels[width][height]);
double get_tallness(int height, int width);
double densitybot(int width, int height, int pixels[width][height]);
double densityrig(int width, int height, int pixels[width][height]);
double densitylef(int width, int height, int pixels[width][height]);
double densitytop(int width, int height, int pixels[width][height]);
double densityNW(int width, int height, int pixels[width][height]);
double densityNE(int width, int height, int pixels[width][height]);
double densitySW(int width, int height, int pixels[width][height]);
double densitySE(int width, int height, int pixels[width][height]);


void hole_bounding_box(int height, int width, int pixels[height][width],
                  int *start_row, int *start_column, int *box_height, int *box_width);
double hole_horizontal_balance(int height, int width, int pixels[height][width]);
double hole_vertical_balance(int height, int width, int pixels[height][width]);
double hole_tallness(int height, int width, int pixels[height][width]);

double white_left_ratio(int height, int width, int pixels[height][width]);

int get_cuts(int height, int width, int array[height][width], int x);
int get_hori_cut(int height, int width, int array[height][width], int x);

void drawline(int holeheight, int holewidth, int holetest[holeheight][holewidth]);

void average(int x, int y, double array[x][y]);
void deviation(double vBal, double hBal, double tall, double dens, double hDens, int hole, double hhBl, double hvBl, double hTal, double wlSp, int cuts, double hcut, double bden, double rden, double lden, double tden, int fhol, double ohhB, double ohvB, double ohTa, double fnho, double den1, double den2, double den3, double den4,
        int x, int y, double rule[x][y], double avg[x][y], double z,
        double stdd[x][y]);
void standardd(int x, int y, double array[x][y]);
void zscore(int x, int y,
        double stdd[x][y], double avg[x][y], double rule[x][y], double zsc[x][y]);
int points(int x, int y, double array[x][y], double array2[x][y]);


int crack_digit(int box_height, int box_width, int box_pixels[box_height][box_width],
        int x, int y, double z);


void split(int height, int width, int array[height][width],
        int array1[height][width],
        int array2[height][width],
        int array3[height][width],
        int array4[height][width]);
void splitchallenge(int height, int width, int array[height][width],
        int array1[height][width],
        int array2[height][width],
        int array3[height][width],
        int array4[height][width]);