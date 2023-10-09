#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void   remove_duplicates(int  arr[], int  * number)
{
    int UniqueCount = 0;
    int i;
    int j;
    int flag;
    int NewArr[*number];
    for (i = 0; i < *number; i++)
    {
        flag = 0;
        for (j = 0; j < UniqueCount; j++){
            if (arr[i] == arr[j])
            flag = 1;
            break;
        }
        if (!flag) {
            NewArr[UniqueCount++] = arr[i];
        }
    }
    *number = UniqueCount;
    for (i = 0; i <= UniqueCount; i++)
    printf("%d\n", NewArr[i]);
    }


int main() {
    
int arr[] = {5, 5, 4, 5, 5, 33, 8, 11, 6};
int size = sizeof(arr)/sizeof(arr[0]);
remove_duplicates(arr, &size);    
}