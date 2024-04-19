
#include "Result.h"

Result::Result(Machine machineA, Machine machineB) {
    this->machine1 = machineA;
    this->machine2 = machineB;
}

int Result::criteria() {
    int max_time = max(machine2.sum_tasks(), machine1.sum_tasks());
    return max_time;
}

void Result::print_results() {
    string all_tasks_combined_1;
    string all_tasks_combined_2;
    for(int task : machine1.get_tasks()){
        all_tasks_combined_1 += to_string(task) + " ";
    }
    cout << "All tasks in machine no."<< this->machine1.get_index() <<": " << all_tasks_combined_1 <<endl;

    for(int task : machine2.get_tasks()){
        all_tasks_combined_2 += to_string(task) + " ";
    }
    cout << "All tasks in machine no."<< this->machine2.get_index() <<": " << all_tasks_combined_2 <<endl;

    cout << "Cmax for this instance: " << criteria() << endl;
}


