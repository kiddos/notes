use std::io;
use std::cmp::max;


fn read_int() -> i32 {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    return s.trim().parse::<i32>().expect("invalid input");
}

fn solve() {
    let n = read_int() as usize;
    let mut p = Vec::new();
    for x in 1..(n+1) {
        p.push(x);
    }

    let mut ans: i64 = 0;
    for i in (0..n).rev() {
        let mut p2 = p.clone();
        p2[i..n].reverse();
        
        let mut cost: i64 = 0;
        let mut max_val: i64 = 0;
        for j in 0..n {
            let c = (j+1) as i64 * p2[j] as i64;
            max_val = max(max_val, c);
            cost += c;
        }
        cost -= max_val;
        ans = max(ans, cost);
    }

    println!("{}", ans);
}


fn main() {
    let t = read_int();
    for _t in 0..t {
        solve();
    }
}
