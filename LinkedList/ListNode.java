package LinkedList;
import java.lang.*;
public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
    public String toString(){
        StringBuilder s = new StringBuilder();
        ListNode temp = this;
        s.append(val);
        temp = temp.next;
        while(temp){
            s.append("==>");
            s.append(temp.val);
            temp = temp.next;
        }
        return s.toString();
    }
}