#include <iostream>
#include <iomanip>  // Для округления
#include <climits>  // Для INT_MAX, INT_MIN

using std::cout;
using std::cin;
using std::endl;

using namespace std;

// Функция для проверки, является ли число простым
bool is_prime(int number) {
    if (number < 2) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;
    for (int i = 3; i*i <= number; i += 2) {
        if (number % i == 0) return false;  
    }
    return true;
}

// Функция для проверки, является ли число степенью двойки
bool is_power_of_two(int number) {
    return (number > 0) && ((number & (number - 1)) == 0);
}

int main(int argc, char* argv[]) {

    setlocale(LC_ALL, "");

    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0)
    {
        isHuman = true;
    }

    if (isHuman) cout << "Введите число N" << endl;

    int n;
    cin >> n;  

    int number;                          // Текущее число
    int sum = 0;                         // Сумма всех чисел
    int min_num = INT_MAX;               // Минимальное число
    int max_num = INT_MIN;               // Максимальное число
    int count_five = 0;                  // Счётчик кратных 5
    int count_two = 0;                   // Счётчик степеней двойки
    int count_last_sum = 0;              // Счётчик чисел, превышающих сумму двух предшествующих
    int prev1 = 0, prev2 = 0;            // Для хранения двух предыдущих чисел
    bool first_two = true;               // Флаг для первых двух чисел

    
    for (int i = 0; i < n; ++i) {
        cin >> number;  

        // Проверка на простое число
        if (is_prime(number)) {
            cout << number << endl;
        }

        // 2. Накопление суммы чисел
        sum += number;

        // 3. Нахождение минимума и максимума
        if (number > max_num) max_num = number;
        if (number < min_num) min_num = number;

        // 4. Проверка кратности 5
        if (number % 5 == 0) {
            ++count_five;
        }

        // 5. Проверка, является ли число степенью двойки
        if (number > 0 && (number & (number - 1)) == 0) {
            ++count_two;
        }

        // 6. Проверка, превышает ли число сумму двух предыдущих
        if (!first_two && number > prev1 + prev2) {
            ++count_last_sum;
        }

        // Обновление предыдущих чисел
        prev2 = prev1;
        prev1 = number;
        if (i == 1) first_two = false;  // После ввода второго числа сбрасываем флаг
    }

    if (isHuman) {
        double average = static_cast<double>(sum) / n;
        cout << fixed << setprecision(2) << "Среднее арифметическое: " << average << endl;
        cout << "Разница между максимальным числом и минимальным: " << max_num - min_num << endl;
        cout << "Количество чисел, кратных 5: " << count_five << endl;
        cout << "Количество чисел, являющихся степенью двойки: " << count_two << endl;
        cout << "Количество чисел, превышающих сумму двух предыдущих: " << count_last_sum << endl;
    }
    else {
        double average = static_cast<double>(sum) / n;
        cout << fixed << setprecision(2) << average << endl;
        cout << max_num - min_num << endl;
        cout << count_five << endl;
        cout << count_two << endl;
        cout << count_last_sum << endl;
    }
    
}
