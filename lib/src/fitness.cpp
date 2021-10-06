#include <iostream>
#include <vector>
using namespace std;

// Returns mean absolute error of two vectors of equal size
float fitness_function(vector<float> data, vector<float> candidate_solution){

    float temp = 0;

    for(int i = 0; i < size(data); i++){
        temp = temp + abs(data[i]-candidate_solution[i]);
    }

float MAE = temp/size(data);

return MAE;
};