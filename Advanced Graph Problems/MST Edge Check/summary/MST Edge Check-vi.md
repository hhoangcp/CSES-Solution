# MST Edge Check

**CSES ID:** 3407  
**Đề bài gốc:** https://cses.fi/problemset/task/3407  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một đồ thị vô hướng có trọng số, liên thông và đơn, với mỗi cạnh đầu vào quyết định xem nó có thể thuộc một cây khung nhỏ nhất nào đó hay không.

## Đầu vào
Dòng đầu: $n$ và $m$. Sau đó $m$ dòng, mỗi dòng $a, b, w$ (một cạnh vô hướng có trọng số).

## Kết quả
Với mỗi cạnh theo thứ tự đầu vào, in ra `YES` nếu nó có thể thuộc một MST, ngược lại in `NO`.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
- $1 \le w \le 10^9$
