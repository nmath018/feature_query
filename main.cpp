//System Includes
#include <iostream> 

//User Includes
#include "seismic_data.h" //5K data points (uncomment in file to add more)
//#include "DN_Mean.h"
#include "MD_hrv.h"
#include "DN_HistogramMode_5.h"
#include "DN_HistogramMode_10.h"

const int TOTAL_DATA_SIZE = 270;
const int WINDOW_SIZE = 32; 
const int NUM_OF_WINDOWS = TOTAL_DATA_SIZE - WINDOW_SIZE; 
const int NUM_OF_FEATURES = 3; 

int main(int argc, char *argv[]) {

    /*
        Feature Score Matrix 

        number of features x number of windows

        number of features = 3 (22 in final implmentation)
        number of windows = total data size / window size
        total data size = 5000
        window size = 100
    
    */
    double fs_matrix[NUM_OF_FEATURES][NUM_OF_WINDOWS]; 
    double *input = (double*) malloc(sizeof(double) * WINDOW_SIZE);

    FILE * infile;
    infile = fopen("/home/pyuva001/feature_query/test_data/test.txt", "r");
    double * y = (double*) malloc(TOTAL_DATA_SIZE * sizeof(double));
    int size = 0;
    double value = 0;
    while (fscanf(infile, "%lf", &value) != EOF) {
        y[size++] = value;
    }

    for (int i = 0; i < NUM_OF_WINDOWS; i++) {
        //printf("%i : %lf \n", i, (y + i)[0]);
        zscore_norm2(y + i, WINDOW_SIZE, input);
        fs_matrix[0][i] = DN_HistogramMode_10(input, WINDOW_SIZE);
        fs_matrix[1][i] = MD_hrv_classic_pnn40(input, WINDOW_SIZE);
        fs_matrix[2][i] = DN_HistogramMode_5(input, WINDOW_SIZE);
    }

    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int j = 0; j < NUM_OF_WINDOWS; j++) {
            printf("%lf ", fs_matrix[i][j]);
        }
        printf("\n");
    }

    free(input);
    free(y);

}