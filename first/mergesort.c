#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define max_size 1000000

void merge(int array[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
      L[i] = array[p + i];
    for (int j = 0; j < n2; j++)
      M[j] = array[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = j = 0;
    k = p;

    while (i < n1 && j < n2) {
      if (L[i] <= M[j]) {
        array[k] = L[i];
        i++;
      } else {
        array[k] = M[j];
        j++;
      }
      k++;
    }

    while (i < n1) {
      array[k] = L[i];
      i++;
      k++;
    }

    while (j < n2) {
      array[k] = M[j];
      j++;
      k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void merge_sort(int array[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    merge_sort(array, l, m);
    merge_sort(array, m + 1, r);

    merge(array, l, m, r);
  }
}


int main(int argc, char** argv){
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
        
    } // shuffle, like card deck
    // who the fuck would want true random here?

    printf("Unsorted array:  ");
    for (int i=0; i < size; i++){
        if(i +1 < size) {
            printf("%i, ",array[i]);
        }
        else {
            printf("%i \n",array[i]);
        }
    }

    merge_sort(array, 0, size - 1);

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