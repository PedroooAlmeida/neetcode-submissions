class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Input: nums = [2,20,4,10,3,4,5]
        // Output: 4
        
        unordered_set<int> seen;

        for (int i = 0; i < nums.size(); i++){
            seen.insert(nums[i]); 
        }

        int length = 0; 

        for (int num : seen){
            int x = 1; 
            if (!seen.count(num - 1)) {
                while (seen.count(num + 1)){
                    num++; 
                    x++; 
                }       
            }
            if (x>length){
                length = x; 
            }
            
        }
        
        return length; 

    }   
};

