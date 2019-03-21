# two pointer 相关

--------------------------------------------------------
#### 148 Sort List
Sort a linked list in O(n log n) time using constant space complexity.
将一个无序的链表进行排序，要求一定的时间复杂度和空间复杂度

这题目可以说是非常非常经典的题目，我们知道对于排序而言，最好的平均时间复杂度就是nlogn，对于数组如此对于链表依旧如此。数组中我们用快排 quick sort，而在链表中，更好实现的方式就是 合并排序 merge sort。这个题目简直就是为了合并排序量身定做的！


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
        // 使用快慢指针搜寻“中点”
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
        // 注意“断开关系”
        ListNode second = slow.next;
        slow.next = null;
        // Recusion 中的常用套路：设计两个分别是左边排好序的和右边排好序的list
        head = sortList(head);
        second = sortList(second);
        // 使用 merge 来排序，复杂度为 N
        return Merge(head, second);
    }
}
```

--------------------------------------------------------
其他相关用到的题目都大同小异，做起来没有太大的难度差别

--------------------------------------------------------
