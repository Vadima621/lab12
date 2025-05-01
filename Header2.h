#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    double data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* front;
    Node* end;
    int size;
    int maxSize;
} Deque;

int isEmpty(Deque* dq) {
    return dq->front == NULL;
}

int isFull(Deque* dq) {
    return dq->size == dq->maxSize;
}

int popFront(Deque* dq, double* value) {
    if (isEmpty(dq)) {
        printf("Дек пуст!\n");
        return 0;
    }

    Node* temp = dq->front;
    *value = temp->data;
    dq->front = dq->front->next;

    if (dq->front == NULL) {
        dq->end = NULL;
    }
    else {
        dq->front->prev = NULL;
    }

    free(temp);
    dq->size--;
    return 1;
}

int popRear(Deque* dq, double* value) {
    if (isEmpty(dq)) {
        printf("Дек пуст!\n");
        return 0;
    }

    Node* temp = dq->end;
    *value = temp->data;
    dq->end = dq->end->prev;

    if (dq->end == NULL) {
        dq->front = NULL;
    }
    else {
        dq->end->next = NULL;
    }

    free(temp);
    dq->size--;
    return 1;
}

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

double check_double() {
    double num;
    while (1) {
        if (scanf_s("%lf", &num) != 1) {
            printf("Ошибка: введите число: ");
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

void initDeque(Deque* dq, int maxSize) {
    dq->front = dq->end = NULL;
    dq->size = 0;
    dq->maxSize = maxSize;
}

void pushFront(Deque* dq, double value) {
    if (isFull(dq)) {
        printf("Дек полон! Удаляем левый элемент...\n");
        double temp;
        popRear(dq, &temp);
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isEmpty(dq)) {
        dq->end = newNode;
    }
    else {
        dq->front->prev = newNode;
    }

    dq->front = newNode;
    dq->size++;
}

void pushRear(Deque* dq, double value) {
    if (isFull(dq)) {
        printf("Дек полон! Удаляем левый элемент...\n");
        double temp;
        popFront(dq, &temp);
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти!\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->end;

    if (isEmpty(dq)) {
        dq->front = newNode;
    }
    else {
        dq->end->next = newNode;
    }

    dq->end = newNode;
    dq->size++;
}

void printDeque(Deque* dq) {
    if (isEmpty(dq)) {
        printf("Дек пуст.\n");
        return;
    }

    printf("Содержимое дека (размер = %d/%d):\n", dq->size, dq->maxSize);
    Node* current = dq->front;
    while (current != NULL) {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeDeque(Deque* dq) {
    while (!isEmpty(dq)) {
        double temp;
        popFront(dq, &temp);
    }
}

void display_menu() {
    printf("\n=== Меню дека ===\n");
    printf("1. Добавить элемент в начало\n");
    printf("2. Добавить элемент в конец\n");
    printf("3. Удалить элемент из начала\n");
    printf("4. Удалить элемент из конца\n");
    printf("5. Показать дек\n");
    printf("6. Очистить экран\n");
    printf("7. Выход\n");
    printf("Выберите действие: ");
}

