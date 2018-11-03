#include <iostream>
using namespace std;

template <typename T>

class GrowArray {
private:
    int capacity; // the size of the block of memory
    int size;     // how many are used
    T* p;       // pointer to the block
    void checkGrow() { //
        if(size + 1 > capacity){   // size 不变，但是capacity变成两倍
            capacity =  capacity * 2;
            T* old = p;
            p = new T[capacity];
            for(int i = 0; i < size; i++){
                p[i] = old[i];   // copy the values
                //cout << p[i] <<"=" << old[i] << ' ';
            }
            delete [] old;
        }
    }
public:
    /*GrowArray():capacity(1),size(0),p(new T[1]) {
    }*/
    GrowArray(int initialSize = 100) {          //  新建
        p = new T[initialSize];
        size = 0;
        capacity = initialSize;
        p[0] = 0;
    }
    ~GrowArray(){
        delete[] p;
    }
    void insertEnd(T v) { //O(1)
        checkGrow();
        p[size++] = v;
    }
    void insertStart(T v) {
        checkGrow();
        for(int i = size; i > 0; i--){
            p[i] = p[i-1];
        }
        p[0] = v;
        size++;
    }
    void insert(int pos, T v) {
        checkGrow();
        // 0 到 pos-1 部分不变化, pos 到 size -1 部分 高项目 = 低项目
        for(int i = size ; i > pos; i--){
            p[i] = p[i-1];
        }
        p[pos] = v;
        size++;
    }
    void removeStart() {
        for (int i = 0; i < size - 1; i++)
            p[i] = p[i+1];
        size--;
    }
    void removeEnd() {
        size--;
    }
    void remove4(){
        int j = 0;
        for(int i = 0; i < size - 1; i++){
            if(i % 4 == 1)
                j++;
            p[i] = p[i + j];
        }
        size-=j;
        /*
        T* old = p;
        p = new T[capacity];
        int j = 0;
        for(int i = 0 ; i < size -1; i++){
            if(i % 4 != 1){
                p[j] = old[i];
                j++;
            }
        }
        delete[] old;
        size = j;*/
    }

    T get(int i) const{
        return p[i];
    }
    int getSize()const{
        return this->size;
    }
    int getCap()const{
        return this->capacity;
    }

    friend ostream& operator <<(ostream& s, const GrowArray& b) {
        for (int i = 0; i < b.size; i++)
            s << b.p[i] << ' ';
        //s << endl;
        return s;
    }
};

int main() {
    GrowArray<int> array;
    for(int i = 0; i < 10; i++){
        array.insertEnd(i + 1);
    }
    cout << array <<endl;
    array.remove4();
    cout << array << endl;
}