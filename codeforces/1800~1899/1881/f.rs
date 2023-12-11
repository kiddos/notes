use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::Ordering;
use std::cmp::{max, min};

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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let k = inputs[1];
    let a = read_vec::<usize>();
    let mut marked = vec![false; n+1];
    for i in 0..k {
        marked[a[i]] = true;
    }

    let mut adj: Vec<Vec<usize>> = vec![Vec::new(); n+1];
    for _ in 1..n {
        let edge = read_vec::<usize>();
        let u = edge[0];
        let v = edge[1];
        adj[u].push(v);
        adj[v].push(u);
    }

    fn compute_dist(node: usize, parent: usize, adj: &Vec<Vec<usize>>, dist: &mut Vec<i32>) {
        for next_node in &adj[node] {
            if *next_node != parent {
                dist[*next_node] = dist[node] + 1;
                compute_dist(*next_node, node, adj, dist);
            }
        }
    }

    let mut dist0 = vec![0; n+1];
    compute_dist(1, 0, &adj, &mut dist0);

    fn find_marked(dist: &Vec<i32>, marked: &Vec<bool>) -> usize {
        dist
            .iter()
            .enumerate()
            .filter(|&(idx, _)| marked[idx])
            .max_by(|(_, a), (_, b)| a.partial_cmp(b).unwrap_or(Ordering::Equal))
            .map(|(index, _)| index)
            .unwrap()
    }

    let node1 = find_marked(&dist0, &marked);
    let mut dist1 = vec![0; n+1];
    compute_dist(node1, 0, &adj, &mut dist1);

    let node2 = find_marked(&dist1, &marked);
    let mut dist2 = vec![0; n+1];
    compute_dist(node2, 0, &adj, &mut dist2);

    let mut ans = i32::MAX;
    for i in 1..=n {
        let d1 = dist1[i];
        let d2 = dist2[i];
        let f = max(d1, d2);
        ans = min(ans, f);
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
