int FirstIndexSimvol(char *string,char simvol){
    int val = 0;
    while (*string)
    {
        if(*string == simvol){
            val = string;
        }
       ++string;
    }
    return val;
}
