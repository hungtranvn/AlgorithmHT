import sys

def insertion_sort(A):
    for j in range(2, len(A)):
        key = A[j]
        i = j - 1
        while i > 0 and A[i] > key:
            A[i+1] = A[i]
            i = i - 1
        A[i+1] = key
        print(A)
    return A

def merge_sort(A, a, b = None):
    if b == None:
        b = len(A)
    if b - a > 1:
        c = (a + b) // 2
        merge_sort(A, a, c) # call log(n) times
        merge_sort(A, c, b)
        merge_sorted_arrays(A, a, c, b)
        '''
        L, R = A[a:c], A[c:b]
        i , j = 0, 0
        while a < b: # O(n) times
            if j >= len(R) or (i < len(L) and L[i] <= R[j]):
                A[a] = L[i]
                i = i + 1
            else:
                A[a] = R[j]
                j = j + 1
            a = a + 1
        '''
    return A

def merge_sorted_arrays(A, a, c, b):
    print("Index:", a, " ", c, " ", b)

    # make two new arrays for comparison
    L, R = A[a:c], A[c:b]
    
    # merge two sorted ranges in one
    i, j = 0, 0
    count = a
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            A[count] = L[i]
            i = i + 1
        else:
            A[count] = R[j]
            j = j + 1
        count = count + 1
    while i < len(L):
        A[count] = L[i]
        i = i + 1
        count = count + 1
    while j < len(R):
        A[count] = R[j]
        j = j + 1
        count = count + 1
        
    print("A_sorted = ", A)

'''
def merge_sorted_arrays(A, p, q, r):
    #print("Index:", p, " ", q, " ", r)
    n1 = len(A[p:q])
    n2 = len(A[q:r])

    # make two new arrays for comparison
    L, R = [None]*(n1), [None]*(n2)
    for i in range(0, n1, 1):
        L[i] = A[p + i]
    for j in range(0, n2, 1):
        R[j] = A[q + j]
    
    # merge two sorted ranges in one
    i, j = 0, 0
    for k in range(p, r, 1):
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1
    #print("A_sorted = ", A)
'''
def main():
    A = [1,4,2,7,6,5]
    print("A = ", A)
    print(merge_sort(A, 0, len(A)))
    #print(A)

if __name__ == "__main__":
    main();