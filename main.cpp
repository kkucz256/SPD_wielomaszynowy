#include <iostream>
#include "Problem.h"

using namespace std;
int main() {
    vector<int>tasks{2,1,3,4,5,3};
    Problem problem = Problem(tasks);
    Result result1 = problem.LSA();
    Result result2 = problem.LPT();
    result1.print_results();
    result2.print_results();


}
