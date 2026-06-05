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
int n, sum;
cin >> n >> sum;
vi v(n);
for(int i = 0; i < n; i++) {
    cin >> v[i];
}
vector<vi>ans1;
sort(v.begin(), v.end());
for(int i = 0; i < n - 3; i++) {
    for(int j = i + 1; j < n - 2; j++) {
        int a = v[i] + v[j], c = j + 1, d = n - 1;
        while(c < d) {
            int need = a + v[c] + v[d];
            if(need == sum) {
                int k = d, k1 = c;
                while(v[d] == v[k] and k > c) {
                ans1.push_back({v[i], v[j], v[c], v[d]});
                k--;
                }
                while(v[c] == v[k1] and k1 < d) {
                ans1.push_back({v[i], v[j], v[c], v[d]});
                k1++;
                }
                d = k;
                c = k1;
            }
            else {
                if(need > sum) {
                    d--;
                }
                else {
                    c++;
                }
            }
        }
    }
}
for(int i = 0; i < ans1.size(); i++) {
    for(int j = 0; j < 4; j++) {
        cout << ans1[i][j] << ' ';
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