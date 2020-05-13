#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define l long int
#define pb push_back
#define fast ios_base::sync_with_stdio(false)
pair<pair<int,int>,int> p[5001];
vector<int> v[5001];
int up[5001];
int down[5001];
queue<int> q;
bool intersect(int x1,int y1,int r1,int x2,int y2,int r2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=(r1+r2)*(r1+r2);
}
void bfs(int arr[])
{
	while(!q.empty())
	{
		int c=q.front();
		q.pop();
		int a,b;
		a=p[c].first.first;
		b=p[c].first.second;
		for(int i=0;i<v[c].size();i++)
		{
			if(arr[v[c][i]]>arr[c]+1)
			{
				arr[v[c][i]]=arr[c]+1;
				q.push(v[c][i]);
			}
		}
	}
}
int main()
{
   fast;
   cin.tie(0);
   cout.tie(0);
   int t,n,i,j,s,d;
   cin>>t;
   while(t--)
   {
   	 cin>>n;
   	 for(i=0;i<n;i++)
   	 {
   	 	int x,y,r;
   	 	cin>>x>>y>>r;
   	 	p[i]=make_pair(make_pair(x,y),r);
	 }
	 cin>>d>>s; // distance and source
	 for(i=0;i<n;i++)
	 {
	 	v[i].clear();
	 	up[i]=INT_MAX;
	 	down[i]=INT_MAX;
	 }
	 //making graph
	 for(i=0;i<(n-1);i++)
	 {
	 	for(j=i+1;j<n;j++)
	    {
	    	if(intersect(p[i].first.first,p[i].first.second,p[i].second,p[j].first.first,p[j].first.second,p[j].second))
	    	{
	    		v[i].pb(j);
	    		v[j].pb(i);
			}
		}
	 }
	 for(i=0;i<n;i++)
	 {
	 	if(p[i].first.second-p[i].second<=s)
	 	{
	 		up[i]=1;
	 		q.push(i);
		}
	 }
	 bfs(up);
	 for(i=0;i<n;i++)
	 {
	 	if(p[i].first.second+p[i].second>=d)
	 	{
	 		down[i]=1;
	 		q.push(i);
		}
	 }
	 bfs(down);
	 int ans=INT_MAX;
	 for(i=0;i<n;i++)
	 {
	 	if(up[i]!=INT_MAX&&down[i]!=INT_MAX)
	 	ans=min(ans,up[i]+down[i]-1);
	 }
	 if(ans==INT_MAX)
	 cout<<-1<<endl;
	 else 
	 cout<<ans<<endl;
   }
   
   
}

