# Digit Queries - Lời giải

**ID:** 2431 | **URL:** https://cses.fi/problemset/task/2431

## Phương pháp

### Tóm tắt bài toán

Xâu vô hạn $S = \text{"123456789101112131415..."}$ được tạo bằng cách nối tất cả số nguyên dương. Với $q$ truy vấn ($1 \le q \le 1000$), mỗi truy vấn cho vị trí $k$ ($1 \le k \le 10^{18}$), tìm chữ số thứ $k$ trong $S$.

### Ý tưởng chính

Vì $k$ lên đến $10^{18}$, không thể xây dựng xâu. Thay vào đó, khai thác cấu trúc của $S$: xâu gồm các nhóm liên tiếp các số có cùng số chữ số.

| Nhóm | Các số | Số lượng | Tổng chữ số |
|------|--------|----------|-------------|
| 1 chữ số | 1--9 | 9 | 9 |
| 2 chữ số | 10--99 | 90 | 180 |
| $d$ chữ số | $10^{d-1}$--$10^d-1$ | $9 \times 10^{d-1}$ | $9 \times 10^{d-1} \times d$ |

Công thức đếm: số có $d$ chữ số chạy từ $10^{d-1}$ đến $10^d-1$, có $9 \times 10^{d-1}$ số, mỗi số đóng góp $d$ chữ số.

**Ba bước giải quyết:**

1. **Tìm nhóm chữ số:** Trừ dần kích thước các nhóm khỏi $k$ cho đến khi $k$ nằm trong nhóm $d$ chữ số hiện tại. Sau khi loại bỏ tất cả chữ số của các nhóm ngắn hơn, $k$ còn lại là vị trí (từ 1) trong nhóm $d$ chữ số.

2. **Tìm số cụ thể:** Số đầu tiên của nhóm $d$ chữ số là $10^{d-1}$. Mỗi số chiếm $d$ vị trí, nên số mục tiêu là $\text{num} = 10^{d-1} + \lfloor(k-1)/d\rfloor$. Độ dịch $(k-1)$ và phép chia nguyên ánh xạ đúng $k$ vào số chứa vị trí đó.

3. **Trích xuất chữ số:** Vị trí chữ số trong số là $\text{pos} = (k-1) \bmod d$ (đánh số từ 0, từ trái sang). Trích xuất bằng cách chia cho $10^{d-1-\text{pos}}$ rồi lấy modulo 10.

### Thuật toán

1. Tính trước các lũy thừa của 10 đến $10^{18}$.
2. Với mỗi truy vấn $k$:
   - Trừ $9 \times 10^{d-1} \times d$ khỏi $k$ khi $k$ còn vượt quá, tăng $d$.
   - Tính $\text{num} = 10^{d-1} + (k-1)/d$.
   - Tính $\text{pos} = (k-1) \bmod d$.
   - Trích xuất chữ số tại vị trí $\text{pos}$ của $\text{num}$.
3. Xuất chữ số.

### Ví dụ minh họa

Từ đề bài:
- $k = 7$: Nằm trong nhóm 1 chữ số. $\text{num} = 1 + 6/1 = 7$, $\text{pos} = 0$. Chữ số = **7**.
- $k = 19$: Trừ 9 → $k = 10$ trong nhóm 2 chữ số. $\text{num} = 10 + 9/2 = 14$, $\text{pos} = 1$. Chữ số tại vị trí 1 của "14" = **4**.
- $k = 12$: Trừ 9 → $k = 3$ trong nhóm 2 chữ số. $\text{num} = 10 + 2/2 = 11$, $\text{pos} = 0$. Chữ số tại vị trí 0 của "11" = **1**.

## Độ phức tạp

- **Thời gian:** $O(\log k)$ mỗi truy vấn — vòng lặp nhóm chạy nhiều nhất 18 lần
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Digit%20Queries.cpp)
