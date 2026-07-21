# Weird Algorithm

**CSES ID:** 1068  
**Đề bài gốc:** https://cses.fi/problemset/task/1068  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bắt đầu từ số nguyên dương $n$, lặp lại việc thay $n$ bằng $n/2$ nếu chẵn và $3n+1$ nếu lẻ, dừng khi đạt 1 (quá trình Collatz). In ra tất cả các giá trị sinh ra theo đường đi, bắt đầu từ $n$ ban đầu.

## Đầu vào
Một dòng chứa số nguyên $n$.

## Kết quả
In ra tất cả giá trị đi qua trên một dòng, kết thúc bằng 1.

## Ràng buộc
- $1 \le n \le 10^6$
