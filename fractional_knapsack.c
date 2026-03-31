#include<stdio.h>
struct item
{
    int value;
    int weight;
    float ratio;
};
float fractional_knapsack(int w,struct item items[],int n)
{
    for(int i=0;i<=n-1;i++)
    {
        items[i].ratio=(float)items[i].value/items[i].weight;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(items[i].ratio<items[j].ratio)
            {
                struct item temp=items[i];
                items[i]=items[j];
                items[j]=temp;
            }
        }
    }
    double sum=0;
    int cap=w;
    for(int i=0;i<n;i++)
    {
        if(items[i].weight<=cap)
        {
            sum+=items[i].value;
            cap-=items[i].weight;
        }
        else
        {
            sum+= items[i].ratio * cap;
            break;
        }
    }
    return sum;
}
int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    float max_value = fractional_knapsack(capacity, items, n);
    printf("Maximum value in knapsack = %.2f\n", max_value);
    return 0;
}
