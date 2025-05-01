/* 5. Организовать три очереди с одинаковым количеством элементов, содержащие соответствено
имена, отчества и фамилии людей. Составьте очередь из элементов, содержащих наиболее полную
информацию о людях, воспользовавшись уже созданными очередями и запросив какую-то
дополнительную информацию. Решение в программе оформляйте через подпрограммы. матерн 01.05.2025 */



#include "Header3.h"

int main() {
  
    Queue names, middles, surnames, fullInfo;
    initQueue(&names);
    initQueue(&middles);
    initQueue(&surnames);
    initQueue(&fullInfo);

    int count;
    printf("Введите количество людей: ");
    scanf_s("%d", &count);

    inputQueue(&names, "имен", count);
    inputQueue(&middles, "отчеств", count);
    inputQueue(&surnames, "фамилий", count);

    combinePeopleInfo(&names, &middles, &surnames, &fullInfo);

    printf("\nПолная информация о людях:\n");
    printQueue(&fullInfo, "Люди");

    freeQueue(&names);
    freeQueue(&middles);
    freeQueue(&surnames);
    freeQueue(&fullInfo);
 
}