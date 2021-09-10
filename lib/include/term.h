#ifndef TERM_H
#define TERM_H

// Term class because this program requires access to multiple parts of a term

#include <iostream>
using namespace std; 

class Term{

    public:
    Term(float acoeff, float apower);
    float get_coeff(){return coeff;}
    float get_power(){return power;}


    private:
    float coeff; 
    float power; 


};

#endif