#include <iostream>
using namespace std;

int SizeOfString(char *string){ 
    int length = 0;
    while (*string)
    {
        ++length;
        ++string;
    }
    return length;
}

int amountS(char *string){ 
    int length = 1;

    while (*string)
    {
        if(*string == ' '){ 
            ++length;
        }   


        ++string;
    }
    return length;
}

void UpperCaseWord(char *string){ 
    while (*string)
    {
        if(*string >= 'a' && *string <= 'z'){
            *string -= 32;
        }
        ++string;
    }
}


void LowerCaseWord(char *string){ 
    while (*string)
    {
        if(*string >= 'A' && *string <= 'Z'){
            *string += 32;
        }
        ++string;
    }
}

bool IsHere(char *string,char simvol){
    while (*string)
    {
        if(*string == simvol){
            return true;
        }
       ++string;
    }
    return false;
}

int Amountcurrent(char *string,char simvol){
    int val = 0;
    while (*string)
    {
        if(*string == simvol){
            ++val;
        }
       ++string;
    }
    return val;
}


 int FirstIndexSimvol(char *string,char simvol){
    int Length = 0;
    while (*string)
    {
        if(*string == simvol){
            break;
        }
        ++Length;
       ++string;
    }
    return Length;
}



int firstInexSub(char *string,char *newString){ 
    int n = 0;
    for (size_t i = 0;string[i]; i++)
    {
        if(string[i] == newString[n]){
            ++n;
            if(i == n){ 
                return n + 1;
            }   
        }else{
            n = 0;
        }

 }
 return n + 1;
}

 
 bool weHave(char *string,char *newstring){
    bool val;
    int n = 0;
    for (size_t i = 0;string[i]; i++)
    {
        if(string[i] == newstring[n]){
            ++n;
            val = true;
            if(i == n){ 
            return val;
            }
        }else{
            val = false;
        }
    }
    return val;
}

void reverse(char *arr)
{
    char *news;
    for (int low = 0;arr[low];low++) {
         for(int high = low;high < arr[high];high++){
            *news = arr[low];
            arr[low] = arr[high];
            arr[high] = *news;
        }
    }
}


void DeleteSticky(char *string){
    
    while (*string)
    {
        if(*string <= 'a' && *string >= 'z' || *string <= 'A' && *string >= 'Z'){
            cout << "Ops we have any!!!!!!" << endl;
        }
        ++string;
    }
}

bool SravString(char *string,char *newstring){ 
    bool val = false;
    for (size_t i = 0;string[i]; i++)
    {
        if(string[i] == newstring[i]){
            val = true;
        }else{
            val = false;
        }
    }
    return val;
}



char* ContactChar(char *string,char *newstring){
    int k = 0;
    char *Lstring = new char[300];
    for (size_t i = 0;string[i]; i++)
    {
        Lstring[k] = string[i];
        ++k;
    }
    for (size_t i = 0;newstring[i];i++)
    {
        Lstring[k] = newstring[i];
        ++k;
    }
    return Lstring;
}

char *PodStrok(char *string,size_t index){ 
    char *Pod = new char[300];
    if(sizeof(string) < index){ 
        return string;
    }
    for (size_t i = 0;string[i]; i++)
    {
        if(i <= index){
            Pod[i] = string[i];
        }
    } 
    return Pod;
}
 
int main(){
    char *string = new char[300];
    char *NewString = new char[300];
    char *Mstring = new char[300];
    int index;
    char simvol;
    cout << "Enter a string: ";
    cin.getline(string,300);

    cout << "Your string: " << string << endl;
 
    cout << "Enter a simvol: ";
    cin >> simvol;
    cout << "Enter a string for find: ";
    cin.ignore();
    cin.getline(NewString,300);
    cout << "1 : Line of word: " << SizeOfString(string) << endl;
    cout << "Amount of slov" << amountS(string) << endl;
    cout << "2 : Count the number of words in a line : " << SizeOfString(string) << endl;
    bool val = IsHere(string,simvol);
    cout << (val ? "This simvol here" : "This simvol not here") << endl;
    cout << "Amount of this simvol: " << Amountcurrent(string,simvol) << endl;
    cout << "First index of simvol: " << FirstIndexSimvol(string,simvol) << endl;
    cout << "Firts index of sub-string: " << firstInexSub(string,NewString) << endl;
    cout << boolalpha << weHave(string,NewString) << endl;

    cout << "Enter a index: ";
    cin >> index;

    cout << "Podstrok: " << PodStrok(string,index) << endl;

    UpperCaseWord(string);
    cout << "Your uppercase string: ";
    cout << string << endl;
    LowerCaseWord(string);
    cout << "Your Lowercase string: ";
    cout << string;
    cout << "Enter a string again: " << endl;
    cin.ignore();
    cin.getline(Mstring,300);

    cout << boolalpha <<  SravString(string,Mstring) << endl;
    cout << "New string: " << string << endl;
    cout << "Connacted string: " <<  ContactChar(string,NewString) << endl;
    reverse(string);

    cout << endl;
    
    DeleteSticky(string);

    
    
    delete[] NewString;
    delete[] string;
    return 0;
}