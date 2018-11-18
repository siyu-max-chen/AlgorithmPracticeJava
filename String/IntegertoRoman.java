package String;
import JavaInterface.JavaRun;
import java.util.*;

public class IntegertoRoman{
    static String[] digitFour = {"","M","MM","MMM"};  // 千位
    static String[] digitThree = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};  // 百位
    static String[] digitTwo = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};  // 百位
    static String[] digitOne = {"","I","II","III","IV","V","VI","VII","VIII","IX"};  // 个位
    class Solution {
        public String intToRoman(int num) {
        //  最简单的方法是直接根据【有限情况】进行转换！！！
            return digitFour[num / 1000] + digitThree[(num % 1000)/100] + digitTwo[(num % 100)/10] + digitOne[num % 10];
        }
        public String intToRomanOther(int num) {
        //  My first solution here, not good !!!!
            StringBuilder ans = new StringBuilder(); char[] A = new char[4]; char[] B = new char[3];
            A[0] = 'I'; A[1] = 'X'; A[2] = 'C'; A[3] = 'M';
            B[0] = 'V'; B[1] = 'L'; B[2] = 'D';
            int digit = 3; int div = 1000; int i = 0;
            while(div != 0){
                i = num / div;
                num = num - div * i;
                div /= 10;
                if(i == 0)
                    ;
                else if(i >= 5){
                    if(i == 9)
                        ans.append(A[digit]).append(A[digit + 1]);
                    else{
                        ans.append(B[digit]);
                        for(int j = 0; j < i - 5; j++)
                            ans.append(A[digit]);
                    }
                }
                else{
                    if(i == 4)
                        ans.append(A[digit]).append(B[digit]);
                    else{
                        for(int j = 0; j < i; j++)
                            ans.append(A[digit]);
                    }
                }
                -- digit;
            }
            return ans.toString();
        }
    }
}