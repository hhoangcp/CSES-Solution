# Same Sum Subsets

**CSES ID:** 3425  
**Đề bài gốc:** https://cses.fi/problemset/task/3425  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho tập $n$ số nguyên dương, chọn hai tập con không giao nhau có tổng bằng nhau. In cả hai tập con (kích thước rồi đến phần tử) hoặc báo không thể.

## Đầu vào
Dòng đầu: $n$. Dòng thứ hai: $n$ số nguyên $x_1,\dots,x_n$.

## Kết quả
Mỗi tập con in kích thước rồi đến các phần tử; in bất kỳ lời giải hợp lệ, hoặc `IMPOSSIBLE` nếu không có.

## Ràng buộc
- $3 \le n \le 40$
- $\sum_{i=1}^{n} x_i \le 2^{n}-2$
