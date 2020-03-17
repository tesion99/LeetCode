/*
设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。

你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用 KthLargest.add，返回当前数据流中第K大的元素。

示例:

int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
说明: 
你可以假设 nums 的长度≥ k-1 且k ≥ 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-largest-element-in-a-stream
*/
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        cap_ = k;
        for (auto n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        if (data_.size() != cap_) {
            data_.push_back(val);
            shiftUp(data_.size() - 1);
        } else {
            if (val > data_[0]) {
                data_[0] = val;
                shiftDown(0);
            }
        }
        return data_[0];
    }
private:
    void shiftUp(int childIndex) {
        int parentIndex = (childIndex - 1) / 2;
        while (parentIndex >= 0 && data_[childIndex] < data_[parentIndex]) {
            swap(data_[childIndex], data_[parentIndex]);
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    void shiftDown(int parentIndex) {
        int childIndex = 2 * parentIndex + 1;
        while (childIndex < data_.size()) {
            if (childIndex + 1 < data_.size() && data_[childIndex + 1]  < data_[childIndex]) {
                ++childIndex;
            }
            if (data_[parentIndex] <= data_[childIndex]) {
                break;
            }
            swap(data_[parentIndex], data_[childIndex]);
            parentIndex = childIndex;
            childIndex = 2 * parentIndex + 1;
        }
    }
private:
    int cap_;
    vector<int> data_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
