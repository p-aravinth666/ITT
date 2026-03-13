 #include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        
        while (left <= right) {
            int partition1 = left + (right - left) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            
            int L1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int R1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            
            int L2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int R2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            if (L1 <= R2 && L2 <= R1) {
                if ((m + n) % 2 == 0) {
                    return (std::max(L1, L2) + std::min(R1, R2)) / 2.0;
                } else {
                    return std::max(L1, L2);
                }
            } else if (L1 > R2) {
                right = partition1 - 1;
            } else {
                left = partition1 + 1;
            }
        }
        return 0.0;
    }
};
