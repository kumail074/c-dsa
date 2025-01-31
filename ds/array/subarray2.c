#include <stdio.h>
#include <stdlib.h>

//it has time complexity of O(n) and auxiliary space of O(1)

int findSplitPoint(int *arr, int n) {
    int leftSum = 0;
    for(int i=0; i<n; i++)
        leftSum += arr[i];

    int rightSum = 0;
    for(int i=n-1; i>=0; i--) {
        rightSum += arr[i];
        leftSum -= arr[i];

        if(rightSum == leftSum) 
            return i;
    }
    return -1;
}

void printTwoParts(int *arr, int n) {
    int splitPoint = findSplitPoint(arr, n);
    if(splitPoint == -1 || splitPoint == n) {
        printf("Not Possible\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<n; i++) {
        if(splitPoint == i)
            printf("\n");
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printTwoParts(arr, n);
    return 0;
}
