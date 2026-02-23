class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int maxLen = 0;
        int start = 0;   // start index of sliding window

        for (int i = 0; i < s.length(); i++) {
            // If character already seen and inside current window
            if (lastIndex.count(s[i]) && lastIndex[s[i]] >= start) {
                start = lastIndex[s[i]] + 1;
            }

            // Update last seen index of current character
            lastIndex[s[i]] = i;

            // Update maximum length
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};