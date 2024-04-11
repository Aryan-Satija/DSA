// CODING NINJAS -> Check whether K-th bit is set or not
bool isKthBitSet(int n, int k)
{
    return n & (1 << (k - 1)) ? true : false;
}