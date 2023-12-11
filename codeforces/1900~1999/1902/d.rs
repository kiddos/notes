use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeMap;

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<i32>();
    let n = inputs[0] as usize;
    let q = inputs[1];
    let s = read_str();
    let b = s.as_bytes();
    
    let mut x: i32 = 0;
    let mut y: i32 = 0;
    let mut pos: Vec<(i32,i32)> = Vec::new();
    let mut indices: BTreeMap<(i32,i32), Vec<usize>> = BTreeMap::new();
    indices.entry((x, y)).or_insert(vec![0]);
    pos.push((x, y));
    for i in 0..n {
        if b[i] == b'U' {
            y += 1;
        } else if b[i] == b'D' {
            y -= 1;
        } else if b[i] == b'L' {
            x -= 1;
        } else if b[i] == b'R' {
            x += 1;
        }
        let idx = indices.entry((x, y)).or_insert(Vec::new());
        idx.push(i+1);
        pos.push((x, y));
    }

    let query_left = |x: i32, y: i32, l: usize| -> bool {
        let key = (x, y);
        if !indices.contains_key(&key) {
            return false;
        }
        let idx: &Vec<usize> = indices.get(&key).unwrap();
        idx[0] <= l-1
    };

    let query_right = |x: i32, y: i32, r: usize| -> bool {
        let key = (x, y);
        if !indices.contains_key(&key) {
            return false
        }
        let idx: &Vec<usize> = indices.get(&key).unwrap();
        idx[idx.len()-1] >= r+1
    };

    let query_middle = |xi: i32, yi: i32, left: usize, right: usize| -> bool {
        let x = pos[left-1].0 + pos[right].0 - xi;
        let y = pos[left-1].1 + pos[right].1 - yi;
        let key = (x, y);
        if !indices.contains_key(&key) {
            return false;
        }
        let idx: &Vec<usize> = indices.get(&key).unwrap();
        let mut l: i32 = 0;
        let mut r: i32 = (idx.len()-1) as i32;
        let mut x: i32 = -1;
        while l <= r {
            let mid = l + (r-l) / 2;
            if idx[mid as usize] >= (left-1) {
                x = idx[mid as usize] as i32;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        if x < 0 {
            return false;
        }
        x <= right as i32
    };

    let do_query = |xi: i32, yi: i32, l: usize, r: usize| -> bool {
        query_left(xi, yi, l) || query_right(xi, yi, r) || query_middle(xi, yi, l, r)
    };

    for _ in 0..q {
        let query = read_vec::<i32>();
        let result = do_query(query[0], query[1], query[2] as usize, query[3] as usize);
        if result {
            writeln!(writer, "YES").ok();
        } else {
            writeln!(writer, "NO").ok();
        }
    }
}

fn main() {
    solve();
}
