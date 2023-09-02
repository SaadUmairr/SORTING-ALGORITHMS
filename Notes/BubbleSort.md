# Bubble Sort

## Introduction
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. It is named "Bubble Sort" because smaller elements "bubble" to the top of the list while larger elements "sink" to the bottom.

## Logic
1. Start at the beginning of the list.
2. Compare the first two elements; if the first is greater than the second, swap them.
3. Move to the next pair of elements and repeat step 2.
4. Continue this process until no more swaps are needed, indicating that the list is sorted.

C++ implementation of Bubble sort: [Bubble Sort](../CPP/BubbleSort.cpp).  
Python implementation of Bubble sort: [Bubble Sort](../Python/BubbleSort.py).  
Java implementation of Bubble sort: [Bubble Sort](../Java/BubbleSort.java).  
Javascipt implementation of Bubble sort: [Bubble Sort](../Javascript/BubbleSort.js).  

## Complexity
- Time Complexity:
  - Best Case: O(n) (when the list is already sorted)
  - Average Case: O(n^2)
  - Worst Case: O(n^2) (when the list is sorted in reverse order)
- Space Complexity: O(1) (since only a few extra variables are used)

## Advantages
- Simple to understand and implement.
- Requires minimal additional memory space.
- Works well for small lists or mostly sorted lists.

## Considerations
- Inefficient for large lists due to its quadratic time complexity.
- Not recommended for use in production systems where faster sorting algorithms are available.

## Disadvantages/Limitations
- Inefficient for larger datasets.
- Performance degrades quickly as the list size increases.
- There are more efficient sorting algorithms available, such as QuickSort and MergeSort.

## Edge Cases
- Bubble Sort can be particularly slow on large lists, especially in its worst-case scenario.
- If the list is already sorted or nearly sorted, the algorithm will still perform unnecessary comparisons and swaps.

## External Links
For more information on Bubble Sort, you can refer to the following articles:
- [Bubble Sort - Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort)
- [Sorting Algorithms: Bubble Sort - GeeksforGeeks](https://www.geeksforgeeks.org/bubble-sort/)
- [Sorting Algorithms Visualized: Bubble Sort - VisuAlgo](https://visualgo.net/en/sorting?slide=1)