#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)

int n;
string s;
const int maxN = 501;
int dp[maxN][maxN];

int res(int low = 0, int high = n - 1) {
	if (low > high) return 0;
	if (low == high) return 1;
	int &ans = dp[low][high];
	if (ans == -1) {
		ans = 1 + res(low + 1, high);
		for (int i = low + 1; i <= high; i++) {
			if (s[low] == s[i]) {
				ans = min(ans, res(low + 1, i - 1) + res(i, high));
			}
		}
	}
	return ans;
}

int32_t main() { fastio;
	cin >> n >> s;
	memset(dp, -1, sizeof dp);
	cout << res() << endl;
	return 0;
}
