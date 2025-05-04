#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<int> numbers;
    int n, x;

    ifstream fin("input.txt");
    int value;
    while (fin >> value) numbers.push_back(value);
    fin.close();

    cout << "Введи n: ";
    cin >> n;
    cout << "Введи x: ";
    cin >> x;

    ofstream out1("output1.txt");
    for (int i = 0; i < numbers.size(); i++) {
        int pos = i + 1;
        if (pos % n == 0)
            out1 << pow(numbers[i], 3) << " ";
        else
            out1 << pow(numbers[i], 2) << " ";
    }
    out1.close();

    //тринач на непарних
    int count3 = 0;
    for (int i = 0; i < numbers.size(); i += 2)
        if (abs(numbers[i]) >= 100 && abs(numbers[i]) <= 999)
            count3++;

    //найбільш непарних  на позиціях з  кратних н
    int maxOdd = INT_MIN;
    bool found = false;
    for (int i = 0; i < numbers.size(); i++) {
        if ((i + 1) % n == 0 && numbers[i] % 2 != 0) {
            if (!found || numbers[i] > maxOdd) {
                maxOdd = numbers[i];
                found = true;
            }
        }
    }
//перше число що закінч на н
   
    int first = -1, pos = -1;
    for (int i = 0; i < numbers.size(); i++) {
        if (abs(numbers[i]) % 10 == n) {
            first = numbers[i];
            pos = i + 1;
            break;
        }
    }

    //наближ знач е
    double y = 1.0, term = 1.0;
    for (int i = 1; i <= n; i++) {
        term *= (double)x / i;
        y += term;
    }

    ofstream out2("results.txt");
    out2 << "К-сть тризначних на непарних позиціях: " << count3 << endl;
    if (found)
        out2 << "Макс. непарне на позиціях, кратних n: " << maxOdd << endl;
    else
        out2 << "Немає непарних на таких позиціях\n";
    if (pos != -1)
        out2 << "Перше число з ост. цифрою " << n << ": " << first << " (позиція " << pos << ")\n";
    else
        out2 << "Немає числа з ост. цифрою " << n << "\n";
    out2 << "e^x ≈ " << y << endl;
    out2.close();

    cout << "Готово! Перевір файли output1.txt і results.txt\n";
    return 0;
}