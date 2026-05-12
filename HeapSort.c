#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Heapify function
void Heapify(int a[],int n,int i)
{
    int l=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&a[left]>a[l]) l=left;
    if(right<n&&a[right]>a[l]) l=right;
    if(l!=i)
    {
        int temp=a[i];
        a[i]=a[l];
        a[l]=temp;
        Heapify(a,n,l);
    }
}
//Bottom-UP heap sort
void heapSortBottomUp(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    // Extract elements
    for (int i = n-1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        Heapify(arr, i, 0);
    }
}
// Insert into heap (Top-Down)
void insertHeap(int heap[], int *size, int val) {
    heap[*size] = val;
    int i = (*size)++;
    while (i > 0) {
        int parent = (i-1)/2;
        if (heap[i] > heap[parent]) {
            int temp = heap[i];
            heap[i] = heap[parent];
            heap[parent] = temp;
            i = parent;
        } else break;
    }
}
// Top-Down Heap Sort
void heapSortTopDown(int arr[], int n) {
    int *heap = (int*)malloc(n * sizeof(int));
    int size = 0;

    // Build heap by insertion
    for (int i = 0; i < n; i++)
        insertHeap(heap, &size, arr[i]);

    // Extract max repeatedly
    for (int i = n-1; i >= 0; i--) {
        arr[i] = heap[0];
        heap[0] = heap[size-1];
        size--;
        Heapify(heap, size, 0);
    }
    free(heap);
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main() {
    int N = 10000000; // Adjust size as needed
    int *arr = (int*)malloc(N * sizeof(int));
    srand(time(NULL));

    // Generate random array
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 1000000;

    printf("Original Array:\n");
    printArray(arr, N);

    // Bottom-Up
    int *arr1 = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) arr1[i] = arr[i];
    clock_t start = clock();
    heapSortBottomUp(arr1, N);
    clock_t end = clock();
    printf("\nBottom-Up Heap Sort Time: %f seconds\n",(double)(end - start) / CLOCKS_PER_SEC);
    // printf("Bottom-Up Sorted Array:\n");
    // printArray(arr1, N);

    // Top-Down
    int *arr2 = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) arr2[i] = arr[i];
    clock_t startTD = clock();
    heapSortTopDown(arr2, N);
    clock_t endTD = clock();
    printf("\nTop-Down Heap Sort Time: %f seconds\n",(double)(endTD - startTD) / CLOCKS_PER_SEC);

    // printf("Top-Down Sorted Array:\n");
    // printArray(arr2, N);

    free(arr);
    free(arr1);
    free(arr2);
    return 0;
}
