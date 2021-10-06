#ifndef GENERATION_H
#define GENERATION_H


#include <iostream>
#include <vector>
#include "candidate.h"
using namespace std;


class Generation{
    public:
    Generation(int anum_candidates, vector<Candidate> vec_of_candidates, vector<float> adata); 
    vector<Candidate> mutate_coeffs();
    vector<Candidate> mutate_power();
    float fitness_function(vector<float> candidate_solution);
    vector<float> get_sorted_loss();


    private:
    vector<Candidate> vec_generation;
    int num_candidates;
    vector<float> data; 


};


#endif