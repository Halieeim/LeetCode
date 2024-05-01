class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> list = new ArrayList<>();
        if(s.length() < p.length()) return list;
        String temp = "";
        for(int i = 0; i < p.length(); i++){
            temp += s.charAt(i);
        }
        char[] t = temp.toCharArray();
        char[] p_chars = p.toCharArray();
        Arrays.sort(t);
        Arrays.sort(p_chars);
        p = new String(p_chars);
        String test = new String(t);
        if(test.equals(p)) list.add(0);
        temp = temp.substring(1);
        for(int i = 0; i < s.length(); i++){
            if(i+p.length() >= s.length()) break;
            temp += s.charAt(i+p.length());
            t = temp.toCharArray();
            Arrays.sort(t);
            test = new String(t);
            if(test.equals(p)) list.add(i+1);
            temp = temp.substring(1);
        }
        return list;
    }
}