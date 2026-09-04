#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define FILE_NAME "tasks.txt"

struct Task {
    int id;
    char description[100];
    int completed;
};

struct Task tasks[MAX_TASKS];
int taskCount = 0;

/* Function declarations */
void addTask();
void viewTasks();
void completeTask();
void deleteTask();
void saveTasks();
void loadTasks();

int main() {
    int choice;

    loadTasks();

    while (1) {
        printf("\n===== TO-DO LIST =====\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        printf("======================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Remove newline from input buffer

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                completeTask();
                break;

            case 4:
                deleteTask();
                break;

            case 5:
                saveTasks();
                printf("Tasks saved. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

/* Add a new task */
void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("Task list is full!\n");
        return;
    }

    tasks[taskCount].id = taskCount + 1;
    tasks[taskCount].completed = 0;

    printf("Enter task: ");
    fgets(tasks[taskCount].description,
          sizeof(tasks[taskCount].description), stdin);

    // Remove newline from fgets
    tasks[taskCount].description[
        strcspn(tasks[taskCount].description, "\n")
    ] = '\0';

    taskCount++;

    saveTasks();

    printf("Task added successfully!\n");
}

/* Display all tasks */
void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks found.\n");
        return;
    }

    printf("\n===== YOUR TASKS =====\n");

    for (int i = 0; i < taskCount; i++) {
        if (tasks[i].completed) {
            printf("%d. [✓] %s\n",
                   tasks[i].id,
                   tasks[i].description);
        } else {
            printf("%d. [ ] %s\n",
                   tasks[i].id,
                   tasks[i].description);
        }
    }
}

/* Mark a task as completed */
void completeTask() {
    int id;

    viewTasks();

    if (taskCount == 0)
        return;

    printf("Enter task ID to complete: ");
    scanf("%d", &id);
    getchar();

    if (id < 1 || id > taskCount) {
        printf("Invalid task ID.\n");
        return;
    }

    tasks[id - 1].completed = 1;

    saveTasks();

    printf("Task completed!\n");
}

/* Delete a task */
void deleteTask() {
    int id;

    viewTasks();

    if (taskCount == 0)
        return;

    printf("Enter task ID to delete: ");
    scanf("%d", &id);
    getchar();

    if (id < 1 || id > taskCount) {
        printf("Invalid task ID.\n");
        return;
    }

    // Shift tasks to remove selected task
    for (int i = id - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
        tasks[i].id = i + 1;
    }

    taskCount--;

    saveTasks();

    printf("Task deleted successfully!\n");
}

/* Save tasks to file */
void saveTasks() {
    FILE *file = fopen(FILE_NAME, "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < taskCount; i++) {
        fprintf(file, "%d|%d|%s\n",
                tasks[i].id,
                tasks[i].completed,
                tasks[i].description);
    }

    fclose(file);
}

/* Load tasks from file */
void loadTasks() {
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        return;
    }

    taskCount = 0;

    while (taskCount < MAX_TASKS &&
           fscanf(file, "%d|%d|%99[^\n]\n",
                  &tasks[taskCount].id,
                  &tasks[taskCount].completed,
                  tasks[taskCount].description) == 3) {

        taskCount++;
    }

    fclose(file);
}




