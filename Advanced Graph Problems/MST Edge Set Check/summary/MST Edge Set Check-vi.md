# MST Edge Set Check

**CSES ID:** 3408  
**Đề bài gốc:** https://cses.fi/problemset/task/3408  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một đồ thị vô hướng có trọng số, liên thông và đơn cùng nhiều tập cạnh. Với mỗi tập, quyết định xem tất cả các cạnh trong tập có thể đồng thời xuất hiện trong một cây khung nhỏ nhất nào đó.

## Đầu vào
Dòng đầu: $n$, $m$, $q$. Sau đó $m$ cạnh có trọng số, đánh số $1,\dots,m$. Rồi $2q$ dòng: với mỗi tập, kích thước trên một dòng và chỉ số cạnh trên dòng tiếp theo; tổng lần nhắc cạnh $\le m$.

## Kết quả
Với mỗi tập cạnh, in ra `YES` nếu tất cả các cạnh có thể cùng thuộc một MST, ngược lại in `NO`.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m, q \le 2 \cdot 10^5$
- $1 \le a, b \le n$
- $1 \le w \le 10^9$
