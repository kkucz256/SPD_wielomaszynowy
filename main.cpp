#include <iostream>
#include "Problem.h"

using namespace std;
int main() {
    vector<int>tasks{3,4,1,5,7,3};
    Problem problem = Problem(tasks);

    Result result1 = problem.LSA();
    Result result2 = problem.LPT();
    Result result3 = problem.dynamic_programming();
    Result result4 = problem.bruteforce();



    cout << "\nLSA results: " << endl;
    result1.print_results();
    cout << "\nLPT results: " << endl;
    result2.print_results();
    cout << "\nDynamic results: " << endl;
    result3.print_results();
    cout << "\nBruteforce results: " << endl;
    result4.print_results();




}
