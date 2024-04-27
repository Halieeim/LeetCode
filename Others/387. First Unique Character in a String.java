class Solution {
    public int firstUniqChar(String s) {
        List<Character> chars = new ArrayList<>();
        for(char c: s.toCharArray()){
            chars.add(c);
        }
        for(int i = 0; i < chars.size(); i++){
            char currentChar = chars.get(i);
            int idx = s.indexOf(currentChar); 
            int j = s.indexOf(currentChar, idx + 1); 
            if (j == -1) { 
                return i;
            }
        }
        return -1;
    }
}