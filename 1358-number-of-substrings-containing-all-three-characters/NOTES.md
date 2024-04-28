// brute force
int i,j;
//int hash[3]={-1,-1,-1};
int n= s.length();
int cnt=0;
for(i=0;i<n;i++)
{
int hash[3]={0};
for(j=i;j<n;j++)
{
hash[s[j]-'a']=1;
if(hash[0]+hash[1]+hash[2]==3)
cnt=cnt+1;
}
}
return cnt;