#include <iostream>
#include <fstream>
#include<sstream>
#include <cstring>
using namespace std;
/*
 * Title: Linked List class
 * Comment: Used class LinkedList2 and class GrowArray to complete some functions
 * 1. Use LinkedList2 to remove 3-divisible indices and its relevant member in the list, repeated 2 times
 * 2. Use GrowArray to catch some Instructions and carry out them
 */
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
            delete []old;
        }
    }
public:
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
    void removeStart(int num = 1) {
        for (int i = 0; i < size - num; i++)
            p[i] = p[i + num];
        size -= num;
    }
    void removeEnd(int num = 1) {
        size -= num;
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
template <typename T>
class LinkedList2{
private:
    class Node{
    public:
        Node* next;
        T val;
    };
    Node* head;
    Node * tail;
public:
    LinkedList2():head(nullptr),tail(nullptr){}
    int getSize()const{
        int count = 0;
        for (Node* p = head; p != nullptr; p = p->next)
            count++;
        return count;
    }
    void addStart(const T& v){
        Node* temp = new Node();
        temp->val = v;
        temp->next = head;
        if(tail == nullptr){
            tail = head;
            head = temp;
            return;
        }
        head = temp;
    }
    void addEnd(const T& v){
        if(head == nullptr){
            addStart(v);
            return;
        }
        if(tail == nullptr){
            tail = new Node();
            tail->val = v;
            tail->next = nullptr;
            head->next = tail;
            return;
        }
        Node* temp = new Node();
        temp->val = v;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
    }
    void removeStart(){
        Node* p = head;
        head = head -> next;
        delete p;
    }
    void removeEnd(){
        if(head == nullptr)
            return;
        Node* p = head;
        if(tail == nullptr){    //  only one member or none member
            delete p;
            head = nullptr;
            return;
        }
        for(; p->next != tail; p = p->next)
            ;
        delete tail;
        p->next = nullptr;
        tail = p;
    }
    void remove3(){
        int size = getSize();
        if(size == 0)
            return;
        Node* p = head; Node* q = p->next;
        if(size == 1){
            removeStart();
            return;
        }
        for(int i = 1; i < size;){
            if(i % 3 == 0){    // q -> i, p -> i - 1
                if(q == tail){  // come to the last element, remove Start&End then return!
                    removeStart();
                    removeEnd();
                    return;
                }
                Node* temp = q;
                q = q->next;
                p -> next = q;
                delete temp;
                i++;
            }
            else{
                p = q;
                q = q->next;
                i++;
            }
        }
        removeStart();
    }
    void reverse(){
        if(head == nullptr || tail == nullptr)
            return;
        Node* temp_head = head;
        Node* p = head->next; Node* q = head;
        for(; p != tail; ){
            Node* temp = p->next;
            p->next = q;
            q = p;
            p = temp;
        }
        tail->next = q;
        head = tail;
        tail = temp_head;
        tail->next = nullptr;
    }
    int read(string file){
        // READ IN the file and get the NUM
        ifstream infile;
        infile.open(file.data());
        if(!infile.is_open())
            return 0;
        string s;
        getline(infile,s);
        istringstream sin(s);
        sin >> s;
        infile.close();
        int num = atoi(s.c_str());
        cout << "num: " << num << endl;
        return num;
    }
    friend ostream&operator<< (ostream&s , const LinkedList2& list){
        for (Node* p = list.head; p != nullptr; p = p->next)
            s << p->val << ' ';
        return s;
    }
};

void GetStringInt(int a[], string s){
    // extract the integers from String like 1:2:10 -> 1, 2, 10
    int start = 0; int count = 0;  int num = 0;  // get the start position
    for(int i = 0; i < s.length()-1; i++){
        if(s[i] ==':'){
            string c = s.substr(start,count);
            count = 0;
            a[num] = atoi(c.c_str());
            start = i + 1;
            num++;
        }
        else
            count++;
    }
    string c = s.substr(start,++count);
    a[num] = atoi(c.c_str());
}

int main() {
    LinkedList2<int> list;
    int num = list.read("linkedlist.dat");
    cout << "-----------------Linked List2 Part-----------------" << endl;
    for(int i = num; i > 0; i--)
        list.addStart(i);    // addStart is of same-complexity as addEnd in this case, but it has less statement//
    cout << list <<endl;
    list.remove3();
    cout << "Remove 3 in first time: " << endl;
    cout << list <<endl;
    list.remove3();
    cout << "Remove 3 in second time: " << endl;
    cout << list <<endl;
    list.reverse();
    cout << "Reverse the linked list: " << endl;
    cout << list <<endl;
    cout << "-----------------Grow Array Instructions Part-----------------" << endl;
    GrowArray<int> array;
    string input;
    cout << "Please print in CORRECT INSTRCUTIONS: " << endl;
    while(true){
        cin >> input;
        if(input == "ADD_FRONT"){
            cin >> input;
            int* a = new int[3];
            GetStringInt(a,input);
            for(int i = a[0]; i <= a[2]; i += a[1]){
                array.insertStart(i);
            }
        }
        else if(input == "ADD_BACK"){
            cin >> input;
            int* a = new int[3];
            GetStringInt(a,input);
            for(int i = a[0]; i <= a[2]; i += a[1]){
                array.insertEnd(i);
            }
        }
        else if(input == "REMOVE_FRONT"){
            cin >> input;
            int a = atoi(input.c_str());
            array.removeStart(a);
        }
        else if(input == "REMOVE_BACK"){
            cin >> input;
            int a = atoi(input.c_str());
            array.removeEnd(a);
        }
        else if(input == "OUTPUT"){
            cout << array << endl;
        }
        else
            cout << "Wrong Input!!!!" << endl;
    }
    return 0;
}