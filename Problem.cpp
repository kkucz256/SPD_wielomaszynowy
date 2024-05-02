#include <algorithm>
#include "Problem.h"

Problem::Problem(vector<int> user_tasks) {
    this->tasks = user_tasks;
}

//Criteria - maximum value between the sum of tasks in 1st machine and 2nd machine
int Problem::criteria(Machine machine1, Machine machine2) {
    int max_time = max(machine2.sum_tasks(), machine1.sum_tasks());
    return max_time;
}

//LSA - task goes to the first free machine (machine with the smaller sum)
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
    int cmax = criteria(machine1, machine2);
    Result result = Result(machine1, machine2, cmax);
    return result;
}

//LPT - task goes to the first free machine, but they are ordered descending
Result Problem::LPT() {
    Machine machine1 = Machine();
    Machine machine2 = Machine();
    vector<int> tasks_cpy = tasks;
    sort(tasks_cpy.begin(), tasks_cpy.end(), [](int a, int b) {
        return a > b;
    });

    machine1.add_task(tasks_cpy[0]);
    machine2.add_task(tasks_cpy[1]);
    for(int i=2;i<size(tasks_cpy);i++){
        if(machine1.sum_tasks() < machine2.sum_tasks())
        {
            machine1.add_task(tasks_cpy[i]);
        }
        else
        {
            machine2.add_task(tasks_cpy[i]);
        }

    }

    int cmax = criteria(machine1, machine2);
    Result result = Result(machine1, machine2, cmax);
    return result;
}

//Dynamic programming
Result Problem::dynamic_programming() {
    Machine machine1 = Machine();
    Machine machine2 = Machine();
    vector<int> tasks_copy = tasks;

    int sum_of_tasks = 0;
    for(int task: tasks){
        sum_of_tasks += task;
    }

    int columns = sum_of_tasks/2 +1;
    int rows = tasks.size() + 1;

    //Nested vector that creates array T
    vector<vector<int>> T(rows, vector<int>(columns, 0));

    //Filling first column with 1s
    for (int i = 0; i < rows; i++) {
        T[i][0] = 1;
    }

    //Filling rows with algorithm from file
    for (int j = 1; j < rows; j++) {
        for (int k = 1; k < columns; k++) {
            if (T[j-1][k] == 1 || (k >= tasks[j-1] && T[j-1][k - tasks[j-1]] == 1)) {
                T[j][k] = 1;
            }
        }
    }


    //Printing the matrix
    /*
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
    */

    //Backtracking - if there is a zero above 1 in current column add the item tasks[row_no] to machine 1, change the
    //item at the same index in copy of tasks to 0, then decrease the column index by its value and do the same
    int current_row = rows - 1;
    int current_column = columns - 1;

    while (current_row >= 0 && current_column > 0) {
        if (T[current_row][current_column] == 1 && T[current_row - 1][current_column] == 0) {
            machine1.add_task(tasks[current_row - 1]);
            tasks_copy[current_row - 1] = 0;
            current_column -= tasks[current_row - 1];
        }
        current_row--;
    }

    //Tasks that are not added to machine 1 (that are not == 0) go to machine 2
    for (int task : tasks_copy) {
        if (task != 0) {
            machine2.add_task(task);
        }
    }

    int cmax = criteria(machine1, machine2);
    Result result = Result(machine1, machine2, cmax);
    return result;
}



Result Problem::bruteforce(){
    Machine best_machinen1 = Machine();
    Machine best_machinen2 = Machine();
    std::vector<int> tasks_copy = tasks;

    int best_cmax = INT_MAX;
    long int all_combinations = pow(2,size(tasks));

    for(int i=0; i < all_combinations ;++i){
        Machine machine1 = Machine();
        Machine machine2 = Machine();

        for(int j=0; j < size(tasks); ++j){

            if(i & (1 <<j)){
                machine1.add_task(tasks[j]);
            }
            else {
                machine2.add_task(tasks[j]);
            }
        }
        //Check if tasks were spread
            int cmax = criteria(machine1, machine2);

            if (cmax < best_cmax) {
                best_cmax = cmax;
                best_machinen1 = machine1;
                best_machinen2 = machine2;

            }

            cout << "Bruteforce configuration " << i << ":" << endl;
            cout << "Machine 1:\tMachine 2:\n  ";
            for (int k = 0; k < tasks.size(); ++k) {
                if (machine1.has_task(tasks[k])){
                    cout << "1"; // Zadanie na maszynie 1
                } else {
                    cout << "0"; // Brak zadania na maszynie 1
                }
            }
            cout << "\t";

            for (int k = 0; k < tasks.size(); ++k) {
                if (machine2.has_task(tasks[k])) {
                    cout << "1"; // Zadanie na maszynie 2
                } else {
                    cout << "0"; // Brak zadania na maszynie 2
                }
            }
            cout << "\n";

            cout << "Criteria: " << cmax << endl;
            cout << endl;
        //}
    }

    Result result = Result(best_machinen1, best_machinen2, best_cmax);
    return result;
}






