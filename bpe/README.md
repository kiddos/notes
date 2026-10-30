# Re-implementation of hugging face's BPE tokenizer in c++

A from-scratch Byte-Pair Encoding (BPE) trainer in C++. It reads a plain
text corpus, iteratively merges the most frequent adjacent symbol pair,
and prints the resulting token vocabulary (up to 50,000 tokens).

## Build & run

```sh
g++ -O2 -std=c++17 -o bpe bpe.cc
./bpe
```

The program reads the corpus from `./wiki.train.tokens` (hard-coded path in
`main`). Output is the vocabulary: each token with its id.

## How it works

1. `split_words` splits the corpus on whitespace (space, tab, newline), skips
   non-ASCII bytes, and deduplicates words into a `vector<string>`.
2. `replace_alphabet` maps each character to a numeric id (`word2id` /
   `id2word`) and builds one `Word` per unique word: a vector of symbol ids.
3. `where_to_update[p]` records which words contain pair `p`, and
   `pair_count[p]` counts its occurrences. All candidate merges go into a
   `priority_queue` (max-heap by pair count).
4. The main loop pops the most frequent pair, creates a new token by
   concatenation, and calls `Word::merge` on every affected word. Each merge
   returns `Change` deltas for the neighbouring pairs; these deltas update
   `pair_count`, and pairs whose count grew are pushed back onto the heap.
   Repeat until the vocabulary reaches `token_size` (50,000).

## Data structures

| Name | Role |
| --- | --- |
| `Pair` / `PairHash` | key of the pair-counting map |
| `Word` | one word as a vector of symbol ids, with an in-place `merge` |
| `Change` | `+1` / `-1` delta for one pair produced by a merge |
| `Merge` | heap entry: pair, count, and the set of words to update |

## Notes / caveats

- The heap can hold stale entries (a pair's count may drop after being
  pushed); the loop tolerates this by skipping pairs whose count is no
  longer positive.
- Characters outside 7-bit ASCII are dropped in `split_words`.
- Frequencies are per unique word, not per occurrence, since words are
  deduplicated up front.

## What I learned from this

- The original idea is to iteratively find the pair with the most count and
  for each word find this pair and replace it. However, this is slow because
  the complexity is `O(n*t)`, where `n` is the number of words and `t` is the
  number of tokens needed.

- To speed this up, the original author finds where the pair occurs in the
  original words and stores them. To find the pair to merge, use a priority
  queue.

- The `-O2` compilation flag optimizes the C++ code a lot. Without this flag,
  the run time goes from `10.18s` to `31.5 seconds`.