// Optimized Approach for ThreeSum problem:
// Time Complexity: O(n^2 logn + nlogn) = O(n^2 logn)
// Space Complexity: O(n)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        
        // Sort the input array to make it easier to find triplets.
        sort(nums.begin(), nums.end());
        
        // Using a set to store unique triplets.
        set<vector<int>> s;
        
        // The final result will be stored in this vector.
        vector<vector<int>> output;
        
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum == target) {
                    // If the sum of the triplet is equal to the target, add it to the set.
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if (sum < target) {
                    // If the sum is less than the target, move the left pointer (j) to the right.
                    j++;
                } else {
                    // If the sum is greater than the target, move the right pointer (k) to the left.
                    k--;
                }
            }
        }
        
        // Copy unique triplets from the set to the output vector.
        for (auto triplets : s)
            output.push_back(triplets);
        
        return output;
    }
};
