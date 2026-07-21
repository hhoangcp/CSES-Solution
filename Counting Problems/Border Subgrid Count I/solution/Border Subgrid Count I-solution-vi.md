# Border Subgrid Count I - Lời giải

**ID:** 3417 | **URL:** https://cses.fi/problemset/task/3417

## Phương pháp

### Tóm tắt bài toán

Cho lưới $n \times n$ trong đó mỗi ô chứa một trong $k$ chữ cái in hoa đầu tiên, đếm — với mỗi chữ cái $c$ — số lượng lưới con hình vuông có toàn bộ 4 đường viền là chữ cái $c$.

### Điều kiện viền qua mảng độ dài chạy

Hình vuông góc trên trái $(i, j)$ kích thước $s$ có viền toàn chữ $c$ khi và chỉ khi:

| Viền | Điều kiện | Ý nghĩa |
|------|----------|---------|
| Trên | $R[i][j] \ge s$ | Đoạn chạy cùng chữ sang phải từ $(i,j)$ đủ phủ cạnh trên |
| Trái | $D[i][j] \ge s$ | Đoạn chạy cùng chữ xuống dưới từ $(i,j)$ đủ phủ cạnh trái |
| Dưới | $L[i{+}s{-}1][j{+}s{-}1] \ge s$ | Đoạn chạy cùng chữ sang trái từ góc dưới phải đủ phủ cạnh dưới |
| Phải | $U[i{+}s{-}1][j{+}s{-}1] \ge s$ | Đoạn chạy cùng chữ lên trên từ góc dưới phải đủ phủ cạnh phải |

Bốn mảng $R, D, L, U$ tính trước trong $O(n^2)$ bằng các lần quét QHD thuận/nghịch.

Bốn điều kiện này là **đủ**: chúng ngầm bảo đảm tất cả viền dùng cùng một chữ cái. Góc trên phải $(i, j{+}s{-}1)$ phải bằng $a[i][j]$ (do $R[i][j] \ge s$) và cũng phải bằng $a[i{+}s{-}1][j{+}s{-}1]$ (do $U[i{+}s{-}1][j{+}s{-}1] \ge s$). Vì đây là cùng một ô, $a[i][j] = a[i{+}s{-}1][j{+}s{-}1]$. Lập luận tương tự cho góc dưới trái. Vậy cả bốn viền là cùng một chữ cái.

### Quy về xử lý theo đường chéo

Cả hai góc $(i, j)$ và $(i{+}s{-}1, j{+}s{-}1)$ nằm trên cùng đường chéo ($i - j$ không đổi). Xử lý từng đường chéo độc lập, đưa bài toán 2D về 1D.

Trên đường chéo với các vị trí đánh chỉ số $0, 1, \ldots, \text{len}-1$:

- $\text{tmp\_u}[k] = \min(R[\text{pos}_k], D[\text{pos}_k])$: kích thước vuông tối đa có thể **bắt đầu** tại vị trí $k$ (góc trên trái).
- $\text{tmp\_d}[k] = \min(L[\text{pos}_k], U[\text{pos}_k])$: kích thước vuông tối đa có thể **kết thúc** tại vị trí $k$ (góc dưới phải).

Cần đếm cặp $(p, k)$ với $p \le k$ sao cho:
- $k - p + 1 \le \text{tmp\_d}[k]$ (viền dưới/phải đủ tại $k$)
- $k - p + 1 \le \text{tmp\_u}[p]$ (viền trên/trái đủ tại $p$)

### Cây Fenwick + lịch hết hạn

Quét $k$ từ trái sang phải. Vị trí $p$ **hết hạn** khi hình vuông lớn quá sức chứa viền: $p$ hết hạn tại thời điểm $p + \text{tmp\_u}[p]$ (tức tại $k$ đầu tiên mà $k - p + 1 > \text{tmp\_u}[p]$).

Sử dụng hệ thống sự kiện bucket: khi xử lý vị trí $p$, lên lịch hết hạn tại thời điểm $p + \text{tmp\_u}[p]$. Duy trì **cây Fenwick** (với tăng tốc bitmask) theo dõi các vị trí đã hết hạn. Với mỗi $k$:

1. **Xử lý hết hạn:** Xả tất cả vị trí lên lịch hết hạn tại thời điểm $k$, đánh dấu vào cây Fenwick.
2. **Lên lịch:** Thêm vị trí $k$ vào bucket hết hạn tại thời điểm $k + \text{tmp\_u}[k]$.
3. **Đếm bắt đầu hợp lệ:** Tất cả vị trí $p \in [k + 1 - \text{tmp\_d}[k],\ k]$ thỏa điều kiện dưới/phải. Trừ đi những vị trí đã hết hạn. Đóng góp vào $\text{ans}[c_k]$ là:
$$\text{tmp\_d}[k] - \big(\text{tổng hết hạn} - \text{hết hạn có chỉ số} < k + 1 - \text{tmp\_d}[k]\big)$$

Cây Fenwick hỗ trợ truy vấn tổng tiền tố trong $O(\log n)$, cho $O(n \log n)$ mỗi đường chéo và $O(n^2 \log n)$ tổng.

### Ví dụ minh họa

**Ví dụ đề bài:** $n = 5$, $k = 3$, lưới:

```
A B B B C
A B A B C
A B B B C
A B B B C
C C C C C
```

**Liệt kê tất cả hình vuông viền:**

| Chữ cái | Cỡ 1 | Cỡ 2 | Cỡ 3 | Tổng |
|---------|------|------|------|------|
| A | 5 ô | — | — | 5 |
| B | 11 ô | (2,1)–(3,2), (2,2)–(3,3) | (0,1)–(2,3) | 14 |
| C | 9 ô | — | — | 9 |

**Truy vết đường chéo $d = -1$: vị trí $(0,1)$, $(1,2)$, $(2,3)$, $(3,4)$:**

| $k$ | Ô | Chữ | tmp_u | tmp_d | Hết hạn được xả | Bắt đầu hoạt động trong khoảng | Đóng góp |
|-----|---|------|-------|-------|-----------------|-------------------------------|----------|
| 0 | (0,1) | B | 3 | 1 | — | {0} | $1 \to$ ans[B] |
| 1 | (1,2) | A | 1 | 1 | — | {1} | $1 \to$ ans[A] |
| 2 | (2,3) | B | 1 | 3 | vị trí 1 (A) hết hạn | {0, 2} trong [0,2] | $2 \to$ ans[B] |
| 3 | (3,4) | C | 1 | 1 | vị trí 0, 2 hết hạn | {3} trong [3,3] | $1 \to$ ans[C] |

Tại $k = 2$: vị trí 0 (B tại $(0,1)$, tmp_u=3) vẫn hoạt động vì hết hạn tại thời điểm $0+3=3 > 2$. Vị trí 1 (A tại $(1,2)$, tmp_u=1) đã hết hạn tại thời điểm $1+1=2$. Cặp $(p{=}0, k{=}2)$ cho hình vuông viền B kích thước $3 \times 3$ hợp lệ (góc trên trái $(0,1)$, góc dưới phải $(2,3)$).

**Kết quả:** Tổng trên tất cả 9 đường chéo: **5, 14, 9**. ✓

## Độ phức tạp

- **Thời gian:** $O(n^2 \log n)$ — mỗi đường chéo trong $O(n)$ đường có $O(n)$ vị trí với $O(\log n)$ thao tác Fenwick mỗi vị trí.
- **Bộ nhớ:** $O(n^2)$ — cho các mảng độ dài chạy và bucket hết hạn.

## Mã nguồn (C++)

[Mã nguồn](../code/Border%20Subgrid%20Count%20I.cpp)
