#include <iostream>
#include "candidate.h"
using namespace std;

Candidate::Candidate(string aname):
name{aname}{}

string Candidate::get_name(){
    return name;
    }

