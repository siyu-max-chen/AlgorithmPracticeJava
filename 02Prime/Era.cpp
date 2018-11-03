# include <iostream>
using namespace std;
static bool a[100];// = {};
static int n = 100;

void era(){
    // Sieve of Eratosthenes
    for (int i = 2*2; i < n; i+=2){
        a[i] = false;
    }
    for(int i = 3; i < n; i++){
        if(a[i])
            for(int j = i*i; j < n; j+= 2*i)
                a[j] = false;
    }
}

int main(){
    for(int i = 0; i < n; i++){
        a[i] = true;
    }
    era();
    int num = 0;
    for(int i = 2; i < n; i++){
        if(a[i]){
            cout << i << " ";
            num++;
        }
    }
    cout << endl << num << endl;
}