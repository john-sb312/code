#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_size 1000000


void counting(int array[], int size, int exponent)
{
    int output[size]; 
    int i, count[10] = {0};

    for (i = 0; i < size; i++){
        count[ (array[i]/exponent)%10 ]++;
    }
    // change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (i = size - 1; i >= 0; i--)
    {
        output[count[ (array[i]/exponent)%10 ] - 1] = array[i];
        count[ (array[i]/exponent)%10 ]--;
    }
    // Copy the output array to arr[]
    for (i = 0; i < size; i++){
        array[i] = output[i];
    }
}

// get maximum value in array[]
int get_max(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++){
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}


void radixsort(int array[], int size) {
    // Find the maximum number to know number of digits
    int max = get_max(array, size);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exponent is passed. exponent is 10^i
    // where i is current digit number
    for (int exponent = 1; max/exponent > 0; exponent *= 10) {
        counting(array, size, exponent);
    }
}

int main(int argc, char** argv) {
    srand(time(0));
    int array[max_size];
    int size = atoi(argv[1]);
    if (size > max_size){
        printf("Size must be smaller than 100000000");
        exit(1);
    }
    
    for (int i=0; i < size; i++) {
        array[i] = i ;  // fill the array in order
    }
    for (int i=0; i < size; i++){
        int random = i + (rand() % (size - i));
        int temp = array[i]; 
        array[i] = array[random]; 
        array[random] = temp;
        
    }
    printf("Unsorted array:  ");
    for (int i=0; i < size; i++){
        if(i +1 < size) {
            printf("%i, ",array[i]);
        }
        else {
            printf("%i \n",array[i]);
        }
    }

    radixsort(array, size);

    printf("Sorted array:    ");
    for (int i = 0; i < size ; i++){
        if(i +1 < size) {
            printf("%i, ",array[i]);
        } else {
            printf("%i \n",array[i]);
        }
    }
    return 0;
}