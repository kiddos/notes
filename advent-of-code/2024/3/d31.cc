#include <bits/stdc++.h>
#include <regex>

using namespace std;

using i64 = long long;

void solve() {
  ifstream input("./input.txt");

  ostringstream buffer;
  buffer << input.rdbuf();

  string text = buffer.str();
  regex p1("mul\\((\\d{1,3}),(\\d{1,3})\\)");
  auto start = std::sregex_iterator(text.begin(), text.end(), p1);
  auto end = std::sregex_iterator();
  i64 total = 0;
  vector<pair<int,int>> muls;
  for (auto it = start; it != end; ++it) {
    string d1 = it->str(1);
    string d2 = it->str(2);
    int x = stoi(d1), y = stoi(d2);
    total += x * y;
  }
  cout << total << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
