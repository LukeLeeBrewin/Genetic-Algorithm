#include <iostream>
#include "term.h"
#include <vector>
#include <cmath>
#include <random>


Term::Term(float acoeff, float apower, vector<float> ax):
coeff{acoeff},
power{apower}, 
x{ax}{};

vector<float> Term::sum_term(){
    int size = x.size(); 
    vector<float> output;
    for(int i = 0; i < size; i++){
        output.push_back(coeff*pow(x[i], power));
    }
    return output;
};

float Term::set_power(){

    // Random number between 0 and 1
    float random_number = (rand() * 4 / double(RAND_MAX)) - 2;
    //std::cout << "A power has been changed from: " << power << " to " << power * random_number << endl;
    power = power * random_number;
    return power; 
}


float Term::set_coeff(){

    // Random number between 0 and 1
    float random_number = (rand() * 4 / double(RAND_MAX)) - 2;
    coeff = coeff * random_number;
    return coeff; 
}