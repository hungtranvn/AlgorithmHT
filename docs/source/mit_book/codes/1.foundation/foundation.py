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
        
        #merge(A, i, k, j)
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
    return A

def main():
    A = [1,4,2,7,6,5]
    print(merge_sort(A, 0, len(A)))
    #print(A)

if __name__ == "__main__":
    main();