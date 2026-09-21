#include <iostream>
using namespace std;
void selectionSort(int* arr, int size)
{
    for(int i=0; i<size-1; i++)
    {
        int minIndex = i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}
int main() {
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(A)/sizeof(A[0]);
    selectionSort(A, size);
    for(int i=0; i<size; i++)
        cout<<A[i]<<" ";
    return 0;
}