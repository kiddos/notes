#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  // when min heap has something to sell
  // there are 2 case,
  // 1. we can continue the selling from last
  // 2. or we start a brand new
  // eg. p = [1, 3, 9, 11]
  // when we reach 9, 9 can continue from 3, which started at 1
  // and 11 can start a brand new from 3
  //
  // so basically imagine there are k increasing subsequence
  // and we want to keep the last element for each subsequence

  priority_queue<int, vector<int>, greater<>> pq;
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!pq.empty() && p[i] > pq.top()) {
      ans += p[i] - pq.top();
      pq.pop();
      // continue from last min
      pq.push(p[i]);
    }
    // starting brand new
    pq.push(p[i]);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
