# include <iostream>
using namespace std;

void quicksort(int x[], int left, int right){
    // Sorting the array before searching
    if(right - left < 1)
        return;
    int pivot = (x[left] + x[right])/2;
    int i = left, j = right;
    while(i < j){
        while(x[i] <= pivot && i < right)
            i++;
        while(x[j] > pivot && j > left)
            j--;
        if(i < j)
            swap(x[i], x[j]);
    }
    quicksort(x, left, i - 1);
    quicksort(x, i, right);
}

void binarysearch(int x[], int target, int n){
    // Binary search in iterator way
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right)/2;
        if(x[mid] > target)
            right = mid - 1;
        else if(x[mid] < target)
            left = mid + 1;
        else{
            cout << "Found in " << mid << " th position" << endl;
            return;
        }
    }
    cout << "Not Found!" << endl;
    return;
}

void binarysearch2(int x[], int left, int right, int target){
    // Binary Search in recursion way
    if(left <= right){
        int mid = (left + right)/2;
        if(x[mid] > target)
            binarysearch2(x, left, mid - 1, target);
        else if(x[mid] < target)
            binarysearch2(x, mid + 1, right, target);
        else{
            cout << "Found in " << mid << " th position" << endl;
            return;
        }
    }
    else{
        cout << "Not Found!" << endl;
        return;
    }
}

int main(){
    int a[] = {3,2,1,6,10,8,9,5,7,6,32,12,456,56,34};
    int n = sizeof(a)/sizeof(a[0]);
    int target = 100;
    quicksort(a, 0, n-1);
    for(int i = 0; i < n; i++)
        cout << a[i] <<' ';
    cout << endl;
    while(true){
        cout << "Please print in a target number: " << endl;
        cin >> target;
        cout << "BinarySearch by iterator to find target: ";
        binarysearch(a, target, n);
        cout << "BinarySearch by recursion to find target: ";
        binarysearch2(a, 0, n - 1, target);
    }
}