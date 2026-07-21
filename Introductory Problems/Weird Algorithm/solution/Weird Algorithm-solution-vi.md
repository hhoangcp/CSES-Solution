# Weird Algorithm - Lời giải

**ID:** 1068 | **URL:** https://cses.fi/problemset/task/1068

## Hướng tiếp cận

### Tóm tắt bài toán

Cho $n$ ($1 \le n \le 10^6$), mô phỏng quy tắc sau cho đến khi $n = 1$: nếu $n$ chẵn, thay $n$ bằng $n/2$; nếu $n$ lẻ, thay $n$ bằng $3n+1$. In tất cả giá trị, bao gồm giá trị ban đầu và giá trị 1 cuối cùng.

### Ý tưởng chính

Đây là **giả thuyết Collatz**: với mọi số nguyên dương ban đầu, dãy được cho là luôn đạt đến 1. Dù chưa chứng minh tổng quát, nó đã được kiểm chứng cho mọi $n \le 2^{68}$, vượt xa giới hạn $10^6$ của bài toán, nên dãy luôn kết thúc trong phạm vi đề bài.

Không có công thức đóng nào dự đoán độ dài dãy mà không chạy nó, nên cách duy nhất là **mô phỏng trực tiếp**: lặp lại áp dụng quy tắc và in từng giá trị.

**Giá trị trung gian có thể vượt phạm vi đầu vào.** Với $n \le 10^6$, giá trị đỉnh trung gian lớn nhất đạt $\sim 5{,}7 \times 10^{10}$ (tại $n = 704511$), vượt xa giới hạn số nguyên 32-bit. Bắt buộc dùng kiểu số nguyên 64-bit.

**Đặc trưng dãy** với một số giá trị ban đầu đáng chú ý:

| $n$ | Số bước | Giá trị đỉnh |
|---|---|---|
| 1 | 0 | 1 |
| 3 | 7 | 16 |
| 27 | 111 | 9232 |
| 9663 | 183 | 27114424 |
| 704511 | 525 | 56991483520 |

Với $n \le 10^6$, số bước tối đa là 525, nên mô phỏng rất nhanh.

### Thuật toán

1. In $n$.
2. Trong khi $n > 1$: nếu $n$ lẻ, đặt $n = 3n+1$; ngược lại, đặt $n = n/2$. In $n$.

### Ví dụ minh họa

**Ví dụ đề bài ($n = 3$):** 3 → 10 → 5 → 16 → 8 → 4 → 2 → 1

Kết quả: `3 10 5 16 8 4 2 1`

## Độ phức tạp

- **Thời gian:** $O(T)$ với $T$ là số bước cho đến khi đạt 1. Với $n \le 10^6$, $T \le 525$.
- **Không gian:** $O(1)$

## Mã nguồn (C++)

[Mã nguồn](../code/Weird%20Algorithm.cpp)
