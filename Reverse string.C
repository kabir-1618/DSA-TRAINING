#include <stdio.h>

void reverseString(char* s, int length) {
    int left = 0;
    int right = length - 1;

    while (left < right) {
        // Swap characters at left and right indices
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // Move left and right indices towards the center
        left++;
        right--;
    }
}

int main() {
    char str[] = {'h', 'e', 'l', 'l', 'o'};
    int length = sizeof(str) / sizeof(str[0]);

    printf("Original string: ");
    for (int i = 0; i < length; i++) {
        printf("%c ", str[i]);
    }
    printf("\n");

    reverseString(str, length);

    printf("Reversed string: ");
    for (int i = 0; i < length; i++) {
        printf("%c ", str[i]);
    }
    printf("\n");

    return 0;
}
