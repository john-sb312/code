#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// #include<string.h>
// #include<ctype.h>

#define max_size 1000000

int partition(int array[], int low, int high){
    int temp, pivot, i, j;
    pivot = array[high];
    i = low - 1;
    
    for(j = low; j < high; j++) {
        if(array[j] <= pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }        
    temp = array[i+1];
    array[i+1]  = array[high];
    array[high] = temp;
    return i + 1;
}


void quicksort(int array[], int low, int high) {
    if (low <= high){
        int pi = partition(array, low, high);
        
        quicksort(array, low, pi - 1);
        quicksort(array, pi + 1, high);
    
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

    /*
    // old random array implement, number looks too random lol
    for(int i=0; i < size; i++)  {
        array[i] = rand() % (1000000 + 1 - 0) + 0; //rand() % (max_number + 1 - minimum_number) + minimum_number
        if(i +1 < rows) {
            printf("%i, ",array[i]);
        }
        else {

            printf("%i \n",array[i]);
        }
    } 

// new approach by shuffling at range start from 0 to size given by user input
// > "why?" you might ask

*/
    
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

    quicksort(array, 0, size - 1);
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