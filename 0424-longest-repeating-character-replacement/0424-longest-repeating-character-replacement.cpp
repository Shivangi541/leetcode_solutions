class Solution {
public:
    int characterReplacement(string s, int k) {
         int result=0;
        int left=0;
        vector<int> inwindow(26); //frequency table for characters inside our window
        int maxCnt=0;
        for(int right=0; right<s.size(); ++right) {
            //add right element
            inwindow[s[right]-'A']++;
            //
            //int maxCnt=*max_element(inwindow.begin(), inwindow.end());
            maxCnt = max(maxCnt, inwindow[s[right]-'A']); //optimization
            //window length = right-left+1
            //window length must not be > than maxCnt+k
            if (right-left+1>maxCnt+k) { //move left pointer if needed
                inwindow[s[left]-'A']--;
                left++;
            }
            result=max(result, right-left+1);
        }
        return result;
    }
};