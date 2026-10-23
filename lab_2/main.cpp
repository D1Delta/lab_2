#include <iostream>
#include <windows.h>
#include "header.h"

int main() {
  setlocale(LC_ALL, "Russian");

  while (true) {
    std::cout << "\n=============================================\n";
    std::cout << "   ЛАБОРАТОРНАЯ РАБОТА №2 (Вариант 6) - STL\n";
    std::cout << "=============================================\n";
    std::cout << " 1. Задание 1 (Задача 4)  - Дек и обратные итераторы\n";
    std::cout << " 2. Задание 2 (Задача 7)  - Вставка в вектор в цикле\n";
    std::cout << " 3. Задание 3 (Задача 1)  - Удаление среднего элемента дека\n";
    std::cout << " 4. Задание 4 (Задача 7)  - Запись '*' в файл (fill_n)\n";
    std::cout << " 5. Задание 5 (Задача 6)  - Поиск (find_first_of) и дубль\n";
    std::cout << " 6. Задание 6 (Задача 6)  - Циклический сдвиг (rotate)\n";
    std::cout << " 7. Задание 7 (Задача 3)  - Сортировка (partial_sort)\n";
    std::cout << " 8. Задание 8 (Задача 1)  - Среднее (adjacent_difference)\n";
    std::cout << " 9. Задание 9 (Задача 1)  - Включение множеств (includes)\n";
    std::cout << "10. Задание 10 (Задача 2) - Суммарная длина слов (map)\n";
    std::cout << " 0. Выход\n";
    std::cout << "---------------------------------------------\n";

    int choice = GetValidInt("Выберите номер задания (0-10): ");

    switch (choice) {
      case 1:
        Task1();
        break;
      case 2:
        Task2();
        break;
      case 3:
        Task3();
        break;
      case 4:
        Task4();
        break;
      case 5:
        Task5();
        break;
      case 6:
        Task6();
        break;
      case 7:
        Task7();
        break;
      case 8:
        Task8();
        break;
      case 9:
        Task9();
        break;
      case 10:
        Task10();
        break;
      case 0:
        std::cout << "Завершение работы программы.\n";
        return 0;
      default:
        std::cout << "Неверный номер задания! Выберите от 0 до 10.\n";
        break;
    }
  }
}