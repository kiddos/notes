use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;
 
fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}
 
fn top_sort(node: usize, adj: &Vec<Vec<i32>>, visited: &mut Vec<bool>, nodes: &mut Vec<i32>) {
    if visited[node] {
        return;
    }
    visited[node] = true;
 
    for next_node in &adj[node] {
        top_sort(*next_node as usize, adj, visited, nodes);
    }
    nodes.push(node as i32);
}
 
fn dfs(node: usize, max_val: i32, k: i64, a: &Vec<i32>, adj: &Vec<Vec<i32>>, visited: &mut Vec<bool>, memo: &mut Vec<i64>) -> i64 {
    if a[node] > max_val {
        return 0;
    }
 
    if memo[node] >= 0 {
        return memo[node];
    }
 
    if visited[node] {
        return k;
    }
    visited[node] = true;
    let mut ans: i64 = 1;
    for next_node in &adj[node] {
        ans = max(ans, dfs(*next_node as usize, max_val, k, a, adj, visited, memo) + 1);
    }
    visited[node] = false;
    memo[node] = ans;
    ans
}
 
fn path_found(max_val: i32, k: i64, nodes: &Vec<i32>, a: &Vec<i32>, adj: &Vec<Vec<i32>>) -> bool {
    let n = a.len();
    let mut visited: Vec<bool> = vec![false; n+1];
    let mut memo: Vec<i64> = vec![-1; n+1];
 
    for node in nodes {
        let len = dfs(*node as usize, max_val, k, a, adj, &mut visited, &mut memo);
        if len >= k {
            return true;
        }
    }
    false
}
 
fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
 
    let inputs = read_vec::<i64>();
    let n = inputs[0] as usize;
    let m = inputs[1] as usize;
    let k = inputs[2];
 
    let mut a = read_vec::<i32>();
    a.insert(0, 0);
    let mut adj: Vec<Vec<i32>> = vec![Vec::new(); n+1];
    for _i in 0..m {
        let edge = read_vec::<i32>();
        let u = edge[0];
        let v = edge[1];
        adj[u as usize].push(v);
    }
 
    let mut nodes: Vec<i32> = Vec::new();
    let mut visited: Vec<bool> = vec![false; n+1];
 
    for node in 1..=n {
        if !visited[node] {
            top_sort(node, &adj, &mut visited, &mut nodes);
        }
    }
 
    nodes.reverse();
 
    let mut l = *a.iter().min().unwrap();
    let mut r = *a.iter().max().unwrap();
    let mut ans = -1;
    while l <= r {
        let mid = l + (r-l) / 2;
        if path_found(mid, k, &nodes, &a, &adj) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
 
    writeln!(writer, "{}", ans).ok();
}
 
fn main() {
    solve();
}
