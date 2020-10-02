// 287. Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/
//
#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int* nums, int numsSize){
    int tortoise = nums[0];
    int hare = nums[0];
    while (1) {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
        if (tortoise == hare) {
            break;
        }
    }  

    tortoise = nums[0];

    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return tortoise;
}

int main () {
    int n, *arr, i, ans;
     
    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    ans = findDuplicate(arr, n);

    printf("%d", ans);

    return 0;
}
