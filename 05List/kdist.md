# k dist 相关
主要的目的就是直接获取某个指针前面第 k 个位置的指针

--------------------------------------------------------
#### [92 Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)
```
Reverse a linked list from position m to n. Do it in one-pass.
反转链表，要求反转从 m 到 n 范围内的链表
```
反转链表本身非常简单，使用两个指针变量，就是让后面的一个指向前面的一个，可以用一个中间变量记录 next prev，循环或者递归都轻易写出。这个题目要求 one pass，显然我们可以获得 n - m 个之后的指针，然后当前指针指向第 m 个的时刻，另一个指针必然是第 n 个。

--------------------------------------------------------
#### [19 Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
```
Given a linked list, remove the n-th node from the end of list and return its head.
**Follow up:** do that in one pass
从结尾处删除第 N 个指针节点 
```
我们只需要获得我们需要的这个节点就行了，然后很容易就能删除掉。思路就是使用 p 和 q，q 默认为 p 后面 第 N 个节点，那么当 q 到达终点，自然p 就是我们需要的节点。

--------------------------------------------------------
