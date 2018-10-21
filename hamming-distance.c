
int countone(int x)
{
    int count = 0;
    while (x != 0) {
        x = x & (x-1);
        count++;
    }
    return count;
}

int hammingDistance(int x, int y) {
    int xor = 0, d = 0;
    xor = x ^ y;
    d = countone(xor);
    return d;
}
