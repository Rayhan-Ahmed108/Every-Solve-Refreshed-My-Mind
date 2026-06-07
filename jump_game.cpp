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

int n;
vi v(10004);
void sol() {
int cnt = 0;
cin >> n;
v.resize(n+3);
for(int i = 1; i <= n; i++) {
    cin >> v[i];
    cnt += (v[i] == 0);
}
if(cnt == 0) {
    cout << "true" << endl;
    return;
}
if(v[1] == 0) {
    if(n == 1) {
        cout << "true" << endl;
        return;
    }
    cout << "false" << endl;
    return;
}
int mx = 1;
for(int i = 1; i <= n; i++) {
    if(v[i] == 0) {
        if(mx > i) {
            continue;
        }
        else {
            cout << "false" << endl;
            return;
        }
    }
    if(v[i] + i >= n) {
        cout << "true" << endl;
        return;
    }
    if(v[v[i] + i] == 0) {
        //cout << i << endl;
        if(v[i] + i > mx) {
            if(v[v[i] + i] == 0) {
                mx = max(mx, v[i] + i - 1);
            }
            else {
                mx = max(mx, v[i] + i);
            }
        }
    }
    else {
        mx = max(mx, i + v[i]);
    }
    if(mx >= n) {
        cout << "true" << endl;
        return;
    }
}
cout << "false" << endl;
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