import sys

def search_recursive(A, n, key):
    if (n >= 0):
        if A[n] == key: #base case
            return n
        return search_recursive(A, n-1, key)
    return None

def insertion_sort(A):
    for j in range(2, len(A)):
        key = A[j]
        i = j - 1
        while i > 0 and A[i] > key: # using binary search? 
            A[i+1] = A[i]
            i = i - 1
        A[i+1] = key
        print(A)
    return A

def insertion_sort_recursive(A, n):
    if n > 1:
        insertion_sort_recursive(A, n-1);
        merge_i(A, n)

def merge_i(A, n):
    '''
    merge the A[n] into sorted A[0:n-1] range
    '''
    key = A[n-1]
    j = n - 2
    while j >= 0 and key < A[j]:
        A[j + 1] = A[j]
        j = j - 1
    A[j + 1] = key

#def binary_search(A, key):

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

def brute_force_max_subarray(A):
    """
    brute force solution:
    A is the diff of prices
    return the subarray's indices 
    """
    ans = -sys.maxsize - 1
    ret = [0, 0]
    for i in range(0, len(A), 1):
        sum = 0
        for j in range(i, len(A), 1):
            sum += A[j]
            if (sum > ans):
                ans = sum
                ret = [i, j]
    return ret + [ans]

def find_max_crossing_subarray(A, low, mid, high):
    """
    helper function used for find_maximum_subarray 
    """
    left_sum = -sys.maxsize - 1
    sum_l = 0
    max_left = mid
    for i in range(mid, low, -1):
        sum_l = sum_l + A[i]
        if sum_l > left_sum:
            left_sum = sum_l
            max_left = i
    
    right_sum = -sys.maxsize - 1
    sum_r = 0
    max_right = mid
    for j in range(mid, high, 1):
        sum_r = sum_r + A[j]
        if sum_r > right_sum:
            right_sum = sum_r
            max_right = j
    return [max_left, max_right, left_sum + right_sum - A[mid]]

def find_maximum_subarray(A, low, high):
    """
    devide conquer technique
    """
    if high == low: #base case 1 element
        return [low, high, A[low]]
    else:
        mid = (low + high) // 2
        left_low, left_high, left_sum = find_maximum_subarray(A, low, mid)
        right_low, right_high,  right_sum = find_maximum_subarray(A, mid + 1, high)
        cross_low, cross_high, cross_sum = find_max_crossing_subarray(A, low, mid, high)
        
        if left_sum >= right_sum and left_sum >= cross_sum:
            return [left_low, left_high, left_sum]
        elif right_sum >= left_sum and left_sum >= cross_sum:
            return [right_low, right_high, right_sum]
        else:
            return [cross_low, cross_high, cross_sum]


def main():
    A = [1, 4, 2, 7, 6, 5]
    print("A = ", A)
    #print(merge_sort(A, 0, len(A)))
    insertion_sort_recursive(A, len(A))
    print(A)
    to_find = search_recursive(A, len(A)-1, 5)
    print(to_find)
    
    B = [-9, 1, -5, 4, 3, -6, 7, 8, -2]
    C = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    print(brute_force_max_subarray(B))
    print(find_maximum_subarray(B, 0, len(B)-1))
if __name__ == "__main__":
    main()