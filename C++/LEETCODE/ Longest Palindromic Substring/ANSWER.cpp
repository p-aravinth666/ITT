#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.length() < 1) return "";
        int start = 0, maxLength = 0;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Length is (right - 1) - (left + 1) + 1
            return right - left - 1;
        };

        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(i, i);     // Odd length
            int len2 = expandAroundCenter(i, i + 1); // Even length
            int len = std::max(len1, len2);

            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
