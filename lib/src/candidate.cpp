#include <iostream>
#include "candidate.h"
#include <vector>
#include <cstdlib>
#include <random>
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
    vector<float> total_sum(x.size(), 0.); 

    // gets vector of term values along x axis 
    vector<float> term_sum; 
    for(int i = 0; i < num_terms; i++){
        term_sum = terms[i].sum_term();

        // adds term to total (still a vector for each point along x axis)
        for(int j = 0; j < x.size(); j++){
            total_sum[j] += term_sum[j]; 
        }

    }

return total_sum;}

vector<Term> Candidate::mutate_terms(int i ){

    for(int i = 0; i < terms.size(); i++){

    // Random number between 0 and 1
    float random_number = rand() / double(RAND_MAX);

    if(random_number < 0.5){
        
        terms[i].set_power();
        terms[i].set_coeff();

        //std::cout << "A term and power have been changed: " << endl;

    }

    }
    
    return terms;
}



