#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] == target - nums[i]) {
                int* result = malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return malloc(sizeof(int) * 0);
}

int main() {
    int nums[5] = { 260, 4096, 5, 10, 22 };
    int returnSize = 0;

    int* twoSumResult = twoSum(nums, sizeof(nums) / sizeof(nums[0]), 32, &returnSize);
    printf("test: %d\n", nums[1]);

    if (returnSize > 0){
        for (int i = 0; i < returnSize; ++i){
            printf("twoSumResult[%d]: %d\n", i, twoSumResult[i]);
        }
        free(twoSumResult);
    }
    else{
        printf("No result\n");
    }
}