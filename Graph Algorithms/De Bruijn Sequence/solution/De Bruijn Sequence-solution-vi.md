# Dãy De Bruijn - Lời giải

**ID:** 1692 | **URL:** https://cses.fi/problemset/task/1692

## Hướng tiếp cận

### Tóm tắt bài toán

Cho số nguyên $n$ ($1 \le n \le 15$), xây dựng chuỗi nhị phân độ dài tối thiểu chứa mọi chuỗi nhị phân độ dài $n$ đúng một lần làm chuỗi con liên tiếp.

### Ý tưởng chính

Mô hình hóa bài toán thành tìm **chu trình Euler** trên **đồ thị De Bruijn** $B(n-1, 2)$:

- **Đỉnh:** Mỗi chuỗi nhị phân độ dài $n-1$ ($2^{n-1}$ đỉnh).
- **Cạnh:** Từ đỉnh $b_1 b_2 \ldots b_{n-1}$, có cạnh nhãn 0 đến $b_2 \ldots b_{n-1} 0$, và cạnh nhãn 1 đến $b_2 \ldots b_{n-1} 1$. Mỗi cạnh tương ứng với một chuỗi nhị phân độ dài $n$ duy nhất: cạnh từ $b_1 \ldots b_{n-1}$ đến $b_2 \ldots b_{n-1} b_n$ biểu diễn chuỗi $b_1 b_2 \ldots b_{n-1} b_n$. Tổng cộng $2^n$ cạnh.

Chu trình Euler đi qua mọi cạnh đúng một lần, tức duyệt tất cả $2^n$ chuỗi độ dài $n$ đúng một lần. Chu trình này luôn tồn tại vì mỗi đỉnh có bậc vào = bậc ra = 2, và đồ thị liên thông yếu — thỏa mãn định lý Euler cho đồ thị có hướng.

Kết quả tối ưu: chuỗi tuyến tính cần ít nhất $2^n + n - 1$ ký tự để chứa $2^n$ chuỗi con độ dài $n$ khác nhau, và thuật toán đạt đúng giới hạn này.

### Thuật toán

1. Bắt đầu DFS từ đỉnh $00\ldots0$ (chuỗi $n-1$ số 0).
2. Tại mỗi đỉnh, thử thêm bit 0 rồi bit 1. Nếu chuỗi độ dài $n$ kết quả chưa xuất hiện, đánh dấu đã thấy và đệ quy khám phá đỉnh hậu tố mới (bỏ ký tự đầu, thêm bit mới).
3. Ghi lại bit đã chọn theo **hậu thứ tự** (sau khi đệ quy quay về). Theo thuật toán Hierholzer: cạnh chỉ được ghi nhận sau khi mọi nhánh đã khám phá xong, tạo chu trình Euler theo thứ tự ngược.
4. Nối tất cả $2^n$ bit trong mảng `edges`, rồi thêm chuỗi khởi đầu $n-1$ số 0 ở cuối, tạo chuỗi tuyến tính độ dài $2^n + n - 1$.

### Ví dụ minh họa

Đầu vào:
```
2
```

Đỉnh (độ dài 1): `0`, `1`. Cạnh: `0→0` (nhãn 0, chuỗi "00"), `0→1` (nhãn 1, chuỗi "01"), `1→0` (nhãn 0, chuỗi "10"), `1→1` (nhãn 1, chuỗi "11").

DFS từ `0`:
- Thử bit 0 → "00" (mới): đệ quy hậu tố `0`. Không còn cạnh mới. Ghi bit **0**.
- Thử bit 1 → "01" (mới): đệ quy hậu tố `1`.
  - Thử bit 0 → "10" (mới): đệ quy hậu tố `0`. Không còn cạnh mới. Ghi bit **0**.
  - Thử bit 1 → "11" (mới): đệ quy hậu tố `1`. Không còn cạnh mới. Ghi bit **1**.
  - Ghi bit **1** (cạnh "01").
- Ghi bit **0** (cạnh "00").

Hậu thứ tự: `0, 0, 1, 1`. Chuỗi: `0011` + `0` = `00110`.

Kết quả:
```
00110
```

Kiểm tra: chuỗi con độ dài 2 là `00`, `01`, `11`, `10` — đủ 4 chuỗi nhị phân. ✓

## Độ phức tạp

- **Thời gian:** $O(n^2 \cdot 2^n)$ — mỗi cạnh thăm một lần; thao tác `set<string>` mất $O(n \log 2^n) = O(n^2)$ mỗi cạnh.
- **Không gian:** $O(2^n)$ — `set` chuỗi đã thấy và mảng `edges`.

## Mã nguồn (C++)

[Mã nguồn](../code/De%20Bruijn%20Sequence.cpp)
