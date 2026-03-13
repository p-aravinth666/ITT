 #include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // Use an array as a direct-address table for all 256 ASCII characters
        std::vector<int> charMap(256, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            // If the character is found and is within the current window
            if (charMap[s[right]] >= left) {
                left = charMap[s[right]] + 1;
            }

            // Update the last seen index of the character
            charMap[s[right]] = right;
            
            // Calculate max length
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
