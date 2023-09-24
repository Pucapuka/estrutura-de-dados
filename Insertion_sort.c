#include <stdio.h>
#include <stdlib.h>

#define size 10

void insertionSort(int array[], int s){
    int i,j, current;
    for (i=1; i<s; i++){
        current = array[i];
        for(j=i-1; j>=0; j--){
            if(current<array[j]){
                array[j+1] = array[j];
            }else{
                break;
            }
        }
        array[j+1] = current;
    }
}

int main(){
    int array[size] = {4,2,1,3,7,8,6,9,5,10};
    int i;
    printf("Before insertion sort:\n");
    for (i = 0; i<size; i++){
        printf("%d\n",array[i]);
    }
    
    insertionSort(array, size);
    printf("After insertion sort:\n");
    for (i = 0; i<size; i++){
        printf("%d\n",array[i]);
    }

    return 0;
}
