gcd: {[x;y] $[x = 0; y; gcd[mod[y; x]; x]]}
lcm: {[x;y] `long$((x * y) % gcd[x;y])}
f: (lcm/)[1 + til[20]]; show[f];
//Answer: 232792560
