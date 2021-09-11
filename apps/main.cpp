#include <iostream>
#include "test.h"
#include <vector>
#include "candidate.h"
#include <cstdlib>
#include <typeinfo>
using namespace std; 


int main(){

    
    // std::cout << "Hello World!" << endl; 

    int num_candidates = 10;
    int num_generations = 100;
    


    vector <float> x; 
    vector <Candidate> vec_candidates;

    // Create x range 
    int steps = 1000;
    float xmax = 5.0;
    float xmin = -5.0;
    float delta = (xmax - xmin)/steps;
    std::cout << delta << endl;

    // Linearly spaced points
    for(int i = 0; i <=steps; i++){
        x.push_back(delta*i + xmin);
        // std::cout << x[i] << endl;
    }
    

    // Initialise Candidates in Vector
    for(int i = 0; i <=num_candidates; i++){
        int rand_num_terms = rand() % 5 + 1;
        vec_candidates.push_back(Candidate{i, rand_num_terms, x});
        // std::cout << vec_candidates[i].get_num_terms() << endl;
    }


    vec_candidates[1].sum_all_terms(); 

}