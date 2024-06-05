#include <stdio.h>
#include <stdlib.h>
// Define a structure for items
typedef struct
{
    int weight;
    int value;
    double ratio;
} Item;

// Function prototypes
void merge_sort(Item items[], int left, int right);
void merge(Item items[], int left, int mid, int right);
double knapsack(Item items[], int n, int capacity);

// Main function
int main()
{
    int n, capacity;

    // User inputs
    scanf("%d", &n);

    Item items[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    scanf("%d", &capacity);

    // Calculate the maximum value
    double max_value = knapsack(items, n, capacity);
    printf("%.2f\n", max_value);

    return 0;
}

// Function to merge two halves
void merge(Item items[], int left, int mid, int right)
{
    // TODO: Implement merge function
    int i = left;
    int j = mid + 1;
    int k = 0;
    Item temp[right - left + 1];
    while(i <= mid && j <= right)
    {
        if(items[i].ratio > items[j].ratio)
        {
            temp[k++] = items[i++];
        }
        else
        {
            temp[k++] = items[j++];
        }
    }
    while(i <= mid)
    {
        temp[k++] = items[i++];
    }
    while(j <= right)
    {
        temp[k++] = items[j++];
    }
    for(int i = left, k = 0; i <= right; i++, k++)
    {
        items[i] = temp[k];
    }
}

// Function to implement merge sort
void merge_sort(Item items[], int left, int right)
{
    // TODO: Implement merge sort function
    if(left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(items, left, mid);
        merge_sort(items, mid + 1, right);
        merge(items, left, mid, right);
    }
}

// Function to calculate the maximum value in the knapsack
double knapsack(Item items[], int n, int capacity)
{
    // TODO: Implement fractional knapsack function
    merge_sort(items, 0, n - 1);
    double max_value = 0;
    for(int i = 0; i < n; i++)
    {
        if(capacity == 0)
        {
            break;
        }
        if(items[i].weight <= capacity)
        {
            max_value += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            max_value += items[i].ratio * capacity;
            capacity = 0;
        }
    }
    return max_value;
}
