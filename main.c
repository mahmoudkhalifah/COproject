#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

//START OF QUICK SORT FUNCTIONS
void swap(int *num1,int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int arr[], int l, int h) {
    int pivot = arr[l],i = l, j = h;
    while (i < j) {
        do {
            i++;
        } while(arr[i]<=pivot);
        do {
            j--;
        } while(arr[j]>pivot);
        if (i<j)
            swap(&arr[i],&arr[j]);
    }
    swap(&arr[l],&arr[j]);
    return j;
}

void quickSort(int arr[], int l, int h) {
    if(l<h) {
        int j=partition(arr,l,h);
        quickSort(arr,l,j);
        quickSort(arr,j+1,h);
    }
}
//END OF QUICK SORT FUNCTIONS

void printArray(int arr[],int size) {
    for(int i=0;i<size;i++) {
        printf("%d ",arr[i]);
    }
}


int main()
{
    int typeOfSort, size;
    printf("enter the number of elements\n>>> ");
    scanf("%d",&size);

    printf("\nenter the number of sort type\n1=> for Quick Sort\n2=> for Insertion Sort\n3=> for Merge Sort \n4=> for exit\n>>> ");
    scanf("%d",&typeOfSort);

    if(typeOfSort == 1) {
        size++;
    }

    int array[size];

    if(typeOfSort == 1) {
        size--;
    }
    printf("\nenter elements:\n");
    for(int i=0;i<size;i++) {
        printf(">>> ");
        scanf("%d",&array[i]);
    }

    switch(typeOfSort) {
        case 1 :
            array[size] = INT_MAX;
            quickSort(array,0,size);
            break;
        case 2 :
            printf("Insertion Sort\n" );
            break;
        case 3 :
            printf("Merge Sort\n" );
            break;
        case 4 :
            return 0;
            break;
        default :
            printf("Invalid choice\n" );
    }
    printArray(array,size);
    return 0;
}