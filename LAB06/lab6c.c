#include <stdio.h>
#include <stdlib.h>

/* Node structure */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Create new node */
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Print list */
void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

/* Merge two lists */
Node* mergeLists(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = list2;  // Attach list2 at end of list1
    return list1;
}

/* Sort linked list using Bubble Sort */
Node* sortList(Node* head) {
    if (head == NULL) return head;

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);

    return head;
}

/* Required Function */
Node* merge_and_sort_lists(Node* list1, Node* list2) {
    Node* merged = mergeLists(list1, list2);
    merged = sortList(merged);
    return merged;
}

/* Main Function */
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* merged = NULL;
    int n1, n2, value;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);

    printf("Enter elements of List 1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);

    printf("Enter elements of List 2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    printf("\nList 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    merged = merge_and_sort_lists(list1, list2);

    printf("\nMerged and Sorted List: ");
    printList(merged);

    return 0;
}