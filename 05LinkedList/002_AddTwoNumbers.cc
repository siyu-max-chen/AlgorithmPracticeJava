#include <iostream>
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

/*
  学习：Onenote\\C++\\Map
  1. speedup的作用原理？ Onenote\\C++\\基础
  2. 做题时遇到了crash问题，一定要保证【指针非空】的情况下再去调用指针 -> 指向的对象的成员，建议新建指针时赋值而非没有任何动作
  3. Onenote\\C++\\List

  算法：
  1. 逻辑：条件首先是 l1 || l2，另外的条件是保证carry值不等于0，当l1,l2都指向空值时，如果进位存在，则同样会新建一个指针并指向 
  2. 可以仅用一个变量sum代表 当前位数的值 和 进位值

  Q：
  1. C++ 的auto怎么用？ 如何标准地遍历一遍 map？
*/

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = nullptr; ListNode* prev = ans;
        int sum = 0;
        while(l1 || l2 || sum){
            sum += (l1)? l1->val: 0;
            sum += (l2)? l2->val: 0;
            if(!ans) ans = new ListNode(sum % 10);
            ListNode* temp = new ListNode(sum % 10);
            prev = (prev)? prev->next = temp: ans;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            sum /= 10;
        }
        return ans;
    }
};

int main(){
    ListNode* l1 = new ListNode(0); ListNode* l1_temp = l1;
    ListNode* l2 = new ListNode(0); ListNode* l2_temp = l2;
    int a[8] = {1, 9, 1, 3, 3, 8, 9, 6};
    Solution sol;
    for(int i = 0; i < 4; i++)
        l1_temp = l1_temp->next = new ListNode(a[i]);
    for(int i = 4; i < 8; i++)
        l2_temp = l2_temp->next = new ListNode(a[i]);
    cout << l1 << l2 ;
    cout << sol.addTwoNumbers(l1, l2);
}