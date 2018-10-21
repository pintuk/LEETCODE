int climbStairs(int n) {
    int i;
    int F[1001];
    
    F[0] = 0;
    F[1] = 1;
    F[2] = 2;
    F[3] = 3;
    for (i = 4; i <= n; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    return F[n];
}
