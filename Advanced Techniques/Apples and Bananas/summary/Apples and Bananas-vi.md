# Apples and Bananas

**CSES ID:** 2111  
**Đề bài gốc:** https://cses.fi/problemset/task/2111  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho trọng số của các quả táo và chuối, mỗi quả là số nguyên trong $1\ldots k$. Với mỗi tổng trọng lượng $w$ từ $2$ đến $2k$, đếm số cặp táo-chuối có tổng bằng $w$.

## Đầu vào
Dòng đầu: $k,n,m$. Dòng hai: $n$ trọng số táo. Dòng ba: $m$ trọng số chuối.

## Kết quả
In $2k-1$ số nguyên, số cặp tương ứng với $w=2,3,\ldots,2k$.

## Ràng buộc
- $1 \le k,n,m \le 2 \cdot 10^5$
- $1 \le a_i,b_i \le k$
