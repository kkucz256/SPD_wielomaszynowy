#include <algorithm>
#include "Problem.h"

Problem::Problem(vector<int> user_tasks) {
    this->tasks = user_tasks;
}


Result Problem::LSA() {
    Machine machine1 = Machine();
    Machine machine2 = Machine();
    machine1.add_task(tasks[0]);
    machine2.add_task(tasks[1]);

    for(int i=2;i<size(tasks);i++){
        if(machine1.sum_tasks() < machine2.sum_tasks())
        {
            machine1.add_task(tasks[i]);
        }
        else
        {
            machine2.add_task(tasks[i]);
        }

    }
    Result result = Result(machine1, machine2);
    return result;
}


Result Problem::LPT() {
    Machine machine1 = Machine();
    Machine machine2 = Machine();
    sort(tasks.begin(), tasks.end(), [](int a, int b) {
        return a > b;
    });
    for(int i=0;i<size(tasks);i++){
        if(i%2==0){
            machine1.add_task(tasks[i]);
        }
        else{
            machine2.add_task(tasks[i]);
        }

    }
    Result result = Result(machine1, machine2);
    return result;
}




