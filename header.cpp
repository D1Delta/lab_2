#include "header.h"
#include <windows.h>
#include <locale>
#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <list>
#include <numeric>
#include <set>
#include <string>
#include <vector>



void ClearInput() {

}

int GetValidInt(const std::string& prompt) {
  int value = 0;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      ClearInput();
      return value;
    }
    std::cout << "Ошибка ввода! Пожалуйста, введите целое число.\n";
    ClearInput();
  }
}

std::vector<int> ReadIntVector(int count, const std::string& container_name) {
  std::vector<int> temp_elements(count);
  std::cout << "Введите " << count << " целых чисел для " << container_name
            << ":\n";
  for (int i = 0; i < count; ++i) {
    temp_elements[i] =
        GetValidInt("  Элемент [" + std::to_string(i + 1) + "]: ");
  }
  return temp_elements;
}

bool IsValidUppercaseWord(const std::string& word) {
  if (word.empty()) {
    return false;
  }
  for (char ch : word) {
    if (ch < 'A' || ch > 'Z') {
      return false;
    }
  }
  return true;
}

// Задание 1 (Задача 4): Заполнение дека и вывод половин в обратном порядке.
void Task1() {
  std::cout << "\n--- Задание 1 (Задача 4) ---\n";
  int count = 0;
  while (count <= 0 || count % 2 != 0) {
    count = GetValidInt("Введите четное количество элементов дека (N > 0): ");
  }

  std::vector<int> raw_data = ReadIntVector(count, "дека D");
  std::deque<int> deque_d(raw_data.begin(), raw_data.end());

  PrintContainer(deque_d, "Исходный дек D: ");

  std::cout << "Первая половина в обратном порядке: ";
  auto half_offset = static_cast<std::ptrdiff_t>(deque_d.size() / 2);
  for (auto it = deque_d.rbegin() + half_offset; it != deque_d.rend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::cout << "Вторая половина в обратном порядке: ";
  for (auto it = deque_d.rbegin(); it != deque_d.rbegin() + half_offset; ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

// Задание 2 (Задача 7): Вставка числа 1 после каждого элемента вектора.
void Task2() {
  std::cout << "\n--- Задание 2 (Задача 7) ---\n";
  int count = 0;
  while (count <= 0) {
    count = GetValidInt("Введите количество элементов вектора V (N > 0): ");
  }

  std::vector<int> raw_data = ReadIntVector(count, "вектора V");
  std::vector<int> vector_v(raw_data.begin(), raw_data.end());
  PrintContainer(vector_v, "Исходный вектор V: ");

  for (auto i = vector_v.begin(); i != vector_v.end(); ++i) {
    i = vector_v.insert(++i, 1);
  }

  PrintContainer(vector_v, "Вектор V после вставки: ");
}

// Задание 3 (Задача 1): Удаление среднего элемента дека.
void Task3() {
  std::cout << "\n--- Задание 3 (Задача 1) ---\n";
  int count = 0;
  while (count < 3 || count % 2 == 0) {
    count =
        GetValidInt("Введите нечетное количество элементов дека (N >= 3): ");
  }

  std::vector<int> raw_data = ReadIntVector(count, "дека D");
  std::deque<int> deque_d(raw_data.begin(), raw_data.end());
  PrintContainer(deque_d, "Исходный дек D: ");

  auto mid_offset = static_cast<std::ptrdiff_t>(deque_d.size() / 2);
  deque_d.erase(deque_d.begin() + mid_offset);

  PrintContainer(deque_d, "Дек D после удаления среднего элемента: ");
}

// Задание 4 (Задача 7): Запись K символов '*' в текстовый файл (fill_n).
void Task4() {
  std::cout << "\n--- Задание 4 (Задача 7) ---\n";
  std::string file_name;
  std::cout << "Введите имя выходного файла (например, stars.txt): ";
  std::cin >> file_name;
  ClearInput();

  int count_k = 0;
  while (count_k <= 0) {
    count_k = GetValidInt("Введите целое число K (K > 0): ");
  }

  std::ofstream out_file(file_name);
  if (!out_file.is_open()) {
    std::cout << "Ошибка открытия файла для записи!\n";
    return;
  }

  std::fill_n(std::ostream_iterator<char>(out_file), count_k, '*');
  out_file.close();

  std::cout << "В файл '" << file_name << "' успешно записано " << count_k
            << " символов '*'.\n";
}

// Задание 5 (Задача 6): Поиск (find_first_of) и дублирование элемента списка.
void Task5() {
  std::cout << "\n--- Задание 5 (Задача 6) ---\n";
  int count_v = 0;
  while (count_v <= 0 || count_v % 2 != 0) {
    count_v =
        GetValidInt("Введите четное количество элементов вектора V (N > 0): ");
  }
  std::vector<int> vector_v = ReadIntVector(count_v, "вектора V");

  int count_l = 0;
  while (count_l <= 0) {
    count_l = GetValidInt("Введите количество элементов списка L (N > 0): ");
  }
  std::vector<int> raw_l = ReadIntVector(count_l, "списка L");
  std::list<int> list_l(raw_l.begin(), raw_l.end());

  PrintContainer(vector_v, "Исходный вектор V: ");
  PrintContainer(list_l, "Исходный список L: ");

  auto half_offset = static_cast<std::ptrdiff_t>(vector_v.size() / 2);
  auto reverse_it = std::find_first_of(list_l.rbegin(), list_l.rend(),
                                       vector_v.begin(),
                                       vector_v.begin() + half_offset);
  if (reverse_it != list_l.rend()) {
    list_l.insert(reverse_it.base(), *reverse_it);
    PrintContainer(list_l, "Список L после дублирования элемента: ");
  } else {
    std::cout << "Совпадающих элементов не найдено. Список не изменен.\n";
  }
}

// Задание 6 (Задача 6): Циклический сдвиг списков вправо и влево (rotate).
void Task6() {
  std::cout << "\n--- Задание 6 (Задача 6) ---\n";
  int shift_k = 0;
  while (shift_k <= 0 || shift_k >= 10) {
    shift_k = GetValidInt("Введите число K (0 < K < 10): ");
  }

  int count1 = 0;
  while (count1 < 10) {
    count1 =
        GetValidInt("Введите количество элементов списка L1 (N >= 10): ");
  }
  std::vector<int> raw1 = ReadIntVector(count1, "списка L1");
  std::list<int> list_l1(raw1.begin(), raw1.end());

  int count2 = 0;
  while (count2 < 10) {
    count2 =
        GetValidInt("Введите количество элементов списка L2 (N >= 10): ");
  }
  std::vector<int> raw2 = ReadIntVector(count2, "списка L2");
  std::list<int> list_l2(raw2.begin(), raw2.end());

  PrintContainer(list_l1, "Исходный список L1: ");
  PrintContainer(list_l2, "Исходный список L2: ");

  auto it1 = list_l1.end();
  std::advance(it1, -shift_k);
  std::rotate(list_l1.begin(), it1, list_l1.end());

  auto it2 = list_l2.begin();
  std::advance(it2, shift_k);
  std::rotate(list_l2.begin(), it2, list_l2.end());

  PrintContainer(list_l1, "L1 (сдвиг вправо на K): ");
  PrintContainer(list_l2, "L2 (сдвиг влево на K):  ");
}

// Задание 7 (Задача 3): Поиск трех наибольших элементов вектора (partial_sort).
void Task7() {
  std::cout << "\n--- Задание 7 (Задача 3) ---\n";
  int count = 0;
  while (count < 3) {
    count = GetValidInt("Введите количество элементов вектора V (N >= 3): ");
  }

  std::vector<int> vector_v = ReadIntVector(count, "вектора V");
  PrintContainer(vector_v, "Исходный вектор V: ");

  std::partial_sort(vector_v.begin(), vector_v.begin() + 3, vector_v.end(),
                    std::greater<int>());

  std::cout << "Три наибольших элемента в порядке убывания: ";
  std::copy(vector_v.begin(), vector_v.begin() + 3,
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}

// Задание 8 (Задача 1): Среднее арифметическое соседних элементов списка.
void Task8() {
  std::cout << "\n--- Задание 8 (Задача 1) ---\n";
  int count = 0;
  while (count < 2) {
    count = GetValidInt("Введите количество элементов списка L (N >= 2): ");
  }

  std::vector<int> raw_l = ReadIntVector(count, "списка L");
  std::list<int> list_l(raw_l.begin(), raw_l.end());

  PrintContainer(list_l, "Исходный список L: ");

  std::vector<double> vector_v;
  std::adjacent_difference(
      list_l.begin(), list_l.end(), std::back_inserter(vector_v),
      [](double curr, double prev) { return (curr + prev) / 2.0; });

  vector_v.erase(vector_v.begin());

  PrintContainer(vector_v, "Полученный вектор средних арифметических V: ");
}

// Задание 9 (Задача 1): Проверка включения множеств (includes).
void Task9() {
  std::cout << "\n--- Задание 9 (Задача 1) ---\n";
  int size0 = 0;
  while (size0 <= 0) {
    size0 = GetValidInt("Введите размер вектора V0 (size0 > 0): ");
  }

  std::vector<int> vector_v0 = ReadIntVector(size0, "вектора V0");

  int vectors_count = 0;
  while (vectors_count <= 0) {
    vectors_count = GetValidInt("Введите количество векторов N (N > 0): ");
  }

  std::set<int> set0(vector_v0.begin(), vector_v0.end());
  int match_count = 0;

  for (int i = 1; i <= vectors_count; ++i) {
    int size_i = 0;
    while (size_i < size0) {
      size_i = GetValidInt("Введите размер вектора V" + std::to_string(i) +
                           " (не менее " + std::to_string(size0) + "): ");
    }
    std::vector<int> vector_vi =
        ReadIntVector(size_i, "вектора V" + std::to_string(i));

    std::set<int> set_i(vector_vi.begin(), vector_vi.end());
    if (std::includes(set_i.begin(), set_i.end(), set0.begin(), set0.end())) {
      ++match_count;
    }
  }

  std::cout << "Количество векторов, содержащих все элементы V0: "
            << match_count << "\n";
}

// Задание 10 (Задача 2): Суммарная длина слов на одну букву (std::map).
void Task10() {
  std::cout << "\n--- Задание 10 (Задача 2) ---\n";
  int count = 0;
  while (count <= 0) {
    count = GetValidInt("Введите количество слов в векторе V (N > 0): ");
  }

  std::vector<std::string> vector_v;
  for (int i = 0; i < count; ++i) {
    std::string word;
    while (true) {
      std::cout << "  Введите слово [" << i + 1
                << "] (только заглавные латинские буквы A-Z): ";
      std::cin >> word;
      ClearInput();
      if (IsValidUppercaseWord(word)) {
        vector_v.push_back(word);
        break;
      }
      std::cout << "  Ошибка! Слово должно состоять только из заглавных "
                << "английских букв (A-Z).\n";
    }
  }

  PrintContainer(vector_v, "Исходный вектор слов V: ");

  std::map<char, std::size_t> map_m;
  for (auto it = vector_v.begin(); it != vector_v.end(); ++it) {
    map_m[(*it)[0]] += it->size();
  }

  std::cout << "Результат (буква -> суммарная длина слов):\n";
  for (auto it = map_m.begin(); it != map_m.end(); ++it) {
    std::cout << it->first << " " << it->second << "\n";
  }
}