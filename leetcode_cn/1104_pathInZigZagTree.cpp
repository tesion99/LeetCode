/*
在一棵无限的二叉树上，每个节点都有两个子节点，树中的节点 逐行 依次按 “之” 字形进行标记。

如下图所示，在奇数行（即，第一行、第三行、第五行……）中，按从左到右的顺序进行标记；

而偶数行（即，第二行、第四行、第六行……）中，按从右到左的顺序进行标记。



给你树上某一个节点的标号 label，请你返回从根节点到该标号为 label 节点的路径，该路径是由途经的节点标号所组成的。

 

示例 1：

输入：label = 14
输出：[1,3,4,14]
示例 2：

输入：label = 26
输出：[1,2,6,10,26]
 

提示：

1 <= label <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree
*/
// 完全二叉树数组，父子节点索引关系
// 1. 先找出对应label存储的节点的正确index
// 2. 遍历该index的父节点，得到路径节点index
// 3. 查找路径节点index对应的value值
// 由题意可知：
//  当为偶数层时，index与value值相等
//  当为奇数层时，index顺序值与value顺序值相反，如第二层，index=[2,3], value=[3,2]
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        // 按照每一层从左到右编号，得到一棵完全二叉树数组，只是数组内容与数组索引index不同
        // 奇数层时，index与数组值相等
        // 偶数层时，index顺序值与数组值顺序相反
        // 如第二层时，index=[2,3]，对应的值value=[3,2]
        int val_index = getValueIndex(label);
        deque<int> dq;
        while (val_index) {
            dq.push_front(val_index);
            val_index /= 2;
        }

        int line = 1, idx = 0, value = 1;
        int start = 1, end = 1;
        vector<int> res(dq.size(), 0);
        while (!dq.empty()) {
            int index = dq.front();
            int value = index;
            if (0 == (line & 1)) {
                value = end - (index - start);
            }

            dq.pop_front();
            res[idx] = value;
            ++idx;
            ++line;
            start *= 2;
            end = 2 * start - 1;
        }
        
        return res;
    }

    int getValueIndex(int label) {
        int vs = 1, ve = 1;
        int level = 1;
        while (label > ve) {
            ++level;
            vs *= 2;
            ve = 2 * vs - 1;
        }
        if (0 == (level & 1)) {
            // 偶数行
            return vs + (ve - label);
        }
        return label;
    }
};
