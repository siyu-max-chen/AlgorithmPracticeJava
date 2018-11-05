package String;
import JavaInterface.JavaRun;
import java.util.*;

public class LetterCombinationsofaPhoneNumber implements JavaRun{

static class Solution {
    static final String[] content = {"abc","def","ghi","jkl","mno","pqrs","tuv",
            "wxyz"
    };
    private void letterRecursion(List<String> ans, String digits, String prev, int count, int len){
        if(count == len){
            ans.add(prev);
            return;
        }
        int numTrans = digits.charAt(count) - '2';
        for(char add: content[numTrans].toCharArray())
            letterRecursion(ans, digits, prev + add, count + 1, len);
    }
    public List<String> letterCombinations(String digits) {
        int len = digits.length();
        List<String> ans = new ArrayList<>();
        if(len == 0) return ans;
        letterRecursion(ans, digits, "", 0, len);
        return ans;
    }
}

public void run(){
    List<String> ans = new Solution().letterCombinations("23");
    for (int i = 0; i < ans.size(); i++) {
        System.out.print(ans.get(i) + ' ');
    }
}
}