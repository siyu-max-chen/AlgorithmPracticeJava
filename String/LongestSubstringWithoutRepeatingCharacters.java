package String;
public class LongestSubstringWithoutRepeatingCharacters{

static class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] Map = new int[256];
        int count = 0; int max = 0; int pivot = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(Map[s.charAt(i)] > 0){
                if(count > max)
                    max = count;
                if(pivot > Map[s.charAt(i)]){
                    count ++;
                }
                else{
                    pivot = Map[s.charAt(i)];
                    count = i - Map[s.charAt(i)] + 1;
                }
            }
            else{
                count++;
            }
            Map[s.charAt(i)] = i + 1;
        }
        return (max > count)?max:count;
    }
}

public void run(){
    System.out.println(new Solution().lengthOfLongestSubstring("abcabcbb"));
}


}