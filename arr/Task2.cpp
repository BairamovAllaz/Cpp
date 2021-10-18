#include <iostream>
using namespace std;
int StepenN(size_t num,size_t n){
    if(n == 0){ 
        return 1;
    } 
    return num * StepenN(num,--n);
}
int FaktNumber(size_t num){ 
    return num == 1 ? 1 : num * FaktNumber(num - 1);
}
int SumCifr(size_t number) {
    return number == 0 ? 0 : SumCifr(number / 10) + number%10;
}
int main() {
    int num, n,num2;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter stepen: ";
    cin >> n;
    cout << "Stepen num: " << StepenN(num,n) << endl;
    cout << "Faktoriel of the number: " << FaktNumber(num) << endl;
    cout << "Enter number 2: ";
    cin >> num2;
    cout << "Sum of digits: " << SumCifr(num2) << endl;
    return 0;
}