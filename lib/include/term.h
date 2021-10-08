#ifndef TERM_H
#define TERM_H

// Term class because this program requires access to multiple parts of a term

#include <iostream>
#include <vector>
using namespace std; 

class Term{

    public:
    Term(float acoeff, float apower, vector<float> ax);
    float get_coeff(){return coeff;}
    float get_power(){return power;}
    float set_power();
    float set_coeff();
    vector<float> sum_term();


    private:
    float coeff; 
    float power; 
    vector <float> x; 

};

#endif