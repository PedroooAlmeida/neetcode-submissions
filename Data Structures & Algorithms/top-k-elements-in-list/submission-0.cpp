
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // 1. Count how often each number appears
        unordered_map<int, int> freq;

        for (int num : nums) {
            if (freq.count(num)) {
                freq[num]++; // Increment if key exists
            } else {
                freq[num] = 1; // Create key with frequency 1
            }
        }

        // 2. Store frequencies and numbers as pairs
        vector<pair<int, int>> counts;

        for (auto& entry : freq) {
            counts.push_back({entry.second, entry.first});
        }
        
        // 3. Sort by frequency, highest first
        sort(counts.rbegin(), counts.rend());

        // 4. Create an array to store our answer
        vector<int> result;

        // 5. Add the k most frequent numbers
        for (int i = 0; i < k; i++) {
            result.push_back(counts[i].second);
        }

        // 6. Return our answer
        return result;
    }
};
