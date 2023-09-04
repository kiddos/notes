use std::io;
use std::cmp::max;
use std::collections::BTreeMap;

fn read_int() -> i32 {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    return s.trim().parse::<i32>().expect("invalid input");
}

fn read_vec() -> Vec<i32> {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|s| s.trim().parse::<i32>().expect("invalid input")).collect()
}

fn solve() {
    let n = read_int();
    let mut portals: Vec<Vec<i32>> = Vec::new();
    for _i in 0..n {
        let values = read_vec();
        portals.push(values);
    }

    let q = read_int();
    let query = read_vec();

    let mut events: Vec<[i32; 3]> = Vec::new();
    let mut can_reach: Vec<i32> = vec![0; n as usize];
    for i in 0..n {
        let l = portals[i as usize][0];
        let b = portals[i as usize][3];
        events.push([l, 0, i]);
        events.push([b, 2, i]);
        can_reach[i as usize] = max(l, b);
    }

    let mut ans: Vec<i32> = vec![0; q as usize];
    for i in 0..q {
        let x = query[i as usize];
        events.push([x, 1, i]);
        ans[i as usize] = x;
    }

    events.sort();
    events.reverse();
    let mut m: BTreeMap<i32, i32> = BTreeMap::new();
    for i in 0..events.len() {
        let event_type = events[i][1];
        let index = events[i][2] as usize;

        if event_type == 2 {
            if let Some(max_key_value) = m.last_key_value() {
                can_reach[index] = max(can_reach[index], *max_key_value.0);
            }
            // enter
            match m.get(&can_reach[index]) {
                Some(count) => m.insert(can_reach[index], count+1),
                None => m.insert(can_reach[index], 1),
            };
        } else if event_type == 1 {
            // query
            if let Some(max_key_value) = m.last_key_value() {
                ans[index] = max(ans[index], *max_key_value.0);
            }
        } else if event_type == 0 {
            // leave
            if let Some(count) = m.get(&can_reach[index]) {
                if *count == 1 {
                    m.remove(&can_reach[index]);
                } else {
                    m.insert(can_reach[index], count-1);
                }
            };
        }
    }

    for i in 0..q {
        print!("{} ", ans[i as usize]);
    }
    println!();
}


fn main() {
    let t = read_int();
    for _t in 0..t {
        solve();
    }
}
