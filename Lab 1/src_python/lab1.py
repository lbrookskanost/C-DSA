def insertion(arr):
    if not arr: #covers special cases
        return []
    n = len(arr)
    sorted_arr = [arr[0]]
    for i in range(1, n):
        inserted = False
        for j in range(0, len(sorted_arr)):
            if arr[i] < sorted_arr[j]: #if current item of arr is less than current item of sorted array
                sorted_arr.insert(j, arr[i]) #insert arr's item at the current sorted arr index
                inserted = True
                break
        if not inserted: #if arr's item is greater than all items in sorted_arr
            sorted_arr.append(arr[i]) #append
    return sorted_arr
    
def insertion_inplace(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i] #value to compare with
        j = i - 1 #controls value that will be moving
        while j >= 0 and arr[j] > key: #pushes j backwards in the list until it's in correct spot
            arr[j+1] = arr[j] #moves j back
            j -=1 #j decrements
        arr[j+1] = key #puts key back in the list
    return arr
    
    
def merge_sort(arr):
    if len(arr) <= 1: #covers special cases & prevents infinite recursion
        return arr
    middle = (len(arr)) // 2
    left = merge_sort(arr[0:middle]) #recurses on left side of list
    right = merge_sort(arr[middle:]) #recurses on right side of list
    return merge(left, right) #calls helper function to sort

def merge(left, right):
    sorted = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]: #if left is the lesser of the two
            sorted.append(left[i]) #append to sorted list
            i += 1 #increment index of left list
        else:
            sorted.append(right[j])
            j += 1
    sorted += left[i:] + right[j:] #add on any remaining items in either list (note- this works because one list is guaranteed empty)
    return sorted
    