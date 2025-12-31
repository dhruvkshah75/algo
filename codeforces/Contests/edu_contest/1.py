t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()
    g = a[-1]
    s = a[-2]

    ans = 0

    for k in range(2, n):
        p1 = 2 * a[k]
        p2 = s if k == n - 1 else g
        P = max(p1, p2) - a[k]

        l, r = 0, k - 1
        while l < r:
            if a[l] + a[r] > P:
                ans += (r - l)
                r -= 1
            else:
                l += 1
    print(ans)