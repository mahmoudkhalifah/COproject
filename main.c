#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647

// MERGE SORT FROM LINE 8 TO LINE 79
// QUICK SORT FROM LINE 83 TO LINE 113

//--START OF MERGE SORT FUNCTIONS--//


// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

//END OF MERGE SORT FUNCTIONS



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


int binarySearch(int arr[], int size, int key){
    int left = 0;
    int right = size - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(arr[mid] == key)
            return mid;

        if(arr[mid] < key)
            left = mid + 1;

        else
            right = mid - 1;
    }

    return -1;
}

int isArraySorted(int arr[], int size){
    int a = 1, i = 0;
    while((a == 1) && i < size - 1){
        if(arr[i] > arr[i+1])
            a = 0;
        i++;
    }
    if(a == 1)
        return 1;
    else return 0;
}
void printArray(int arr[],int size) {
    for(int i=0;i<size;i++) {
        printf("%c ",arr[i]);
    }
}




int main()
{
    int typeOfSort, size;
    printf("enter the number of elements\n>>> ");
    scanf("%d",&size);


    if(typeOfSort == 1) {
        size++;
    }

    int array[size];

    if(typeOfSort == 1) {
        size--;
    }
    getc(stdin);
    printf("\nenter elements:\n");
    for(int i=0;i<size;i++) {
        printf(">>> ");
        //scanf("%d",&array[i]);
        array[i] = getc(stdin);
        getc(stdin);
    }

    printf("\nenter the number of sort type\n1=> for Quick Sort\n2=> for Insertion Sort\n3=> for Merge Sort \n4=> for Search(Binary Search)\n5=> for exit\n>>> ");
    scanf("%d",&typeOfSort);



    while(typeOfSort != 5) {
        switch(typeOfSort) {
            case 1 :
                array[size] = INT_MAX;
                quickSort(array,0,size);
                break;
            case 2 :
                printf("Insertion Sort\n" );
                break;
            case 3 :
                printf("Given array is \n");
                printArray(array, size);
                mergeSort(array, 0, size - 1);
                printf("\nSorted array is \n");

                break;
            case 4:
                if(isArraySorted(array, size)) {
                    int key, searchItem;
                    printf("Enter item to search for\n");
                    getc(stdin);
                    key = getc(stdin);
                    searchItem = binarySearch(array, size, key);

                    if(searchItem != -1)
                        printf("Found in index: %d\n", searchItem);
                    else printf("Not Found!\n");

                } else printf("You Must Sort the list first and then search.\n");
                break;
            case 5:
                return 0;
                break;
            default:
                printf("Invalid choice\n" );
        }
        printf("Sorted array: ");
        printArray(array,size);
        printf("\n\nenter the number of sort type\n1=> for Quick Sort\n2=> for Insertion Sort\n3=> for Merge Sort \n4=> for Search(Binary Search)\n5=> for exit\n>>> ");
        scanf("%d",&typeOfSort);

    }
    return 0;
}
