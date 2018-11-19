package LinkedList;
import java.util.*;
import JavaInterface.JavaRun;
import LinkedList.ListNode;

public class AddTwoNumbers implements JavaRun{
/*
    题号：2
    已完成
*/
static class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0); ListNode temp = head;
        int sum = 0;
        while( (l1!= null) || (l2 != null) || sum > 0){
            if(l1 == null) l1 = new ListNode(0);
            if(l2 == null) l2 = new ListNode(0);
            sum += l1.val + l2.val;
            temp = temp.next = new ListNode(sum % 10);
            l1 = l1.next;
            l2 = l2.next;
            sum /= 10;
        }
        return head.next;
    }
}

public void run(){
    int[] array1 = {1, 2, 3, 4, 5};
    int[] array2 = {3, 4, 5, 6, 7};
    ListNode l1 = new ListNode(array1[0]), l2 = new ListNode(array2[0])
    , l1temp = l1, l2temp = l2;
    for(int i = 1; i < array1.length; i++)
        l1temp = l1temp.next = new ListNode(array1[i]);
    for(int i = 1; i < array2.length; i++)
        l2temp = l2temp.next = new ListNode(array2[i]);
    System.out.println(l1);
    System.out.println(l2);
    System.out.println(new Solution().addTwoNumbers(l1, l2));
}

}