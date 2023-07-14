int maxArea(int* height, int heightSize) {
    int left = 0;               // Left pointer starting from the beginning
    int right = heightSize - 1; // Right pointer starting from the end
    int maxArea = 0;            // Maximum area initialized to 0

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];  // Select the smaller height
        int area = (right - left) * h;  // Calculate the area

        if (area > maxArea) {
            maxArea = area;  // Update the maximum area if the current area is greater
        }

        if (height[left] < height[right]) {
            left++;  // Move the left pointer towards the right
        } else {
            right--;  // Move the right pointer towards the left
        }
    }

    return maxArea;
}
