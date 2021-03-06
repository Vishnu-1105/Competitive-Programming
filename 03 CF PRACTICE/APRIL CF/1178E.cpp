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
#define size(a) (int) a.size()

int32_t main() { fastio;
	string s; cin >> s;
	int n = size(s);
	if (n < 4) {
		cout << s[0] << endl;
	} else {
		int low = 0, high = n - 1;
		vector<char> res; int sz = 0;
		while (low < high) {
			int curr = high - low + 1;
			if (curr < 4) {
				res.push_back(s[low]);
				break;
			}
			if (s[low] == s[high] or s[low] == s[high - 1]) {
				res.push_back(s[low]);
			} else {
				res.push_back(s[low + 1]);
			}
			sz++;
			low += 2;
			high -= 2;
		}
		for (auto r : res) cout << r;
		for (int i = sz - 1; i >= 0;i--) {
			cout << res[i];
		} cout << endl;
	}
    return 0;
}
