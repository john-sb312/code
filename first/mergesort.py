import random, os

MAX_SIZE = 1000000

def merge_sort(array):
    if len(array) > 1:

        # r is the point where this thing is divide into 2 subarrays
        r = len(array)//2
        L = array[:r]
        M = array[r:]

        # Sort 2 halves
        merge_sort(L)
        merge_sort(M)

        i = j = k = 0

        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                array[k] = L[i]
                i += 1
            else:
                array[k] = M[j]
                j += 1
            k += 1

        # When we run out of elements in either L or M,
        # pick up the remaining elements and put in A[p..r]
        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1

        while j < len(M):
            array[k] = M[j]
            j += 1
            k += 1


def random_number_array(size):
    random_gen = random.sample(range(0, size), size)
    return random_gen

def get_number_input():
    print("> Input array size: ")
    try:
        num = int(input())
        return num
    except Exception as m:
        print(f"{m}; Please input a real number.")
        return get_number_input()


if __name__ == "__main__":
    size = get_number_input()
    unsorted_array = random_number_array(size)
    print(f"Unsorted array  : {unsorted_array}")

    sorted_array = unsorted_array
    merge_sort(sorted_array)
    print(f"Sorted array    : {sorted_array}")