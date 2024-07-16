Elementary Data Structures
==========================

******
Arrays
******
The array is fundamental contiguosly allocated data structure.
A structure of fixed-size data records such that each element can be efficiently located by its index or address.

*Advantages*:

Constant time access given the index: the index of each element maps directly to a particular address, we can access arbitrary data items instantly.

Space efficieny: No space is wasted

Memory locality: Physical continuity between successive data access helps exploit the high-speed cache memory.

*Disadvantages*:

We can not adjust their size in the middle of executions. However, we can efficiently enlarge arrays as we need in the miracle of dynamic array.

******************************
Pointers and linked structures
******************************
Pointers are the conections that holds the pieces of linked structures together

.. highlight:: cpp
   :linenothreshold: 79
.. code-block:: cpp
   :linenos:
   :caption: list datastructure implementation
    
    typedef struct List
    {
        item_type item;
        struct List *next;
    } list;
    list* search_list(list* l, item_type x)
    {
        if (l == NULL)
        {
            return(NULL);
        }

        if (l->item == x)
        {
            return l;
        }
        else
        {
            return search_list(l->next, x);
        }
    }
    void insert_list(list **l, item_type x)
    {
        list* p;
        p = malloc(sizeof(list));
        p->item = x;
        p->next = *l;
        *l = p;
    }
    list *item_ahead(list *l, list *x)
    {
        if (l == NULL  || l->next == NULL)
        {
            return NULL;
        }

        if (l->next == x)
        {
            return(l);
        }
        else
        {
            return(item_ahead(l->next, x));
        }
    }
    void delete_list(list **l, list **x)
    {
        list *p;
        list *pred;

        p = *l;
        pred = item_ahead(*l, *x);

        if (pred == NULL)
        {
            *l = p->next;
        }
        else
        {
            pred->next = *x->next;
        }
        
        free(*x);
    }

*****************************
Containers: stacks and queues
*****************************
stacks: LIFO, interface (push, pop)

examples: executing recursive algorithm

queues: FIFO, interface (enqueue, dequeue)

examples: jobs processed, breath first search

**********
Dictionary
**********
Interface: search, insert, delete, max, min, precessor, successor

Examples: remove all duplicate names from mailing list

+------------------------+---------------+--------------------+
| Dictionary operation   | Unsorted array| Sorted array       |
|                        |               |                    |
+========================+===============+====================+
| search(A, k)           | O(n)          | O(n)               |
+------------------------+---------------+--------------------+
| insert(A, k)           | O(1)          | O(n)               |
+------------------------+---------------+--------------------+
| delete(A, k)           | O(1)          | O(n)               |
+------------------------+---------------+--------------------+
| successor(A, k)        | O(n)          | O(1)               |
+------------------------+---------------+--------------------+
| predessor(A, k)        | O(n)          | O(1)               |
+------------------------+---------------+--------------------+
| minimum(A, k)          | O(n)          | O(1)               |
+------------------------+---------------+--------------------+
| maximum(A, k)          | O(n)          | O(1)               |
+------------------------+---------------+--------------------+

+------------------------+-------------------+-------------------------+
|                        | Singly linked list| Doubly linked list array|
|  Dictionary operation  +---------+---------+-------------+-----------+
|                        |unsorted | sorted  |unsorted     | sorted    |
+========================+=========+=========+=============+===========+
| search(A, k)           |O(n)     |O(n)     |O(n)         |O(n)       |
+------------------------+---------+---------+-------------+-----------+
| insert(A, k)           |O(1)     |O(n)     |O(1)         |O(n)       |
+------------------------+---------+---------+-------------+-----------+
| delete(A, k)           |O(n)     |O(n)     |O(1)         |O(1)       |
+------------------------+---------+---------+-------------+-----------+
| successor(A, k)        |O(n)     |O(1)     |O(n)         |O(1)       |
+------------------------+---------+---------+-------------+-----------+
| predessor(A, k)        |O(n)     |O(n)     |O(n)         |O(1)       |
+------------------------+---------+---------+-------------+-----------+
| minimum(A, k)          |O(1)     |O(1)     |O(n)         |O(1)       |
+------------------------+---------+---------+-------------+-----------+
| maximum(A, k)          |O(1)     |O(1)     |O(n)         |O(1)       |
+------------------------+---------+---------+-------------+-----------+

*********
Exercises
*********
3-1. [3] A common problem for compilers and text editors is determining whether
the parentheses in a string are balanced and properly nested. For example, the
string ((())())() contains properly nested pairs of parentheses, while the strings
)()( and ()) do not. Give an algorithm that returns true if a string contains
properly nested and balanced parentheses, and false if otherwise. For full credit,
identify the position of the first offending parenthesis if the string is not properly
nested and balanced.

3-2. [5] Give an algorithm that takes a string S consisting of opening and closing
parentheses, say )()(())()()))())))(, and finds the length of the longest balanced
parentheses in S, which is 12 in the example above. (Hint: The solution is not
necessarily a contiguous run of parenthesis from S.)

3-3. [3] Give an algorithm to reverse the direction of a given singly linked list. In
other words, after the reversal all pointers should now point backwards. Your
algorithm should take linear time.

3-4. [5] Design a stack S that supports S.push(x), S.pop(), and S.findmin(), which
returns the minimum element of S. All operations should run in constant time.

3-5. [5] We have seen how dynamic arrays enable arrays to grow while still achieving
constant-time amortized performance. This problem concerns extending
dynamic arrays to let them both grow and shrink on demand.
(a) Consider an underflow strategy that cuts the array size in half whenever
the array falls below half full. Give an example sequence of insertions and
deletions where this strategy gives a bad amortized cost.
(b) Then, give a better underflow strategy than that suggested above, one that
achieves constant amortized cost per deletion.

3-6. [3] Suppose you seek to maintain the contents of a refrigerator so as to minimize
food spoilage. What data structure should you use, and how should you use
it?

3-7. [5] Work out the details of supporting constant-time deletion from a singly
linked list as per the footnote from page 79, ideally to an actual implementation.
Support the other operations as efficiently as possible.

3-8. [5] Tic-tac-toe is a game played on an n×n board (typically n = 3) where two
players take consecutive turns placing “O” and “X” marks onto the board cells.
The game is won if n consecutive “O” or ‘X” marks are placed in a row, column,
or diagonal. Create a data structure with O(n) space that accepts a sequence
of moves, and reports in constant time whether the last move won the game.

3-9. [3] Write a function which, given a sequence of digits 2–9 and a dictionary of n
words, reports all words described by this sequence when typed in on a standard
telephone keypad. For the sequence 269 you should return any, box, boy, and
cow, among other words.

3-10. [3] Two strings X and Y are anagrams if the letters of X can be rearranged
to form Y . For example, silent/listen, and incest/insect are anagrams. Give an
efficient algorithm to determine whether strings X and Y are anagrams.
