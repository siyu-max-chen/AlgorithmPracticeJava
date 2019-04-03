# Linked List  链表
*“男人最重要的是持久。”*

---
### 总述
链表的题目比较少，大致因为题目类型比较单一而且题目相对简单。链表的题目可能唯一的trick就是使用【**双指针**】，并且大多数题目用 **recursion** 的方式可以轻松解决。唯一要注意的陷阱是**指针指向**有些情况下必须**重置**（当然部分tree的题目也会涉及！）。这里的链表通常指的是最简单的**只含有头部**的**单向链表**，双向链表和包含尾部的链表这里很少涉及，但是在某些题目例如设计一些数据结构时可以用到，可以减少遍历的复杂度！
- 基础代码
``` java
public class ListNode {
     int val;
     ListNode next;
     ListNode(int x) { val = x; }
}
```

- 反转链表
``` java 
比较基础的操作，复杂度O(N)/O(1)。只需要从头开始用变量记录即可。
```
``` java
ListNode p = head, q = p.next;
while(q != null){
    ListNode temp = q.next; // 保留节点
    q.next = p;     // 将链表关系反转 p -> q 变为 q -> p
    p = q; q = temp;    // pq指向下两个节点
}
head.next = null;   // 不要忘记重置
return p;
```

---
### 1. 双指针  two pointers
所谓双指针，一般情况下有以下几种不同的理解：
- 定义 slow 和 fast 两种不同**速度**的指针，每次循环他们移动的次数有差别
- 定义指针 p 和 q，一个指针总是在另一个指针的 k 距离后面
- 定义指针 left 和 right（类似BS），用来遍历（但在链表中不常用，是一种思路）

#### 1.1 slow n fast
slow 和 fast 是两个不同速度的指针，这种设计可以方便我们在 one pass 的情况下找到链表中的“特殊点”：比如中点（1/2处）或者任意比例的点（1/3 处）。
而且，通过合理设计代码的先后，可以选择到底是“小中点”还是“大中点”，有道题挺蛋疼的就是有这样的细致要求。

##### 例题：148 Sort List
``` 
Sort a linked list in O(n log n) time using constant space complexity.
将一个无序的链表进行排序，要求一定的时间复杂度和空间复杂度
```
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
*其他相关用到的题目都大同小异，做起来没有太大的难度差别*
#### 1.2 k dist
这类没啥好说的，就是一开始指针q在p的后面，这样如果q到达终点后，p必然指向距离终点前k距离的结点上。部分题目需要 one pass可以用到，很局限。

##### 例题：92 Reverse Linked List II
```
Reverse a linked list from position m to n. Do it in one-pass.
反转链表，要求反转从 m 到 n 范围内的链表
```
反转链表本身非常简单，使用两个指针变量，就是让后面的一个指向前面的一个，可以用一个中间变量记录 next prev，循环或者递归都轻易写出。这个题目要求 one pass，显然我们可以获得 n - m 个之后的指针，然后当前指针指向第 m 个的时刻，另一个指针必然是第 n 个。

##### 例题：19 Remove Nth Node From End of List
```
Given a linked list, remove the n-th node from the end of list and return its head.
Follow up: do that in one pass
从结尾处删除第 N 个指针节点 
```
我们只需要获得我们需要的这个节点就行了，然后很容易就能删除掉。思路就是使用 p 和 q，q 默认为 p 后面 第 N 个节点，那么当 q 到达终点，自然p 就是我们需要的节点。

#### 1.3 left n right
left 和 right 作为左右指针最常见在于“分治法”。而分治法中一个典型就是Binary Search。当然我印象中 3 sum 也是使用这种【思路】的题目。总之需要心中有数，这类可以方便我们从两头缩小范围

---
### 2. 递归  recursion
其实怎么说，递归只是一种coding的方式，在链表题目中可以让代码更加的简洁、漂亮。这算是递归的最简单的练习吧。

##### 例题：109 Convert Sorted List to Binary Search Tree
```
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
```
将排序好的list转化为平衡二叉树。因为要求是平衡二叉树，所以最简单的构造方式就是使用“中点”作为二叉树的根，分别构造出他两边的左右树枝。写法用recursion非常简洁与简单！

``` java
class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        // 注意两种边界情况
        if(head == null)
            return null;
        if(head.next == null)
            return new TreeNode(head.val);
        // 快慢指针找中点的 trick
        ListNode slow = head, fast = head.next;
        while(fast.next != null){
            fast = fast.next;
            if(fast.next == null)
                break;
            fast = fast.next;
            slow = slow.next;
        }
        ListNode node = slow.next;
        TreeNode root = new TreeNode(node.val);
        slow.next = null;
        // 构造 recursion，左儿子是左边的list， 右边的儿子是右边的list，而且注意要重置list的next
        root.left = sortedListToBST(head);
        root.right = sortedListToBST(node.next);
        return root;
    }
}
```
##### 例题：82 Remove Duplicates from Sorted List II
```
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
类似之前的简单题目，这次的要求是所有重复的节点全部删除并不保留。
```
思路和之前的类似，无非就是判断这个节点到底是不是重复节点？只需要加一些判定条件，依然可以用 recursion 的方式实现。

```java
class Solution {
    private ListNode Helper(ListNode node, int val){
        if(node == null)
            return null;
        if(node.val == val)
            return Helper(node.next, val);
        else{
            if(node.next == null)
                return node;
            else if(node.next.val != node.val){
                node.next = Helper(node.next, node.val);
                return node;
            }
            else
                return Helper(node.next, node.val);
        }
    }
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null || head.next == null)
            return head;
        if(head.next.val == head.val)
            return Helper(head, head.val);
        else{
            head.next = Helper(head, head.val);
            return head;
        }
    }
}
```

---
### 3. Loop/Cycle  环
有些链表题目中提示该链表某个部位可能存在环，这时我们需要了解并使用"Floyd-Cycle-Detection-Algorithm"。
该理论主要分为两部分：
- 判断环的存在：使用slow n fast的双指针，开始都指向头部节点，fast的速度是slow的两倍，如果 slow 和 fast 可以相遇则说明存在环；若最后fast指向null则不存在换
- 判断环的起点：同上，在相遇点的时刻，让一点指针指向head，另一个指针指向该点，那么当两个指针再次相遇的点就是“环的开始”。
- 对于某些数组形式的问题，该理论同样适用。
##### 例题：142 Linked List Cycle II
```
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
寻找环的开始节点。
```
- 不太满足的做法：
使用一个 HashSet<ListNode>，不断遍历链表，当出现set里已经有重复的值的时候返回该值，当没有包含时则返回 null
- 满足的做法：
使用 Floyd-Cycle-Detection-Algorithm

---
