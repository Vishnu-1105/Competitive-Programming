#include <bits/stdc++.h>
using namespace std;

int n;
vector< vector<int> > table;
vector<int> LOG;

void build(vector<int> arr) {
    LOG.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        LOG[i] = !(i & (i - 1)) + LOG[i - 1];
    }
    int lg = LOG[n] + 1;
    table.assign(n, vector<int>(lg));
    for (int j = 0; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            if (j == 0) {
                table[i][j] = arr[i];
            } else {
                table[i][j] = table[i][j - 1] < table[i + (1 << (j - 1))][j - 1] ? 
                                table[i][j - 1] : table[i + (1 << (j - 1))][j - 1];
            }
        }
    }
}

int query(int low, int high) {
    int k = LOG[high - low + 1];
    return table[low][k] < table[high - (1 << k) + 1][k] ? 
            table[low][k] : table[high - (1 << k) + 1][k];
}

int main() {
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build(arr);
    int q; cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << query(x, y) << endl;
    }
	return 0;
}