#include <iostream>

using namespace std;

const int SIZE = 10;

//task_1
int reverseArr(int* arr, int size, int* evenCount, int* oddCount) {
    for (int i = size - 1; i >= 0; --i) {
        cout << *(arr + i) << " ";
        if (*(arr + i) % 2 == 0) {
            ++*evenCount;
        }
        else {
            ++*oddCount;
        }
    }

    if (*evenCount > *oddCount) {
        return 1;
    }
    else if (*evenCount < *oddCount) {
        return 2;
    }
    else {
        return 0;
    }
}

//task_2
void findMax(int arr[], unsigned size, int& max) {
    max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
}

int main()
{
    //task_1
    // int arr[100] = { 1, 2, 3, 4, 5 };
    // int evenCount = 0, oodCount = 0;

    // int result = reverseArr(arr, 5, &evenCount, &oodCount);
    // cout << endl;
    // cout << result << endl;
    // cout << evenCount << " : " << oodCount << endl;

    //task_2
    // int arr[SIZE] = { 5, 7, 9, 1, 2, 4 };
    // int max = 0;

    // findMax(arr, 6, max);
    // cout << max << endl;

    //task_3
    // unsigned size;
    // int* arr;

    // std::cout << "Insert size of array: ";
    // std::cin >> size;

    // arr = new int[size];

    // for(unsigned i = 0; i < size; ++i){
    //     std::cout << "arr[" << i << "] = ";
    //     std::cin >> arr[i];
    // }

    // for(unsigned i = 0; i < size; ++i){
    //     std::cout << arr[i] << std::endl;
    // }
    
    // delete[] arr;
    
    return 0;
}