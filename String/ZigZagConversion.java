package String;
import java.lang.*;
public class ZigZagConversion{

static class Solution {
    public String convert(String s, int numRows) {
        String[] a = new String[numRows];
        for(int i = 0; i < numRows; i++)
            a[i] = "";
        StringBuilder ans = new StringBuilder("");
        int len = s.length(); int i = 0, flag = 1, count = 0;
        int num = numRows - 1;
        if(num == 0) return s;
        while(count < len){
            a[i] += s.charAt(count);
            if(i % num == 0 && count != 0)
                flag = -flag;
            ++ count;
            i += flag;
        }
        for(int j = 0; j < numRows; j++)
            ans.append(a[j]);
        return ans.toString();
    }
}

public void run(){
    System.out.println(new Solution().convert("PAYPALISHIRING", 1));
    System.out.println(new Solution().convert("PAYPALISHIRING", 3));
    System.out.println(new Solution().convert("PAYPALISHIRING", 4));
}

}