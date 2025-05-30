#include <stdio.h>
#include <string.h>
#define MAX_KVARTYR 100

typedef struct {
    char vulytsia[50];
    int budynok;
    int nomer_kvartyry;
    char vlasnyk[50];
    char storona_svitu[20];
} Kvartyra;

int main() {
    system("chcp 65001");
    Kvartyra kvartyry[MAX_KVARTYR] = {
        {"Шевченка", 10, 1, "Іваненко", "південь"},
        {"Шевченка", 10, 2, "Петренко", "північ"},
        {"Франка", 12, 3, "Коваленко", "схід"},
        {"Шевченка", 10, 4, "Сидоренко", "південь"},
        {"Франка", 14, 5, "Мельник", "захід"}
    };
    int n = 5;
    char zadanastorona[20];
    char zadanavulytsia[50];
    printf("Введіть потрібну сторону світу (наприклад: південь): ");
    fgets(zadanastorona, sizeof(zadanastorona), stdin);
    zadanastorona[strcspn(zadanastorona, "\n")] = 0;
    printf("Введіть назву вулиці: ");
    fgets(zadanavulytsia, sizeof(zadanavulytsia), stdin);
    zadanavulytsia[strcspn(zadanavulytsia, "\n")] = 0;
    FILE *output = fopen("rezultat.txt", "w");
    if (!output) {
        perror("Не вдалося відкрити файл для запису");
        return 1;
    }
    int found = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(kvartyry[i].storona_svitu, zadanastorona) == 0 &&
            strcmp(kvartyry[i].vulytsia, zadanavulytsia) == 0) {
            fprintf(output, "Вулиця: %s, Будинок: %d, Квартира: %d, Власник: %s, Вікна: %s\n",
                    kvartyry[i].vulytsia,
                    kvartyry[i].budynok,
                    kvartyry[i].nomer_kvartyry,
                    kvartyry[i].vlasnyk,
                    kvartyry[i].storona_svitu);
            found = 1;
        }
    }
    if (!found) {
        fprintf(output, "Квартир, що відповідають умовам, не знайдено.\n");
    }
    fclose(output);
    printf("Результати записано у файл rezultat.txt\n");
    return 0;
}