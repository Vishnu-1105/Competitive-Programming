#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
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
    int res = 1; a %= m; while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m; b >>= 1;
    } return res;
}

int now() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now()
    .time_since_epoch()).count();
}

map<pair<int, pair<int, int>>, int> H;

int getRes(int &n, int &k, int index, int sum, int max_poss) {
    if (index == n) {
        return (sum == 0);
    }
    if (H.count({ max_poss, { index, sum } })) {
        return H[{ max_poss, { index, sum } }];
    }
    int res = 0;
    for (int i = 0; i <= max_poss; i++) {
        res = (res + getRes(n, k, index + 1, sum - i, max_poss - (i ? i - 1 : 0))) % HELL;
    }
    H[{ max_poss, { index, sum } }] = res;
    return res;
}

int32_t main() { fastio;
    time_t start = now();
    int n, k;
    cin >> n >> k;
    k = min(n, k);
    cout << getRes(n, k, 0, n, k + 1) % HELL << endl;
    cerr << "TIME => " << now() - start << endl;
    return 0;
}