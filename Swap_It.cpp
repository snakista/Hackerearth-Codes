#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
int main()
{
   fast;
   cin.tie(0);
   cout.tie(0);
   ll t,n,k,i;
   cin>>t;
   while(t--)
   {
   	 cin>>n>>k;
   	 ll arr[n];
   	 for(i=0;i<n;i++)
   	 cin>>arr[i];
   	 ll pos,j;
   	 for(i=0;i<n&&k>0;i++)
   	 {
   	 	pos=i;
   	 	for(j=i+1;j<n;j++)
   	 	{
   	 		if(j-i>k)
   	 		break;
   	 		if(arr[j]<arr[pos])
   	 		pos=j;
		}
		for(j=pos;j>i;j--)
		swap(arr[j],arr[j-1]);
		k-=pos-i;
	 }
	 for(i=0;i<n;i++)
	 cout<<arr[i]<<" ";
	 cout<<endl;
   }
 
}

