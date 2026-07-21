# Counting Paths

**CSES ID:** 1136  
**Đề bài gốc:** https://cses.fi/problemset/task/1136  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một cây và danh sách các đường đi giữa các cặp đỉnh. Với mỗi đỉnh cần đếm xem có bao nhiêu đường đi trong danh sách đi qua đỉnh đó. Mỗi đường đi là đường đi đơn duy nhất giữa hai đầu.

## Đầu vào
Dòng đầu chứa $n$ và $m$. Tiếp theo là $n-1$ dòng cạnh, rồi $m$ dòng mỗi dòng cho hai đầu $a$ và $b$ của một đường đi.

## Kết quả
In ra $n$ số nguyên: số đường đi chứa mỗi đỉnh $1 \dots n$.

## Ràng buộc
- $1 \le n, m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
