# Tìm mẫu

**CSES ID:** 2102  
**Đề bài gốc:** https://cses.fi/problemset/task/2102  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một văn bản và nhiều mẫu truy vấn. Với mỗi mẫu, cần quyết định nó có xuất hiện ít nhất một lần ở bất kỳ đâu trong văn bản hay không.

## Đầu vào
Dòng đầu là văn bản độ dài $n$. Dòng thứ hai là số nguyên $k$, tiếp theo $k$ dòng mỗi dòng một mẫu. Tất cả dùng ký tự a–z.

## Kết quả
Với mỗi mẫu theo thứ tự, in "YES" nếu xuất hiện trong văn bản, ngược lại in "NO".

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le k \le 5 \cdot 10^5$
- tổng độ dài các mẫu $\le 5 \cdot 10^5$
