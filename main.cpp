#include <iostream>
#include <chrono>
#include "Problem.h"

using namespace std;
using namespace chrono;

int main() {
    //10 tasks 1-10 vector<int> tasks{3, 7, 3, 4, 9, 4, 6, 2, 6, 1};
    //10 tasks 10-20 vector<int>tasks{17,17,14,12,19,13,17,18,15,10};
    //15 tasks 1-10 vector <int> tasks{4,1,1,1,6,7,4,6,6,2,8,9,4,3,8};
    //15 tasks 10-20 vector<int> tasks{20,12,12,15,20,12,15,19,11,15,11,15,18,18,15};
    //20 tasks 1-10 vector<int> tasks{4,9,1,7,2,1,6,4,10,5,9,2,10,4,6,2,6,7,8,9};
    //20 tasks 10-20 vector<int> tasks{18,12,18,16,13,19,13,13,20,19,16,10,17,14,12,10,18,13,18,14};
    //20 tasks 50-100 vector<int> tasks{99, 91, 78, 66, 99, 99, 75, 65, 63, 64, 93, 95, 75, 71, 50, 62, 77, 58, 82, 56};
    vector<int> tasks{4, 10, 10, 2, 9, 6, 7, 6, 2, 7, 7, 3, 7, 8, 3, 4, 6, 4, 8, 9, 10, 6, 4, 9, 9};


    Problem problem = Problem(tasks);

    steady_clock::time_point startLSA = steady_clock::now();
    Result result1 = problem.LSA();
    steady_clock::time_point endLSA = steady_clock::now();
    duration<double, milli> elapsedLSA = endLSA - startLSA;
    cout << "\nLSA time: " << elapsedLSA.count() << " ms" << endl;
    cout << "LSA results: " << endl;
    result1.print_results();

    steady_clock::time_point startLPT = steady_clock::now();
    Result result2 = problem.LPT();
    steady_clock::time_point endLPT = steady_clock::now();
    duration<double, milli> elapsedLPT = endLPT - startLPT;
    cout << "\nLPT time: " << elapsedLPT.count() << " ms" << endl;
    cout << "LPT results: " << endl;
    result2.print_results();

    steady_clock::time_point startDP = steady_clock::now();
    Result result3 = problem.dynamic_programming();
    steady_clock::time_point endDP = steady_clock::now();
    duration<double, milli> elapsedDP = endDP - startDP;
    cout << "\nDynamic Programming time: " << elapsedDP.count() << " ms" << endl;
    cout << "Dynamic Programming results: " << endl;
    result3.print_results();


    steady_clock::time_point startBF = steady_clock::now();
    Result result4 = problem.bruteforce();
    steady_clock::time_point endBF = steady_clock::now();
    duration<double, milli> elapsedBF = endBF - startBF;
    cout << "\nBruteforce time: " << elapsedBF.count() << " ms" << endl;
    cout << "Bruteforce results: " << endl;
    result4.print_results();



    return 0;


}
