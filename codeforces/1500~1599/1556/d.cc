#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query_and(int l, int r) {
  cout << "and " << l << " " << r << endl;
  int result = 0;
  cin >> result;
  return result;
}

int query_or(int l, int r) {
  cout << "or " << l << " " << r << endl;
  int result = 0;
  cin >> result;
  return result;
}

void answer(int x) {
  cout << "finish " << x << endl;
}

int query_sum(int i, int j) {
  int and_result = query_and(i, j);
  int or_result = query_or(i, j);
  return or_result + and_result;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> sums(n+1);
  for (int i = 2; i <= n; ++i) {
    int sum = query_sum(i-1, i);
    sums[i] = sum;
  }

  int s = query_sum(1, 3);
  // sums[2] = a[1] + a[2]
  // sums[3] = a[2] + a[3]
  // s = a[1] + a[3]
  // s + sums[2] - sums[3] = a[1] + a[3] + a[1] + a[2] - a[2] - a[3]
  //  = a[1] * 2
  vector<int> a(n+1);
  a[1] = (s + sums[2] - sums[3]) / 2;
  for (int i = 2; i <= n; ++i) {
    a[i] = sums[i] - a[i-1];
  }

  sort(a.begin()+1, a.end());
  int ans = a[k];
  answer(ans);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
