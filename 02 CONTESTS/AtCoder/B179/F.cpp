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

// --------------------- Range Update Add, Range Query sum (LAZY) ---------------------- //
// 0 based indexed
// Implementation by ScaryTerry
class SegmentTree {
    private:
        int treeSize, arrSize;
        vector<pair<int, int>> tree;

        int __query(int qLow, int qHigh, int low, int high, int pos) {
            if (qLow <= low and qHigh >= high) {
                return tree[pos].first + (high - low + 1) * tree[pos].second;
            }
            if ((qLow > high) or (qHigh < low)) {
                return 0;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            if (tree[pos].second != 0) {
                int add = tree[pos].second;
                tree[pos].first += (high - low + 1) * add;
                tree[left].second += add;
                tree[right].second += add;
                tree[pos].second = 0;
            }
            int leftVal = __query(qLow, qHigh, low, mid, left);
            int rightVal = __query(qLow, qHigh, mid + 1, high, right);
            return leftVal + rightVal;
        }

        void __update(int qLow, int qHigh, int low, int high, int pos, int val) {
            if (qLow <= low and qHigh >= high) {
                tree[pos].second += val;
                return;
            }
            if ((qLow > high) or (qHigh < low)) {
                return;
            }
            int mid = (high + low) / 2;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;

            if (tree[pos].second != 0) {
                int add = tree[pos].second;
                tree[left].second += add;
                tree[right].second += add;
                tree[pos].second = 0;
            }
            __update(qLow, qHigh, low, mid, left, val);
            __update(qLow, qHigh, mid + 1, high, right, val);
            tree[pos].first = tree[left].first + tree[right].first 
            + (mid - low + 1) * tree[left].second + (high - mid) * tree[right].second;
        }

        void __build(vector<int> &arr, int pos, int low, int high) {
            if (low == high) {
                tree[pos].first = arr[low];
            } else {
                int mid = (low + high) / 2;
                int left = pos * 2 + 1;
                int right = pos * 2 + 2;

                __build(arr, left, low, mid);
                __build(arr, right, mid + 1, high);
                tree[pos].first = tree[left].first + tree[right].first;
            }
        }

    public:
        SegmentTree(int n) {
            arrSize = n;
            treeSize = 4 * arrSize;
            tree.resize(treeSize, { 0, 0 });
        }

        SegmentTree(vector<int> &arr) {
            arrSize = arr.size();
            treeSize = 4 * arrSize;
            tree.resize(treeSize, { 0, 0 });
            __build(arr, 0, 0, arrSize - 1);
        }

        int _query(int qLow, int qHigh) {
            return __query(qLow, qHigh, 0, arrSize - 1, 0);
        }

        void _update(int qLow, int qHigh, int val) {
            __update(qLow, qHigh, 0, arrSize - 1, 0, val);
        }
};

int32_t main() { fastio;
	int n, q;
	cin >> n >> q;
	SegmentTree rows(n), cols(n);
	int ans = (n - 2) * (n - 2);
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			
		} else {

		}
	}
	cout << ans << endl;
	return 0;
}