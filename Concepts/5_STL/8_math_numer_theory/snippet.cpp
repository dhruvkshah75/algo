#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vlli;
typedef pair<int , int> pii;
typedef pair<long , long> pll;
typedef vector<pair<int ,int>> vpii;
typedef vector<pair<long, long>> vpll;
typedef vector<long double> vld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
ll MOD = 1e9 +7;
// upper bound -> greater than
// lower bound -> equal or greater
//Pre compute all primes
//smallest prime factor computation
//TO delete only one occurrence of a number in a multiset-> delete using the iterator pointing to that number. m.erase(iterator)
/*
	segment Tree code
	void build(segmentArray, actualArray , int index_for_segment_array , int start , int end)
	{
		if(start == end)
		{
			populate the node.
		}
	}
	void query(int Qs, int Qe, int st, int ed, int index_for_sgmt_tree)
	void update( arr1,arr2, int st, int ed, int index, int position)
	{
		if(st==ed && ed==position)
		{
			modify
			return;
		}
	}
*/

void smallestPrimefactor(vlli& spf,ll psize){
	vlli tspf(psize+1, 1e9);
	tspf[0]=0;
	tspf[1]=1;
	vector<bool> isprime(psize+1,true);
	isprime[0]=false;
	isprime[1]=false;
	for(ll i=2;i<=psize;i++){
		if(isprime[i]){
			tspf[i]=i;
			for(ll j=i*i;j<=psize;j=j+i){
				isprime[j]=false;
				tspf[j]=min(i,tspf[j]);
			}
		}
	}
	spf=tspf;
}

vector<pair<ll , ll>> primeFactorization(ll x, vector<int>& spf){
	vector<pair<ll,ll>> ans;
	while(x!=1){
		ll prime=spf[x];
		ll cnt=0;
		while(x%prime==0){
			cnt++;
			x=x/prime;
		}
		ans.push_back({prime,cnt});
	}
	return ans;
}

void precomputeprime(vector<bool>& primes, ll psize){
	vector<bool> tvector(psize+1, true);
	tvector[0]=false;
	tvector[1]=false;
	for(ll i=2;i<=psize;i++){
		if(tvector[i]==true){
			for(ll j=i*i;j<=psize;j=j+i){
				tvector[j]=false;
			}
		}
	}
	primes=tvector;
}

ll mul(ll x, ll y)
{
	return (x%MOD * y%MOD)%MOD;
}

ll MODpower(ll x, ll y)
{
	ll ans=1;
	while(y>0){
		if(y&1){
			ans=mul(ans,x);
		}
		x=mul(x,x);
		y=y>>1;
	}
	return ans;
}

ll modDivide(ll x, ll y) // (a/(b*c))%m = (a. b^(m-2) . c^(m-2))%m  ..IF M is not PRIME -> (a/b)%M = (a * (b^(phi(M) - 1)))%M.
{
	return mul(x, MODpower(y, (MOD-2)));
}

ll binarExpIterative(ll a , ll b)
{
	ll res=1;
	while(b>0){
		if(b&1){
			res=res*a;
		}
		a=a*a;
		b>>=1;
	}
	return res;
}
ll phi(ll n){ //Euler's Totient Function  O(Sqrt(N)) //number of numbers <n which are relatively prime with n  p^k-> p^k - multiples of p<=p^k
	ll result=n;
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			while(n%i == 0){
				n/=i;
			}
			result=result-result/i;
		}
	}
	if(n>1){
		result=result - result/n;
	}
	return result;
}

ll minver(ll n)
{
	return MODpower( n , MOD-2);
}

ll ncr(ll n, ll r , vlli& fact, vlli& ifact)
{
	return mul(fact[n], mul(ifact[r] , ifact[n-r])); // MOD = 1e9+7 ;
}

void preFactor(int n){
	vlli fact(n+1);
	vlli ifact(n+1);
	fact[0]=1;
	for(int i=1;i<=n; i++){
		fact[i]=mul(fact[i-1],i);
	}
	ifact[n]=minver(fact[n]);
	for(int i=n-1;i>=0;i--){
		ifact[i]=mul(ifact[i+1], i+1);
	}
	// cout ncr(n1, c1, fact , ifact)
	// for(int i=0;i<=10;i++)
	// {
	// 	cout<<"10 C "<<i<<" = "<<ncr(10,i,fact,ifact)<<endl;
	// }
}

int main(){
    
}


