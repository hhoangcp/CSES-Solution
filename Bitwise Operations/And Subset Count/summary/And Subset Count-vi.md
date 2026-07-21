# And Subset Count

**CSES ID:** 3141  
**Đề bài gốc:** https://cses.fi/problemset/task/3141  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho một mảng số nguyên, đếm với mỗi $k$ từ $0$ đến $n$ có bao nhiêu tập con không rỗng mà AND bitwise đúng bằng $k$.

## Đầu vào
Dòng đầu: số nguyên $n$. Dòng sau: $n$ số nguyên $a_1,\dots,a_n$.

## Kết quả
In $n+1$ số nguyên: số lượng ứng với $k = 0, 1, \dots, n$, mỗi số lấy modulo $10^9+7$.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $0 \le a_i \le n$
