#pragma warning(disable:4996);
#include <stdio.h>
#include <stdlib.h>

// 函数返回两个数中的较大值
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 计算最大连续子数组和
int maxSubArraySum(int arr[], int size) {
    int ture_max = 0; // 最大连续子数组和初始化为0
    int curr_max = 0;   // 当前连续子数组和初始化为0

    for (int i = 0; i < size; i++) {
        curr_max = max(arr[i], curr_max + arr[i]);
        ture_max = max(ture_max, curr_max);
    }
    return ture_max;
}

int main() {
    int n;
    printf("请输入整数代表输入数的个数：");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }

    printf("请输入数据：");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = maxSubArraySum(arr, n);
    printf("最大连续子数组和为 %d\n", max_sum);

    // 释放动态分配的内存
    free(arr);

    return 0;
}

