class Solution {
    public String minWindow(String s, String t) {
        if (s == null || t == null || s.isEmpty() || t.isEmpty() || s.length() < t.length()) {
            return "";
        }

        // Preprocess t to count characters
        HashMap<Character, Integer> targetCharCount = new HashMap<>();
        for (char c : t.toCharArray()) {
            targetCharCount.put(c, targetCharCount.getOrDefault(c, 0) + 1);
        }

        // Sliding window approach
        HashMap<Character, Integer> windowCharCount = new HashMap<>();
        int left = 0, right = 0;
        int requiredChars = targetCharCount.size();
        int formedChars = 0;
        int minLen = Integer.MAX_VALUE;
        int minLeft = 0, minRight = 0;

        while (right < s.length()) {
            char currentChar = s.charAt(right);
            windowCharCount.put(currentChar, windowCharCount.getOrDefault(currentChar, 0) + 1);

            if (targetCharCount.containsKey(currentChar) && windowCharCount.get(currentChar).intValue() == targetCharCount.get(currentChar).intValue()) {
                formedChars++;
            }

            // Try to minimize the window
            while (left <= right && formedChars == requiredChars) {
                char leftChar = s.charAt(left);
                int currentWindowLen = right - left + 1;
                if (currentWindowLen < minLen) {
                    minLen = currentWindowLen;
                    minLeft = left;
                    minRight = right;
                }

                windowCharCount.put(leftChar, windowCharCount.get(leftChar) - 1);
                if (targetCharCount.containsKey(leftChar) && windowCharCount.get(leftChar).intValue() < targetCharCount.get(leftChar).intValue()) {
                    formedChars--;
                }
                left++;
            }

            right++;
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(minLeft, minRight + 1);
    }
}