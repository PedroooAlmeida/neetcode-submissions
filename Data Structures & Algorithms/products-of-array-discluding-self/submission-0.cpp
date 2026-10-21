
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // Create result array, same size as nums, filled with 1s
        vector<int> result(nums.size(), 1);

        int leftProduct = 1;
        
        
        // store products to the left of index i 
        for (int i = 0; i < nums.size(); i++) {
            result[i] = leftProduct;
            leftProduct *= nums[i];
        }
        
        int rightProduct = 1;
        
        // multiply right products w/ left products already in result
        for (int i = nums.size() - 1; i >= 0; i--) {
            result[i] *= rightProduct; // mutiply the saved left product by everything to the right
            rightProduct *= nums[i]; // include current number for next iteration
        }

        // 3. Return answer
        return result;
    }
};
