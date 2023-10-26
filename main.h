//System Includes
#include <iostream> 

//User Includes
#include "seismic_data.h" //5K data points (uncomment in file to add more)
#include "DN_Mean.h"
#include "FC_LocalSimple.h"
#include "DN_HistogramMode_5.h"
#include "stats.h"

const int TOTAL_DATA_SIZE = 5000;
const int WINDOW_SIZE = 100; 
const int NUM_OF_WINDOWS = TOTAL_DATA_SIZE/WINDOW_SIZE; 
const int NUM_OF_FEATURES = 3; 