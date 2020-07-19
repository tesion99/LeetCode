/*
给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (0 == n) return false;

        if (1 == n) return true;

        if (n % 2 != 0) return false;

        return isPowerOfTwo(n/2);
    }
};
