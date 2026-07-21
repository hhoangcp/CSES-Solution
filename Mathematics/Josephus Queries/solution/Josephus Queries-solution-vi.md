# Josephus Queries - Lời giải

**ID:** 2164 | **URL:** https://cses.fi/problemset/task/2164

## Phương pháp

### Tóm tắt bài toán

$n$ người đứng thành vòng tròn được đánh số $1, 2, \ldots, n$. Mỗi lượt, người thứ hai tính từ người bắt đầu bị loại bỏ. Lặp lại cho đến khi không còn ai. Xử lý $q$ truy vấn: cho $n$ và $k$, ai là người thứ $k$ bị loại?

### Ý tưởng chính

Trong một vòng quét qua $n$ người, tất cả người ở vị trí chẵn ($2, 4, 6, \ldots$) bị loại. Vòng đầu loại $\lceil n/2 \rceil$ người, để lại $\lfloor n/2 \rfloor$ người sống sót tạo thành bài toán con nhỏ hơn. Gọi $f(n, k)$ là người thứ $k$ bị loại trong vòng $n$ người.

**Trường hợp $k \le \lceil n/2 \rceil$:** Người thứ $k$ bị loại ngay vòng đầu. Đáp án là $2k$ nếu $2k \le n$, hoặc $(2k) \bmod n$ nếu $2k > n$ (chỉ xảy ra khi $n$ lẻ và $k = \lceil n/2 \rceil$, cho người số 1).

**Trường hợp $k > \lceil n/2 \rceil$:** Người thứ $k$ bị loại tổng thể là người thứ $k' = k - \lceil n/2 \rceil$ bị loại trong $\lfloor n/2 \rfloor$ người còn sống. Gọi đệ quy $p = f(\lfloor n/2 \rfloor, k - \lceil n/2 \rceil)$, rồi ánh xạ vị trí $p$ về số hiệu gốc.

**Ánh xạ ngược:** Sau vòng đầu loại hết vị trí chẵn, người sống sót theo thứ tự là:
- $n$ chẵn: $1, 3, 5, \ldots, n-1$. Người thứ $p$ có số hiệu gốc $2p - 1$.
- $n$ lẻ: $3, 5, 7, \ldots, n$. Người thứ $p$ có số hiệu gốc $2p + 1$. (Vì $n$ lẻ nên người cuối vòng đầu là người số 1, vòng tiếp bắt đầu từ người số 3.)

### Thuật toán

Với mỗi truy vấn $(n, k)$:
1. Cơ sở: nếu $n = 1$, trả về $1$.
2. Nếu $k \le \lceil n/2 \rceil$: trả về $2k$ nếu $2k \le n$, ngược lại $(2k) \bmod n$.
3. Ngược lại: tính $p = f(\lfloor n/2 \rfloor, k - \lceil n/2 \rceil)$ bằng đệ quy. Trả về $2p - 1$ nếu $n$ chẵn, $2p + 1$ nếu $n$ lẻ.

### Ví dụ minh họa

Với $n = 7$, thứ tự loại bỏ đầy đủ là $2, 4, 6, 1, 5, 3, 7$.

- $f(7, 1)$: $k = 1 \le 4$, $2 \cdot 1 = 2 \le 7$ → đáp án **2**.
- $f(7, 3)$: $k = 3 \le 4$, $2 \cdot 3 = 6 \le 7$ → đáp án **6**.
- $f(7, 5)$: $k = 5 > 4$. $k' = 1$, $p = f(3, 1) = 2$. $n = 7$ lẻ → $2 \cdot 2 + 1 =$ **5**.
- $f(2, 2)$: $k = 2 > 1$. $k' = 1$, $p = f(1, 1) = 1$. $n = 2$ chẵn → $2 \cdot 1 - 1 =$ **1**.

## Độ phức tạp

- **Thời gian:** $O(\log n)$ mỗi truy vấn ($n$ giảm một nửa mỗi tầng đệ quy)
- **Không gian:** $O(\log n)$ (chiều sâu đệ quy), hoặc $O(1)$ nếu triển khai bằng vòng lặp

## Mã nguồn (C++)

[Mã nguồn](../code/Josephus%20Queries.cpp)
