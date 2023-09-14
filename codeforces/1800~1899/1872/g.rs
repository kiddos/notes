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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let n = read_int::<usize>();
    let a = read_vec::<i64>();

    let max_p = (n * 2) as i64;
    let mut p = 1;
    let mut enough = false;
    for i in 0..n {
        p *= a[i];
        if p > max_p {
            enough = true;
            break;
        }
    }

    if enough {
        let mut l = 0;
        let mut r = n-1;
        while l < r && a[l] == 1 {
            l += 1;
        }
        while r > l && a[r] == 1 {
            r -= 1;
        }

        writeln!(writer, "{} {}", l+1, r+1).ok();
        return;
    }

    let mut indices: Vec<usize> = Vec::new();
    for i in 0..n {
        if a[i] > 1 {
            indices.push(i);
        }
    }

    let mut best_value: i64 = a.iter().sum();
    let mut ans: (usize, usize) = (0, 0);

    let mut p: Vec<i64> = vec![1];
    let mut s: Vec<i64> = vec![0];
    for i in 0..n {
        p.push(*p.last().unwrap() * a[i]);
        s.push(*s.last().unwrap() + a[i]);
    }

    let m = indices.len();
    for i in 0..m {
        for j in i..m {
            let i1 = indices[i];
            let i2 = indices[j];
            let value = s[i1] + s[n] - s[i2+1] + p[i2+1] / p[i1];
            if value > best_value {
                best_value = value;
                ans = (i1, i2);
            }
        }
    }

    writeln!(writer, "{} {}", ans.0 + 1, ans.1 + 1).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
