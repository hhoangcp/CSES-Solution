# Graph Coloring

**CSES ID:** 3308  
**Đề bài gốc:** https://cses.fi/problemset/task/3308  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Tô màu các đỉnh của một đồ thị đơn bằng số màu ít nhất sao cho không hai đỉnh kề nhau cùng màu (số sắc).

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng, mỗi dòng một cạnh giữa hai đỉnh phân biệt $a,b$.

## Kết quả
In ra số màu ít nhất $k$, rồi $n$ số nguyên $c_1,\dots,c_n$ với $1 \le c_i \le k$; bất kỳ tô màu hợp lệ nào cũng được.

## Ràng buộc
- $1 \le n \le 16$
- $0 \le m \le \frac{n(n-1)}{2}$
