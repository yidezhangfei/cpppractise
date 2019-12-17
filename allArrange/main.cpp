#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
    int t = b;
    b = a;
    a = t;
}

void arrangeInternal(vector<int>& nums, int local, vector<vector<int>>& result) {
    if (local == nums.size() - 1) {
        result.emplace_back(nums);
    } else if (local == nums.size()) {
        return;
    } else {
        for (int i = local; i < nums.size(); i++) {
            swap(nums[i], nums[local]);

            arrangeInternal(nums, local+1, result);

            swap(nums[i], nums[local]);
        }
    }
}

std::vector<std::vector<int>> arrange(vector<int>& nums) {
    std::vector<std::vector<int>> result;
    arrangeInternal(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums = {1,2,3,4};
    auto result = arrange(nums);

    for (auto i: result) {
        for (auto j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}