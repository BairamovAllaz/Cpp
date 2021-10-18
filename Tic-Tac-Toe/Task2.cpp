#include <iostream>
using namespace std;

bool isIp(char *IP){ 
    int segs = 0;
    int chcnt = 0;
    int accum = 0;  
    while (*IP) {
        if (*IP == '.') {
            if (chcnt == 0)
                return false;

            if (++segs == 4)
                return false;
            chcnt = 0;
            accum = 0;
            IP++;
            continue;
        }

        //check size
        if ((*IP < '0') || (*IP > '9'))
            return false;
        

        if ((accum = accum * 10 + *IP - '0') > 255)
            return false;
        chcnt++;
        IP++;
    }
    if (segs != 3)
        return false;

    if (chcnt == 0)
        return false;
    return true;
}


int length(char *string){
    int len = 0;
    while(*string){
        ++len;
        ++string;
    }
    return len;
}

bool isMacAdress(char *Mac){
    int lengthMac = length(Mac);
    if(lengthMac < 17){
        return false;
    }
    for(int i = 0; i < lengthMac; i++) {
        if(i % 3 != 2)
            return false;
        if(i % 3 == 2 && Mac[i] != ':')
            return false;
    }
    return true;
}

int main(){ 
    char *IP = new char[100];
    char *Mac = new char[100];
    cout << "Enter a IP adress";
    cin.getline(IP,300);
    bool resultIP = isIp(IP);
    cout << (resultIP ? "This is a IP adress": "This is not ip adress");
    cout << "Enter a mac adress: ";
    cin.ignore();
    cin.getline(Mac,300);
    bool resultMAC = isMacAdress(IP);
    cout << (resultMAC ? "This is a mac adress": "This is not mac adress");
    return 0;
}