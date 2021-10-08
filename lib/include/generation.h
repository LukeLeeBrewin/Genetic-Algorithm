#ifndef GENERATION_H
#define GENERATION_H


#include <iostream>
#include <vector>
#include "candidate.h"
#include <utility>
using namespace std;

typedef std::pair<float, Candidate> pairs;
class Generation{
    public:
    Generation(int anum_candidates, vector<Candidate> vec_of_candidates, vector<float> adata); 
    float fitness_function(vector<float> candidate_solution);
    vector<pairs> get_sorted_loss();
    vector<pairs> mutate_candidates();
    vector<Candidate> get_current_candidates(){return vec_generation;};
    vector<pairs> get_loss_candidate(){return loss_candidate;};

    private:
    vector<Candidate> vec_generation;
    int num_candidates;
    vector<float> data; 
    vector<pairs> loss_candidate;



};


#endif