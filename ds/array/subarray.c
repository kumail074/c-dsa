#include <stdio.h>
#include <stdlib.h>

int findSplitPoint(int *arr, int n) {
    int leftSum = 0;
    
    for(int i=0; i<n; i++) {
        leftSum += arr[i];

        int rightSum = 0;
        for(int j=i+1; j<n; j++) {
            rightSum += arr[j];
        }

        if(leftSum == rightSum)
            return i+1;
    }
    return -1;
}

void printTwoParts(int *arr, int n) {
    int splitPoint = findSplitPoint(arr, n);
    if(splitPoint == -1 || splitPoint == n) {
        printf("Not possible\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<n; i++) {
        if(splitPoint == i)
            printf("\n");
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printTwoParts(arr, n);
    return 0;
}
