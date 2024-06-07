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
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Item left_half[n1];
    Item right_half[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        left_half[i] = items[left + i];
    for (int j = 0; j < n2; j++)
        right_half[j] = items[mid + 1 + j];

    // Merge the two halves
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (left_half[i].ratio >= right_half[j].ratio)
        {
            items[k] = left_half[i];
            i++;
        }
        else
        {
            items[k] = right_half[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements (if any)
    while (i < n1)
    {
        items[k] = left_half[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        items[k] = right_half[j];
        j++;
        k++;
    }
}
// Function to implement merge sort
void merge_sort(Item items[], int left, int right)
{
    // TODO: Implement merge sort function
    if (left < right)
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

    double total_value = 0.0;
    int current_capacity = capacity;

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= current_capacity)
        {
            // Take the whole item
            total_value += items[i].value;
            current_capacity -= items[i].weight;
        }
        else
        {
            // Take a fraction of the item
            total_value += (items[i].ratio * current_capacity);
            break; // Knapsack is full
        }
    }

    return total_value;
}