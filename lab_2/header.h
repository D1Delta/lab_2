#ifndef LAB2_STL_TASKS_H_
#define LAB2_STL_TASKS_H_

#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

// Вспомогательные функции ввода и вывода.
void ClearInput();
int GetValidInt(const std::string& prompt);
std::vector<int> ReadIntVector(int count, const std::string& container_name);
bool IsValidUppercaseWord(const std::string& word);

// Выводит элементы любого контейнера с использованием итераторов.
template <typename Container>
void PrintContainer(const Container& container,
                    const std::string& message = "") {
    if (!message.empty()) {
        std::cout << message;
    }
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

// Функции решения задач лабораторной работы №2 (Вариант 6).
void Task1();
void Task2();
void Task3();
void Task4();
void Task5();
void Task6();
void Task7();
void Task8();
void Task9();
void Task10();

#endif  // LAB2_STL_TASKS_H_