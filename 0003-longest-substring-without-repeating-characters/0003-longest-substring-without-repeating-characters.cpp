class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.size();
        int res = 0;
        
        // Iterate through possible starting indices
        for (int i = 0; i < n; i++) {
            vector<bool> visited(256);  // Track character occurrences
            
            // Find length of substring without repeating characters
            for (int j = i; j < n; j++) {
                if (visited[str[j]])  // If character is repeated, exit loop
                    break;
                res = max(res, j - i + 1);
                visited[str[j]] = true;
            }
            visited[str[i]] = false;  // Move to next starting index
        }
        
        return res;
    }
};