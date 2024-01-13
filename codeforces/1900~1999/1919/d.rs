use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BinaryHeap;
use std::cmp::min;

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

struct Node {
    x: i32,
    l: i32,
    r: i32,
    deleted: bool,
}

fn should_remove(i: i32, nodes: &Vec<Node>) -> bool {
    let n = nodes.len();
    if i < 0 || i >= n as i32 {
        return false;
    }
    let i = i as usize;
    let l = nodes[i].l;
    let r = nodes[i].r;
    let x = nodes[i].x;
    (l >= 0 && nodes[l as usize].x == x-1) || (r < n as i32 && nodes[r as usize].x == x-1)
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let a = read_vec::<i32>();
    let mut nodes: Vec<Node> = Vec::new();
    for i in 0..n {
        nodes.push(Node{
            x: a[i],
            l: i as i32 - 1,
            r: i as i32 + 1,
            deleted: false,
        });
    }


    let mut pq: BinaryHeap<(i32,i32)> = BinaryHeap::new();
    for i in 0..n {
        if should_remove(i as i32, &nodes) {
            pq.push((nodes[i].x, i as i32));
        }
    }

    while !pq.is_empty() {
        if let Some(item) = pq.pop() {
            let idx = item.1 as usize;

            if nodes[idx].deleted {
                continue;
            }
            
            nodes[idx].deleted = true;
            let l = nodes[idx].l;
            let r = nodes[idx].r;
            if l >= 0 {
                nodes[l as usize].r = r;
            }
            if r < n as i32 {
                nodes[r as usize].l = l;
            }

            if should_remove(l, &nodes) {
                pq.push((nodes[l as usize].x, l));
            }
            if should_remove(r, &nodes) {
                pq.push((nodes[r as usize].x, r));
            }
        }
    }

    let mut left = 0;
    let mut min_val = i32::MAX;
    for i in 0..n {
        if !nodes[i].deleted {
            left += 1;
            min_val = min(min_val, nodes[i].x);
        }
    }

    if left == 1 && min_val == 0 {
        writeln!(writer, "YES").ok();
    } else {
        writeln!(writer, "NO").ok();
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
