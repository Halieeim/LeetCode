class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        List<String> res = new ArrayList<>();
        int index = 0;
        
        while (index < words.length) {
            int lineLength = words[index].length();
            int lastWordIndex = index + 1;
            
            while (lastWordIndex < words.length && lineLength + 1 + words[lastWordIndex].length() <= maxWidth) {
                lineLength += 1 + words[lastWordIndex].length();
                lastWordIndex++;
            }
            
            StringBuilder line = new StringBuilder(words[index]);
            int numOfWords = lastWordIndex - index;
            int numOfSpaces = maxWidth - lineLength + numOfWords - 1; // Remaining spaces to distribute
            
            if (lastWordIndex == words.length || numOfWords == 1) {
                // Left justify the last line or if only one word in the line
                for (int i = index + 1; i < lastWordIndex; i++) {
                    line.append(" ").append(words[i]);
                }
                line.append(" ".repeat(maxWidth - line.length()));
            } else {
                // Distribute spaces evenly between words
                int spacesBetweenWords = numOfSpaces / (numOfWords - 1);
                int extraSpaces = numOfSpaces % (numOfWords - 1);
                
                for (int i = index + 1; i < lastWordIndex; i++) {
                    for (int j = 0; j < spacesBetweenWords; j++) {
                        line.append(" ");
                    }
                    if (extraSpaces > 0) {
                        line.append(" ");
                        extraSpaces--;
                    }
                    line.append(words[i]);
                }
            }
            
            res.add(line.toString());
            index = lastWordIndex;
        }
        
        return res;
    }
}