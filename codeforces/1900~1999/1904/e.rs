use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::{min, max};

struct SegmentTree {
    data: Vec<i32>,
    lazy: Vec<i32>,
}

impl SegmentTree {
    fn new(n: usize) -> Self {
        Self {
            data: vec![0; n*4],
            lazy: vec![0; n*4],
        }
    }

    fn update(&mut self, i: usize, tl: i32, tr: i32, l: i32, r: i32, x: i32) {
        if tl > r || tr < l {
            return;
        }
        if tl >= l && tr <= r {
            self.data[i] += x;
            self.lazy[i] += x;
            return;
        }
        self.push(i, tl, tr);
        let tm = tl + (tr - tl) / 2;
        if tl <= tm {
            self.update(i * 2 + 1, tl, tm, l, r, x);
        }
        if tr >= tm+1 {
            self.update(i * 2 + 2, tm+1, tr, l, r, x);
        }
        self.data[i] = max(self.data[i * 2 + 1], self.data[i * 2 + 2]);
    }

    fn query_max(&mut self, i: usize, tl: i32, tr: i32, ql: i32, qr: i32) -> i32 {
        if tl > qr || tr < ql {
            return 0;
        }

        if tl >= ql && tr <= qr {
            return self.data[i];
        }

        self.push(i, tl, tr);
        let tm = tl + (tr - tl) / 2;

        max(self.query_max(i * 2 + 1, tl, tm, ql, min(qr, tm)),
            self.query_max(i * 2 + 2, tm + 1, tr, max(ql, tm+1), qr))
    }

    fn push(&mut self, i: usize, tl: i32, tr: i32) {
        if self.lazy[i] != 0 {
            if tl != tr {
                self.data[i * 2 + 1] += self.lazy[i];
                self.lazy[i * 2 + 1] += self.lazy[i];

                self.data[i * 2 + 2] += self.lazy[i];
                self.lazy[i * 2 + 2] += self.lazy[i];
            }
            self.lazy[i] = 0;
        }
    }
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let q = inputs[1];

    let mut adj: Vec<Vec<usize>> = vec![Vec::new(); n+1];
    for _ in 1..n {
        let edge = read_vec::<usize>();
        let u = edge[0];
        let v = edge[1];
        adj[u].push(v);
        adj[v].push(u);
    }

    let mut queries: Vec<Vec<usize>> = Vec::new();
    let mut query_indices: Vec<Vec<usize>> = vec![Vec::new(); n+1];
    for i in 0..q {
        let q = read_vec::<usize>();
        let a: Vec<usize> = q[2..].iter().map(|val| *val).collect();
        queries.push(a);
        query_indices[q[0]].push(i);
    }

    fn dfs1(node: usize, parent: usize, adj: &Vec<Vec<usize>>, t_in: &mut Vec<i32>, t_out: &mut Vec<i32>, t: &mut i32) {
        *t += 1;
        t_in[node] = *t;
        for next_node in &adj[node] {
            if *next_node == parent {
                continue;
            }

            dfs1(*next_node, node, adj, t_in, t_out, t);
        }
        t_out[node] = *t;
    }

    let mut t_in = vec![0; n+1];
    let mut t_out = vec![0; n+1];
    let mut t = 0;
    dfs1(1, 0, &adj, &mut t_in, &mut t_out, &mut t);

    let mut tree = SegmentTree::new((t+1) as usize);
    for node in 2..=n {
        tree.update(0, 0, t, t_in[node], t_out[node], 1);
    }

    // for node in 1..=n {
    //     println!("node: {} {}-{} depth: {}", node, t_in[node], t_out[node], tree.query_max(0, 0, t, t_in[node], t_out[node]));
    // }
    // println!();

    fn process_query(current_node: usize, a: &Vec<usize>, t_in: &Vec<i32>, t_out: &Vec<i32>, t_max: i32, next: &Vec<usize>, tree: &mut SegmentTree, ans: &mut i32) {
        let mut skips: Vec<(i32,i32)> = Vec::new();
        for node in a.iter() {
            if *node == current_node {
                return;
            }

            if t_in[*node] <= t_in[current_node] && t_out[current_node]  <= t_out[*node] {
                let next_node = next[*node];
                // ancestor
                skips.push((0, t_in[next_node]-1));
                skips.push((t_out[next_node]+1, t_max));
            } else {
                skips.push((t_in[*node], t_out[*node]));
            }
        }

        skips.sort();
        let mut prev: i32 = 0;
        for (l, r) in skips.iter() {
            if prev < *l {
                // println!("{}-{} = {}", prev, *l-1, tree.query_max(0, 0, t_max, prev, *l-1));
                *ans = max(*ans, tree.query_max(0, 0, t_max, prev, *l-1))
            }
            prev = max(prev, *r+1);
        }
        if prev <= t_max {
            // println!("{}-{} = {}", prev, t_max, tree.query_max(0, 0, t_max, prev, t_max));
            *ans = max(*ans, tree.query_max(0, 0, t_max, prev, t_max));
        }
    }

    fn dfs2(node: usize, parent: usize, adj: &Vec<Vec<usize>>, t_max: i32, tree: &mut SegmentTree, t_in: &Vec<i32>, t_out: &Vec<i32>, next: &mut Vec<usize>, queries: &Vec<Vec<usize>>, query_indices: &Vec<Vec<usize>>, ans: &mut Vec<i32>) {
        for qi in query_indices[node].iter() {
            // println!("node = {}, index= {}", node, *qi);
            process_query(node, &queries[*qi], t_in, t_out, t_max, next, tree, &mut ans[*qi]);
        }

        // println!("node: {} {}-{} depth: {}", node, t_in[node], t_out[node], tree.query_max(0, 0, t_max, t_in[node], t_out[node]));

        tree.update(0, 0, t_max, 1, t_max, 1);
        for next_node in &adj[node] {
            if *next_node == parent {
                continue;
            }

            let t1 = t_in[*next_node as usize];
            let t2 = t_out[*next_node as usize];
            tree.update(0, 0, t_max, t1, t2, -2);

            next[node] = *next_node;
            dfs2(*next_node, node, adj, t_max, tree, t_in, t_out, next, queries, query_indices, ans);
            tree.update(0, 0, t_max, t1, t2, 2);
        }
        tree.update(0, 0, t_max, 1, t_max, -1);
    }

    let mut ans = vec![0; q];
    let mut next = vec![0; n+1];
    dfs2(1, 0, &adj, t, &mut tree, &t_in, &t_out, &mut next, &queries, &query_indices, &mut ans);


    for i in 0..q {
        writeln!(writer, "{}", ans[i]).ok();
    }
}

fn main() {
    solve();
}
