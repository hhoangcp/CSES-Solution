from functools import reduce

n = int(input())
r = list(map(int, input().split()))

denominator = reduce(lambda x, y: x * y, r, 1)

numerator = 0

for i in range(n):
    for j in range(i + 1, n):
        if r[i] <= r[j]:
            numerator += (denominator//r[j]) * (r[i] - 1)
        else:
            numerator += (denominator//r[i]) * ((r[i] - r[j]) * 2 + r[j] - 1)
denominator *= 2

int_part = numerator // denominator
numerator %= denominator

P = 300
dec_part = numerator * (10 ** (P + 6)) // denominator
if dec_part % (10 ** P) > (10 ** (P - 1)) * 5:
    dec_part //= 10 ** P
    dec_part += 1
elif dec_part % (10 ** P) < (10 ** (P - 1)) * 5:
    dec_part //= 10 ** P
else:
    dec_part //= 10 ** P
    if dec_part % 2 == 1:
        dec_part += 1
if dec_part == 1000000:
    int_part += 1
    dec_part = 0

print(int_part, '.', f'{dec_part:06}', sep='')