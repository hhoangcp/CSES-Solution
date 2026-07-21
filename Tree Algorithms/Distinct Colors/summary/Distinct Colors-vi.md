# Distinct Colors

**CSES ID:** 1139  
**Đề bài gốc:** https://cses.fi/problemset/task/1139  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một cây có gốc, mỗi đỉnh có một màu. Với mỗi đỉnh cần báo số màu phân biệt xuất hiện trong cây con của nó.

## Đầu vào
Dòng đầu chứa $n$. Dòng tiếp theo là $n$ màu $c_1 \dots c_n$. Sau đó là $n-1$ cạnh.

## Kết quả
In ra $n$ số nguyên: số màu phân biệt trong cây con của mỗi đỉnh $1 \dots n$.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c_i \le 10^9$
