# two pointer 相关
*“男人最重要的是持久。”*

--------------------------------------------------------
#### 148 Sort List
Sort a linked list in O(n log n) time using constant space complexity.
将一个无序的链表进行排序，要求一定的时间复杂度

这题目可以说是非常非常经典的题目，我们知道对于排序而言，最好的平均时间复杂度就是nlogn，对于数组如此对于链表依旧如此。数组中我们用快排 quick sort，而在链表中，更好实现的方式就是 合并排序 Merge Sort。这个题目简直就是为了合并排序量身定做的！


``` java
class Solution {
    private ListNode Merge(ListNode a, ListNode b){
        // 两个 special test cases
        if(a == null)
            return b;
        if(b == null)
            return a;
        if(a.val > b.val){
            b.next = Merge(a, b.next);
            return b;
        }
        else{
            a.next = Merge(a.next, b);
            return a;
        }
    }
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode slow = head, fast = head.next;
        ListNode next = fast.next;
        while(next != null){
            fast = next;
            if(fast.next == null)
                break;
            fast = fast.next;
            next = fast.next;
            slow = slow.next;
        }
        ListNode second = slow.next;
        slow.next = null;
        // Recusion 中的常用套路：两个分别是左边排好序的和右边排好序的list
        head = sortList(head);
        second = sortList(second);
        return Merge(head, second);
    }
}
```

--------------------------------------------------------
#### 1. 双指针  two pointers
所谓双指针，一般情况下有以下几种不同的理解：
- 定义 slow 和 fast 两种不同**速度**的指针，每次循环他们移动的次数有差别
- 定义指针 p 和 q，一个指针总是在另一个指针的 k 距离后面
- 定义指针 left 和 right（类似BS），用来遍历（但在链表中不常用，是一种思路）

##### 1.1 slow n fast
slow 和 fast 是两个不同速度的指针，这种设计可以方便我们在 one pass 的情况下找到链表中的“特殊点”：比如中点（1/2处）或者任意比例的点（1/3 处）。
而且，通过合理设计代码的先后，可以选择到底是“小中点”还是“大中点”，有道题挺蛋疼的就是有这样的细致要求。

题目：

##### 1.2 k dist 
这类没啥好说的，就是一开始指针q在p的后面，这样如果q到达终点后，p必然指向距离终点前k距离的结点上。部分题目需要 one pass可以用到，很局限。

题目：

##### 1.3 left n right
left 和 right 作为左右指针最常见在于“分治法”。而分治法中一个典型就是Binary Search。当然我印象中 3 sum 也是使用这种【思路】的题目。总之需要心中有数，这类可以方便我们从两头缩小范围

--------------------------------------------------------
#### 2. 递归  Recursion
其实怎么说，递归只是一种coding的方式，在链表题目中可以让代码更加的简洁、漂亮。这算是递归的最简单的练习吧。


