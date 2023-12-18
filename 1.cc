#include <iostream>
#include <cmath>

int findMinIndex(const double arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

double sumBetweenNegatives(const double arr[], int size) {
    int firstNegIndex = -1;
    int secondNegIndex = -1;

    
    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            if (firstNegIndex == -1) {
                firstNegIndex = i;
            } else {
                secondNegIndex = i;
                break;
            }
        }
    }

    double sum = 0.0;
    if (firstNegIndex != -1 && secondNegIndex != -1) {
        for (int i = firstNegIndex + 1; i < secondNegIndex; ++i) {
            sum += arr[i];
        }
    }

    return sum;
}

int main() {
    const int size = 10;  
    double arr[size];

   
    for (int i = 0; i < size; ++i) {
        std::cout << "Введіть " << i + 1 << "-й елемент: ";
        std::cin >> arr[i];
    }

    
    int minIndex = findMinIndex(arr, size);
    std::cout << "Номер мінімального елемента: " << minIndex << std::endl;

    
    double sumBetweenNeg = sumBetweenNegatives(arr, size);
    std::cout << "Сума елементів між першим і другим від'ємними: " << sumBetweenNeg << std::endl;

    
    for (int i = 0; i < size; ++i) {
        if (std::abs(arr[i]) <= 1) {
            
            std::cout << arr[i] << " ";
        }
    }
    for (int i = 0; i < size; ++i) {
        if (std::abs(arr[i]) > 1) {
            
            std::cout << arr[i] << " ";
        }
    }

    return 0;
}
