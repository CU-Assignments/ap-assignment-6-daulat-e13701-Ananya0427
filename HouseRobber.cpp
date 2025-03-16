class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];

        int prev2 = 0, prev1 = 0;
        for (int money : nums) {
            int curr = max(prev1, money + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
