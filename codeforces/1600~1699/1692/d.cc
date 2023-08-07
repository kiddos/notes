#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_palindrome(int minutes) {
  int h = minutes / 60;
  int m = minutes % 60;
  return h / 10 == m % 10 && m / 10 == h % 10;
}

void solve() {
  string time;
  for (int i = 0; i < 5; ++i) {
    char ch = '\0';
    cin >> ch;
    time.push_back(ch);
  }

  int x = 0;
  cin >> x;

  int h = stoi(time.substr(0, 2));
  int m = stoi(time.substr(3, 2));
  int minutes = h * 60 + m;

  vector<bool> visited(1440);
  int ans = 0;
  while (!visited[minutes]) {
    visited[minutes] = true;
    ans += is_palindrome(minutes);
    minutes = (minutes + x) % 1440;
  }

  cout << ans << endl;
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
