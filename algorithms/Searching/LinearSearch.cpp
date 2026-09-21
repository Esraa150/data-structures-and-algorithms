#include <iostream>
using namespace std;
int search(int* arr, int size, int x)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i] == x)
            return i;
    }
    return -1;
}
int main() {
    int A[] = {2, 4, 50, 4, 7};
    int res = search(A, sizeof(A)/sizeof(A[0]), 50);
    if(res == -1)
        cout<<"Not found!";
    else
        cout<<"Element found at index: "<<res;

    return 0;
}