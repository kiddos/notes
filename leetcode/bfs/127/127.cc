#include <bits/stdc++.h>

using namespace std;

// Word Ladder
//
// classic bfs problem

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord)) return 0;

    queue<string> q;
    q.push(beginWord);

    int step = 1;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        string word = q.front();
        q.pop();
        if (word == endWord) return step;

        for (int i = 0; i < word.length(); ++i) {
          char cc = word[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            if (c != cc) {
              word[i] = c;
              if (words.count(word)) {
                q.push(word);
                words.erase(word);
              }
            }
          }
          word[i] = cc;
        }
      }
      step++;
    }
    return 0;
  }
};

class Solution2 {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (!words.count(endWord)) return 0;

    unordered_set<string> s1({beginWord}), s2({endWord});
    int step = 1;
    while (!s1.empty() && !s2.empty()) {
      if (s1.size() > s2.size()) {
        swap(s1, s2);
      }

      unordered_set<string> next;
      for (string word : s1) {
        for (int i = 0; i < word.length(); ++i) {
          char cc = word[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            if (c == cc) continue;

            word[i] = c;
            if (s2.count(word)) return step + 1;
            if (words.count(word)) {
              words.erase(word);
              next.insert(word);
            }
          }
          word[i] = cc;
        }
      }
      s1 = next;
      step++;
    }
    return 0;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string beginWord, endWord;
  vector<string> wordList;
  int ans = 0;

  beginWord = "hit";
  endWord = "cog";
  wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
  ans = Solution().ladderLength(beginWord, endWord, wordList);
  assert(ans == 5);
  ans = Solution2().ladderLength(beginWord, endWord, wordList);
  assert(ans == 5);

  beginWord = "hit";
  endWord = "cog";
  wordList = {"hot", "dot", "dog", "lot", "log"};
  ans = Solution().ladderLength(beginWord, endWord, wordList);
  assert(ans == 0);
  ans = Solution2().ladderLength(beginWord, endWord, wordList);
  assert(ans == 0);
  return 0;
}
