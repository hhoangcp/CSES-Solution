# Transfer Speeds Sum

**CSES ID:** 3111  
**Đề bài gốc:** https://cses.fi/problemset/task/3111  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một mạng máy tính tạo thành cây trên $n$ máy tính với $n-1$ kết nối, mỗi kết nối có một tốc độ truyền. Định nghĩa $d(a,b)$ là tốc độ nhỏ nhất trên đường đi duy nhất giữa $a$ và $b$. Tính tổng $d(a,b)$ trên mọi cặp không thứ tự $\{a,b\}$.

## Đầu vào
Dòng đầu: $n$. Sau đó $n-1$ dòng, mỗi dòng $a, b, x$ (một cạnh với tốc độ truyền $x$).

## Kết quả
In ra một số nguyên: tổng tốc độ truyền trên mọi cặp không thứ tự.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x \le 10^6$
