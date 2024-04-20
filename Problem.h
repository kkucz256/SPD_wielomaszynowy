#ifndef PROBLEM_H
#define PROBLEM_H

#include "Machine.h"
#include "Result.h"

class Problem {
    vector<int> tasks;
public:
    Problem(vector<int> user_tasks);
    int criteria(Machine machine1, Machine machine2);
    Result LSA();
    Result LPT();
    Result dynamic_programming();
};

#endif // PROBLEM_H