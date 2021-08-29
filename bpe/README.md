Re-implementation of hugging face's BPE tokenizer in c++
======

What I learned from this

- original idea of implement is to iteratively find the pair with the most count
  and for each word find this pair and replace it.
  However, this is slow because the complexity is `O(n*t)`, where n the is number of words and t is the number of tokens
  needed.

- To speed this up, the original author finds where the pair occur in the original words and store them.
  To find the pair to merge, use priority queue.

- -O2 compilation flag optimize the c++ code a lot.
  Without this flag, the run time goes from `10.18s` to `31.5 seconds`
