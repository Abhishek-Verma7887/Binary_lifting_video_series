#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef  vector<int> vi;

/*
You are given a string S composed of only lowercase letters and an array of points corresponding 
to each letter. You have to find maximum score you can get for a substring which starts and ends 
with same letter. Constraints : 1 <= |S| <= 10^5  -10^5 <= points <= 10^5
*/

#define LL long long
#define FOR(i,a,b) for(long i=a;i<b;i++)
#define pb push_back
#define ll long long
#define pob pop_back
#define fi first
#define mdeb(x) cout << #x<<' '<< x <<"\n";
#define mdeb2(x,y) cout<< #x<<' '<<x<<' '<< #y<<' '<<y<<"\n";
#define mdeb3(x,y,z) cout<< #x<<' '<<x<<' '<< #y<<' '<<y<<' '<< #z<<' '<<z<<"\n";
#define si second
#define test_n LL N; cin>>N; while(N--)
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end() 
 
int n;
 

int main(){
fastio;
test_n{
string s;
cin>>s;
n=s.size(); //length of string
ll cost[26];
vi last_pos(26,n+1); //
cout<<"n: "<<n<<"\n";

FOR(i,0,26){
	cin>>cost[i];
}

pair<ll,ll> lift[n+2][20]; /*
stores in first the next 2^ith ancestor and in second stores the sum from 1 after current node to 2^ith ancestor 
*/

vector<vector<ll>> maxi(n+2,vector<ll>(20,-1)); //maxi[1][2]: the maximum the 2^th power for which th score is maximum
vector<ll> maxV(n+2,-1e18);    

ll sumi=0; ll psum[n+2];
psum[0]=0;
FOR(i,0,n){
	last_pos[s[i]-'a']=i+1;
 sumi+=cost[s[i]-'a']; psum[i+1]=sumi;
}

FOR(i,0,20){
	lift[n+1][i].fi=n+1;
	lift[n+1][i].si=0;
}

//now 
FOR(ch,0,26)
{	 ll prev=0;
	FOR(i,0,n){
		int c=s[i]-'a'; 
	
		if(c==ch){
			lift[prev][0].fi=i+1;
			if(prev==0){ lift[prev][0].si=0; }
			else{lift[prev][0].si= psum[i+1]-psum[prev];}
			prev=i+1;
		}
		
	}
	lift[prev][0].fi=n+1;
	lift[prev][0].si=0;
}

FOR(i,1,n+1){
	if(lift[i][0].si>maxV[i]){ maxV[i]=lift[i][0].si; maxi[i][0]=0;}
}


FOR(j,1,20){
	FOR(i,1,n+1){
		lift[i][j].fi=lift[lift[i][j-1].fi][j-1].fi;
		lift[i][j].si=lift[lift[i][j-1].fi][j-1].si+ lift[i][j-1].si;
		if(lift[i][j].si>maxV[i]){ maxV[i]=lift[i][j].si; maxi[i][j]=j;}else{ maxi[i][j]=maxi[i][j-1]; }
	}
}


ll fans=-1e18;

pair<int,int> ind_ans;


FOR(i,1,n+1){
	ll sum=0;
	ll m_sum=0;
	ll mAnc=i;
	int pprev=i;
	int maxPow=19;
	while(mAnc!=n+1&&maxi[mAnc][maxPow]>=0&&maxPow>=0){
		sum+=lift[mAnc][maxi[mAnc][maxPow]].si;
		m_sum=max(m_sum,sum);
		pprev=mAnc;
		int tmp_maxi=maxi[mAnc][maxPow];
		mAnc=lift[mAnc][maxi[mAnc][maxPow]].fi;	
		maxPow=tmp_maxi-1;
	}
	if(cost[s[i-1]-'a']+m_sum>=fans){ 
		if(mAnc>=n+1){mAnc=last_pos[s[i-1]-'a'];} 
		ind_ans={i,mAnc};
	}
	fans=max(fans,cost[s[i-1]-'a']+m_sum);
}

cout<<fans<<"\n";
cout<<"INDEX:"<<ind_ans.fi<<" "<<ind_ans.si<<"\n";
}

return 0;}

/*
INput:
abhishekvermaisthenewkingofuniverseandisexceptionallytalented
30886 -36915 38335 60492 -41421 90027 20059 13926 -83426 55736 95368 -56429 21530 65123 3135 79802 -23058 98167 18456 78042 -77373 -44919 98537 94324 64370 3526
OUTPT:
688722 (explanation: from index 6 to index 59)
*/

/*
check this , it's giving wrong output
1
lnkljxfbiekejubuzaspukcxur
23397 69285 -36377 -72697 -50704 -97549 31229 23501 47255 -5406 6318 80772 -71512 -56614 -26226 -40452 6594 -25168 -17087 -3691 56034 52466 51181 -98048 93795 -45046
correct:181353
wrong:141363
*/