int singleNumber(int* nums, int numsSize) {
    int i, odd = 0;
    
    for (i = 0; i < numsSize; i++) {
        odd = odd ^ nums[i];
    }
    return odd;
}
