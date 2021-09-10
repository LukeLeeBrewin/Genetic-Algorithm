#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <iostream>
using namespace std;


class Candidate{

    public:
    Candidate(string aname);
    string get_name();

    private:
    string name; 
};


#endif