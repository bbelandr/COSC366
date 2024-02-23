#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void hackthis(){
    int key = 0xabcd1234;
    char buf[32];
    printf("please hack me: ");
    gets(buf); //hint: hack this!
    if(key == 0xbeefcafe){
        printf("you got me\n");
        system("ping 8.8.8.8");
    }
    else{
        printf("It doesn't work.\n");
    }
}

int main(int argc, char* argv[]){
    hackthis();
    return 0;
}