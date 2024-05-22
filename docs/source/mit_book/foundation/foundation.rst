The Role of Algorithms in Computing
===================================

**********
Algorithms
**********

An algorithm is any well-defined computational procedure that takes some value, or set of values, as input and produces some value, or set of values, as output.

The problems are solved by algorithms: the Human Genome project, the internet (find rout)

Some specific problems:

**************
Dat structures
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