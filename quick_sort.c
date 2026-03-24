#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp= *a;
    *a= *b;
    *b= temp;
}
int partition(int a[],int l,int h)
{
    int i=l,j=h,pivot=a[l];
    while(i<j)
    {
        do
        {
            i++;
        }while(a[i]<=pivot);
        do
        {
            j--;
        }while(a[j]>pivot);
        if(i<j) swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[j]);
    return j;
}
void Quick_sort(int a[],int l,int h)
{
    if(l>=h) return;
    int j=partition(a,l,h);
    Quick_sort(a,l,j-1);
    Quick_sort(a,j+1,h);
}
int main() {
    srand(time(0));
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % (2*n + 1)) - n;  // values between -n and +n
    }
    printf("Original array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    clock_t start = clock();
    Quick_sort(arr, 0, n - 1);
    clock_t end = clock();
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);
    return 0;
}
