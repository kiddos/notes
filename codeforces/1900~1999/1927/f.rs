use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

struct DisjointSet {
    parent: Vec<usize>,
    rank: Vec<i32>,
}

impl DisjointSet {
    fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
            rank: vec![0; n],
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]);
        }
        self.parent[x]
    }

    fn join(&mut self, x: usize, y: usize) -> bool {
        let px = self.find(x);
        let py = self.find(y);
        if px == py {
            return false;
        }
        if self.rank[px] > self.rank[py] {
            self.parent[py] = px;
        } else if self.rank[py] > self.rank[px] {
            self.parent[px] = py;
        } else {
            self.parent[py] = px;
            self.rank[px] += 1;
        }

        true
    }
}

fn dfs(node: usize, p: usize, target: usize, adj: &Vec<Vec<usize>>, path: &mut Vec<usize>) -> bool {
    if node == target {
        return true;
    }
    for next_node in adj[node].iter() {
        if *next_node == p {
            continue;
        }

        path.push(*next_node);
        if dfs(*next_node, node, target, adj, path) {
            return true;
        }
        path.pop();
    }
    false
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let m = inputs[1];

    let mut edges: Vec<(usize, usize, usize)> = Vec::new();
    for _i in 0..m {
        let edge = read_vec::<usize>();
        let u = edge[0];
        let v = edge[1];
        let w = edge[2];
        edges.push((w, u, v));
    }
    edges.sort();
    edges.reverse();

    let mut ds = DisjointSet::new(n+1);
    let mut adj: Vec<Vec<usize>> = vec![Vec::new(); n+1];
    let mut min_w: i32 = i32::MAX;
    let mut start: usize = 0;
    let mut end: usize = 0;
    for i in 0..edges.len() {
        let w = edges[i].0;
        let u = edges[i].1;
        let v = edges[i].2;
        if ds.join(u, v) {
            adj[u].push(v);
            adj[v].push(u);
        } else {
            start = u;
            end = v;
            min_w = w as i32;
        }
    }
    
    let mut path = vec![start];
    dfs(start, 0, end, &adj, &mut path);

    writeln!(writer, "{} {}", min_w, path.len()).ok();
    for i in 0..path.len() {
        write!(writer, "{} ", path[i]).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
