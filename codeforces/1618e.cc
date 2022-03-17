#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> solve(vector<int>& b) {
  int n = b.size();
  ll b_sum = accumulate(b.begin(), b.end(), 0LL);
  int sum = (n+1) * n / 2;
  if (b_sum % sum != 0) return {};

  ll a_sum = b_sum / sum;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    ll c = a_sum - (b[i] - b[(i-1+n)%n]);
    if (c <= 0 || c % n != 0) return {};
    ans[i] = c / n;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];
    vector<int> ans = solve(b);
    if (ans.size() == 0) cout << "NO\n";
    else {
      cout << "YES\n";
      for (int a : ans) cout << a << ' ';
      cout << '\n';
    }
  }
  cout.flush();
  return 0;
}
