#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
#define endl "\n"
const int mod = 1e9 + 7;
const long long INF = 1e18;
#define FAST_IO                           \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(0);                       \
    }

int binexp( int a,int b){ int ans=1; a=a%mod; while(b){if(b&1){ans=(ans*a)%mod;}a=(a*a)%mod;b>>=1;}return ans;}
bool isPrime(int n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}

#define vi      vector<int>
#define int     long long int
#define yes     cout << "YES\n";
#define no      cout << "NO\n"; 

void sol() {
int n;
cin >> n;
map<string, vector<int>>m;
vector<string>v(n), v1(n);
for(int i = 0; i < n; i++) {
    cin >> v[i];
}
v1 = v;
for(int i = 0; i < n; i++) {
    string s = v[i];
    sort(s.begin(), s.end());
    m[s].push_back(i);
}
vector<string>h;
for(auto it : m) {
    h.push_back(it.first);
}
vector<vector<string>>ans(h.size());
for(int i = 0; i < h.size(); i++) {
    for(auto it : m[h[i]]) {
        ans[i].push_back(v[it]);
    }
}
for(int i = 0; i < ans.size(); i++) {
    for(int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << ' ';
    }
    cout << endl;
}
}

int32_t main()
{
    FAST_IO
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t;
    // cin >> t;
    // while(t--)
    sol();
}