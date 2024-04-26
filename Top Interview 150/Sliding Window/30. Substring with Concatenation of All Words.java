class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) {
            return result;
        }
        
        int wordLength = words[0].length();
        int totalWordsLength = wordLength * words.length;
        int sLength = s.length();
        Map<String, Integer> wordFreq = new HashMap<>();
        for (String word : words) {
            wordFreq.put(word, wordFreq.getOrDefault(word, 0) + 1);
        }
        
        for (int i = 0; i <= sLength - totalWordsLength; i++) {
            Map<String, Integer> wordsSeen = new HashMap<>();
            int j = 0;
            while (j < words.length) {
                String currentWord = s.substring(i + j * wordLength, i + (j + 1) * wordLength);
                if (wordFreq.containsKey(currentWord)) {
                    wordsSeen.put(currentWord, wordsSeen.getOrDefault(currentWord, 0) + 1);
                    if (wordsSeen.get(currentWord) > wordFreq.getOrDefault(currentWord, 0)) {
                        break;
                    }
                } else {
                    break;
                }
                j++;
            }
            if (j == words.length) {
                result.add(i);
            }
        }
        
        return result;
    }
}