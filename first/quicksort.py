import random, os

MAX_SIZE = 1000000

def partition(array, low, high): 
    pivot = array[high]
    i = low - 1
 
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            # (array[i], array[j]) = (array[j], array[i])
            temp = array[i]
            array[i] = array[j]
            array[j] = temp

    temp = array[i+1]
    array[i+1] = array[high]
    array[high] = temp

    return i + 1


def quick_sort(array, low, high):
    if low < high:
        pi = partition(array, low, high)

        quick_sort(array, low, pi - 1)
        quick_sort(array, pi + 1, high)
 
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
    quick_sort(sorted_array, 0, size - 1)
    print(f"Sorted array    : {sorted_array}")