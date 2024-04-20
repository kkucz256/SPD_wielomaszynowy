#ifndef RESULT_H
#define RESULT_H
#include "Machine.h"

class Result {
    Machine machine1;
    Machine machine2;
    int criteria;
public:
    Result(Machine machineA, Machine machineB, int criteria);
    void print_results();
};

#endif //RESULT_H
