#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(const std::vector<long long>& numbers) {
    // int has the datatype of int32_t so we change to long long so no overflow
    long long max_product = 0;
    int n = numbers.size();

    for (long long first = 0; first < n; ++first) {
        for (long long second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

// Implement Stress Test: Find the largest number in the array
long long MaxPairwiseProduct2(const std::vector<long long>& numbers){
    int n = numbers.size();

    // find first largest number: Correct
    int max_index1 = 0;
    for (int i = 1; i < n ; i++){
        if(numbers[i] > numbers[max_index1]){
            max_index1 = i;
        }
    }

    //find second largest number: The position i has to be different; if value at i > value at index 2 or index 1 == index 2
    //since the value that we are interested in is i, we can have the same value max but not the same position
    int max_index2 = 0;
    for (int i = 1; i < n; i++){
        if ((i != max_index1) && ((numbers[i] > numbers[max_index2]) || max_index1 == max_index2)){
            max_index2 = i;
        }
    }
    // cout << max_index1 << " " << max_index2 << endl;
    return numbers[max_index1] * numbers[max_index2];
}

int main() {
    // // Implementing stress test" pick random number of elements and random elements
    // while(true){
    //     int n = rand() % 100 + 2; // moduler 4 so number is from 0-3 then add 2 which mean the random number is from range 0-5
    //     cout << "Number of Elements are: " << n << endl;
    //     vector<long long int> a; // declare a vector
    //     for (int i = 0; i < n; i++){
    //         a.push_back(rand() % 10000); // generate random number less than 10
    //     }
    //     // show number
    //     for (int i = 0; i < n; i++){
    //         cout << a[i] << " ";
    //     }
    //     cout << endl;
    //     long long res1 = MaxPairwiseProduct(a);
    //     long long res2 = MaxPairwiseProduct2(a);
    //     if (res1 != res2){ //we can see where the two elements are wrong
    //         cout << "Wrong answer: " << res1 << " " << res2 << endl;
    //         break;
    //     }
    //     else{
    //         cout << "ok" << endl;
    //     }
    // }

    // main
    int n;
    std::cin >> n; // take in input len of vector
    std::vector<long long> numbers(n); // create vector of type int named numbers with n number of elements
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i]; // append elements to the vectors
    }

    std::cout << MaxPairwiseProduct2(numbers) << "\n"; // test with fast version
    return 0;
}
