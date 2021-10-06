#ifndef GENERATION_H
#define GENERATION_H


#include <iostream>
#include <vector>
#include "candidate.h"
using namespace std;


class Generation{
    public:
    Generation(int anum_candidates, vector<Candidate> vec_of_candidates); 
    vector<Candidate> mutate_coeffs();
    vector<Candidate> mutate_power();



    private:
    vector<Candidate> vec_generation;
    int num_candidates;


};


#endif