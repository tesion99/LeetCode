/*
给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

注意：请不要在超过该数组长度的位置写入元素。

要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

 

示例 1：

输入：[1,0,2,3,0,4,5,0]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
示例 2：

输入：[1,2,3]
输出：null
解释：调用函数后，输入的数组将被修改为：[1,2,3]
 

提示：

1 <= arr.length <= 10000
0 <= arr[i] <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/duplicate-zeros
*/
// 首先遍历数组，确定0的个数
// 从尾部开始反向扫描，确定该值之前的0的个数，从而确定新的坐标
// 直至当前数之前没有0值，退出扫描
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        if (arr.empty()) {
            return;
        }
        int zero = 0;
        for (auto n : arr) {
            if (n == 0) {
                ++zero;
            }
        }

        // 没有0或者全是0，直接返回，无需移动
        if (zero == 0 || zero == arr.size()) {
            return;
        }

        int sz = arr.size();
        for (int i = sz - 1; i >= 0; --i) {
            if (zero == 0) {
                break;
            }
            if (arr[i] == 0) {
                --zero;
            }

            if (i + zero <= sz - 1) {
                arr[i + zero] = arr[i];
            }
            arr[i] = 0;
        }
    }
};
