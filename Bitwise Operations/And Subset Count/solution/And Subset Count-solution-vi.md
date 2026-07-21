# And Subset Count - Lời giải

**ID:** 3141 | **URL:** https://cses.fi/problemset/task/3141

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, với mỗi $k = 0, 1, \ldots, n$, tính số tập con không rỗng có phép AND bit bằng $k$, lấy modulo $10^9 + 7$.

### Ý tưởng chính

Phép AND của tập con bằng $k$ iff mọi phần tử chứa các bit 1 của $k$ (tức mỗi phần tử là **siêu tập** của $k$) và không có bit 0 nào của $k$ được đặt đồng thời trong mọi phần tử. Dùng **SOS DP** để đếm siêu tập của mỗi mask, rồi **nghịch đảo Möbius** (SOS ngược) để trích số tập con có AND đúng bằng mask qua bao hàm-loại trừ trên mạng Boolean.

### Thuật toán

1. **Khởi tạo:** Với mỗi phần tử $a_i$, tăng $dp[a_i]$ lên 1. Lúc này $dp[mask]$ đếm số phần tử bằng $mask$.
2. **SOS DP thuận — đếm siêu tập:** Với mỗi bit $i$ từ $0$ đến $H-1$, nếu bit $i$ được đặt trong $mask$: $dp[mask \oplus 2^i] \mathrel{+}= dp[mask]$. Sau bước này, $dp[mask]$ = số phần tử là siêu tập của $mask$ (tức $a_i \wedge mask = mask$). Quan sát chính: nếu $a_i$ là siêu tập của $mask$ thì cũng là siêu tập của mọi mặt con, nên số lượng lan truyền xuống.
3. **Đếm tập con có AND chứa $mask$:** $ans[mask] = 2^{dp[mask]} - 1$. Mọi tập con không rỗng từ $dp[mask]$ phần tử siêu tập đều có AND chứa $mask$ (vì AND của các siêu tập vẫn là siêu tập), và đây là tất cả tập con như vậy. Vậy $ans[mask] = \sum_{mask \subseteq s} f[s]$ với $f[s]$ là số tập con có AND đúng bằng $s$.
4. **Nghịch đảo Möbius — kết quả đúng bằng mask:** Theo bao hàm-loại trừ trên mạng Boolean, $f[mask] = g[mask] - \sum_{mask \subset s} f[s]$ với $g[mask]$ là giá trị trước nghịch đảo. Đây chính là SOS DP ngược: với mỗi bit $i$, nếu bit $i$ được đặt trong $mask$: $ans[mask \oplus 2^i] \mathrel{-}= ans[mask]$. Sau bước này, $ans[mask]$ là số tập con có AND đúng bằng $mask$.

### Ví dụ minh họa

Đầu vào: $n = 4$, mảng $[3, 1, 3, 4]$.

**Bước 1:** $dp[1] = 1$, $dp[3] = 2$, $dp[4] = 1$ (còn lại $0$).

**Bước 2 — SOS thuận (hiện mask $0$–$7$):**

| $mask$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| Sau bit 0 | 1 | 1 | 0 | 2 | 1 | 0 | 0 | 0 |
| Sau bit 1 | 3 | 3 | 2 | 2 | 1 | 0 | 0 | 0 |
| Sau bit 2 | **4** | **3** | **2** | **2** | **1** | 0 | 0 | 0 |

Các giá trị chính: $dp[0]=4$ (tất cả ⊃ 0), $dp[1]=3$ (1,3,3 ⊃ 1), $dp[3]=2$ (3,3 ⊃ 3), $dp[4]=1$ (4 ⊃ 4).

**Bước 3:** $ans[mask] = 2^{dp[mask]} - 1$: $ans[0]=15$, $ans[1]=7$, $ans[2]=3$, $ans[3]=3$, $ans[4]=1$.

**Bước 4 — Nghịch đảo Möbius (trừ đóng góp siêu tập):**

- Bit 2: $ans[0] -= ans[4] \Rightarrow 14$; $ans[1] -= ans[5] \Rightarrow 7$; $ans[2] -= ans[6] \Rightarrow 3$; $ans[3] -= ans[7] \Rightarrow 3$.
- Bit 1: $ans[0] -= ans[2] \Rightarrow 11$; $ans[1] -= ans[3] \Rightarrow 4$; $ans[4] -= ans[6] \Rightarrow 1$; $ans[5] -= ans[7] \Rightarrow 0$.
- Bit 0: $ans[0] -= ans[1] \Rightarrow 7$; $ans[2] -= ans[3] \Rightarrow 0$; $ans[4] -= ans[5] \Rightarrow 1$; $ans[6] -= ans[7] \Rightarrow 0$.

Kết quả: $ans[0]=7$, $ans[1]=4$, $ans[2]=0$, $ans[3]=3$, $ans[4]=1$.

Output: `7 4 0 3 1`.

## Độ phức tạp

- **Thời gian:** $O(n + H \cdot 2^H)$ với $H = 18$
- **Không gian:** $O(2^H)$

## Mã nguồn (C++)

[Mã nguồn](../code/And%20Subset%20Count.cpp)
