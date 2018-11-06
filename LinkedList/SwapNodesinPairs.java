package LinkedList;
import java.util.*;
import JavaInterface.JavaRun;
import LinkedList.ListNode;

/*
    Date: 18/11/05


*/

public class SwapNodesinPairs{
    class Solution {
        public ListNode swapPairs(ListNode head) {
            if(head == null)  return null;
            if(head.next == null)  return head;
            ListNode tail = head.next; ListNode nextHead = tail.next;
            tail.next = head;
            head.next = swapPairs(nextHead);
            return tail;
        }
    }
}