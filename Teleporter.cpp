#include<iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
using namespace __gnu_pbds;
typedef  vector<int> vi;
typedef  vector<vi> vii;
typedef  vector<tuple<int,int,int>> vti3;


ULL mod1=(1e9+7);
ULL mod2=(1152921504606846976);

#define FOR(i,a,b) for(long i=a;i<b;i++)
#define pb push_back
#define ll long long
#define pob pop_back
#define fi first
#define si second
#define mdeb(x) cout << #x<<' '<< x <<"\n";
#define mdeb2(x,y) cout<< #x<<' '<<x<<' '<< #y<<' '<<y<<"\n";
#define mdeb3(x,y,z) cout<< #x<<' '<<x<<' '<< #y<<' '<<y<<' '<< #z<<' '<<z<<"\n";
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define less(x) order_of_key(x)
#define element(x) find_by_order(x)
#define mii map<int,int>
#define mp make_pair
#define msi map<string,int>
#define musi unorderd_map<string,int>
#define test_n LL N; cin>>N; while(N--)
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end() 
void printans(int f){
	if(f){cout<<"YES\n";}else{ cout<<"NO\n";}
}

 
int n;
 

int main(){
fastio;
ll n,k;
cin>>n>>k;
ll lift[n+1][64];
vector<int> A(n);
FOR(i,0,n){
	cin>>A[i]; lift[i][0]=A[i]-1;
}

FOR(j,1,64){
	FOR(i,0,n){
		lift[i][j]=lift[lift[i][j-1]][j-1];
	}
}

int u=0;
FOR(i,0,64){
	if(k&(1LL<<i)){ u=lift[u][i]; }
}
cout<<u+1<<"\n";

return 0;}
