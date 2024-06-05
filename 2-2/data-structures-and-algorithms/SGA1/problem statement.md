Question1
You are given a set of n items, where each item i has 

1 ) A weight wi
2 ) A value vi

The total capacity of your knapsack is W.

Determine the optimal way to fill the knapsack with a subset of these items to maximize the total value. This means you can take any portion 0 ≤ xi ≤ 1 of item 𝑖, where xi is the fraction of item 𝑖 taken. The total weight of the selected items (including fractions) must not exceed the knapsack's capacity 𝑊.

Hint: Use merge sort algorithm.

You have been provided with the driver code, with appropriate TODO comments to guide you through the implementation. You have to only edit merge(), merge_sort(), and knapsack() subroutines in the file student_file.c. You have been provided with the driver code in the main() function in the same file. DO NOT MODIFY ANY LINES OF THE FILE APART FROM WITHIN THE FUNCTION merge(),  merge_sort(), and knapsack(), else your assignment will not be evaluated.  You are free to add other functions if you wish to.

INPUT   OUTPUT
5       14
2 4
3 1
4 5
6 2
3 8
10

Note: The example input given here differs from the test cases checked when the code is submitted. 
