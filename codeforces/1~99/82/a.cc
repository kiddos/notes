#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  vector<string> people = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  i64 current_count = people.size();
  i64 total = 0;
  i64 p = 1;
  while (total + current_count * p < n) {
    total += current_count * p;
    p *= 2;
  }
  n -= total;

  int index = (n-1) / p;
  cout << people[index] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
