#include <iostream>
using namespace std;

int SizeOfString(char *string){ 
    if(*string == '\0' || *string == 0){
        return 0;
    }
    return 1 + SizeOfString(++string);
}

int KolSlow(char *string){
    int slov = 0;
    if(*string == '\0' || *string == 0){
        return 0;
    }
    slov =slov +  SizeOfString(++string);
    if(*string == ' '){
        ++slov;
    }
    return slov;
}

void ConvertStringDown(char *string) { 
    if(*string == '\0' || *string == 0){
        return;
    }
    if(*string >= 'A' && *string <= 'Z'){ 
     *string = *string + 32;
    }
    ConvertStringDown(++string);
}



void ConvertStringUp(char *string) { 
    if(*string == '\0' || *string == 0){
        return;
    }
    if(*string >= 'a' && *string <= 'z'){ 
     *string = *string - 32;
    }
    ConvertStringUp(++string);
}



bool checkSimvol(char *string,char simvol){ 
    if(*string == '\0' || *string == 0){
        return false;
    }
    if(*string == simvol){ 
        return true;
    }
    return checkSimvol(++string,simvol);

}

int AmountSimvol(char *string,char simvol){ 
    if(*string == '\0' || *string == 0){
        return 0;
    }
    int kol = checkSimvol(++string,simvol);
    if(*string == simvol){ 
        ++kol;
    }
    return kol;
}

int main(){
    bool val;
    char simvol;
    char *string = new char[300];
    cout << "Enter a string : ";
    cin.getline(string,300);


    cout << "Your string: " << string << endl;    

    cout << "Size of String: " << SizeOfString(string) << endl;
    cout << "Amount og string: " << KolSlow(string) << endl;
     ConvertStringDown(string);
    cout << "New Lowcase string: " << string << endl;
    ConvertStringUp(string);
    cout << "New uppercase: " << string << endl;    
    
    cout << "Enter a string : ";
    cin.getline(string,300);
    cout << "Enter a simvolL: ";
    cin >> simvol; 
    val = checkSimvol(string,simvol);
    cout << boolalpha << val << endl;
    cout << "Amount of simvol : " << AmountSimvol(string,simvol) << endl;
 
    delete[] string;
    return 0;
}