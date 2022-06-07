#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n = 0;
  cin >> n;
  ll m = (n+1) * n;
  if (m % 4 == 0 || (m + 1) % 4 == 0) {
    cout << "YES\n";
    unordered_set<int> s1;
    unordered_set<int> s2;
    for (int i = 1; i <= n; ++i) s1.insert(i);

    ll target = m / 4;
    int val = n;
    while (target > val) {
      s1.erase(val);
      s2.insert(val);
      target -= val;
      val--;
    }
    s1.erase(target);
    s2.insert(target);

    cout << s1.size() << '\n';
    for (int val : s1) cout << val << ' ';
    cout << '\n';
    cout << s2.size() << '\n';
    for (int val : s2) cout << val << ' ';
    cout << '\n';
  } else {
    cout << "NO\n";
  }
  cout.flush();
  return 0;
}
