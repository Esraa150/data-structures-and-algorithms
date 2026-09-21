#include <iostream>
using namespace std;
void bubbleSort(int* arr, int size)
{
    for(int i=0; i<size-1; i++)
    {
        for(int j=0; j<size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(A)/sizeof(A[0]);
    bubbleSort(A, size);
    for(int i=0; i<size; i++)
        cout<<A[i]<<" ";
    return 0;
}