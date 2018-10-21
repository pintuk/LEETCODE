int removeDuplicates(int* nums, int numsSize) {
    int i;
    int len = 0, val = 0;
    
    if (nums == NULL)
        return 0;
    
    if (numsSize == 0)
        return 0;
    
    for (i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i-1]) {
            val++;
        } else {
            len = i - val;
            nums[len] = nums[i];
        }
    }
    return len+1;
}
