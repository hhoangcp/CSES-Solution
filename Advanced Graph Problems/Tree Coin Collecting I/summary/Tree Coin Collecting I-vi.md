# Tree Coin Collecting I

**CSES ID:** 3114  
**Đề bài gốc:** https://cses.fi/problemset/task/3114  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một cây $n$ đỉnh, một số đỉnh được đánh dấu chứa đồng xu. Trả lời $q$ truy vấn: với cặp $(a,b)$, tìm độ dài đường đi ngắn nhất từ $a$ đến $b$ đi qua ít nhất một đỉnh có đồng xu.

## Đầu vào
Dòng đầu: $n$ và $q$. Dòng hai: $n$ giá trị $c_i \in \{0,1\}$ (ít nhất một giá trị 1). Sau đó $n-1$ cạnh cây $a,b$. Cuối cùng $q$ dòng truy vấn, mỗi dòng hai đầu mút $a,b$.

## Kết quả
In ra $q$ số nguyên, mỗi truy vấn một số.

## Ràng buộc
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a, b \le n$
