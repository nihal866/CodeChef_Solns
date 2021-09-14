#include <bits//stdc++.h>
using namespace std;
 void dfs(vector<int>a[],int node,int distance[])
 {
     for(int child:a[node])
     {
         if(distance[child]==-1)
         {
             distance[child]=distance[node]+1;
            dfs(a,child, distance);
         }
     }
 }
int main() {
 int t;
 cin>>t;
 while(t--);
  {
      int n,m,s,k;
      int distance[n+1];

      memset(distance,-1,sizeof(distance));
      distance[0]=1;
      cin>>n>>m>>s>>k;
       vector<int> a[n+2];
       for(int i=0;i<m;i++)
       {
           int u,v;
           cin>>u>>v;
           a[u].push_back(v);
         a[v].push_back(u);
       }
         dfs(a,0,distance);
         vector<int> classes;
         for(int i=0;i<s;i++)
         {
             int x;
             cin>>x;
             classes.push_back(distance[x]);
         }
         sort(classes.begin(),classes.end());
         long long int ans=0;
         auto itr=classes.begin();
         while(itr-classes.begin()<k)
         {
             ans+=*itr;
             itr++;
         }
          cout<<distance[1]<<endl;

  }
	return 0;
}
