#include <iostream>
#include <vector>
#include "generation.h"



Generation::Generation(int anum_candidates):
num_candidates{anum_candidates}, 
vec_generation{vec_of_candidates}
{};

vector<Candidate> Generation::mutate_coeffs(){
    return vec_generation;
};

vector<Candidate> Generation::mutate_power(){
    return vec_generation;
};