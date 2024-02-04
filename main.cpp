#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> taskList;

void saveTasksToFile(const vector<string>& tasks, const string& filename) {
    ofstream outputFile(filename);

    if (outputFile.is_open()) {
        for (const string& task : tasks) {
            outputFile << task << "\n";
        }

        cout << "Tasks saved successfully.\n";
        outputFile.close();
    } else {
        cerr << "Error: Unable to open the file for saving tasks.\n";
    }
}

void loadTasksFromFile(vector<string>& tasks, const string& filename) {
    ifstream inputFile(filename);

    if (inputFile.is_open()) {
        tasks.clear();

        string task;
        while (getline(inputFile, task)) {
            tasks.push_back(task);
        }

        cout << "Tasks loaded successfully.\n";
        inputFile.close();
    } else {
        cerr << "Error: Unable to open the file for loading tasks.\n";
    }
}

void addTask() {
    cout << "Enter task name: ";
    string taskName;
    getline(cin, taskName);

    if (!taskName.empty()) {
        taskList.push_back(taskName);
        saveTasksToFile(taskList, "tasks.txt");
    } else {
        cout << "Enter a valid task.\n";
    }
}

void displayTasks() {
    cout << "Tasks:\n";
    for (const string& task : taskList) {
        cout << task << endl;
    }
}

void removeTask() {
    displayTasks();
    cout << "Task removed";
}

void markComplete() {
    cout << "Which task you want to mark as completed? " << endl;
    cout << "Tasks:\n";
    for (const string& task : taskList) {
        cout << task << endl;
    }
}

void deleteAllTasks() {
    cout << "Are you sure you want to delete all task? \n"
            "1. Yes \n"
            "2. No ";
    cout << "\n";
    int answer;
    cin >> answer;

    switch (answer) {
        case 1:
            taskList.clear();
            cout << "All task deleted successfully";
            break;
        case 2:
            cout << "No task deleted";
            break;
        default:
            cout << "Incorrect selection";
            break;
    }
}

void deleteLastTask() {
    cout << "Deleting the last task" << endl;
    taskList.pop_back();
    cout << "Last added task deleted" << endl;
}

int main() {
    cout << "--------------------------\n"
            "Welcome to keep notes \n"
            "--------------------------------- \n";

    cout << "\n";

    cout << "What do you want to do today? \n"
            "1. Add task \n"
            "2. Display task \n"
            "3. Mark task as Completed \n"
            "4. Delete all tasks present \n"
            "5. Delete the last task \n"
            "6. Exit program";

    cout << "\n";
    cout << "Enter number corresponding to task: ";
    int number;
    cin >> number;

    cin.ignore();

    switch (number) {
        case 1:
            addTask();
            break;
        case 2:
            removeTask();
            break;
        case 3:
            markComplete();
            break;
        case 4:
            deleteAllTasks();
            break;
        case 5:
            deleteLastTask();
            break;
        case 6:
            exit(0);
        default:
            cout << "Incorrect selection";
            break;
    }

    return 0;
}
