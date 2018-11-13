package SingleAlgorithm;
import java.util.*;
import JavaInterface.JavaRun;

public class PalindromeNumber{
    class Solution {
        public boolean isPalindrome(int x) {
            // Withour ultilizing String
            if(x < 0)  return false;
            int reverse = 0, temp = x;
            while(temp > 0){
                reverse = reverse * 10 + temp % 10;
                temp /= 10;
            }
            return reverse == x;
        }

        public boolean isPalindromeOther(int x) {
            // Withour ultilizing String
            if(x < 0)  return false;
            char[] chArray = Integer.toString(x).toCharArray();
            int left = 0, right = chArray.length - 1;
            while(right > left){
                if(chArray[left] != chArray[right])
                    return false;
                ++left;
                --right;
            }
            return true;
        }
    }
}