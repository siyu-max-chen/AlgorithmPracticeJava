package LinkedList;
import java.util.*;
import JavaInterface.JavaRun;
import LinkedList.ListNode;

/*
    Date: 18/11/05


*/

public class MergeTwoSortedLists implements JavaRun{

    static class Solution {
        public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
            if(l1 == null)  return l2;
            if(l2 == null)  return l1;
            ListNode large = (l1.val >= l2.val)? l1: l2;
            ListNode small = (l2.val > l1.val)? l1: l2;
            ListNode head = small;
            while(large != null && small != null){
                if(small.next != null){
                    if(small.next.val > large.val){
                        if(large.next != null){
                            l1 = small.next; l2 = large.next;
                            if(l2.val >= l1.val){
                                small.next = large;
                                large.next = l1;
                                small = l1; large = l2;
                            }
                            else{
                                small.next = large;
                                large.next = l2;
                                small = l2; large = l1;
                            }
                        }
                        else{
                            l1 = small.next;
                            small.next = large;
                            large.next = l1;
                            return head;
                        }
                    }
                    else
                        small = small.next;
                }
                else{
                    small.next = large;
                    return head;
                }
            }
            return head;
        }
    }

public void run(){
    int[] array1 = {1, 2, 4};
    int[] array2 = {1, 3, 4};
    ListNode l1 = new ListNode(array1[0]), l2 = new ListNode(array2[0])
    , l1temp = l1, l2temp = l2;
    for(int i = 1; i < array1.length; i++)
        l1temp = l1temp.next = new ListNode(array1[i]);
    for(int i = 1; i < array2.length; i++)
        l2temp = l2temp.next = new ListNode(array2[i]);
    System.out.println(l1);
    System.out.println(l2);
    System.out.println(new Solution().mergeTwoLists(l1, l2));
}

}