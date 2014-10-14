/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/

public class Solution {
    public boolean wordBreak(String s, Set<String> dict) {
        
        if(s.length()==0) {
            return false;
        }
        
        boolean []dp = new boolean[s.length()+1];
        Arrays.fill(dp, false);
        
        dp[0] = true;
        
        
        for(int i = 0; i < s.length(); i++) {
            if(dp[i] == true){
                for(String s1 : dict){
                    if (s1.length() <= s.length() - i) { 
                        if(s1.equals(s.substring(i,s1.length()+i))) {
                            dp[i+s1.length()] = true;
                        }
                    }
                }
            }
        }
        
        return dp[s.length()];
        
    }
}
