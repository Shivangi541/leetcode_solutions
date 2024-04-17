class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // brute force
       int ans =0;

        int l=0;
        int r=0;
        int n = fruits.size();
        int prev = fruits[0];
        while(r<n && fruits[r]==prev)
        {
            r++;
        }

        while(r<n)
        {
            pair<int, int> last;
            int next = fruits[r];
            while(r<n && (fruits[r]==next || fruits[r]==prev))
            {
                int counter=0;
                while(r<n && fruits[r]==next)
                {
                    counter++;
                    r++;
                    last = {next,counter};
                }
                counter =0;
                while(r<n && fruits[r]==prev)
                {
                    counter++;
                    r++;
                    last = {prev, counter};
                }   
            }
            ans = max(ans, r-l);
            prev = last.first;
            l = r-last.second;
        }

        ans = max(ans, r-l);

        return ans;
     
    }
};