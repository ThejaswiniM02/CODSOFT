#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Task {
    string description;
    bool completed;
};
// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markAsCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);
int main() {
    vector<Task> tasks;
    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 5);

    return 0;
}
void displayMenu() {
    cout << "\nTO-DO LIST MANAGER\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}
void addTask(vector<Task>& tasks) {
    Task newTask;
    cin.ignore(); // Clear the input buffer
    cout << "Enter the task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}
void viewTasks(const vector<Task>& tasks) {
    cout << "\nTASK LIST\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        cout << (tasks[i].completed ? "[X] " : "[ ] ");
        cout << tasks[i].description << "\n";
    }
}
void markAsCompleted(vector<Task>& tasks) {
    viewTasks(tasks);
    size_t index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}
void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);
    size_t index;
    cout << "Enter the task number to remove: ";
    cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}
