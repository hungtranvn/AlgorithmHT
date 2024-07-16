Sorting
=======

********
Heapsort
********
Heaps data structure:
PARENT(i) = [1/2], LEFT(i) = 2i, RIGHT(i) = 2i + 1

There are two kinds of heaps: max-heap and min-heap
MAX_HEAP: for every node i other than the root, A[PARENT(i)] >= A[i]
MIN_HEAP: for every node i ohter than the root, A[PARENT(i)] <= A[i]

MAX-HEAPIFY: runs O(lgn) time to maintaining the max-heap property.
BUILD-MAX-HEAP: runs O(n) time to build the max heap from unordered input array
HEAPSORT: runs O(nlgn) time to sort an array in place
MAX-HEAP-INSERT, HEAP-EXTRACT_MAX, HEAP-INCREASE_KEY, HEAP_MAXIMUM which runs in O(lgn) time, allow the heap data structure to implement a priority queue.

6.1-1 What are the minimum and maximum numbers of elements in a heap of height h?

6.1-2 Show that an n-element heap has height lgn.

6.1-3 Show that in any subtree of a max-heap, the root of the subtree contains the largest value occurring anywhere in that subtree.

6.1-4 Where in a max-heap might the smallest element reside, assuming that all elements are distinct?
The left most right element at the bottom of the tree is the smallest one.

6.1-5 Is an array that is in sorted order a min-heap?

6.1-6 Is the array with values <23; 17; 14; 6; 13; 10; 1; 5; 7; 12> a max-heap?
No, the tree at the node 4 (value 6) is not satifies the condition of max heap

6.1-7 Show that, with the array representation for storing an n-element heap, the leaves are the nodes indexed by n/2 + 1, n/2 + 2, ..., n
LEFT(⌊n/2⌋+1) = 2(⌊n/2⌋ + 1)
             > 2(n/2 - 1) + 2 = n - 2 + 2 = n.
=> larger than the number of element in array

Maintaining the heap property
#############################

MAX_HEAPIFY(A,i)
    l =LEFT(i)
    r = RIGHT(i)
    if l <= A.heap_size and A[l] > A[i]
        largest = l
    else
        largest = i
    
    if r <= A.heap_size and A[r] > A[largest]
        largest = r
    
    if largest != i
        exchange A[i] with A[largest]
        MAX_HEAPIFY(A,largest)


6.2-1 Using Figure 6.2 as a model, illustrate the operation of MAX-HEAPIFY on the array A 27; 17; 3; 16; 13; 10; 1; 5; 7; 12; 4; 8; 9; 0.

6.2-2 Starting with the procedure MAX-HEAPIFY, write pseudocode for the procedure MIN-HEAPIFY(A, i), which performs the corresponding manipulation on a minheap. How does the running time of MIN-HEAPIFY compare to that of MAXHEAPIFY?

6.2-3 What is the effect of calling MAX-HEAPIFY(A, i) when the element AOEi  is larger than its children?

6.2-4 What is the effect of calling MAX-HEAPIFY(A, i)) for i > A.heap-size/2?

6.2-5 The code for MAX-HEAPIFY is quite efficient in terms of constant factors, except possibly for the recursive call in line 10, which might cause some compilers to produce inefficient code. Write an efficient MAX-HEAPIFY that uses an iterative control construct (a loop) instead of recursion.

6.2-6 Show that the worst-case running time of MAX-HEAPIFY on a heap of size n is lg n. (Hint: For a heap with n nodes, give node values that cause MAXHEAPIFY to be called recursively at every node on a simple path from the root down to a leaf.)
The root is the smallest element in heap

Building a heap
###############

BUILD_MAX_HEAP(A)
    A.heap_size = A.length
    for i = A.length/2 downto 1
        MAX_HEAPIFY(A, i)

6.3-1 Using Figure 6.3 as a model, illustrate the operation of BUILD-MAX-HEAP on the array A <5; 3; 17; 10; 84; 19; 6; 22; 9>

6.3-2 Why do we want the loop index i in line 2 of BUILD-MAX-HEAP to decrease from A.length/2 to 1 rather than increase from 1 to A.length/2
If we loop from 1 to A.length/2, it can not achieve heap property

6.3-3 Show that there are at most n/2^h+1 nodes of height h in any n-element heap.

Heapsort algorithm
##################

HEAPSORT(A
    BUILD_MAX_HEAP(A)
    for i = A.length downto 2
        exchange A[1] with A[i]
        A.heap_size = A.heap_size - 1
        MAX_HEAPIFY(A, 1)

***************
priority queues
***************

*********
Quicksort
*********