# Increasing Subsequence II - Lời giải

**ID:** 1748 | **URL:** https://cses.fi/problemset/task/1748

## Hướng tiếp cận

### Phát biểu lại bài toán

Cho mảng $n$ số nguyên, đếm số dãy con tăng trong mảng. Các dãy con có cùng giá trị nhưng khác vị trí được tính riêng. Kết quả lấy modulo $10^9 + 7$.

### Ý tưởng cốt lõi

Gọi $f(i)$ là số dãy con tăng kết thúc tại vị trí $i$. Khi đó:

$$f(i) = 1 + \sum_{\substack{j < i \\ x_j < x_i}} f(j)$$

Số $1$ đại diện cho dãy con chỉ gồm $x_i$; tổng $\sum f(j)$ là số cách mở rộng các dãy con tăng kết thúc tại $j < i$ (với $x_j < x_i$) bằng cách thêm $x_i$ vào cuối. Tổng đáp án là $\sum_{i=1}^{n} f(i)$.

**Tại sao BIT kết hợp nén tọa độ hoạt động:** Ta cần cấu trúc dữ liệu nhanh chóng tính tổng $f(j)$ trên các $j$ đã xử lý có $x_j < x_i$. Cây chỉ số nhị phân (BIT) hỗ trợ truy vấn tổng tiền tố và cập nhật điểm trong $O(\log n)$, nhưng cần chỉ số trong $[1, n]$. Nén tọa độ ánh xạ các giá trị phân biệt thành thứ hạng từ 1 đến $N$ ($N \le n$), bảo toàn thứ tự nên $\text{rank}(x_j) < \text{rank}(x_i) \iff x_j < x_i$.

**Tại sao dùng `Query(rank(x_i) - 1)` thay vì `Query(rank(x_i))`:** Ta cần dãy con tăng nghiêm ngặt ($x_j < x_i$, không phải $\le$). Dùng `rank(x_i) - 1` loại trừ các phần tử bằng $x_i$, đảm bảo chỉ tính tổng trên các giá trị nhỏ hơn $x_i$.

**Tính đúng (bất biến):** Sau khi xử lý phần tử $i$, `BIT[p]` lưu tổng $f(j)$ cho mọi $j \le i$ có $\text{rank}(x_j) \le p$. Chứng minh bằng quy nạp: ban đầu BIT toàn 0; khi xử lý $i$, `Query(rank(x_i) - 1)` trả về đúng $\sum_{j<i, x_j < x_i} f(j)$ (nén tọa độ bảo toàn thứ tự), và `Update(rank(x_i), f(i))` thêm $f(i)$ tại đúng vị trí, duy trì bất biến.

### Thuật toán

1. Nén tọa độ các giá trị phân biệt thành thứ hạng $1 \ldots N$.
2. Với mỗi $i$ từ 1 đến $n$:
   - $f(i) = (\text{Query}(\text{rank}(x_i) - 1) + 1) \bmod (10^9 + 7)$
   - $\text{Update}(\text{rank}(x_i),\ f(i))$
   - $\text{ans} = (\text{ans} + f(i)) \bmod (10^9 + 7)$

### Ví dụ

Đầu vào: $n = 3$, $x = [2, 1, 3]$. Nén tọa độ: $\{1, 2, 3\} \to \text{thứ hạng}\ \{1, 2, 3\}$.

| $i$ | $x_i$ | thứ hạng | Query(thứ hạng−1) | $f(i)$ | ans |
|-----|-------|----------|-------------------|--------|-----|
| 1 | 2 | 2 | Query(1) = 0 | 1 | 1 |
| 2 | 1 | 1 | Query(0) = 0 | 1 | 2 |
| 3 | 3 | 3 | Query(2) = 1 + 1 = 2 | 3 | 5 |

5 dãy con tăng: $[2]$, $[1]$, $[3]$, $[2,3]$, $[1,3]$.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — nén tọa độ $O(n \log n)$ + $n$ thao tác BIT mỗi cái $O(\log n)$
- **Bộ nhớ:** $O(n)$ — cho BIT và mảng nén tọa độ

## Mã nguồn (C++)

[Mã nguồn](../code/Increasing%20Subsequence%20II.cpp)
