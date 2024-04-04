use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::min;

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

fn greater(x: (i64, i64), y: (i64, i64)) -> bool {
    x.0 * y.1 > x.1 * y.0
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let mut m = vec![0; n];
    let mut k = vec![0; n];
    for i in 0..n {
        let row = read_vec::<i32>();
        m[i] = row[0];
        k[i] = row[1];
    }

    let max_k = *k.iter().max().unwrap();
    let max_m = *m.iter().max().unwrap();

    let mut best: (i64, i64) = (0, 1);
    let mut ans = Vec::new();
    for t in 1..=max_k {
        if t > max_m {
            break;
        }

        let mut score = vec![0; max_m as usize + 1];
        for i in 0..n {
            score[m[i] as usize] += min(t, k[i]);
        }

        let mut p = Vec::new();
        for i in 0..=max_m as usize {
            p.push((score[i], i));
        }

        p.sort();
        p.reverse();
        let mut total = 0;
        let mut list = Vec::new();
        for i in 0..t {
            total += p[i as usize].0 as i64;
            list.push(p[i as usize].1);
        }

        if greater((total, t as i64), best) {
            best = (total, t as i64);
            ans = list;
        }
    }

    writeln!(writer, "{}", ans.len()).ok();
    for i in 0..ans.len() {
        write!(writer, "{} ", ans[i]).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    solve();
}
