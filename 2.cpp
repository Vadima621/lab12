/*15. Создать дек для плавающих чисел. Максимальный размер дека вводится с экрана. Создать
функции для ввода и вывода элементов дека. Ввести в дек числа с экрана. После этого перейти в режим
ввода, при котором перед занесением элемента происходит удаление левого элемента.
матерн 01.05.2025*/

#include"Header2.h"



int main() {
    Deque dq;
    int choice;
    double value;

    printf("Введите максимальный размер дека: ");
    int maxSize = check_positive_int();
    initDeque(&dq, maxSize);

    printf("\n=== Заполнение дека ===\n");
    while (dq.size < dq.maxSize) {
        printf("Введите элемент %d/%d: ", dq.size + 1, dq.maxSize);
        value = check_double();
        pushRear(&dq, value);
    }

    while (1) {
        display_menu();
        choice = check_positive_int();

        switch (choice) {
        case 1:
            printf("Введите значение для добавления в начало: ");
            value = check_double();
            pushFront(&dq, value);
            break;
        case 2:
            printf("Введите значение для добавления в конец: ");
            value = check_double();
            pushRear(&dq, value);
            break;
        case 3: {
            double val;
            if (popFront(&dq, &val)) {
                printf("Удалён элемент из начала: %.2f\n", val);
            }
            break;
        }
        case 4: {
            double val;
            if (popRear(&dq, &val)) {
                printf("Удалён элемент из конца: %.2f\n", val);
            }
            break;
        }
        case 5:
            printDeque(&dq);
            break;
        case 6:
            system("cls");
            break;
        case 7:
            freeDeque(&dq);
            printf("Программа завершена.\n");
            return 0;
        default:
            printf("Неверный выбор! Попробуйте снова (1-7).\n");
        }
    }
}