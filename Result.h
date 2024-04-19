#include "Machine.h"

class Result {
    Machine machine1;
    Machine machine2;
public:
    Result(Machine machineA, Machine machineB);
    int criteria();
    void print_results();
};


