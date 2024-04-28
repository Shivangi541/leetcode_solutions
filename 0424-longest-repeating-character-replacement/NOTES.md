// brute force
class Solution {
public:
int characterReplacement(string s, int k) {
int longestSubstring = 0;
​
int n = s.size();
​
// Iterate over each character in the string.
for (int i = 0; i < n; i++)
{
// Stores the count of characters. Initialize to all zeros.
vector<int> cnt(26, 0);
// Stores the maximum count of any character in the current substring.
int mx = 0;
// Iterate over each character in the current substring.
for (int j = i; j < n; j++)
{
// Calculate the index of the character in the count array.
int ch = s[j] - 'A';
// Increment the count of the current character.
cnt[ch]++;
​
// Update the maximum count of any character in the current substring.
mx = max(mx, cnt[ch]);
// Calculate the length of the current substring.
int substringLen = j - i + 1;
// Check if the number of operations required to convert the current substring into a repeating substring is less than or equal to 'k'.
if ((substringLen - mx) <= k)
{
// Update the length of the longest repeating substring if the current substring can be converted into a repeating substring.
longestSubstring = max(longestSubstring, substringLen);
}
}
}
// Return the length of the longest repeating substring with the same characters.
return longestSubstring;
}
};