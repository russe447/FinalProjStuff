#include <vector>
#include <string>
//#include <openssl/sha.h>
#include <string.h>
#include <iostream>

#include "block_t.h"

int main() {

    char a[] = "hello";
    char b[] = "my";
    char c[] = "name";
    char d[] = "is";
    char e[] = "austin";

    string second = "hellomynameisaustin";

    //char buf[sizeof(f)];

    string first = "";
    for (int x = 0; x < strlen(a); x++) {
        first += a[x];
    }
    for (int y = 0; y < strlen(b); y++) {
        first += b[y];
    }
    for (int j = 0; j < strlen(c); j++) {
        first += c[j];
    }
    for (int k = 0; k < strlen(d); k++) {
        first += d[k];
    }
    for (int l = 0; l < strlen(e); l++) {
        first += e[l];
    }

    //printf("%s\n", first.c_str());
    //printf("%s\n", second.c_str());
    unsigned char obuf1[] = {1, 3, 4, 5, 6};
    unsigned char obuf2[] = {1, 3, 4, 5, 6};

    printf("%d\n", memcmp(obuf1, obuf2, sizeof(obuf1)));

    

}