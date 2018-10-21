int isprime(int n)
{
    int i;
    for (i = 2; i*i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
int countPrimes(int n) {
    int val = 0;
    int i;
    if (n <= 2) return 0;
    if (n == 3) return 1;
    val = 2;
    for (i = 4; i < n; i++) {
        if (i % 2 == 0 || i % 3 == 0) continue;
        if (isprime(i)) val++;
    }
    return val;
}
