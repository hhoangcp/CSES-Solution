# Reversals and Sums

**CSES ID:** 2074  
**Đề bài gốc:** https://cses.fi/problemset/task/2074  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Xử lý $m$ thao tác trên mảng $n$ số nguyên: hoặc đảo ngược một mảng con liên tiếp, hoặc truy vấn tổng của một mảng con liên tiếp. In kết quả của mỗi truy vấn tổng.

## Đầu vào
Dòng đầu: $n,m$. Dòng hai: $n$ số nguyên $x_1,\ldots,x_n$. Sau đó $m$ dòng, mỗi dòng ba số nguyên $t,a,b$: $t=1$ đảo ngược vị trí $a\ldots b$, $t=2$ truy vấn tổng đoạn đó.

## Kết quả
In đáp án cho mọi thao tác có $t=2$.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le m \le 10^5$
- $0 \le x_i \le 10^9$
- $1 \le a \le b \le n$
