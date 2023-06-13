#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  priority_queue<int, vector<int>, less<>> pq;
  ll value = 0;
  for (int i = 0; i < n; ++i) {
    int l = i, r = n-i-1;
    if (s[i] == 'L') {
      pq.push(max(r-l, 0));
      value += l;
    } else if (s[i] == 'R') {
      pq.push(max(l-r, 0));
      value += r;
    }
  }

  for (int i = 0; i < n; ++i) {
    value += pq.top();
    pq.pop();
    cout << value << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
