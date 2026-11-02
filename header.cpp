#include "header.h"

#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

// Задание 1 (Задача 4): Заполнение дека и вывод половин в обратном порядке.
void Task1() {
  std::cout << "\n--- Задание 1 (Задача 4) ---\n";
  int n = 0;
  std::cout << "Введите четное количество элементов дека: ";
  while (!(std::cin >> n) || n <= 0 || n % 2 != 0) {
    std::cout << "Ошибка! Введите положительное четное число: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::vector<int> temp(n);
  std::cout << "Введите " << n << " чисел:\n";
  for (int i = 0; i < n; ++i) {
    std::cout << "Элемент [" << i + 1 << "]: ";
    while (!(std::cin >> temp[i])) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
  }

  std::deque<int> d(temp.begin(), temp.end());

  std::cout << "Исходный дек: ";
  for (auto it = d.begin(); it != d.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  int half = n / 2;
  std::cout << "Первая половина в обратном порядке: ";
  for (auto it = d.rbegin() + half; it != d.rend(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::cout << "Вторая половина в обратном порядке: ";
  for (auto it = d.rbegin(); it != d.rbegin() + half; ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

// Задание 2 (Задача 7): Вставка числа -1 после каждого элемента вектора.
void Task2() {
  std::cout << "\n--- Задание 2 (Задача 7) ---\n";
  int n = 0;
  std::cout << "Введите количество элементов вектора: ";
  while (!(std::cin >> n) || n <= 0) {
    std::cout << "Ошибка! Введите целое положительное число: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::vector<int> temp(n);
  std::cout << "Введите " << n << " чисел:\n";
  for (int i = 0; i < n; ++i) {
    std::cout << "Элемент [" << i + 1 << "]: ";
    while (!(std::cin >> temp[i])) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
  }

  std::vector<int> v(temp.begin(), temp.end());

  std::cout << "Исходный вектор: ";
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  for (auto i = v.begin(); i != v.end(); ++i) {
    i = v.insert(++i, -1);
  }

  std::cout << "Вектор после вставки -1: ";
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

// Задание 3 (Задача 1): Удаление среднего элемента дека.
void Task3() {
  std::cout << "\n--- Задание 3 (Задача 1) ---\n";
  int n = 0;
  std::cout << "Введите нечетное количество элементов дека (N >= 3): ";
  while (!(std::cin >> n) || n < 3 || n % 2 == 0) {
    std::cout << "Ошибка! Введите нечетное число (>= 3): ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::vector<int> temp(n);
  std::cout << "Введите " << n << " чисел:\n";
  for (int i = 0; i < n; ++i) {
    std::cout << "Элемент [" << i + 1 << "]: ";
    while (!(std::cin >> temp[i])) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
  }

  std::deque<int> d(temp.begin(), temp.end());

  std::cout << "Исходный дек: ";
  for (auto it = d.begin(); it != d.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  d.erase(d.begin() + d.size() / 2);

  std::cout << "Дек после удаления среднего элемента: ";
  for (auto it = d.begin(); it != d.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

// Задание 4 (Задача 7): Запись K символов '*' в текстовый файл (fill_n).
void Task4() {
  std::cout << "\n--- Задание 4 (Задача 7) ---\n";
  std::string file_name;
  std::cout << "Введите имя файла (например, stars.txt): ";
  std::cin >> file_name;

  int k = 0;
  std::cout << "Введите количество символов K (K > 0): ";
  while (!(std::cin >> k) || k <= 0) {
    std::cout << "Ошибка! Введите положительное целое число: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::ofstream out_file(file_name);
  if (!out_file.is_open()) {
    std::cout << "Не удалось открыть файл для записи!\n";
    return;
  }

  std::fill_n(std::ostream_iterator<char>(out_file), k, '*');
  out_file.close();

  std::cout << "Успешно записано " << k << " символов '*' в файл "
            << file_name << ".\n";
}

// Задание 5 (Задача 6): Поиск (find_first_of) и дублирование элемента списка.
void Task5() {
  std::cout << "\n--- Задание 5 (Задача 6) ---\n";
  int size_v = 0;
  std::cout << "Введите четное количество элементов вектора V: ";
  while (!(std::cin >> size_v) || size_v <= 0 || size_v % 2 != 0) {
    std::cout << "Ошибка! Введите положительное четное число: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::vector<int> v(size_v);
  std::cout << "Введите элементы вектора V:\n";
  for (int i = 0; i < size_v; ++i) {
    std::cout << "V[" << i + 1 << "]: ";
    while (!(std::cin >> v[i])) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
  }

  int size_l = 0;
  std::cout << "Введите количество элементов списка L: ";
  while (!(std::cin >> size_l) || size_l <= 0) {
    std::cout << "Ошибка! Введите положительное число: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::list<int> l;
  std::cout << "Введите элементы списка L:\n";
  for (int i = 0; i < size_l; ++i) {
    int val = 0;
    std::cout << "L[" << i + 1 << "]: ";
    while (!(std::cin >> val)) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
    l.push_back(val);
  }

  std::cout << "Исходный вектор V: ";
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::cout << "Исходный список L: ";
  for (auto it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  int half_v = size_v / 2;
  auto rit = std::find_first_of(l.rbegin(), l.rend(), v.begin(),
                                v.begin() + half_v);

  if (rit != l.rend()) {
    l.insert(rit.base(), *rit);
    std::cout << "Список L после дублирования: ";
    for (auto it = l.begin(); it != l.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << "\n";
  } else {
    std::cout << "Совпадающих элементов не найдено. Список не изменен.\n";
  }
}

// Задание 6 (Задача 6): Циклический сдвиг списков вправо и влево (rotate).
void Task6() {
  std::cout << "\n--- Задание 6 (Задача 6) ---\n";
  int k = 0;
  std::cout << "Введите число K (0 < K < 10): ";
  while (!(std::cin >> k) || k <= 0 || k >= 10) {
    std::cout << "Ошибка! Введите целое число от 1 до 9: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  int n1 = 0;
  std::cout << "Введите размер первого списка L1 (>= 10): ";
  while (!(std::cin >> n1) || n1 < 10) {
    std::cout << "Ошибка! Введите число не менее 10: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::list<int> l1;
  std::cout << "Введите элементы списка L1:\n";
  for (int i = 0; i < n1; ++i) {
    int val = 0;
    std::cout << "L1[" << i + 1 << "]: ";
    while (!(std::cin >> val)) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
    l1.push_back(val);
  }

  int n2 = 0;
  std::cout << "Введите размер второго списка L2 (>= 10): ";
  while (!(std::cin >> n2) || n2 < 10) {
    std::cout << "Ошибка! Введите число не менее 10: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::list<int> l2;
  std::cout << "Введите элементы списка L2:\n";
  for (int i = 0; i < n2; ++i) {
    int val = 0;
    std::cout << "L2[" << i + 1 << "]: ";
    while (!(std::cin >> val)) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
    l2.push_back(val);
  }

  std::cout << "Исходный список L1: ";
  for (auto it = l1.begin(); it != l1.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::cout << "Исходный список L2: ";
  for (auto it = l2.begin(); it != l2.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  // Сдвиг L1 вправо на K позиций
  auto it1 = l1.end();
  std::advance(it1, -k);
  std::rotate(l1.begin(), it1, l1.end());

  // Сдвиг L2 влево на K позиций
  auto it2 = l2.begin();
  std::advance(it2, k);
  std::rotate(l2.begin(), it2, l2.end());

  std::cout << "L1 после сдвига вправо: ";
  for (auto it = l1.begin(); it != l1.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::cout << "L2 после сдвига влево:  ";
  for (auto it = l2.begin(); it != l2.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

// Задание 7 (Задача 3): Поиск трех наибольших элементов (partial_sort).
void Task7() {
  std::cout << "\n--- Задание 7 (Задача 3) ---\n";
  int n = 0;
  std::cout << "Введите количество элементов вектора V (N >= 3): ";
  while (!(std::cin >> n) || n < 3) {
    std::cout << "Ошибка! Введите целое число не менее 3: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::vector<int> v(n);
  std::cout << "Введите элементы вектора V:\n";
  for (int i = 0; i < n; ++i) {
    std::cout << "V[" << i + 1 << "]: ";
    while (!(std::cin >> v[i])) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
  }

  std::cout << "Исходный вектор: ";
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::partial_sort(v.begin(), v.begin() + 3, v.end(), std::greater<int>());

  std::cout << "Три наибольших элемента в порядке убывания: ";
  std::copy(v.begin(), v.begin() + 3,
            std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";
}

// Задание 8 (Задача 1): Среднее арифметическое соседних элементов списка.
void Task8() {
  std::cout << "\n--- Задание 8 (Задача 1) ---\n";
  int n = 0;
  std::cout << "Введите количество элементов списка L (N >= 2): ";
  while (!(std::cin >> n) || n < 2) {
    std::cout << "Ошибка! Введите целое число не менее 2: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::list<int> l;
  std::cout << "Введите элементы списка L:\n";
  for (int i = 0; i < n; ++i) {
    int val = 0;
    std::cout << "L[" << i + 1 << "]: ";
    while (!(std::cin >> val)) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
    l.push_back(val);
  }

  std::cout << "Исходный список L: ";
  for (auto it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::vector<double> v;
  std::adjacent_difference(
      l.begin(), l.end(), std::back_inserter(v),
      [](double a, double b) { return (a + b) / 2.0; });

  v.erase(v.begin());

  std::cout << "Полученный вектор средних арифметических V: ";
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
}

// Задание 9 (Задача 1): Проверка включения множеств (includes).
void Task9() {
  std::cout << "\n--- Задание 9 (Задача 1) ---\n";
  int size0 = 0;
  std::cout << "Введите размер вектора V0: ";
  while (!(std::cin >> size0) || size0 <= 0) {
    std::cout << "Ошибка! Введите положительное число: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::vector<int> v0(size0);
  std::cout << "Введите элементы вектора V0:\n";
  for (int i = 0; i < size0; ++i) {
    std::cout << "V0[" << i + 1 << "]: ";
    while (!(std::cin >> v0[i])) {
      std::cout << "Ошибка! Введите целое число: ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }
  }

  int n = 0;
  std::cout << "Введите количество сравниваемых векторов N (N > 0): ";
  while (!(std::cin >> n) || n <= 0) {
    std::cout << "Ошибка! Введите положительное число: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::set<int> set0(v0.begin(), v0.end());
  int matches = 0;

  for (int i = 1; i <= n; ++i) {
    int size_i = 0;
    std::cout << "Введите размер вектора V" << i << " (>= " << size0 << "): ";
    while (!(std::cin >> size_i) || size_i < size0) {
      std::cout << "Ошибка! Размер должен быть не меньше " << size0 << ": ";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    }

    std::vector<int> vi(size_i);
    std::cout << "Введите элементы вектора V" << i << ":\n";
    for (int j = 0; j < size_i; ++j) {
      std::cout << "V" << i << "[" << j + 1 << "]: ";
      while (!(std::cin >> vi[j])) {
        std::cout << "Ошибка! Введите целое число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
      }
    }

    std::set<int> set_i(vi.begin(), vi.end());
    if (std::includes(set_i.begin(), set_i.end(), set0.begin(), set0.end())) {
      ++matches;
    }
  }

  std::cout << "Количество векторов, содержащих все элементы V0: "
            << matches << "\n";
}

// Задание 10 (Задача 2): Суммарная длина слов на одну букву (std::map).
void Task10() {
  std::cout << "\n--- Задание 10 (Задача 2) ---\n";
  int n = 0;
  std::cout << "Введите количество слов: ";
  while (!(std::cin >> n) || n <= 0) {
    std::cout << "Ошибка! Введите положительное число: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
  }

  std::vector<std::string> v(n);
  std::cout << "Введите " << n << " слов (ЗАГЛАВНЫМИ латинскими буквами):\n";
  for (int i = 0; i < n; ++i) {
    std::cout << "Слово [" << i + 1 << "]: ";
    std::cin >> v[i];
  }

  std::cout << "Исходные слова: ";
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  std::map<char, int> m;
  for (auto it = v.begin(); it != v.end(); ++it) {
    m[(*it)[0]] += it->size();
  }

  std::cout << "Результат (буква и суммарная длина слов):\n";
  for (auto it = m.begin(); it != m.end(); ++it) {
    std::cout << it->first << " " << it->second << "\n";
  }
}
