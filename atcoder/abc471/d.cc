#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int q = 0;
  i64 v = 0;
  cin >> q >> v;
  priority_queue<i64, vector<i64>, less<>> pq;
  for (int i = 0; i < q; ++i) {
    int type = 0;
    cin >> type;
    if (type == 1) {
      i64 tq = 0, wq = 0;
      cin >> tq >> wq;
      pq.push(wq - tq);
    } else if (type == 2) {
      int tq = 0;
      cin >> tq;
      if (pq.empty()) {
        cout << "-1" << endl;
      } else {
        i64 largest = pq.top();
        pq.pop();
        i64 level = min(largest + tq, v);
        cout << level << endl;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
