
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> groups;

        for (string word : strs) {
            string s = word;
            sort(s.begin(), s.end());

            if (groups.count(s)) {
                groups[s].push_back(word);
            } else {
                groups[s] = {word};
            }
        }

        vector<vector<string>> result;

        for (auto& pair : groups) {
            result.push_back(pair.second);
        }

        return result;
    }
};
