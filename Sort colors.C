void sortColors(int* nums, int numsSize) {
    int low = 0;        // index for the low boundary of the current color
    int mid = 0;        // index for the mid boundary of the current color
    int high = numsSize - 1;    // index for the high boundary of the current color

    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                // Swap the element at 'mid' with the element at 'low'
                swap(&nums[mid], &nums[low]);
                low++;
                mid++;
                break;
            case 1:
                // The element is already in the correct position
                mid++;
                break;
            case 2:
                // Swap the element at 'mid' with the element at 'high'
                swap(&nums[mid], &nums[high]);
                high--;
                break;
        }
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
