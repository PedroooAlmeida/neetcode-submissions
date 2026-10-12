class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Create an empty hash map
        unordered_map<int, int> seen;

        // Go through each number in vector nums 
        for (int i = 0; i < nums.size(); i++) {

            // Calculate the number we need, x (which is target minus value at i)
            int x = target - nums[i];

            // Check if we've seen that number
            if (seen.count(x)) {

                // Return its index and our current index
                return {seen[x], i};
            }

            // Remember the current number and index
            seen[nums[i]] = i;
        }

        return {};
    }
};
