/*
* Задание #6
* Автор: Бринк А.С.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include <locale.h>

// Функция замены нижнего подчеркивания в названии страны на пробел
void undecorate_name(char * name) {
    int cnt;
    while (name[cnt]) {
        if (name[cnt] == '_')
            name[cnt] = ' ';
        cnt++;
    }
}

int main(int argc, char * argv[])
{
    setlocale(LC_ALL, "ru_RU.UTF8");
    COUNTRY ** list;
    list = map_load();
    // Переменные для населения и площади
    int population;
    int area;
    // Выделяем динамически память под команду и название страны
    char * cmd = (char *)malloc(sizeof(char));
    char * name = (char *)malloc(sizeof(char));

    for(;;) {
        //printf("Введите команду\n");
        scanf("%s", cmd);
        if (strcmp(cmd, "add") == 0) {
            scanf("%s", name);
            scanf("%i", population);
            scanf("%i", area);
            undecorate_name(&name);
            printf("Добавляю страну: %s\n", name);
            // TODO: map_add
        }
        else if (strcmp(cmd, "delete") == 0) {
            scanf("%s", name)'
            undecorate_name(&name);
            printf("Удаляю страну: %s\n", name);
            // TODO: map_delete
        }
        else if (strcmp(cmd, "dump") == 0) {
            printf("Вывожу страны\n");
            //TODO: map_dump
        }
        else if (strcmp(cmd, "view") == 0) {
            scanf("%s", name)'
            undecorate_name(&name);
            printf("Вывожу информацию о стране: %s\n", name);
            //TODO: map_find
            //TODO: add print_country() ready ?
        }
        else if (strcmp(cmd, "count") == 0) {
            printf("Вывожу количество стран\n");
            //TODO: add count() ready ?
        }
        else if (strcmp(cmd, "save") == 0) {
            printf("Сохраняю в базу данных\n");
            map_save(list);
        }
        else if (strcmp(cmd, "quit") == 0) {
            printf("Звершаю работу\n");
            break;
        }
        else {
            printf("Неизвестная команда\n");
        }
        
    }

    // Очищаем динамически выделенную память
    free(cmd);
    free(name);
    map_clear(list);
    
    return 0;
}

