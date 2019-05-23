#include <iostream>
#include <vector>

// 未完成

int detCalc(std::vector<std::vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i ++) {
        for (int j = 0; j < matrix[0].size(); j ++) {
            int sig = 0;
        }
    }
    return 0;
}

// 输出从1到n的全排列
std::vector<std::vector<int>> arrange(int n) {
    std::vector<int> nums;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }
    std::vector<std::vector<int>> result;
    permut(nums, 0, nums.size()-1, result);
    return result;
}

void permut(std::vector<int>& in, int start_pos, int end_pos, std::vector<std::vector<int>>& out) {
    if (start_pos == end_pos) {
        return;
    }
} 

int main() {
    std::vector<int> v1 = {1,2,4};
    std::vector<int> v2 = {2,3,5};
    std::vector<int> v3 = {3,7,9};

    std::vector<std::vector<int>> matrix;

    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);

    int result = detCalc(matrix);
}