use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeMap;
use std::cmp::min;

const INF: i32 = 1000000000;

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn dp(a: u32, b: u32, c: u32, d: u32, x0: i64, n: usize, memo: &mut BTreeMap<(u32,u32,u32,u32), i32>) -> i32 {
    let key = (a, b, c, d);
    if let Some(value) = memo.get(&key) {
        return *value;
    }

    let x = x0 * 2_i64.pow(a) * 3_i64.pow(b) * 5_i64.pow(c) * 7_i64.pow(d);
    let s = x.to_string();
    if s.len() == n {
        memo.insert(key, 0);
        return 0;
    }

    let mut ans = INF;
    for ch in s.chars() {
        let mut y = (ch as u8 - b'0') as i32;
        if y < 2 {
            continue;
        }

        let mut a2 = a;
        let mut b2 = b;
        let mut c2 = c;
        let mut d2 = d;
        while y % 2 == 0 {
            a2 += 1;
            y /= 2;
        }

        while y % 3 == 0 {
            b2 += 1;
            y /= 3;
        }

        while y % 5 == 0 {
            c2 += 1;
            y /= 5;
        }

        while y % 7 == 0 {
            d2 += 1;
            y /= 7;
        }

        ans = min(ans, dp(a2, b2, c2, d2, x0, n, memo) + 1);
    }

    memo.insert(key, ans);
    ans
}

fn solve() {
    let inputs = read_vec::<i64>();
    let n = inputs[0] as usize;
    let x0 = inputs[1] as i64;

    let mut memo: BTreeMap<(u32,u32,u32,u32), i32> = BTreeMap::new();
    let ans = dp(0, 0, 0, 0, x0, n, &mut memo);

    if ans >= INF {
        println!("-1");
    } else {
        println!("{}", ans);
    }
}

fn main() {
    solve();
}
