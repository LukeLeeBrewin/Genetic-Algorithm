#include <iostream>
#include <vector>
#include "candidate.h"
#include <cstdlib>
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include "generation.h"
#include <string>
#include <utility>





int main(){

   
 

    const int num_candidates = 10;
    const int num_generations = 100;
    


    vector <float> x; 
    vector <Candidate> vec_candidates;

    // Create x range 
    int steps = 1000;
    float xmax = 5.0;
    float xmin = -5.0;
    float delta = (xmax - xmin)/steps;


    // Linearly spaced points
    for(int i = 0; i <=steps; i++){
        x.push_back(delta*i + xmin);
        // std::cout << x[i] << endl;
    }

    // Initialise Candidates in Vector
    for(int i = 0; i <=num_candidates; i++){
        int rand_num_terms = rand() % 5 + 1;
        vec_candidates.push_back(Candidate{i, rand_num_terms, x});
    }


    // Read in data.csv
    string myText; 
    ifstream MyReadFile("../../../data/data.txt");
    vector<float> y;

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
    // Output the text from the file
    y.push_back(stof(myText));
    }





    Generation gens{num_candidates, vec_candidates, y};
    for(int i = 0; i < num_generations; i++){

        gens.get_sorted_loss();


        // for(int j = 0; j < gens.get_current_candidates().size(); i++){
        gens.mutate_candidates(); 
        // }

    }





}