package Recursion;
import java.util.*;
import JavaInterface.JavaRun;

public class GenerateParentheses{
    class Solution {
        private void Recursion(List<String> ans, String s, int n1, int n2, int len){
            if(n1 == len && n2 == len){
                ans.add(s);
                return;
            }
            if(n1 < len){
                if(n1 > n2){
                    Recursion(ans, s + '(', n1 + 1, n2 , len);
                    Recursion(ans, s + ')', n1, n2 + 1, len);
                }
                else
                    Recursion(ans, s + '(', n1 + 1, n2 , len);
            }
            else
                Recursion(ans, s + ')', n1, n2 + 1, len);
        }
        public List<String> generateParenthesis(int n) {
            List<String> ans = new ArrayList<>();
            if(n == 0)  return ans;
            if(n == 1){
                ans.add("()");
                return ans;
            }
            int len = n;
            Recursion(ans, "((", 2, 0, len);
            Recursion(ans, "()", 1, 1, len);
            return ans;
        }
    }
}