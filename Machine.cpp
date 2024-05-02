#include "Machine.h"

int Machine::machineCount = 0;

Machine::Machine() {
    machineCount++;
    index = machineCount;
}

std::vector<int> Machine::get_tasks(){
    return tasks;
}

void Machine::add_task(int number) {
    this->tasks.push_back(number);
}

int Machine::sum_tasks() {
    int all_tasks = 0;
    for(int task : tasks){
        all_tasks += task;
    }
    return all_tasks;
}

bool Machine::has_task(int task) const{
    for(int t : tasks) {
        if(t == task) {
            return true;
        }
    }
    return false;
}



