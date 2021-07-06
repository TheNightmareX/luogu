#include<bits/stdc++.h>
using namespace std;

int main() {
    int count, tgt_num;
    cin >> count >> tgt_num;
    
    queue<int> subjects;
    for (int id = 1; id <= count; id++)
        subjects.push(id);

    while (!subjects.empty()) {
        int num = 1;
        while (true) {
            int id = subjects.front();
            subjects.pop();
            if (num == tgt_num) {
                cout << id << ' ';
                break;
            } else {
                subjects.push(id);
                num++;
            }
        }
    }

    return 0;
}