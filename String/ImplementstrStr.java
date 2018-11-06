package String;
import JavaInterface.JavaRun;
import java.util.*;

/*
    Date: 18/11/05


*/

public class ImplementstrStr{
    class Solution {
        public int strStr(String haystack, String needle) {
            int len1 = haystack.length(), len2 = needle.length();
            if(len2 == 0)  return 0;
            if(len1 == 0 || len1 < len2)  return -1;
            char head = needle.charAt(0);
            for(int i = 0; i < len1 - len2 + 1; i++)
                if(haystack.charAt(i) == head)
                    if(needle.equals(haystack.substring(i,i + len2)))
                        return i;
            return -1;
        }
    }
}