/* 15 Создать очередь для целых чисел.Максимальный размер очереди вводится с экрана.Создать
функции для ввода и вывода элементов очереди.Ввести в очередь числа с экрана.После этого перейти
в режим ввода, при котором перед добавлением элемента происходит удаление одного элемента.
матерн 01.05.2025
*/



#include"Header1.h"

int main() {
    Queue q;
    int choice, value;

    printf("Введите максимальный размер очереди: ");
    int maxSize = check_positive_int();

    initQueue(&q, maxSize);

    printf("\n=== Заполнение очереди ===\n");

    while (q.size < q.maxSize) {
        printf("Введите элемент %d/%d: ", q.size + 1, q.maxSize);
        value = check_any_int();  
        enqueue(&q, value);
    }

    printf("\n=== Режим работы с очередью ===\n");
    printf("Теперь при добавлении нового элемента будет удаляться первый элемент\n");

    while (1) {
        printf("\nМеню:\n");
        printf("1. Добавить элемент (enqueue)\n");
        printf("2. Удалить элемент (dequeue)\n");
        printf("3. Показать очередь\n");
        printf("4. Очистить экран\n");
        printf("5. Выход\n");
        printf("Выберите действие: ");

        choice = check_positive_int();  

        switch (choice) {
        case 1:
            printf("Введите значение для добавления: ");
            value = check_any_int();  
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q, &value);
            break;
        case 3:
            printQueue(&q);
            break;
        case 4:
            system("cls");
            break;
           
        case 5:
            freeQueue(&q);
            printf("Программа завершена.\n");
            return 0;
        default:
            printf("Неверный выбор! Попробуйте снова (1-4).\n");
        }
    }
}