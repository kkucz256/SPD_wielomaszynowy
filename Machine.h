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
    int get_index();

    void add_task(int number);
    void print_tasks();
    int sum_tasks();

};

#endif // MACHINE_H

