# Increasing Array II - Lời giải

**ID:** 2132 | **URL:** https://cses.fi/problemset/task/2132

## Đề bài

Cho mảng $n$ số nguyên, biến đổi thành mảng không giảm bằng cách tăng hoặc giảm giá trị. Mỗi tăng/giảm 1 đơn vị chi phí 1. Tìm tổng chi phí tối thiểu.

## Hướng tiếp cận

### Quy hoạch động trên hàm lồi: $f_i(x) = |a_i - x| + \min_{z \le x} f_{i-1}(z)$

Tìm dãy không giảm $y_1 \le y_2 \le \cdots \le y_n$ tối thiểu hóa $\sum |a_i - y_i|$. Gọi $f_i(x)$ là chi phí tối thiểu cho $i$ phần tử đầu với $y_i = x$. Công thức truy hồi:

$$f_i(x) = |a_i - x| + \min_{z \le x} f_{i-1}(z)$$

$f_i(x)$ là **hàm lồi từng đoạn** (convex piecewise linear): $f_1(x) = |a_1 - x|$ lồi, phép $\min_{z \le x}$ bảo toàn tính lồi, cộng $|a_i - x|$ (lồi) cũng bảo toàn. Do đó hàm chỉ cần biểu diễn qua các **điểm gãy** (vị trí độ dốc thay đổi).

### Slope Trick: Lưu điểm gãy bằng Max-Heap

Hàm lồi từng đoạn được đặc trưng hoàn toàn bởi tập điểm gãy. Vì phép $\min_{z \le x}$ "san phẳng" mọi đoạn dốc dương, ta chỉ cần lưu các điểm gãy trong vùng độ dốc $\le 0$ bằng một **Max-Heap**:

- **$|a_i - x|$ thêm điểm gãy tại $a_i$**: độ dốc bên trái $a_i$ giảm 1, bên phải tăng 1.
- **$\min_{z \le x}$ cắt bỏ đoạn dốc dương**: nếu đỉnh heap $t > a_i$, đoạn $[a_i, t]$ có độ dốc dương không cần thiết. Hạ xuống $a_i$ tiết kiệm $t - a_i$. Lấy $t$ ra, đẩy $a_i$ vào lại (duy trì cấu trúc hàm lồi mới).

## Thuật toán

1. Khởi tạo max-heap `Q` và `ans = 0`.
2. Với mỗi phần tử $a_i$:
   - Đẩy $a_i$ vào heap.
   - Nếu `Q.top() > a_i`: `ans += Q.top() - a_i`, lấy đỉnh ra, đẩy $a_i$ vào lại.
3. Xuất `ans`.

## Ví dụ minh họa

Mảng: $[3, 8, 5]$.

- **Thêm 3:** Heap `{3}`, `ans = 0`. (Hàm hình chữ V đạt cực tiểu tại 3).
- **Thêm 8:** Heap `{8, 3}`, `ans = 0`. (8 nằm bên phải điểm cực tiểu, cực tiểu kéo dài từ 3 đến 8).
- **Thêm 5:**
  - Đẩy 5: Heap `{8, 5, 3}`.
  - $5 < $ `Q.top()` $= 8$: `ans += 8 - 5 = 3`.
  - Pop 8, đẩy 5: Heap `{5, 5, 3}`.

Kết quả: 3.

### Ví dụ theo đề bài

Mảng: $[3, 8, 5, 6, 5]$.

- **Thêm 3:** Heap `{3}`, `ans = 0`.
- **Thêm 8:** Heap `{8, 3}`, `ans = 0`.
- **Thêm 5:**
  - Đẩy 5: Heap `{8, 5, 3}`.
  - $5 < $ `Q.top()` $= 8$: `ans += 8 - 5 = 3`.
  - Pop 8, đẩy 5: Heap `{5, 5, 3}`.
- **Thêm 6:**
  - Đẩy 6: Heap `{6, 5, 5, 3}`.
  - $6 \not< $ `Q.top()` $= 6$: không thay đổi. `ans = 3`.
- **Thêm 5:**
  - Đẩy 5: Heap `{6, 5, 5, 5, 3}`.
  - $5 < $ `Q.top()` $= 6$: `ans += 6 - 5 = 1`. `ans = 4`.
  - Pop 6, đẩy 5: Heap `{5, 5, 5, 5, 3}`.

Kết quả: 4.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — mỗi phần tử tối đa 2 thao tác heap
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Increasing%20Array%20II.cpp)
