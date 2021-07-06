#include<bits/stdc++.h>
using namespace std;

int main() {
    string exp;
    cin >> exp;

    int i = 0;
    int unhandled_count = 0;
    while (true) {
        if (exp[i] == '@' || unhandled_count < 0)
            break;

        if (exp[i] == '(')
            unhandled_count++;
        if (exp[i] == ')')
            unhandled_count--;

        i++;
    }

    cout << (unhandled_count ? "NO" : "YES");

    return 0;
}