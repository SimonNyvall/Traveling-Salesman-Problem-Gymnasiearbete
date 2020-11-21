#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

// Global Varibles.
const int populationSize = 10;
const int citySize = 5;


int _population[populationSize][citySize];


int order[citySize] = { 0,1,2,3,4 };
int cityPoints[citySize][2]; // [0]city -> [1]point x, y


// shuffle function
void shuffle(int deck[]) {
    int temp = 0;
    int randomIndex = 0;
    for (int i = 0; i < citySize; i++) {
        randomIndex = rand() % citySize;
        temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

void setRandomCityPoint(int cityIndex) {
    // map of 100x100 points
    for (int i = 0; i <= citySize; i++) {
        for (int j = 0; j < 2; j++) {
            cityPoints[i][j] = (rand() % 100 + 1);
        }
    }
}

void calcDistace(int pointA[], int pointB[]) {
    int d = sqrt(pow(pointA[0] - pointA[1]), 2 + pow(pointB[0] - pointB[1]), 2));
}

int main() {
    srand(time(NULL)); // Seeds the random number generator

    // Populate the population with an array from 0..5 according to the city size
    for (int i = 0; i <= populationSize; i++) {
        for (int j = 0; j < citySize; j++) {
            _population[i][j] = order[j];
        }
    }
    
    // Shuffle the array
    for (int arrayCount = 0; arrayCount < populationSize; arrayCount++) {
        shuffle(_population[arrayCount]);
    }

    // ------------------------------------------------------------------------
    for (int i = 0; i < citySize; i++) {
        setRandomCityPoint(i);
    }


    // print population
    for (int i = 0; i <= citySize; i++) {
        for (int j = 0; j < 2; j++) {
            //std::cout << _population[i][j] << std::endl;
            std::cout << cityPoints[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    //std::cout << _population[0][0] << std::endl;

    
}


