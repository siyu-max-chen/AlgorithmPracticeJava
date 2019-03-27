# recursion 相关
只是写法和思路，没有啥特别的

--------------------------------------------------------
#### [109 Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)
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

--------------------------------------------------------
#### [82 Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
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
--------------------------------------------------------
