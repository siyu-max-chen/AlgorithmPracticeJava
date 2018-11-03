#include <iostream>
#include <fstream>
#include<sstream>
#include <cstring>
using namespace std;
/*
 * Title: Linked List class
 * Comment: Used class LinkedList2 and class GrowArray to complete some functions
 * 1. Use LinkedList2 to remove 3-divisible indices and its relevant member in the list, repeated 2 times
 */

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
    return 0;
}