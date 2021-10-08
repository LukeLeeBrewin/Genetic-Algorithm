#include <iostream>
#include <vector>
#include "generation.h"
#include <algorithm>
#include <random>
using namespace std; 
typedef std::pair<float, Candidate> pairs;

Generation::Generation(int anum_candidates, vector<Candidate> vec_of_candidates, vector<float> adata):
num_candidates{anum_candidates}, 
vec_generation{vec_of_candidates}, 
data{adata}
{};


// Returns mean absolute error of two vectors of equal size
float Generation::fitness_function(vector<float> candidate_solution){

    float temp = 0;

    for(int i = 0; i < size(data); i++){
        temp = temp + abs(data[i]-candidate_solution[i]);
    }

float MAE = temp/size(data);

return MAE;};




vector<pairs> Generation::get_sorted_loss(){

    
    // If first generation, add to vector, if not, change values. 
    if(loss_candidate.size() == 0){
    for(int i = 0; i < num_candidates; i++){
        
        float mae = fitness_function(vec_generation[i].sum_all_terms());
        loss_candidate.push_back(make_pair(mae, vec_generation[i]));

    }
    }
    // If vector is not empty edit values
    else{

        for(int i = 0; i < num_candidates; i++){
            float mae = fitness_function(loss_candidate[i].second.sum_all_terms());
            std::cout << mae << std::endl;
            // loss_candidate[i] = make_pair(mae, loss_candidate[i].second);
            loss_candidate[i].first = mae;
            }

    }

    sort(loss_candidate.begin(), loss_candidate.end(), [](pairs a, pairs b){ return a.first < b.first; });
    
    // Display min value
    std::cout << "The smallest loss value in this generation is: " << loss_candidate[0].first << "\n\n" << endl;


    return loss_candidate; 
};


vector<pairs> Generation::mutate_candidates(){

    //std::cout << loss_candidate.size() << " is the size of loss_candidate" << endl;
    // Keep the 2 best and mutate the rest
    for(int i = 2; i < loss_candidate.size(); i++){

        // Random number between 0 and 1
        float random_number = rand() / double(RAND_MAX);
    
        // 20% Chance of mutation
        if(random_number < 0.5){
            std::cout << "Candidate " << i << " will be mutated" << endl;
            loss_candidate[i].second.mut8ate_terms(i); 
        }
    }
return loss_candidate;}