#ifndef PROBLEM_H
#define PROBLEM_H

#include "Machine.h"
#include "Result.h"

class Problem {
    vector<int> tasks;
public:
    Problem(vector<int> user_tasks);
    Result LSA();
    Result LPT();
};

#endif // PROBLEM_H