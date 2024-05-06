class Solution {
public:
    bool check(int speed,vector<int>& piles, int h){
        // mid = speed
        int n=piles.size();
        int count=0; // count -> total number of hours
        for(int i=0; i<n; i++){
            if(count > h) return false;
            if(speed >= piles[i]) count++;
            else if(piles[i]%speed==0) count+=piles[i]/speed;
            else count+=piles[i]/speed + 1;
        }
        if(count > h) return false;
        else return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int n=piles.size();
       // finding maximum number in the array 
       int max=INT_MIN;
       for(int i=0; i<n; i++) {
            if(max < piles[i]) max=piles[i];
        }
        // binary search
        int low= 1; // always low will be-> one banana per hour
        int high=max; // high will be max speed means maximum number in the array
        int ans=-1;
        while(low <= high){
            int mid=low+(high-low)/2;
            if(check(mid,piles,h)==true){ // funcation call
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};