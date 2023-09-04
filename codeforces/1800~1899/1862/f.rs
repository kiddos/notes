use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
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

    let inputs = read_vec::<i64>();
    let w = inputs[0];
    let f = inputs[1];
    let n = read_int::<usize>();
    let s = read_vec::<i64>();

    let sum = s.iter().sum::<i64>() as usize;
    let mut dp: Vec<bool> = vec![false; sum+1];
    dp[0] = true;
    for i in 0..n {
        for a in (0..=sum).rev() {
            if dp[a] && a + s[i] as usize <= sum {
                dp[a + s[i] as usize] = true;
            }
        }
    }

    let mut ans = i32::MAX as i64;
    for a in 0..=sum {
        if dp[a] {
            let group1 = a as i64;
            let group2 = (sum - a) as i64;

            let mut water = (group1 + w - 1) / w;
            let mut fire = (group2 + f - 1) / f;
            let mut require = max(water, fire);
            ans = min(ans, require);

            water = (group2 + w - 1) / w;
            fire = (group1 + f - 1) / f;
            require = max(water, fire);
            ans = min(ans, require);
        }
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
