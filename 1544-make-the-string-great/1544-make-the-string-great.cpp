class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        string ans = "";
        if(s.size()<2){
            return s;
        }
        for(int i=0;i<s.size();i++){
            if(!st.empty() && abs(s[i]-st.top())==('a'-'A')){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};