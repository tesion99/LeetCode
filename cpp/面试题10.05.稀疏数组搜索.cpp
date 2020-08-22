/*
稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。

示例1:

 输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
 输出：-1
 说明: 不存在返回-1。
示例2:

 输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
 输出：4
提示:

words的长度在[1, 1000000]之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sparse-array-search-lcci
*/
// 二分查找，遇到空字符串就继续移动
class Solution {
public:
    int findString(vector<string>& words, string s) {
        int left = 0, right = words.size() - 1;
        while (left <= right) {
            while (left <= right && words[left].empty()) ++left;
            while (left <= right && words[right].empty()) --right;
            if (left > right) break;
            
            int pos = (left + right) / 2;
            int mid = pos;
            while (left < mid && words[mid].empty()) --mid;

            int ret = strcmp(words[mid].c_str(), s.c_str());
            if (ret > 0) {
                right =  mid - 1;
            } else if (ret < 0) {
                left = pos + 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
