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
    if s.is_empty() {
        return Vec::new();
    }
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<i32>();
    let n = inputs[0];
    let k = inputs[1];

    let mut ans = Vec::new();
    let mut msb = 0;
    for b in 0..31 {
        if (k & (1 << b)) > 0 {
            msb = b;
        }
    }
    for b in 0..31 {
        if (1 << b) > n {
            break;
        }
        if b == msb {
            continue;
        }
        ans.push(1 << b);
    }
    ans.push(k ^ (1 << msb));
    ans.push(k+1);
    ans.push(k + 1 + (1 << msb));

    writeln!(writer, "{}", ans.len()).ok();
    for i in 0..ans.len() {
        write!(writer, "{} ", ans[i]).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
