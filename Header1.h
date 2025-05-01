
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct {
    Node* front; 
    Node* end;   
    int size;     
    int maxSize;  
} Queue;


int check_positive_int() {
    int num;
    while (1) {
        if (scanf_s("%d", &num) != 1) {
            printf("Ошибка: введите целое число: ");
            while (getchar() != '\n');
            continue;
        }

        if (getchar() != '\n') {
            printf("Ошибка: введите только число (без лишних символов): ");
            while (getchar() != '\n');
            continue;
        }

        if (num <= 0) {
            printf("Ошибка: введите корректное число ");
            continue;
        }

        break;
    }
    return num;
}


int check_any_int() {
    int num;
    while (1) {
        if (scanf_s("%d", &num) != 1) {
            printf("Ошибка: введите целое число: ");
            while (getchar() != '\n');
            continue;
        }

        if (getchar() != '\n') {
            printf("Ошибка: введите только число (без лишних символов): ");
            while (getchar() != '\n');
            continue;
        }

        break;
    }
    return num;
}

void initQueue(Queue* q, int maxSize) {
    q->front = q->end = NULL;
    q->size = 0;
    q->maxSize = maxSize;
}


int isEmpty(Queue* q) {
    return q->front == NULL;
}


int isFull(Queue* q) {
    return q->size == q->maxSize;
}

int dequeue(Queue* q, int* value) {
    if (isEmpty(q)) {
        printf("Очередь пуста!\n");
        return 0;
    }

    Node* temp = q->front;
    *value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->end = NULL;
    }

    free(temp);
    q->size--;
    printf("Удалён элемент: %d\n", *value);
    return 1;
}



void enqueue(Queue* q, int value) {
    if (isFull(q)) {
        printf("Очередь полная! Удаляем первый элемент...\n");
        int deletedValue;
        dequeue(q, &deletedValue);
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->end = newNode;
    }
    else {
        q->end->next = newNode;
        q->end = newNode;
    }
    q->size++;
    printf("Добавлен элемент: %d\n", value);
}



void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Очередь пуста.\n");
        return;
    }

    printf("Содержимое очереди (размер = %d/%d):\n", q->size, q->maxSize);
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        int temp;
        dequeue(q, &temp);
    }
}

