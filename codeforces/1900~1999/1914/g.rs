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
    let c = read_vec::<i32>();
    
    let m = n * 2;
    let mut last: Vec<i32> = vec![-1; n+1];
    let mut s: Vec<(i32, i32, i32)> = Vec::new();
    let mut ans1: i32 = 0;
    let mut ans2: i64 = 1;
    let k_mod = 998244353;
    for i in 0..m {
        if last[c[i] as usize] < 0 {
            last[c[i] as usize] = i as i32;
            s.push((i as i32, 1, 1));
        } else {
            let mut count: i32 = 1;
            let mut end: i32 = -1;
            let l = last[c[i] as usize] as i32;
            while !s.is_empty() && s[s.len()-1].0 > l {
                count += s[s.len()-1].1 as i32;
                end += s[s.len()-1].2 as i32;
                s.pop();
            }

            let size = s.len();
            count += s[size-1].1;
            end += s[size-1].2;
            s[size-1] = (s[size-1].0, count, end);
            if end == 0 {
                s.pop();
                if s.is_empty() {
                    ans1 += 1;
                    ans2 *= count as i64;
                    ans2 %= k_mod;
                }
            }
        }
    }

    writeln!(writer, "{} {}", ans1, ans2).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
