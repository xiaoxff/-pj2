#pragma warning(disable:4996);
#include <stdio.h>
#include <stdlib.h>

// ���������������еĽϴ�ֵ
int max(int a, int b) {
    return (a > b) ? a : b;
}

// ������������������
int maxSubArraySum(int arr[], int size) {
    int ture_max = 0; // �������������ͳ�ʼ��Ϊ0
    int curr_max = 0;   // ��ǰ����������ͳ�ʼ��Ϊ0

    for (int i = 0; i < size; i++) {
        curr_max = max(arr[i], curr_max + arr[i]);
        ture_max = max(ture_max, curr_max);
    }
    return ture_max;
}

int main() {
    int n;
    printf("���������������������ĸ�����");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("�ڴ����ʧ��\n");
        return 1;
    }

    printf("���������ݣ�");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int max_sum = maxSubArraySum(arr, n);
    printf("��������������Ϊ %d\n", max_sum);

    // �ͷŶ�̬������ڴ�
    free(arr);

    return 0;
}

