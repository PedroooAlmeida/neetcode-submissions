class Solution {
public:

    // combine multiple strings into one

    string encode(vector<string>& strs) {
        // length + # + string
        // hello world -> 5#hello5#world
        string encoded = ""; 

        for (string word : strs){
            encoded += to_string(word.length()); 
            encoded += "#";
            encoded += word; 
        }  
        
        return encoded; 

    }

    // separate that string back into the original list

    vector<string> decode(string s) {

        vector<string> result; 
        string length = ""; 

        for (int i = 0; i < s.length(); i++){
        
            if (s[i] == '#'){
                int len = stoi(length); 
                result.push_back(s.substr((i+1),len));
                i = i + len; // start at the next length digit
                length = ""; 
            } else {
                length += s[i]; 
            }
        }

        return result; 
    }
};
