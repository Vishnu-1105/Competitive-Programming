#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(x) fastpow(x, HELL - 2, HELL);

int32_t main() { fastio;
    int t; cin >> t;
    while (t--) {
    	int n, k;
    	cin >> n >> k;
    	for (int i = 0; i < n; i++) {
    		int x; cin >> x;	
    		if (x == 1) {
    			cout << 1 << endl;
    		} else {
		    	int den = inv(fastpow(52, x));
		    	int num = fastpow(52 + 2 * k, x / 2) % HELL;
		    	if (x & 1) {
		    		num = (num * 52) % HELL;
		    	}
		    	cout << (num * den) % HELL << endl;
    		}
    	}
    }
    return 0;
}
