#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Element;

int compare(const void* a, const void* b) {
    return ((Element*)a)->value - ((Element*)b)->value;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Element* elements = (Element*)malloc(numsSize * sizeof(Element));
    for (int i = 0; i < numsSize; i++) {
        elements[i].value = nums[i];
        elements[i].index = i;
    }

    qsort(elements, numsSize, sizeof(Element), compare);

    int left = 0;
    int right = numsSize - 1;
    while (left < right) {
        int sum = elements[left].value + elements[right].value;
        if (sum == target) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = elements[left].index;
            result[1] = elements[right].index;
            *returnSize = 2;
            free(elements);
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    *returnSize = 0;
    free(elements);
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int* result = twoSum(nums, numsSize, target, &returnSize);

    printf("Output: ");
    if (result != NULL) {
        printf("[%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
