a: 600851475143;
L: 2 + til[`long$sqrt[a]];
d: L[where[mod[a; L] = 0]];
d: `long$(d, (a % d));
max[d[where[sum[flip[not[mod\:[d;d]]]] = 1]]]
//Solution: 6857
