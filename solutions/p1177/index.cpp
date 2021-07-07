#include<bits/stdc++.h>
using namespace std;

void quick_sort(int *numbers, int start, int end) {
    if (end - start <= 1)
        return;

    // avoid always picking the most front number as the pivot number so that the worst situation will not appear every time
    int length = end - start;
    swap(numbers[start], numbers[rand() % length + start]);

    int index_to_swap = start + 1;
    for (int i = index_to_swap; i < end; i++)
        if (numbers[i] < numbers[start])
            swap(numbers[index_to_swap++], numbers[i]);

    // numbers left side are all smaller or equal and right side ones are all greater or equal than the number with the pivot index.
    int pivot_index = index_to_swap - 1;
    swap(numbers[start], numbers[pivot_index]);
    quick_sort(numbers, start, pivot_index);
    quick_sort(numbers, pivot_index + 1, end);
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
