#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define Task structure */
typedef struct Task {
    char description[100];
    int priority;          // 1 = High, 2 = Medium, 3 = Low
    char due_date[20];     // Format: YYYY-MM-DD
    struct Task *next;
} Task;

/* Head pointer */
Task *head = NULL;

/* Function to create a new task node */
Task* createTask(char desc[], int priority, char due_date[]) {
    Task *newTask = (Task*)malloc(sizeof(Task));
    if (newTask == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(newTask->description, desc);
    newTask->priority = priority;
    strcpy(newTask->due_date, due_date);
    newTask->next = NULL;

    return newTask;
}

/* Compare dates (YYYY-MM-DD format) */
int compareDates(char d1[], char d2[]) {
    return strcmp(d1, d2); // works correctly for YYYY-MM-DD
}

/* Add Task (sorted by due date) */
void addTask(char desc[], int priority, char due_date[]) {
    Task *newTask = createTask(desc, priority, due_date);

    /* Insert at beginning if list empty or earliest due date */
    if (head == NULL || compareDates(due_date, head->due_date) < 0) {
        newTask->next = head;
        head = newTask;
        return;
    }

    /* Insert in sorted position */
    Task *temp = head;
    while (temp->next != NULL &&
           compareDates(temp->next->due_date, due_date) <= 0) {
        temp = temp->next;
    }

    newTask->next = temp->next;
    temp->next = newTask;
}

/* Remove Task by description */
void removeTask(char desc[]) {
    if (head == NULL) {
        printf("Task list is empty!\n");
        return;
    }

    Task *temp = head;
    Task *prev = NULL;

    /* If head node matches */
    if (strcmp(head->description, desc) == 0) {
        head = head->next;
        free(temp);
        printf("Task removed successfully.\n");
        return;
    }

    /* Search for the task */
    while (temp != NULL && strcmp(temp->description, desc) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Task removed successfully.\n");
}

/* Display all tasks */
void displayTasks() {
    if (head == NULL) {
        printf("No tasks available.\n");
        return;
    }

    Task *temp = head;
    printf("\n----- Task List -----\n");
    while (temp != NULL) {
        printf("Description : %s\n", temp->description);
        printf("Priority    : %d\n", temp->priority);
        printf("Due Date    : %s\n", temp->due_date);
        printf("---------------------\n");
        temp = temp->next;
    }
}

/* Update Task (priority or due date) */
void updateTask(char desc[]) {
    Task *temp = head;

    while (temp != NULL && strcmp(temp->description, desc) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Task not found!\n");
        return;
    }

    int choice;
    printf("Update:\n1. Priority\n2. Due Date\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter new priority (1-High, 2-Medium, 3-Low): ");
        scanf("%d", &temp->priority);
    } else if (choice == 2) {
        char newDate[20];
        printf("Enter new due date (YYYY-MM-DD): ");
        scanf("%s", newDate);

        /* Remove and reinsert to maintain sorted order */
        int pr = temp->priority;
        char descCopy[100];
        strcpy(descCopy, temp->description);

        removeTask(descCopy);
        addTask(descCopy, pr, newDate);
        printf("Due date updated and task re-prioritized.\n");
        return;
    } else {
        printf("Invalid choice!\n");
        return;
    }

    printf("Task updated successfully.\n");
}

/* Main Menu */
int main() {
    int choice, priority;
    char desc[100], due_date[20];

    while (1) {
        printf("\n===== Task Management System =====\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Display Tasks\n");
        printf("4. Update Task\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
        case 1:
            printf("Enter description: ");
            fgets(desc, sizeof(desc), stdin);
            desc[strcspn(desc, "\n")] = '\0';

            printf("Enter priority (1-High, 2-Medium, 3-Low): ");
            scanf("%d", &priority);

            printf("Enter due date (YYYY-MM-DD): ");
            scanf("%s", due_date);

            addTask(desc, priority, due_date);
            printf("Task added successfully.\n");
            break;

        case 2:
            printf("Enter description to remove: ");
            getchar();
            fgets(desc, sizeof(desc), stdin);
            desc[strcspn(desc, "\n")] = '\0';
            removeTask(desc);
            break;

        case 3:
            displayTasks();
            break;

        case 4:
            printf("Enter description to update: ");
            getchar();
            fgets(desc, sizeof(desc), stdin);
            desc[strcspn(desc, "\n")] = '\0';
            updateTask(desc);
            break;

        case 5:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
