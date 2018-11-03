#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    friend ostream& operator<<(ostream& s, ListNode* list){
        s << list->val;
        while(list->next){
            list = list->next; 
            s << " -> " << list->val;
        }
        s << '\n';
        return s;
    }
};

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> list_vector;
        ListNode* temp = head; list_vector.push_back(head);
        while(temp->next){
            temp = temp->next;
            list_vector.push_back(temp);
        }
        int len = list_vector.size();
        if(len < 2) return nullptr;
        n = n % (len);
        if(n == 0)
            return head->next;
        else if(n == 1){
            list_vector[len - 2]->next = nullptr;
        }
        else{
            if(len == 2){
                list_vector[(len - n - 1) % len]->next = nullptr;
                return list_vector[(len - n - 1) % len];
            }
            else
                list_vector[(len - n - 1) % len]->next = list_vector[(len - n + 1) % len];
        }
        return head;
    }
};

int main(){
    ListNode* list = new ListNode(0); ListNode* list_temp = list;
    int a[8] = {1, 9, 1, 3, 3, 8, 9, 6};
    Solution sol;
    for(int i = 0; i < 8; i++)
        list_temp = list_temp->next = new ListNode(a[i]);
    cout << list;
    cout << sol.removeNthFromEnd(list, 2);
    cout << sol.removeNthFromEnd(list, 10);
    cout << sol.removeNthFromEnd(list, -2);
}