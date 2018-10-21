#define MAX 0x7fffffff

long int y;

long int power(int ten, int p)
{
    int i;
    long int val = 1;
    
    for (i = 1; i <= p; i++) {
        val *= ten;
    }
    //printf("val = %ld\n", val);
    return val;
}

int reverse(int x) {
    int A[32];
    int n, i = 0, sign = 0;
    
    if (x == 0)
        return 0;
    if (x < 0) {
        sign = 1;
        x = -(x);
    }
    
    while (x != 0) {
        A[i++] = x % 10;
        x = x / 10;
    }
    n = i;
    y = 0;
    for (i = 0; i < n; i++) {
        y = y + (long int)(A[i]*power(10, n-1-i));
        //printf("A[i] = %d, y = %ld\n", A[i], y);
        if (y > INT_MAX || y < INT_MIN)
            return 0;
    }
    
    if (sign == 1)
        y = -(y);
    
    
    return (int)y;
}
