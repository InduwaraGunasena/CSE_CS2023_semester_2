#include <iostream>
#include <ctime>
#include<algorithm>
using namespace std;

void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b = temp;
}

int partition (int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    for (int j = p; j <= r- 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            swap (&A[i], &A[j]);
        }
    }
    swap (&A[i + 1], &A[r]);
    return (i + 1);
}

void quickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p,r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }

}

void quickSortIterative(int arr[], int l, int h)
{
    int stack[h - l + 1];
    int top = -1;

    stack[++top] = l;
    stack[++top] = h;

    while (top >= 0) {
        h = stack[top--];
        l = stack[top--];

        int p = partition(arr, l, h);

        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }

        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int main()
{   //#################################
    int size = 900;
    int no_of_loops = 1000;
    //#################################

    int arr[size];
    for(int i = 0; i < size; i++)
        arr[i]=rand()%100;
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    clock_t start;
    clock_t end;
    double t1, t2;

    start = clock();
    for(int j= 0; j< no_of_loops; j++){
        int copyArr[arr_size];
        copy_n(arr,arr_size,copyArr);
        quickSort(copyArr, 0, arr_size-1);
    }
    end = clock();

    t1 = ((end - start) / (double)CLOCKS_PER_SEC)/ no_of_loops;
    cout << "Time taken by Recursive Quick Sort    : " << fixed << t1 << " \n" << endl;
    cout << "######################################## \n";

    start = clock();
    for(int j= 0; j< no_of_loops; j++){
        int copyArr[arr_size];
        copy_n(arr,arr_size,copyArr);
        quickSortIterative(copyArr, 0, arr_size - 1);
    }
    end = clock();

    t2 = ((end - start) / (double)CLOCKS_PER_SEC)/ no_of_loops;
    cout << "Time taken by Non-Recursive Quick Sort: " << fixed << t2 << "\n" << endl;
    return 0;
}
