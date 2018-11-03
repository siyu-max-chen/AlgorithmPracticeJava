#include <iostream>
#include <cmath>
#include <fstream>
#include <cstring>
#include <assert.h>
#include<sstream>

using namespace std;
template <typename T>

class GrowArray {
private:
    int capacity; // the size of the block of memory
    int size;     // how many are used
    T* p;       // pointer to the block
    void checkGrow() { //
        if(size + 1 > capacity){   // double the capacity
            capacity =  capacity * 2;
            T* old = p;
            p = new T[capacity];
            for(int i = 0; i < size; i++){
                p[i] = old[i];   // copy the values
            }
            delete []old;
        }
    }
public:
    GrowArray(int initialSize = 100) { // Create an array with initial size is convinient
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
    void insertStart(T v) { //O(n)
        checkGrow();
        for(int i = size; i > 0; i--){
            p[i] = p[i-1];
        }
        p[0] = v;
        size++;
    }
    void insert(int pos, T v) { //O(n)
        checkGrow();
        // 0 to pos-1 dont change, pos to size -1 x[high] = x[low]
        for(int i = size ; i > pos; i--){
            p[i] = p[i-1];
        }
        p[pos] = v;
        size++;
    }
    void removeStart() { //O(n)
        for (int i = 0; i < size - 1; i++)
            p[i] = p[i+1];
        size--;
    }
    void removeEnd() { //O(1)
        size--;
    }
    T get(int i) const{ //O(1)
        return p[i];
    }
    int getSize()const{ //O(1)
        return this->size;
    }
    int getCap()const{ //O(1)
        return this->capacity;
    }
    friend ostream& operator <<(ostream& s, const GrowArray& b) { //O(n)
        for (int i = 0; i < b.size; i++)
            s << b.p[i] << ' ';
        return s;
    }
};

class Point{
private:
    double x; double y;
public:
    Point(double x = 0, double y = 0):x(x),y(y){}
    double getX() const{ return x; }
    double getY() const{ return y; }
    friend ostream&operator<< (ostream& s, const Point& b){
        s << "(" << b.x << "," << b.y << ")";
        return s;
    }
};

void quicksort(double x[], int left, int right) {
    // you could also use heapsort to solve this problems
    if (right - left < 1){
        return;
    }
    else {
        double pivot = (x[left] + x[right]) / 2;
        int i = left, j = right;
        while (i < j) {        //O(n)
            while (x[i] <= pivot && i < right)
                i++;
            while (x[j] > pivot && j > left)
                j--;
            if (i < j) {
                swap(x[i], x[j]);
            }
        }
        quicksort(x, left, i - 1);  // logn
        quicksort(x, i, right);
    }
}

class ConvexHull{
private:
    int size;    //
    GrowArray<Point>* growArray;
public:
    ConvexHull(int size):size(size){
        growArray = new GrowArray<Point>[size * size];  // create a n * n size grow array
    }
    void printAllListSizes() const{ // Print out the size of each growarray, if NOTHING dont print out!!！
        cout << "------------Print all lists sizes------------" << endl;
        for(int i = 0; i < size * size ; i++){
            if(growArray[i].getSize()!=0)
                cout << i << " th List's size is: " << growArray[i].getSize() << endl;
        }
        cout << "Another Lists' size is 0 !!!" << endl;
    }

    void read(string file){
        ifstream infile;
        infile.open(file.data());   //READ IN the file twice!!! first time to find out the max&min of x,y
        if(!infile.is_open())
            return;
        string s1;
        double a,b;
        double xmin, xmax, ymin, ymax;
        bool initial = false;
        while(getline(infile,s1))
        {
            istringstream sin(s1);
            sin >> a >> b;  // a is x and b is y
            if(initial){
                if(a > xmax)
                    xmax = a;
                else if(a < xmin)
                    xmin = a;
                if(b > ymax)
                    ymax = b;
                else if(b < ymin)
                    ymin = b;
            }
            else{
                xmax = a; xmin = a;
                ymax = b; ymin = b;
                initial = true;
            }
        }
        // After the first time, we know the max&min of x and y
        infile.close();
        string s2;
        infile.open(file.data());
        if(!infile.is_open())
            return;
        double grid_width = (xmax - xmin)/size, grid_height = (ymax - ymin)/size;
        double XperBox = 1/(xmax - xmin) * size, YperBox = 1/(ymax - ymin) * size;
        while(getline(infile,s2)) {
            istringstream sin(s2);
            sin >> a >> b;  // a is x and b is y
            int index = min(int((b - ymin) * YperBox), size - 1) * size + min(int((a - xmin) * XperBox), size - 1);
            growArray[index].insertEnd(Point(a,b));
        }
        infile.close();
    }
    void printminmax(GrowArray<Point> &array, int index) const{
        // update GrowArray<Point> array to GrowArray<Point> &array, the former one might cause crash!
        // Still dont know why ?
        int array_size = array.getSize();
        if(array_size > 1){
            double* x = new double[array_size];
            double* y = new double[array_size];
            for(int j = 0; j < array_size; j++){
                x[j] = array.get(j).getX();
                y[j] = array.get(j).getY();
            }
            quicksort(x, 0, array_size - 1);
            quicksort(y, 0, array_size - 1);
            cout << index << " th List's minx, maxx, miny, maxy are: " << x[0] <<
             " " << x[array_size - 1] << " " << y[0] << " " <<
             y[array_size - 1] << endl;
            delete[] x; delete[] y;
            return;
        }
        else if(array_size > 0) {
            cout << index << " th List's minx, maxx, miny, maxy are: " << array.get(0).getX() <<
            " " << array.get(0).getX() << " " << array.get(0).getY() << " " <<
            array.get(0).getY() << endl;
            return;
        }
        else{
            return;
        }
    }
    void printMinMax() const{
        cout << "------------Print Min and Max------------" << endl;
        for(int i = 0; i < size * size ; i++)
            printminmax(growArray[i], i);
        cout << "Another Lists are Empty" << endl;
    }
    void printPerimeterClockWiseOrder() const{
        cout << "------------Print Perimeter Clockwise Order------------" << endl;
        int n = 0, col = 0, row = 0;
        for(; col < size; col++){
            n = col + size * row;
            if(growArray[n].getSize() > 0)
                printminmax(growArray[n], n);
            else
                cout << n << " th List is Empty" << endl;
        }
        for(col--,row++; row < size; row++){
            n = col + size * row;
            if(growArray[n].getSize() > 0)
                printminmax(growArray[n], n);
            else
                cout << n << " th List is Empty" << endl;
        }
        for(row--,col--; col > -1; col--){
            n = col + size * row;
            if(growArray[n].getSize() > 0)
                printminmax(growArray[n], n);
            else
                cout << n << " th List is Empty" << endl;
        }
        for(col++,row--; row > 0; row--){
            n = col + size * row;
            if(growArray[n].getSize() > 0)
                printminmax(growArray[n], n);
            else
                cout << n << " th List is Empty" << endl;
        }
    }
};
int main() {
    ConvexHull ch(16);
    ch.read("convexhullpoints.dat");
    ch.printAllListSizes();
    ch.printMinMax();
    ch.printPerimeterClockWiseOrder();
}