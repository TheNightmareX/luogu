#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> numbers;
    while (true) {
        int number;
        cin >> number;

        if (!number)
            break;

        numbers.push(number);
    }

    while (!numbers.empty()) {
        cout << numbers.top() << ' ';
        numbers.pop();
    }
        
    return 0;
}
