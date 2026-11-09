#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

/**
 * @brief Розраховує суму заданого ряду від n = 1 до N.
 *
 * Формула ряду: S = sum(2/n + n/2).
 * Оскільки результатом ділення можуть бути дробові числа,
 * розрахунок ведеться у типі double.
 *
 * @param limit Верхня межа ряду (ціле число N, N >= 1).
 * @return Сума ряду у вигляді дійсного числа подвійної точності.
 */
double calculateSeriesSum(int limit);

int main() {
    // Налаштування кодування UTF-8 для коректного відображення кирилиці в консолі Windows
    SetConsoleOutputCP(CP_UTF8);

    int limitN;
    int readStatus;

    // Цикл для надійного введення значення N з перевіркою всіх умов
    while (1) {
        printf("Введіть ціле число N (N >= 1): ");
        readStatus = scanf("%d", &limitN);


        // Перевірка, чи введено саме ціле число
        if (readStatus != 1) {
            printf("Помилка: некоректне введення. Будь ласка, введіть ціле число.\n");
            scanf("%*[^\n]"); // Очищення буфера до кінця рядка
            continue;
        }

        // Перевірка обмеження згідно з умовою (N >= 1)
        if (limitN < 1) {
            printf("Помилка: значення N має бути більше або дорівнювати 1. Спробуйте ще раз.\n");
            continue;
        }

        // Якщо всі перевірки пройдені, виходимо з циклу
        break;
    }

    // Розрахунок суми та виведення результату
    double resultSum = calculateSeriesSum(limitN);

    // Використовуємо %lf для виведення типу double (за замовчуванням 6 знаків після коми)
    printf("\nСума ряду S = %lf\n", resultSum);

    return 0;
}

double calculateSeriesSum(int limit) {
    double totalSum = 0.0;

    // Проходимо по всіх членах ряду від 1 до limit (N)
    for (int n = 1; n <= limit; n++) {
        // Використовуємо 2.0, щоб уникнути цілочисельного ділення.
        // Наприклад, при цілочисельному діленні 2 / 3 буде 0, 
        // а 2.0 / 3 дасть правильний дробовий результат 0.666...
        double term = (2.0 / n) + (n / 2.0);
        totalSum += term;
    }

    return totalSum;
}