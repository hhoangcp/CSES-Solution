# String Functions - Lời giải

**ID:** 2107 | **URL:** https://cses.fi/problemset/task/2107

## Đề bài

Cho chuỗi $s$ độ dài $n$ (vị trí $1..n$, ký tự 'a'–'z'). Tính và in hai hàm:
- $z(i)$: độ dài lớn nhất của chuỗi con bắt đầu tại $i$ và là tiền tố của $s$; quy ước $z(1)=0$.
- $\pi(i)$: độ dài lớn nhất của chuỗi con kết thúc tại $i$, là tiền tố của $s$, có độ dài $\le i-1$ (hậu tố riêng dài nhất của $s[1..i]$ trùng với tiền tố).

In hai dòng: trước các giá trị $z$, sau các giá trị $\pi$.

## Hướng tiếp cận

### Bước 1: Hàm Z

$Z[i] = \max\{k : s[i..i+k-1] = s[1..k]\}$, với $Z[1] = 0$. Duy trì đoạn $[L, R]$ xa nhất về bên phải đang khớp tiền tố ($s[L..R] = s[1..R-L+1]$). Với $i$ từ $2$ đến $n$:

1. **Khởi tạo:** nếu $i \le R$, tận dụng đối xứng qua $L$ (vị trí đối xứng $i-L+1$): $Z[i] = \min(Z[i-L+1], R-i+1)$ — giá trị đối xứng đã biết, bị chặn bởi biên $R$ (phần ngoài $R$ chưa kiểm tra). Nếu $i > R$, đặt $Z[i]=0$.
2. **Mở rộng:** tăng $Z[i]$ khi $s[i+Z[i]] = s[Z[i]+1]$.
3. **Cập nhật:** nếu $i + Z[i] - 1 > R$, đặt $L = i$, $R = i + Z[i] - 1$.

### Bước 2: Hàm tiền tố

$\pi[i] = \max\{k : 1 \le k < i, s[1..k] = s[i-k+1..i]\}$, với $\pi[1] = 0$. Với $i$ từ $2$ đến $n$:

1. Đặt $j = \pi[i-1]$ (độ dài khớp lớn nhất tại vị trí trước).
2. Trong khi $j > 0$ và $s[i] \neq s[j+1]$, lùi $j = \pi[j]$.
3. Nếu $s[i] = s[j+1]$, tăng $j$ lên 1.
4. Đặt $\pi[i] = j$.

**Tính đúng của bước lùi:** từ $j = \pi[i-1]$ ta có $s[1..j] = s[i-j..i-1]$. Nếu $s[i] \neq s[j+1]$, tiền tố dài $j+1$ không khớp; cần tìm tiền tố ngắn hơn $j' < j$ vẫn là hậu tố của $s[1..i-1]$ và có thể khớp tiếp với $s[i]$. Vì mọi hậu tố của $s[1..j]$ trùng tiền tố đều được $\pi$ quản lý, ứng cử viên dài nhất tiếp theo đúng là $j' = \pi[j]$. Lặp lại cho đến khi khớp hoặc $j=0$.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"abaabca"}$ ($n = 7$).

| $i$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| $s[i]$ | a | b | a | a | b | c | a |
| $Z[i]$ | 0 | 0 | 1 | 2 | 0 | 0 | 1 |
| $\pi[i]$ | 0 | 0 | 1 | 1 | 2 | 0 | 1 |

Một số giá trị đáng chú ý:
- $Z[4] = 2$: $s[4..5] = \text{"ab"} = s[1..2]$, rồi dừng vì $s[6]=\text{c} \neq s[3]=\text{a}$.
- $Z[7] = 1$: $s[7] = \text{"a"} = s[1]$.
- $\pi[5] = 2$: tiền tố $\text{"ab"}$ (độ dài 2) vừa là hậu tố của $s[1..5] = \text{"abaab"}$ ($s[4..5]$).
- $\pi[7] = 1$: tiền tố $\text{"a"}$ là hậu tố của $s[1..7] = \text{"abaabca"}$ ($s[7]$).

Kết quả:
```
0 0 1 2 0 0 1
0 0 1 1 2 0 1
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ với hàm Z, mỗi bước mở rộng thành công tăng biên phải $R$ lên ít nhất 1 và $R \le n$; với hàm $\pi$, con trỏ $j$ tăng nhiều nhất $n$ lần (mỗi vị trí tăng nhiều nhất 1) và mỗi lần giảm bớt ít nhất 1 nên tổng giảm $\le n$. Cả hai đều tuyến tính.
- **Bộ nhớ:** $O(n)$ $\textemdash$ lưu hai mảng $Z$ và $\pi$.

## Mã nguồn (C++)

[Mã nguồn](../code/String%20Functions.cpp)
