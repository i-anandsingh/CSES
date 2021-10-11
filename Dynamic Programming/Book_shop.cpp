// Problem Link :- 
/* By- Anand Singh */    
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/trie_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;

#define getFast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define br "\n"
#define inf 1e18
#define pi 3.1415926535897
#define mp make_pair
#define int long long int
#define ld long double
#define mid(l,r)  (l+(r-l)/2)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define ub(x, k)    upper_bound((x).begin(), (x).end(), k);
#define lb(x, k)    lower_bound((x).begin(), (x).end(), k);
#define loop(i, a, x)    for(int i = (a); i <= (x); i++)
#define bpc(n)    __builtin_popcount(x)
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
typedef vector<bool>    vb;
typedef vector<int>    vi;
typedef pair<int, int>    pii;
typedef vector<pii>    vp;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}

vector<int> cost, pages;
int book_shop(int n, int x){
	vector<int> dp1(x+1, 0);
	vector<int> dp2(x+1, 0);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= x; j++){
			dp1[j] = dp2[j];
			if(cost[i] <= j)
				dp1[j] = max(dp2[j], pages[i] + dp2[j-cost[i]]);
		}
		dp2.swap(dp1);
		dp1.clear();
	}
	return dp2[x];
}
signed main(int32_t argc, char const *argv[]){
	getFast;
	//Write your code here...
	int n, x;
	cin>>n>>x;
	cost.pb(0);
	pages.pb(0);
	loop(i, 1, n){
		int a;
		cin>>a;
		cost.pb(a);
	}
	loop(i, 1, n){
		int a;
		cin>>a;
		pages.pb(a);
	}
	cout<<book_shop(n, x);
	return 0;
}