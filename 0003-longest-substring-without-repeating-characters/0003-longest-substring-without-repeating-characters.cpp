class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int left = 0, ans = INT_MIN; // 'left' tracks the left boundary of the current substring, 'ans' stores the length of the longest substring without repeating characters
        int n = s.size(); // 'n' stores the length of the input string 's'
        unordered_map<char, int> mp; // 'mp' is a hashmap that stores characters of the current substring along with their frequencies
        
        // Check if the string is empty
        if (n == 0)
            return 0; // If the string is empty, return 0

        // Loop through the string
        for (int right = 0; right < n; right++) {
            // Update the frequency of the character at index 'right' in the hashmap
            mp[s[right]]++;
            // Check if there are repeating characters in the current substring
            while (mp[s[right]] > 1) {
                // If there are repeating characters, move the left boundary of the substring
                mp[s[left]]--; // Decrement the frequency of the character at index 'left' in the hashmap
                left++; // Move the left boundary to the right
            }
            // Update the length of the longest substring without repeating characters
            ans = max(ans, (right - left) + 1); // Update 'ans' by taking the maximum of its current value and the length of the current substring
        }
        // Check if 'ans' is still at its initial value (no non-repeating characters found)
        if (ans == INT_MIN)
            return 0; // If no non-repeating characters were found, return 0
        else
            return ans; // Otherwise, return the length of the longest substring without repeating characters 
    }
};