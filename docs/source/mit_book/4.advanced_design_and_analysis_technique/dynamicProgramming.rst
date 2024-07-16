Dynamic programming
===================

*******************
Rod cutting problem
*******************
Given a rod of length *n* inches and a table of prices *pi*
i 1 2 3 4 5  6  7  8  9  10
p 1 5 8 9 10 17 17 20 24 30

Determine the maximum revenue rn obtainable by cutting up the rod and selling the pieces.

With n = 4, we can cut a 4-inch rod into two 2-inch pieces which produces revenue p2 + p2 = 10 (optimal)

If an optimal solution cuts the rod into k pieces, for some 1 <= k <= n, then an optimal decomposition
n = i1 + i2 + i3 + ... + ik
Maximum revenue rn = pi1 + pi2 + ... + pik

CUT_ROD(p, n)
    if n == 0
        return 0
    q = -inf
    for i = 1 to n
        q = max(q, p[i] + CUT_ROD(p, n-i))
    return q

Time complexity: 2^n

**Using dynamic programming for optimal rod cutting**

A naive recursive solution is ineffient because it solves the same subproblems repeatedly.

We arrange for each subproblem to be solved only once, saving its solution, we can just look it up rather than recompute it when we meet the subproblem latter.

The saving maybe dramatic: an exponential time solution may be transformed into a polynminal-time solution.

There are two ways to implement a dynamic programming approach.

The first approach is top-down memoization: we write the procedure recursively in a natural manner, but modified to save the result of each subproblem (usually in an array or hash table). The procedure now first checks to see whether it has previously solved this subproblem. If so, it returns the saved value, saving further computation at this level; if not, the procedure computes the value in the usua manner.

The second approach is the bottom-up method. This approach typically depends on some natual notion of the size of a subproblem, such that solving any particular subproble depends only on solving "smaller" subproblems. We sort subproblems by size and solve them in size order, smaller first.

MEMOIZED_CUT_ROD(p, n)
    let r[0..n] be a new array
    for i = 0 to n-i
        r[i] = -inf
    return MEMOIZED_CUT_ROD_AUX(p, n, r)

MEMOIZED_CUT_ROD_AUX(p, n, r)
    if r[n] >= 0
        return r[n]
    if n == 0
        q = 0
    else q = -inf
        for i = 1 to n
            q = max(q, p[i] + MEMOIZED_CUT_ROD_AUX(p, n-i, r))
    r[n] = q
    return q

BOTTOM_UP_CUT_ROD(p, n)
    let r[0..n] be a new array
    r[0] = 0
    for j = 1 to n
        q = -inf
        for i = i to j
            q = max(q, p[i] + r[j-i])
        r[j] = q
    return r[n]

**Reconstructing a solution**

EXTENDED_BOTTOM_CUT_ROD(p, n)
    let r[0..n] and s[0..n] be new arrays
    r[0] = 0
    for j = 1 to n
        q = -inf
        for i = 1 to j
            if q < p[i] + r[j - i]
                q = p[i] + r[j - i]
                s[j] = i
        r[j] = q
    return r and s

PRINT_CUT_ROD_SOLUTION(p, n)
    r, s = EXTENDED_BOTTOM_CUT_ROD(p,n)
    while n > 0
        print s[n]
        n = n - s[n]

**Exercises**
15.1-1 Show that equation (15.4) follows from equation (15.3) and the initial condition T .0/ D 1.

15.1-2 Show, by means of a counterexample, that the following “greedy” strategy does not always determine an optimal way to cut rods. Define the density of a rod of length i to be pi=i , that is, its value per inch. The greedy strategy for a rod of length n cuts off a first piece of length i , where 1 i n, having maximum density. It then continues by applying the greedy strategy to the remaining piece of length n 􀀀 i .

15.1-3 Consider a modification of the rod-cutting problem in which, in addition to a price pi for each rod, each cut incurs a fixed cost of c. The revenue associated with a solution is now the sum of the prices of the pieces minus the costs of making the cuts. Give a dynamic-programming algorithm to solve this modified problem.

15.1-4 Modify MEMOIZED-CUT-ROD to return not only the value but the actual solution, too.

15.1-5 The Fibonacci numbers are defined by recurrence (3.22). Give an O.n/-time dynamic-programming algorithm to compute the nth Fibonacci number. Draw the subproblem graph. How many vertices and edges are in the graph?

****************************
Maxtrix chain multiplication
****************************
