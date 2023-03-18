#permutation
def remove_permutation(arr):
    if len(arr) < 2:
        return arr
    else:
        perms = []
        for i in range(len(arr)):
            rest = arr
            rest.pop(i)
            ps = remove_permutation(rest)
            current = arr[i]
            ps.insert(0, current)
        return ps

arr = [1,2,3]
remove_permutation(arr)
