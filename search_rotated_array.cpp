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
int n, target;
cin >> n >> target;
vi v(n);
for(int i = 0; i < n; i++) {
    cin >> v[i];
}
int lo = 0, hi = n - 1;
        int ans = 0;
        if(v[0] > v[n - 1]) {
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(v[mid] >= v[lo]) {
            if(v[hi] >= v[mid]) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
                ans = lo;
            }
            }
            else {
                if(mid > 0 && v[mid] < v[mid - 1]) {
                    ans = mid;
                    break;
                }
                else {
                    hi = mid - 1;
                }
            }
            }
        }
        lo = 0;
        hi = ans - 1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(v[mid] == target) {
                cout << mid << endl;
                return;
            }
            if(v[mid] > target) {
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }         
        }
        lo = ans;
        hi = n - 1;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(v[mid] == target) {
                cout << mid << endl;
                return;
            }                
            if(v[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        cout << -1 << endl;
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