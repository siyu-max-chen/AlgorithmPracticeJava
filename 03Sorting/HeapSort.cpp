#include <iostream>
using namespace std;

void makesubheap(int x[], int i, int n){
    int left = 2*i + 1, right = 2*i + 2;
    int largest = i;
    if(x[left] > x[largest] && left < n)
        largest = left;
    if(x[right] > x[largest] && right < n)
        largest = right;
    if(i != largest){
        swap(x[i], x[largest]);
        makesubheap(x, largest, n);
    }
}

void heapsort(int x[], int n){
    // make the initial heap
    for(int i = n/2 - 1; i >= 0 ; i--)
        makesubheap(x, i, n);
    for(int i = n-1; i >= 0; i--){
        swap(x[0], x[i]);  // make sure x[i] is the bigest one from x[0] to x[i]
        makesubheap(x, 0, i);  // makesuheap from x[0] to x[i-1]
    }
}

int main(){
    int a[] = {1,3,4,6,8,9,10,12,2,7,23,123,54,765};
    int n = sizeof(a)/sizeof(a[1]);
    heapsort(a, n);
    cout << n << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}