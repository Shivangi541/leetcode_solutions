class Solution {
public:
int nthMagicalNumber(int n, int a, int b) {
int ans=0;
int i=1;
int number=2;
while(i<=n) {
if(number%a==0 || number%b==0) {
if(i==n){
ans=number;
break;
}
i++;
}
number++;
}
ans = number;
return ans;
}
};