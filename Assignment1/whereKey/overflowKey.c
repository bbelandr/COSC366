#include <stdio.h>

void print_hex(const char *s)
{
  while(*s)
    printf("%02x", (unsigned int) *s++);
  printf("\n");
}

// Here is what I think is beefcafe in hex: ¾ïÊþ
int main() {
    // char value = 0xbeefcafe;
    // printf (value);
    unsigned char key[4];
    key[3] = 0xbe;
    key[2] = 0xef;
    key[1] = 0xca;
    key[0] = 0xfe;

    unsigned int *p = key;

    // printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA%s\n", key);    
    printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA%4x\n", *p);    

} 