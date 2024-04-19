#include <string>
#include <iostream>
#include "Machine.h"

int Machine::machineCount = 0;

Machine::Machine() {
    machineCount++;
    index = machineCount;
}
std::vector<int> Machine::get_tasks(){
    return tasks;
}

int Machine::get_index(){
    return index;
}

void Machine::add_task(int number) {
    this->tasks.push_back(number);
}


void Machine::print_tasks() {
    string all_tasks_combined;
    for(int task : tasks){
        all_tasks_combined += to_string(task) + " ";
    }
    cout << "All tasks in machine no."<< this->index <<": " << all_tasks_combined <<endl;
}

int Machine::sum_tasks() {
    int all_tasks = 0;
    for(int task : tasks){
        all_tasks += task;
    }
    return all_tasks;
}



