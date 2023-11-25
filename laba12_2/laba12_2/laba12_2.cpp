#include <iostream>

using namespace std;

int countNonDecreasingSubarrays(int arr[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        int j = i;

        // Знаходження неперервної послідовності чисел з неспадаючими значеннями
        while (j + 1 < size && arr[j] <= arr[j + 1]) {
            j++;
        }

        // Додаємо кількість ділянок для поточної точки i
        count += (j - i + 1);
    }

    return count;
}

int main() {
    const int size = 150;
    int arr[size];

    // Заповнюємо масив випадковими значеннями в діапазоні -100..100
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201 - 100; // від -100 до 100 включно
    }

    // Виводимо масив (опціонально)
    cout << "Масив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Обчислюємо кількість ділянок
    int result = countNonDecreasingSubarrays(arr, size);

    // Виводимо результат
    cout << "Кількість ділянок з неспадаючими значеннями: " << result << endl;

    return 0;
}
