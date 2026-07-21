# Nim Game II

**CSES ID:** 1098  
**Đề bài gốc:** https://cses.fi/problemset/task/1098  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Nim giới hạn: mỗi lượt lấy $1$, $2$ hoặc $3$ que từ một đống không rỗng; ai lấy que cuối cùng thắng. Xác định người thắng khi chơi tối ưu.

## Đầu vào
Dòng đầu là $t$. Mỗi test gồm $n$ rồi đến dòng chứa $n$ kích thước đống $x_i$.

## Kết quả
Với mỗi test in `first` hoặc `second`.

## Ràng buộc
- $1 \le t \le 2 \cdot 10^5$
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $\sum n \le 2 \cdot 10^5$
