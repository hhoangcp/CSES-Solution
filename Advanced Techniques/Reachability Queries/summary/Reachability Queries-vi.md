# Reachability Queries

**CSES ID:** 2143  
**Đề bài gốc:** https://cses.fi/problemset/task/2143  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Đồ thị có hướng có $n$ đỉnh và $m$ cạnh. Trả lời $q$ truy vấn hỏi liệu có thể đi từ đỉnh $a$ đến đỉnh $b$ theo các cạnh có hướng hay không.

## Đầu vào
Dòng đầu: $n,m,q$. Sau đó $m$ dòng, mỗi dòng hai số nguyên phân biệt $a,b$ (cạnh $a\to b$). Cuối cùng $q$ dòng truy vấn, mỗi dòng hai số nguyên $a,b$.

## Kết quả
Với mỗi truy vấn in `YES` hoặc `NO`.

## Ràng buộc
- $1 \le n \le 5 \cdot 10^4$
- $1 \le m,q \le 10^5$
