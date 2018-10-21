#include <string.h>

#define SWAP(a,b)   do { \
                        char t; \
                        t = a;  \
                        a = b;  \
                        b = t;  \
                    } while(0)

char* reverseString(char* s) {
    int i;
    int len = 0;
    
    if (s == NULL)
        return NULL;
    len = strlen(s);
    
    if (len == 1)
        return s;
    
    for (i = 0; i < len/2; i++) {
        SWAP(s[i], s[len - 1 - i]);
    }
    
    return s;
}
