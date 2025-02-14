#include <iostream>
#include <string>


int main(){
    int* arr = new int[5];
    for(int i = 0; i < 5; i++){
        arr[i] = i + 1;
    }

    std::cout << 5 << "\n";
    for(int i = 0; i < 5; i++){
        std::cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;

}