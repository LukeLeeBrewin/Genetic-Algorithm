#include <iostream>
#include <vector>
#include "generation.h"
#include <algorithm>



Generation::Generation(int anum_candidates, vector<Candidate> vec_of_candidates, vector<float> adata):
num_candidates{anum_candidates}, 
vec_generation{vec_of_candidates}, 
data{adata}
{};

vector<Candidate> Generation::mutate_coeffs(){
    return vec_generation;
};

vector<Candidate> Generation::mutate_power(){
    return vec_generation;
};


// Returns mean absolute error of two vectors of equal size
float Generation::fitness_function(vector<float> candidate_solution){

    float temp = 0;

    for(int i = 0; i < size(data); i++){
        temp = temp + abs(data[i]-candidate_solution[i]);
    }

float MAE = temp/size(data);

return MAE;};




vector<float> Generation::get_sorted_loss(){

    vector<float> sorted_loss;
    
    for(int i = 0; i < num_candidates; i++){
        
        float mae = fitness_function(vec_generation[i].sum_all_terms());
        sorted_loss.push_back(mae);
    }
    sort(sorted_loss.begin(), sorted_loss.end());


    return sorted_loss; 
};
