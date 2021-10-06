#include <iostream>
#include "candidate.h"
#include <vector>
#include <cstdlib>
using namespace std;

Candidate::Candidate(int aid, int anum_terms, vector <float> ax):
id{aid}, num_terms{anum_terms}, x{ax}
{
    // Initialise Terms
    for(int i = 0; i < num_terms; i++){

        // Initialise Random Powers and Coeffs for Term
        // 1 - 5 
        float coeff = (float)(rand() % 5 + 1);
        float power = (float)(rand() % 5 + 1); 
        terms.push_back(Term{coeff, power, x});
    }

};

vector<float> Candidate::sum_all_terms(){
    vector<float> y(x.size(), 0.0); 
    for(int i = 0; i < num_terms; i++){

        // Create vector of sum of the ith term
        vector<float> term_sum = terms[i].sum_term(); 

        for(int j = 0; j < x.size(); j++){
            // Elementwise addition of terms
            y[j] = y[j] + term_sum[j];
        }

    }
return y;}



