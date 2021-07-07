#include<bits/stdc++.h>
using namespace std;

void quick_sort(int *numbers, int start, int end) {
    if (end - start <= 1)
        return;

    int base_num = numbers[start];

    int index_to_swap = start + 1;
    for (int i = index_to_swap; i < end; i++)
        if (numbers[i] < base_num)
            swap(numbers[index_to_swap++], numbers[i]);

    // numbers left side are all smaller or equal and right side are all greater or equal.
    int center_index = index_to_swap - 1;
    swap(numbers[start], numbers[center_index]);
    quick_sort(numbers, start, center_index);
    quick_sort(numbers, center_index + 1, end);
}

int main() {
    const int MAX_NUMBER_COUNT = 100000;

    int number_count;
    cin >> number_count;

    int numbers[MAX_NUMBER_COUNT + 5];
    for (int i = 0; i < number_count; i++)
        cin >> numbers[i];

    quick_sort(numbers, 0, number_count);
    
    for (int i = 0; i < number_count; i++)
        cout << numbers[i] << ' ';

    return 0;
}
