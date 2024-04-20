#include "Result.h"

Result::Result(Machine machineA, Machine machineB, int criteria) {
    this->machine1 = machineA;
    this->machine2 = machineB;
    this->criteria = criteria;
}


void Result::print_results() {
    string all_tasks_combined_1;
    string all_tasks_combined_2;
    for(int task : machine1.get_tasks()){
        all_tasks_combined_1 += to_string(task) + " ";
    }
    cout << "All values in machine no. 1: " << all_tasks_combined_1 <<endl;

    for(int task : machine2.get_tasks()){
        all_tasks_combined_2 += to_string(task) + " ";
    }
    cout << "All values in machine no. 2: " << all_tasks_combined_2 <<endl;

    cout << "Criteria for this instance: " << criteria << endl;
}


