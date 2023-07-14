#include <stdio.h>
#include <stdlib.h>

int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    int evenIndex = 0;
    int oddIndex = 1;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % 2 == 0) {
            result[evenIndex] = nums[i];
            evenIndex += 2;
        } else {
            result[oddIndex] = nums[i];
            oddIndex += 2;
        }
    }
    
    *returnSize = numsSize;
    return result;
}
