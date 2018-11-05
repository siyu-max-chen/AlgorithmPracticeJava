package LinkedList;
import java.util.*;
import JavaInterface.JavaRun;
import LinkedList.ListNode;

public class MergeTwoSortedLists implements JavaRun{

static class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        
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