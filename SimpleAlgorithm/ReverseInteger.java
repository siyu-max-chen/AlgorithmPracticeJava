package SingleAlgorithm;
import java.util.*;
import JavaInterface.JavaRun;

class ReverseInteger{
/*
    18/11/08
*/
/*
    题号：7
    已完成
*/
static class Solution {
    // Using long(a larger data type) to detect the overflow
    public int reverse(int x) {
        long ans = 0;
        while(x != 0){
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        if( ans > Integer.MAX_VALUE || ans < Integer.MIN_VALUE)
                return 0;
        return (int)ans;
    }

    // Withour using larger data type, judge before operation
    public int reverseWithoutUsingLong(int x) {
        int ans = 0;
        while(x != 0){
            if( ans > Integer.MAX_VALUE/10 || ans < Integer.MIN_VALUE/10)
                return 0;
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }
}

    public void run(){

    }

}