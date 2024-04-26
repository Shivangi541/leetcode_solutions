class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0,sum=0;
        for(int i=0;i<=k-1;i++)
        {
            lsum+=cardPoints[i];
            sum=lsum;
        }
        int n = cardPoints.size();
        int right = n-1;
        for(int j=k-1;j>=0;j--)
        {
            lsum-=cardPoints[j];
            rsum+=cardPoints[right];
            right--;
            sum=max(sum,lsum+rsum);
            }
        return sum;
    }
};