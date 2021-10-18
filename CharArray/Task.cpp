#include <iostream>
using namespace std;
int SizeOf(char string[]);
void toLow(char string[]);
void DeleteP(char string[]);
bool IsPolindrom(char string[]);
int to_int_number(char string[]);
bool isIntNumber(char string[]);
bool isBinNumber(char string[]);
int ToBin(char string[]);
int Stepen(int x,int y);
bool is_hex_number(char string[]);
int hexadecimalToDecimal(char string[]);
int main(){
    char string[300];
    cout << "Enter a string: ";
    cin.getline(string,300);
    cout << (IsPolindrom(string) ? "Is polindrom" : "Not Polindrom!") << endl;
    cout << boolalpha <<"Is int number : " << isIntNumber(string) << endl;
    if(isIntNumber(string)){
        to_int_number(string);
        cout << "to int: " << string << endl;
    };
    cout << boolalpha << "Is Bin Number : " << isBinNumber(string) << endl;
    if(isBinNumber(string)){
        cout << "Bin int: " << ToBin(string) << endl;
    }

    cout << boolalpha << is_hex_number(string) << endl;
    if(is_hex_number(string)){
        cout << "Hex to int: " << hexadecimalToDecimal(string) << endl; 
    }


    return 0;
}

int SizeOf(char string[]){
    int s = 0;
    for (size_t i = 0;string[i]; i++) ++s;
    return s;
}
void toLow(char string[]){ 
    for (size_t i = 0;string[i]; i++)
    {
        if(string[i] >= 'A' || string[i] <= 'B'){
            string[i] += 32;
        }
    }
}
void DeleteP(char str[]){
    for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
				str[j] = str[j + 1];
		}
	}
}
bool IsPolindrom(char string[]){
    int size = SizeOf(string);
    char *NewArr = new char[300];
    __memcmp(NewArr,string,300);
    toLow(NewArr);
    DeleteP(NewArr);
    for (size_t i = 0;NewArr[i]; i++)
    {
        if(!(NewArr[i] != NewArr[size - i - 1])){
            delete[] NewArr;
            return false;
        }
    }
    delete[] NewArr;
    return true;
}


bool isIntNumber(char string[]){
    for (size_t i = 0;string[i]; i++)
    {
        if(!(string[i] >= '0' && string[i] <= '9')) return false;
    }
    return true;
}

int to_int_number(char string[]){
    int t = 0;
    for (size_t i = 0;string[i]; i++)
    {
        t = t * 10 + string[i] - '0';
    }
    return t;
}


bool isBinNumber(char string[]){
    for (size_t i = 0;string[i]; i++)
    {
        if(!(string[i] == '1' || string[i] == '0')){
            return false;
        }
    }
    return true;
}

int Stepen(int x,int y){
    int res = 1;
	for (int i = 1; i <= y; i++)
		res *= x;
	return res;
}
int ToBin(char string[]){
     int r = 0;
     int size= SizeOf(string);
		for (size_t i = size; i > 0; i--)
			r += (string[i - 1] - '0') * Stepen(2, (size - i));
		return r;
}
bool is_hex_number(char string[])
{
	for (size_t i = 0; string[i]; i++)
	{
		if (!((string[i] >= '1' && string[i] <= '9') || (string[i] >= 'A' && string[i] <= 'F') && 'h'))
			return false;
	}
	return true;
}


int hexadecimalToDecimal(char string[])
{
    int len = SizeOf(string);
    int base = 1;
    int dec_val = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (string[i] >= '0' && string[i] <= '9') {
            dec_val += (int(string[i]) - 48) * base;
            base = base * 16;
        }
        else if (string[i] >= 'A' && string[i] <= 'F') {
            dec_val += (int(string[i]) - 55) * base;
            base = base * 16;
        }
    }
    return dec_val;
}