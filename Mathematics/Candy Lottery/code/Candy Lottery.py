n, k = map(int, input().strip().split())

ans = 0.0
for i in range(1, k + 1):
    add, sub = 1.0, 1.0
    
    for j in range(1, n + 1):
        add *= i / k
        sub *= (i - 1) / k

    ans += i * (add - sub)

ans *= 1000000
ans = round(ans)
ans /= 1000000
print("{0:.6f}".format(ans))
