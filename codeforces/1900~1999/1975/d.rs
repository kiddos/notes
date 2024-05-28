use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::VecDeque;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    if s.is_empty() {
        return Vec::new();
    }
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn compute_dist(node: usize, parent: usize, adj: &Vec<Vec<usize>>, d: &mut Vec<i32>) {
    for &next_node in adj[node].iter() {
        if next_node == parent {
            continue;
        }

        d[next_node] = d[node] + 1;
        compute_dist(next_node, node, adj, d);
    }
}

fn find_meeting_point(b: usize, adj: &Vec<Vec<usize>>, a_dist: &Vec<i32>) -> usize {
    let n = adj.len();
    let mut q = VecDeque::new();
    q.push_back(b);
    let mut visited = vec![false; n+1];
    let mut step = 0;
    while !q.is_empty() {
        let size = q.len();
        for _i in 0..size {
            if let Some(node) = q.pop_front() {
                if a_dist[node] <= step {
                    return node;
                }

                for &next_node in adj[node].iter() {
                    if visited[next_node] {
                        continue;
                    }
                    visited[next_node] = true;
                    q.push_back(next_node);
                }
            }
        }
        step += 1;
    }
    0
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let inputs = read_vec::<usize>();
    let a = inputs[0];
    let b = inputs[1];

    let mut adj = vec![Vec::new(); n+1];
    for _i in 1..n {
        let edge = read_vec::<usize>();
        let u = edge[0];
        let v = edge[1];
        adj[u].push(v);
        adj[v].push(u);
    }
    
    let mut a_dist = vec![0; n+1];
    compute_dist(a, 0, &adj, &mut a_dist);
    let mut b_dist = vec![0; n+1];
    compute_dist(b, 0, &adj, &mut b_dist);

    let meet = find_meeting_point(b, &adj, &a_dist);
    let mut meet_dist = vec![0; n+1];
    compute_dist(meet, 0, &adj, &mut meet_dist);

    let d = *meet_dist.iter().max().unwrap();
    let ans = 2 * (n as i32 - 1) - d + b_dist[meet];
    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
