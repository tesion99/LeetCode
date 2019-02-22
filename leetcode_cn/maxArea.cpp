/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

// 遍历
class Solution {
public:
    int maxArea(vector<int>& height) {
        int cap = 0;
        int area = 0;
        for (int i = 0, j = height.size() - 1; i < j; ++i) {
            while (j > i) {
                area = (j - i) * min(height[i], height[j]);
                if (area > cap) cap = area;
                --j;
            }
            j = height.size() - 1;
        }
        
        return cap;
    }
};

// 以最小的height进行两侧逼近
class Solution {
public:
    int maxArea(vector<int>& height) {
        int cap = 0;
        int area = 0;
        int min_height = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            min_height = min(height[i], height[j]);
            area = (j - i) * min_height;
            if (area > cap) cap = area;
            
            while(i < j && min_height >= height[i]) ++i;
            
            while (j > i && min_height >= height[j]) --j; 
            
        }
    
        return cap;
    }
};
