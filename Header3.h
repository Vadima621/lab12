#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node* next;
} Node;


typedef struct {
    Node* front;
    Node* end;
    int size;
} Queue;

void initQueue(Queue* q) {
    q->front = q->end = NULL;
    q->size = 0;
}

void enqueue(Queue* q, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy_s(newNode->data, 50, value, 49);
    newNode->data[49] = '\0';
    newNode->next = NULL;

    if (q->end == NULL) {
        q->front = q->end = newNode;
    }
    else {
        q->end->next = newNode;
        q->end = newNode;
    }
    q->size++;
}

int dequeue(Queue* q, char* value) {
    if (q->front == NULL) return 0;

    Node* temp = q->front;
    strncpy_s(value, 50, temp->data, 49);
    value[49] = '\0';
    q->front = q->front->next;

    if (q->front == NULL) {
        q->end = NULL;
    }

    free(temp);
    q->size--;
    return 1;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

void inputQueue(Queue* q, const char* prompt, int count) {
    printf("Введите %d %s:\n", count, prompt);
    for (int i = 0; i < count; i++) {
        char value[50];
        printf("%s %d: ", prompt, i + 1);
        scanf_s("%49s", value, 50);
        enqueue(q, value);
    }
}

void combinePeopleInfo(Queue* names, Queue* middles, Queue* surnames, Queue* fullInfo) {
    char name[50], middle[50], surname[50];
    char gender[10];

    while (!isEmpty(names) && !isEmpty(middles) && !isEmpty(surnames)) {
        dequeue(names, name);
        dequeue(middles, middle);
        dequeue(surnames, surname);

        printf("Укажите пол для %s %s %s (м/ж): ", surname, name, middle);
        scanf_s("%9s", gender, 10);

        char full[150];
        sprintf_s(full, sizeof(full), "%s %s %s (%s)", surname, name, middle, gender);
        enqueue(fullInfo, full);
    }
}

void printQueue(Queue* q, const char* title) {
    printf("%s:\n", title);
    Node* current = q->front;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        char temp[50];
        dequeue(q, temp);
    }
}