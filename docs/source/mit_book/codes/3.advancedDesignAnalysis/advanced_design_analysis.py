import sys

#cutting rode

def cut_rod(p, n):
    """
    naive recursive solution
    """
    if n == 0:
        return 0
    q = -1
    for i in range(1, n+1, 1): # loop to n
        q = max(q, p[i] + cut_rod(p, n - i))
    return q

def memoized_cut_rod(p, n):
    """
    top-down approach
    """
    r = [-1]*(n+1)
    return memoized_cut_rod_aux(p, n, r)

def memoized_cut_rod_aux(p, n, r):
    if r[n] >= 0:
        return r[n]
    if n == 0:
        q = 0
    else: 
        q = -1
        for i in range(1, n+1):
            q = max(q, p[i] + memoized_cut_rod_aux(p, n-i, r))
    r[n] = q
    return q

def bottom_up_cut_rod(p, n):
    r = [-1]*(n+1)
    r[0] = 0
    for j in range(1, n+1):
        q = -1
        for i in range(1, j+1):
            q = max(q, p[i] + r[j - i])
        r[j] = q
    
    return r[n]

def extended_bottom_up_cut_rod(p, n):
    r = [-1]*(n+1)
    s = [-1]*(n+1)

    r[0] = 0
    for j in range(1, n+1):
        q = -1
        for i in range(1, j+1):
            if q < p[i] + r[j-i]:
                q = p[i] + r[j - i]
                s[j] = i
        r[j] = q
    return r, s

def print_cut_rod_solution(p, n):
    r, s = extended_bottom_up_cut_rod(p, n)
    while n > 0:
        print(s[n])
        n = n - s[n]

def main():
    print("main function")
    p = [0, 1, 5, 8, 9, 10, 17, 20, 24, 30]
    n = 4
    print(cut_rod(p, n))
    print(memoized_cut_rod(p,n))
    print(bottom_up_cut_rod(p, n))
    print_cut_rod_solution(p, n)

if __name__ == "__main__":
    main()