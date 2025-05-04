#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isBalanced(const string& input) {
    vector<char> st;
    for (char c : input) {
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;
            char top = st.back();
            st.pop_back();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    while (true) {
        cout << "Введіть рядок з дужками: ";
        string input;
        getline(cin, input);

        if (isBalanced(input)) {
            cout << "Правильно\n";
            break;
        }
        else {
            cout << "Помилка, введіть ще раз\n";
        }
    }
    return 0;
}
