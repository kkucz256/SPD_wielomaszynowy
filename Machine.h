#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <vector>


using namespace std;

class Machine {
    vector<int> tasks;
    static int machineCount;
    int index;
public:
    Machine();
    vector<int> get_tasks();
    void add_task(int number);
    int sum_tasks();
    bool has_task(int task) const;
};

#endif // MACHINE_H

