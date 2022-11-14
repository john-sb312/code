import random, os

MAX_SIZE = 1000000

def countingSort(array, place):
    size = len(array)
    output = [0] * size
    count = [0] * 10

    # Calculate count of elements
    for i in range(0, size):
        index = array[i] // place
        count[index % 10] += 1

    # Calculate cumulative count
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Place the elements in sorted order
    i = size - 1
    while i >= 0:
        index = array[i] // place
        output[count[index % 10] - 1] = array[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(0, size):
        array[i] = output[i]



def radix_sort(array):
    # Get maximum element
    max_element = max(array)

    # Apply counting sort to sort elements based on place value.
    place = 1
    while max_element // place > 0:
        countingSort(array, place)
        place *= 10


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
    radix_sort(sorted_array)
    print(f"Sorted array    : {sorted_array}")