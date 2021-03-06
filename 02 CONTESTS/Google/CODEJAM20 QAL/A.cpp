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
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)

int32_t main() { fastio;
    int t; cin >> t;
    for (int _ = 1; _ <= t; _++) {
    	cout << "Case #" << _ << ": ";
    	int n; cin >> n;
    	int mat[n][n];
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
	    		cin >> mat[i][j];
    		}
    	}
    	int res = 0;
    	for (int i = 0; i < n; i++) {
    		res += mat[i][i];
    	}
    	int rows = 0, cols = 0;
    	for (int i = 0; i < n; i++) {
    		set<int> s;
    		for (auto m : mat[i]) {
    			s.insert(m);
    		}
    		if ((int) s.size() < n) {
    			rows++;
    		}
    	}

    	vector<set<int>> s(n);
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			s[j].insert(mat[i][j]);
    		}
    	}
    	for (auto x : s) {
    		if ((int) x.size() < n) {
    			cols++;
    		}
    	}

    	cout << res << " " << rows << " " << cols << endl;
    }
    return 0;
}
