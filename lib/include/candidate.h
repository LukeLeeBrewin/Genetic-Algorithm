#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
#include <vector>
#include "term.h"
using namespace std;


class Candidate{

    public:
    Candidate(int aid, int anum_terms, vector <float> ax);
    int get_id(){return id;}
    int get_num_terms(){return num_terms;}
    vector<float> sum_all_terms();
    vector<Term> mutate_terms(int i); 

    private:
    int num_terms; 
    int id;
    vector <float> x;
    vector<Term> terms; 
    
};


#endif