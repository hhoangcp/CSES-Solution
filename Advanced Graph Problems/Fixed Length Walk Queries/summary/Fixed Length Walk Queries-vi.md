# Fixed Length Walk Queries

**CSES ID:** 3357  
**Đề bài gốc:** https://cses.fi/problemset/task/3357  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một đồ thị vô hướng đơn, liên thông và một dãy truy vấn. Mỗi truy vấn hỏi có tồn tại đường đi đúng $x$ cạnh từ đỉnh $a$ đến đỉnh $b$ hay không.

## Đầu vào
Dòng đầu: $n$, $m$, $q$. Sau đó $m$ cạnh vô hướng, mỗi cạnh là hai đỉnh $a,b$. Cuối cùng $q$ dòng truy vấn, mỗi dòng $a, b, x$.

## Kết quả
Với mỗi truy vấn, in ra `YES` hoặc `NO` trên một dòng riêng.

## Ràng buộc
- $2 \le n \le 2500$
- $1 \le m \le 5000$
- $1 \le q \le 10^5$
- $0 \le x \le 10^9$
