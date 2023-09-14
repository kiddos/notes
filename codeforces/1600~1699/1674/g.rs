use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::HashSet;
use std::cmp::max;

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn dfs(node: usize, adj: &Vec<Vec<usize>>, depth: &mut Vec<i32>) -> i32 {
    if depth[node] > 0 {
        return depth[node];
    }

    let mut ans: i32 = 1;
    for next_node in &adj[node] {
        ans = max(ans, dfs(*next_node, adj, depth) + 1);
    }
    depth[node] = ans;
    ans
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let m = inputs[1];

    let mut edges: Vec<(i32, i32)> = Vec::new();
    let mut in_degree: Vec<i32> = vec![0; n+1];
    let mut out_degree: Vec<i32> = vec![0; n+1];
    for _i in 0..m {
        let edge = read_vec::<i32>();
        edges.push((edge[0], edge[1]));

        in_degree[edge[1] as usize] += 1;
        out_degree[edge[0] as usize] += 1;
    }

    let mut remove: HashSet<usize> = HashSet::new();
    for i in 0..m {
        let u = edges[i].0 as usize;
        let v = edges[i].1 as usize;
        if in_degree[v] == 1 {
            remove.insert(i);
        }
        if out_degree[u] == 1 {
            remove.insert(i);
        }
    }

    let mut adj: Vec<Vec<usize>> = vec![Vec::new(); n+1];
    for i in 0..m {
        if remove.contains(&i) {
            continue;
        }

        let u = edges[i].0 as usize;
        let v = edges[i].1 as usize;
        adj[u].push(v);
    }

    let mut depth: Vec<i32> = vec![0; n+1];
    let mut ans: i32 = 0;
    for node in 1..=n {
        ans = max(ans, dfs(node, &adj, &mut depth));
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    solve();
}
