class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;
        map<string, vector<string>> table;
        // Group anagrams based on sorted strings
        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            table[sortedStr].push_back(str);
        }

        // Copy grouped anagrams to the result
        for (const auto& pair : table) {
            anagrams.push_back(pair.second);
        }
        return anagrams;
    }
};