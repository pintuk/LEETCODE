#if 0
int missingNumber(int* nums, int numsSize) {
    int i,j;
    int n = 0;
    int miss = -1;
    int flag;
    
    for (i = 0; i <= numsSize; i++) {
        flag = 1;
        for (j = 0; j < numsSize; j++) {
            //printf("i:%d, nums[%d]:%d, i^nums[j]=%d, flag:%d\n", i, j, nums[j], (i^nums[j]), flag);
            if ((i ^ nums[j]) == 0) {
                flag = 0;
                //printf("2 => i:%d, nums[%d]:%d, i^nums[j]=%d, flag:%d\n", i, j, nums[j], (i^nums[j]), flag);
                break;
            }
        }
        //printf("i:%d, nums:%d, i^nums[j]=%d, flag:%d\n", i, nums[j], (i^nums[j]), flag);
        if (flag == 1) {
            miss = i;
            break;
        }
    }
    return miss;
}
#endif

int missingNumber(int* nums, int numsSize) {   
    int i, realsum = 0;
    int sum = 0;
    
    realsum = numsSize*(numsSize + 1)/2;
    for (i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return (realsum - sum);
}
