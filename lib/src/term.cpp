#include <iostream>
#include "term.h"
#include <vector>
#include <cmath>


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