package LinkedList;
import java.util.*;
import JavaInterface.JavaRun;

class AddTwoNumbers implements JavaRun{

static class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode ans = null; ListNode prev = ans;
        int sum = 0;
        while(l1 || l2 || sum){
            sum += (l1)? l1.val: 0;
            sum += (l2)? l2.val: 0;
            if(!ans) ans = new ListNode(sum % 10);
            ListNode temp = new ListNode(sum % 10);
            prev = (prev)? prev->next = temp: ans;
            if(l1) l1 = l1.next;
            if(l2) l2 = l2.next;
            sum /= 10;
        }
        return ans;
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
}


}