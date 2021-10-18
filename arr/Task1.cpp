#include <iostream>
#include <ctime>
using namespace std;


void PrintArray(const int *arr,size_t size){
    if(size <= 0) {
        return;
    }
    cout << arr[size] << endl;
    PrintArray(arr,size -1); 
}


int MinElement(const int *arr,size_t size){ 
    if(size == 1){
        return arr[0];
    }else{ 
    int min = MinElement(arr,size - 1);
    if(arr[size-1] > min){
        return min;
    }else{
        return arr[size-1];
    }
    }
}

int MaxElement(const int *arr,size_t size){ 
    if(size == 1){
        return arr[0];
    }else{ 
    int max = MaxElement(arr,size - 1);
    if(arr[size-1] < max){
        return max;
    }else{
        return arr[size-1];
    }
    }
}


int sumElement(const int *arr,size_t size) { 
    if(size <= 0){ 
        return 0;
    }
    return sumElement(arr,size - 1) + arr[size - 1];
}

int prozElement(const int *arr,size_t size) { 
    if(size <= 0){ 
        return 1;
    }
    return prozElement(arr,size - 1) * arr[size - 1];
}

bool checkMyElement(const int *arr, size_t size, size_t checkMe){ 
    if(size <= 0){ 
        return false;
    }
    if(arr[size] == checkMe){ 
        return true;
    }
    return checkMyElement(arr,size - 1,checkMe);
}

int SumOfMinus(const int *arr,size_t size){
    if(size <= 0){ 
        return 0;
    } 
    int num = SumOfMinus(arr,size - 1);

    if(arr[size] < 0) { 
        ++num;
    }
    return num;
}


int SumOfPluse(const int *arr,size_t size){
    if(size <= 0){ 
        return 0;
    } 
    int num = SumOfPluse(arr,size - 1);

    if(arr[size] >= 0) { 
        ++num;
    }
    return num;
}

int AmountOfGivenElement(const int *arr,size_t size,size_t MyElement){
    if(size <= 0){ 
        return 0;
    } 
    int num = AmountOfGivenElement(arr,size - 1,MyElement);

    if(arr[size] == MyElement) { 
        ++num;
    }
    return num;
}


int AmountKotnix(const int *arr,size_t size){
    if(size <= 0){ 
        return 0;
    } 
    int num = AmountKotnix(arr,size - 1);

    if(arr[size] % 2 == 0) { 
        ++num;
    }
    return num;
}

int AmountNeKotnix(const int *arr,size_t size){
    if(size <= 0){ 
        return 0;
    } 
    int num = AmountNeKotnix(arr,size - 1);

    if(arr[size] % 2 == 1) { 
        ++num;
    }
    return num;
}




int main(){ 
    srand(time(0));
    int size;
    int checkElement;
    cout << "Enter a size: ";
    cin >> size;
    int *arr = new int[size];

    for (size_t i = 0; i < size; i++)
        arr[i] = rand() % (10+10) - 10;
    
    PrintArray(arr,size);

    cout << "Minimum Element in the array: " << MinElement(arr,size) << endl;
    cout << "Maximum Element in the array: " << MaxElement(arr,size) << endl;
    cout << "Sum of the element: " << sumElement(arr,size) << endl;
    cout << "Product of elements: " << prozElement(arr,size) << endl;
    cout << "Amoount of minus numbers: " << SumOfMinus(arr,size) << endl;
    cout << "Amount of positive elements: " << SumOfPluse(arr,size) << endl;    
    cout << "The number of even elements in this array: " << AmountKotnix(arr,size) << endl;
    cout << "Amount of Not even elements in this array: " << AmountNeKotnix(arr,size) << endl;
    cout << "Enter a element for checking: ";
    cin >> checkElement;

    cout << "Your checking element is: " << boolalpha << checkMyElement(arr,size,checkElement) << endl; 
    cout << "Amount of given number: " << AmountOfGivenElement(arr,size,checkElement) << endl;
    delete[] arr;
    return 0;
}