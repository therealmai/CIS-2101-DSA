#include <stdio.h>

int searchElem(int arr[], int count, int elem)
{
    int low = 0, high = count-1, mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(elem > arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return (arr[low] == elem)?low:-1;
}

void main()
{
    int sortedArr[] = {1, 6, 7, 9, 12, 18, 19, 21};
    printf("At index: %d", searchElem(sortedArr, 9, 10));
}