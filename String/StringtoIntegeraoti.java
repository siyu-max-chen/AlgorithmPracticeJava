public class StringtoIntegeraoti{

    class Solution {
        public int myAtoi(String str) {
            int ans = 0; int index = 0;
            boolean isPostive = true;
            str = str.trim();
            int len = str.length();
            if(len == 0) return 0;
            char[] chArray = str.toCharArray(); char a = chArray[index];
            if(a == '+')
                ++index;
            else if(a == '-'){
                isPostive = false;
                ++index;
            }
            else if( 47 < a && a < 58){
                ans = a - 48;
                ++index;
            }
            else
                return 0;
            while(index < len){
                int digit = chArray[index] - '0';
                if( -1 < digit && digit < 10){
                    if(ans > Integer.MAX_VALUE/10 || ans == Integer.MAX_VALUE/10 && Integer.MAX_VALUE%10 < digit){
                        System.out.println("No!");
                        return (isPostive)? Integer.MAX_VALUE: Integer.MIN_VALUE;}
                    ans = ans * 10 + digit;
                    ++index;
                }
                else
                    return (isPostive)? ans: -ans;
            }
            return (isPostive)? ans: -ans;
        }
    }
}