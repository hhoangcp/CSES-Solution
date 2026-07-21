# Tổ hợp từ

**CSES ID:** 1731  
**Đề bài gốc:** https://cses.fi/problemset/task/1731  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn được cho một chuỗi đích và một từ điển gồm các từ phân biệt. Hãy đếm số cách tạo chuỗi bằng cách nối các từ trong từ điển (mỗi từ dùng được nhiều lần), kết quả lấy modulo $10^9+7$.

## Đầu vào
Dòng đầu chứa chuỗi đích gồm $n$ ký tự (a–z). Dòng thứ hai là số nguyên $k$, tiếp theo $k$ dòng mỗi dòng một từ trong từ điển (a–z).

## Kết quả
In một số nguyên: số cách modulo $10^9+7$.

## Ràng buộc
- $1 \le n \le 5000$
- $1 \le k \le 10^5$
- tổng độ dài các từ $\le 10^6$
