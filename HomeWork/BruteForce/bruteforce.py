#https://www.brainkart.com/article/Exhaustive-Search_8013/
import numpy as np
import math

def selection_sort(A):
    for i in range(len(A) - 1):
        m = i
        for j in range(i + 1, len(A), 1):
            if A[m] > A[j]:
                m = j
        A[i], A[m] = A[m], A[i]

    return A

def bubble_sort(A):
    for i in range(len(A)):
        for j in range(len(A) - 1 - i):
            if A[j + 1] < A[j]:
                A[j], A[j + 1] = A[j + 1], A[j]
    return A

def string_match(P, T):
    print("len(T) = ", len(T), "len(P) = ", len(P))
    for i in range(len(T) - len(P)):
        j = 0
        while j < len(P) and P[j] == T[i + j]:
            j = j + 1
        if j == len(P):
            return i
    return -1

def closest_pair(data):
    x = data[0, :]
    y = data[1, :]
    
    min_dist = 200
    for i in range(x.size - 1):
        for j in range(i + 1, x.size, 1):
            if min_dist > math.sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2)):
                min_dist = math.sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2))
    return min_dist

def convex_hull(data):
    x = data[0, :]
    y = data[1, :]
    
    boundary_points = []
    for i in range(x.size - 1):
        for j in range(i + 1, x.size, 1):
            if check_boundary(i, j, x, y):
                if i not in boundary_points:
                    boundary_points.append(i)
                if j not in boundary_points:
                    boundary_points.append(j)
    boundary_points.sort()
    return boundary_points

def check_boundary(i, j, x, y):
    a = y[j] - y[i]
    b = x[i] - x[j]
    c = x[i]*y[j] - y[i]*x[j]
    
    mark_table = [0 for i in range(x.size)]
     
    for k in range(x.size):
        current_compute = a*x[k] + b*y[k]
        if current_compute > c:
            mark_table[k] = 1
        elif current_compute < c:
            mark_table[k] = -1
        else:
            mark_table[k] = 0
    for i in mark_table:
        print(i)
    if 1 in mark_table and -1 in mark_table:
        return False
    else:
        return True
    
def main():
    data = np.array([[1,2,2,2,3,3,3,4,3],[4,2,4,6,2,4,6,4,3]])
    points = convex_hull(data)
    print("RESULT:")
    for i in points:
        print(i)



if __name__ == "__main__":
    main()


