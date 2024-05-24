The Role of Algorithms in Computing
===================================

**********
Algorithms
**********

An algorithm is any well-defined computational procedure that takes some value, or set of values, as input and produces some value, or set of values, as output.

The problems are solved by algorithms: the Human Genome project, the internet (find rout)

Some specific problems:

**************
Data structures
**************

*********
Exercises
*********
1.1-1 Give a real-world example that requires sorting or a real-world example that requires computing a convex hull.

1.1-2 Other than speed, what other measures of efficiency might one use in a real-world setting?

1.1-3 Select a data structure that you have seen previously, and discuss its strengths and limitations.

1.1-4 How are the shortest-path and traveling-salesman problems given above similar? How are they different?

1.1-5 Come up with a real-world problem in which only the best solution will do. Then come up with one in which a solution that is “approximately” the best is good
enough.

1.2-1 Give an example of an application that requires algorithmic content at the application level, and discuss the function of the algorithms involved.

1.2-2 Suppose we are comparing implementations of insertion sort and merge sort on the same machine. For inputs of size n, insertion sort runs in 8n2 steps, while merge sort runs in 64nlgn steps. For which values of n does insertion sort beat merge
sort?

1.2-3 What is the smallest value of n such that an algorithm whose running time is 100n2 runs faster than an algorithm whose running time is 2n on the same machine?

Examine: insertion sort (incremental method)
============================================

Input: A sequence of numbers <a1, a2, a3, ..., an>.

Output: A permutation reordering <a1', a2', a3', ..., an'>.

Examine: merge sort (devide and conquer)
========================================

******************
Divide and conquer 
******************
Divide:

Conquer:

Combine:

2.3-4 We can express insertion sort as a recursive procedure as follows. In order to sort A[1..n]], we recursively sort A[1..n-1] and then insert A[n] into the sorted array A[1..n-1]. Write a recurrence for the worst-case running time of this recursive version of insertion sort.

2.3-5 Referring back to the searching problem (see Exercise 2.1-3), observe that if the sequence A is sorted, we can check the midpoint of the sequence against and eliminate half of the sequence from further consideration. The binary search algorithm repeats this procedure, halving the size of the remaining portion of the sequence each time. Write pseudocode, either iterative or recursive, for binary search. Argue that the worst-case running time of binary search is ‚.lg n/.

2.3-6 Observe that the while loop of lines 5–7 of the INSERTION-SORT procedure in Section 2.1 uses a linear search to scan (backward) through the sorted subarray A[1..j-1]]. Can we use a binary search (see Exercise 2.3-5) instead to improve the overall worst-case running time of insertion sort to ‚.n lg n/?

2.3-7 Describe a nlgn time algorithm that, given a set S of n integers and another integer x, determines whether or not there exist two elements in S whose sum is exactly x.

solution1: nlogn
Sort array S
for i in S:
    to_find = x - S[i]
    binary search

solution2: logn
two pointers

Examine: The maximum-subarray problem
=====================================
MIT book pag.68
solution1: try every possible pair of buy and sell dates in which the buy date precedes the sell date. A period of n days has (n, 2) such pairs of dates. Since (n, 2) is O(n2).

Examine: The matrix multiplication problem
==========================================