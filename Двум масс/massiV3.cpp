#include "Header.h"



void massiV3() {
    int** a;
    int i, j, n, * m;
    int mass[100];
    printf("������� ���������� �����: ");
    scanf_s("%d", &n);
    a = (int**)malloc(n * sizeof(int*));
    m = (int*)malloc(n * sizeof(int)); // ������ ���-�� �������� � ������� ������� a

    // ���� ��������� �������
    for (i = 0; i < n; i++)
    {
        printf("������� ���������� ����. ������ %d: ");
        scanf_s("%d", &m[i]);
        a[i] = (int*)malloc(m[i] * sizeof(int));
        for (j = 0; j < m[i]; j++) {
            printf("a[%d][%d]= ", i, j);
            scanf_s("%d", &a[i][j]);
        }
    }

    //� ������ ������ ����� ������� 
    //������� �������� �������� ��� ���������.

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m[i]; j++)
        {
            if (a[i][j] % 2 == 0) {

                //��������� ��� ����� ������� ��������
                for (int k = 0; k < n; k++) {
                    mass[k] = a[i + k + 1][j];
                }

                a[i + 1][j] = fact(a[i][j]);
                
                for (int k = 0; k < n; k++) {
                    a[i + k + 2][j] = mass[k];
                }
            }
        }
        printf("\n");
    }




    // ����� ��������� �������
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m[i]; j++)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    // ������������ ������
    for (i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
    free(m);
    getchar(); getchar();

}