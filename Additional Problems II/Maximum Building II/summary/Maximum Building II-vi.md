# Maximum Building II

**CSES ID:** 1148  
**Đề bài gốc:** https://cses.fi/problemset/task/1148  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bản đồ rừng $n \times m$ có ô trống (`.`) và ô có cây (`*`). Có thể đặt một tòa nhà hình chữ nhật chỉ phủ ô trống (không chặt cây). Với mỗi chiều cao $h$ và rộng $w$, đếm số cách đặt hình chữ nhật $h \times w$.

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $n$ dòng mỗi dòng $m$ ký tự (`.` hoặc `*`).

## Kết quả
In $n$ dòng mỗi dòng $m$ số nguyên: phần tử hàng $h$, cột $w$ là số cách đặt hình $h \times w$.

## Ràng buộc
- $1 \le n, m \le 1000$
