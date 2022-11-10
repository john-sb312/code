#include<stdlib.h>
#include<time.h>

int* generate_random_arrays(int size){
    srand(time(0));
    int array[size];
    for (int i=0; i < size; i++) {
        array[i] = i ;  // fill the array in order
    }
    for (int i=0; i < size; i++){
        int random = i + (rand() % (size - i));
        int temp = array[i]; 
        array[i] = array[random]; 
        array[random] = temp;  
    }
    return array;
} //experiment, might use later

int mergesort(int array[], int size){

}


int main(int argc, char** argv){

}