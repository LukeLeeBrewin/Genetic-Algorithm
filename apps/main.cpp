#include <iostream>
#include "test.h"
#include <vector>
#include "candidate.h"
#include <cstdlib>
#include <typeinfo>
#include <fstream>
#include "fitness.h"
#include <algorithm>
using namespace std; 


int main(){

    
    // std::cout << "Hello World!" << endl; 

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
    while (getline (MyReadFile, myText)) {
    // Output the text from the file
    y.push_back(std::stof(myText));
    }



    vector<float> candidate_solution = vec_candidates[1].sum_all_terms(); 

    vector<float> temp_mae;
    float MAE[num_generations][num_candidates];

    for (int i = 0; i < num_candidates; i++){
        temp_mae.push_back(fitness_function(y, vec_candidates[i].sum_all_terms()));
    }



    // This is probably rubbish
    sort(temp_mae.begin(), temp_mae.end());

    for(int i = 0; i < num_candidates; i++){
        MAE[0][i] = temp_mae[i];
        std::cout << MAE[0][i] << endl; 

        // Takes top two candidates and puts them in the next generation
        if(i < 2 && i !=num_generations-1){
            MAE[1][i] = temp_mae[i];
        }


    }


}