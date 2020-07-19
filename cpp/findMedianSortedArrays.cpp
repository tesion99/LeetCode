/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz = nums1.size() + nums2.size();
        int i = 0;
        int j = 0;
        bool vec_one = false;
        bool is_odd = sz % 2; // 数据总数是否是奇数
        int target_index = sz / 2 + 1;
        double result = 0.0;

        while (i < nums1.size() || j < nums2.size()) {
            if (i == nums1.size()) {
                vec_one = false;
                ++j;
            } else if (j == nums2.size()) {
                vec_one = true;
                ++i;
            } else {
                if (nums1[i] > nums2[j]) {
                    ++j;
                    vec_one = false;
                } else {
                    ++i;
                    vec_one = true;
                }
            }

            if (!is_odd && (target_index - 1 == i + j)) {
                result = vec_one ? nums1[i - 1] : nums2[j - 1];
            }

            if (target_index == i + j) {
                result += vec_one ? nums1[i - 1] : nums2[j - 1];
                break;
            }
        } // end while

        return is_odd ? result : result / 2.0;
    }
}
