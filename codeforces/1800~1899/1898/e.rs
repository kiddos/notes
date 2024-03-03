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

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let m = inputs[1];

    let s = read_str().as_bytes().to_vec();
    let t = read_str().as_bytes().to_vec();

    let mut indices: Vec<Vec<usize>> = vec![Vec::new(); 26];
    for i in (0..n).rev() {
        let c = (s[i] - b'a') as usize;
        indices[c].push(i);
    }

    for i in 0..m {
        let c = (t[i] - b'a') as usize;

        if let Some(k) = indices[c].pop() {
            for c2 in 0..c {
                while !indices[c2].is_empty() && *indices[c2].last().unwrap() <= k {
                    indices[c2].pop();
                }
            }
        } else {
            writeln!(writer, "NO").ok();
            return;
        }
    }

    writeln!(writer, "YES").ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
