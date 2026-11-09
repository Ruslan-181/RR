#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

#define ARRAY_SIZE 7

/**
 * @brief Знаходить значення, що найчастіше зустрічається в одновимірному масиві.
 *
 * Якщо кілька різних чисел мають однакову максимальну кількість повторень,
 * повертається перше з них у порядку слідування в масиві.
 *
 * @param numbers Константний одновимірний масив цілих чисел (без права модифікації).
 * @param size Кількість елементів у масиві.
 * @return Значення, що зустрічається найчастіше, або 0, якщо розмір масиву <= 0.
 */
int findMostFrequent(const int numbers[], int size);

int main(void) {
    // Налаштування кодування UTF-8 для коректного відображення кирилиці в консолі Windows
    SetConsoleOutputCP(CP_UTF8);

    int numbers[ARRAY_SIZE];
    int inputNumber;
    int readStatus;

    // Лічильник i збільшується лише після успішного введення коректного числа
    for (int i = 0; i < ARRAY_SIZE;) {
        printf("%d: Введіть ціле число з проміжку [-3; 3]: ", i + 1);
        readStatus = scanf("%d", &inputNumber);

        // Перевірка, чи вдалося зчитати саме ціле число
        if (readStatus != 1) {
            printf("Помилка: введіть ціле число.\n");
            scanf("%*[^\n]"); // Очищення буфера введення до кінця рядка
            continue;
        }

        // Перевірка належності введеного числа діапазону [-3; 3]
        if (inputNumber < -3 || inputNumber > 3) {
            printf("Значення виходить за межі [-3; 3]. Спробуйте ще раз.\n");
            continue;
        }

        numbers[i] = inputNumber;
        i++;
    }

    int mostFrequentValue = findMostFrequent(numbers, ARRAY_SIZE);
    printf("\nЗначення, що найчастіше зустрічається: %d\n", mostFrequentValue);

    return 0;
}

int findMostFrequent(const int numbers[], int size) {
    if (size <= 0) {
        return 0;
    }

    int mostFrequent = numbers[0];
    int maxCount = 0;

    // Перебираємо кожен елемент і підраховуємо кількість його повторень у масиві
    for (int i = 0; i < size; i++) {
        int currentCount = 0;

        for (int j = 0; j < size; j++) {
            if (numbers[j] == numbers[i]) {
                currentCount++;
            }
        }

        // Оновлюємо лідера, якщо поточне число зустрічається частіше
        if (currentCount > maxCount) {
            maxCount = currentCount;
            mostFrequent = numbers[i];
        }
    }

    return mostFrequent;
}