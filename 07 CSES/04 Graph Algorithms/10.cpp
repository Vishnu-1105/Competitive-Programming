// CSES High Score
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
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int n, m;
const int maxN = 2.5e3 + 5;
vector<vector<int>> edges;
vector<int> radj[maxN], xadj[maxN];
bool haramkhor[maxN], vis[maxN];
set<int> S;
bool poss;

void dfs1(int node) {
	vis[node] = true;
	if (haramkhor[node]) {
		S.insert(node);
	}
	for (auto x : radj[node]) {
		if (!vis[x]) {
			dfs1(x);
		}
	}
}

void dfs2(int node) {
	vis[node] = true;
	if (haramkhor[node]) {
		if (S.find(node) != S.end()) {
			poss = true;
		}
	}
	for (auto x : xadj[node]) {
		if (!vis[x]) {
			dfs2(x);
		}
	}
}

int32_t main() { fastio;
	cin >> n >> m;
	int a, b, w;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> w;
		edges.pb({ a, b, -w });
		radj[b].pb(a);
		xadj[a].pb(b);
	}
	vector<int> distance(n + 1, INF);
	for (int i = 1; i <= n; i++) distance[i] = INF;
	distance[1] = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (auto e : edges) {
			distance[e[1]] = min(distance[e[1]], distance[e[0]] + e[2]);
		}
	}
	for (auto e : edges) {
		if ((distance[e[0]] + e[2]) < distance[e[1]])
			haramkhor[e[1]] = true;
	}
	dfs1(n);
	memset(vis, 0, sizeof vis);
	dfs2(1);
	if (poss) {
		cout << -1 << endl;
	} else {
		cout <<	-distance[n] << endl;
	}
	return 0;
}