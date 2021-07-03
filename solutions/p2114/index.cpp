#include <bits/stdc++.h>
using namespace std;

int main() {
    int operation_count, max_number;
    cin >> operation_count >> max_number;

    const int MAX_INDEX = 100000 + 5;
    struct {
        string type;
        int payload;
    } operations[MAX_INDEX];
    for (int index = 0; index < operation_count; index++)
        cin >> operations[index].type >> operations[index].payload;

    const int MAX_BIT_COUNT = 30;
    int number = 0, result = 0;
    // movement: 需要移动的位数
    for (int movement = MAX_BIT_COUNT - 1; movement >= 0; movement--) {
        // [i] 存储该位置bit为 i 时该位置 bit 的 result: 0/1
        int operation_results[2] = { 0, 1 };
        for (int bit = 0; bit <= 1; bit++)
            for (int index = 0; index < operation_count; index++) {
                string type = operations[index].type;
                // 取出操作的 payload 在此位置上的值: 0/1
                int payload = (operations[index].payload >> movement) & 1;
                if (type == "AND")
                    operation_results[bit] &= payload;
                if (type == "OR")
                    operation_results[bit] |= payload;
                if (type == "XOR")
                    operation_results[bit] ^= payload;
            }

        if (operation_results[0]) // 成立 0 -> 1
            result |= 1 << movement;
        else if (operation_results[1]) { // 成立 1 -> 1
            int updated_number = number | (1 << movement);
            if (updated_number <= max_number) {
                number = updated_number;
                result |= 1 << movement;
            }
        }
    }

    cout << result;
}
