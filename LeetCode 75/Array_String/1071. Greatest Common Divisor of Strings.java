class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String t = str1.length() < str2.length() ? str1 : str2;
        String s = str1.length() >= str2.length() ? str1 : str2;
        for(int i = 0; i < t.length(); i++){
            String temp = t.substring(0,t.length() - i);
            int idx = s.indexOf(temp);
            int count = 0;
            while(idx != -1){
                if(idx % temp.length() == 0){
                    count++;
                }
                idx = s.indexOf(temp, idx+1);
            }
            int idx2 = t.indexOf(temp);
            int count2 = 0;
            while(idx2 != -1){
                if(idx2 % temp.length() == 0){
                    count2++;
                }
                idx2 = t.indexOf(temp, idx2+1);
            }
            int len = count * temp.length();
            int len2 = count2 * temp.length();
            if(len == s.length() && len2 == t.length()) return temp;
        }
        return "";
    }
}