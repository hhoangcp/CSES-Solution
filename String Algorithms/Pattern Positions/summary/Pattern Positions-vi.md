# Vị trí mẫu

**CSES ID:** 2104  
**Đề bài gốc:** https://cses.fi/problemset/task/2104  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một văn bản và nhiều mẫu truy vấn, với mỗi mẫu hãy đưa ra chỉ số bắt đầu nhỏ nhất (từ 1) mà nó xuất hiện trong văn bản, hoặc $-1$ nếu không xuất hiện.

## Đầu vào
Dòng đầu là văn bản độ dài $n$. Dòng tiếp theo là số nguyên $k$, sau đó $k$ dòng mỗi dòng một mẫu. Tất cả dùng ký tự a–z.

## Kết quả
Với mỗi mẫu theo thứ tự, in vị trí nhỏ nhất (từ 1) mà nó xuất hiện, hoặc $-1$.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le k \le 5 \cdot 10^5$
- tổng độ dài các mẫu $\le 5 \cdot 10^5$
