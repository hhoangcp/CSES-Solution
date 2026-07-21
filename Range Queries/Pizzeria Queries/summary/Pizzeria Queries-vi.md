# Pizzeria Queries

**CSES ID:** 2206  
**Đề bài gốc:** https://cses.fi/problemset/task/2206  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ tòa nhà trên phố, mỗi tòa có giá pizza $p_k$. Đặt từ tòa $a$ đến tòa $b$ có giá $p_a + |a-b|$. Truy vấn hoặc cập nhật giá một tòa, hoặc với tòa $k$ cho trước hỏi tổng giá nhỏ nhất trên mọi nhà cung cấp.

## Đầu vào
Dòng đầu chứa $n$ và $q$. Dòng hai liệt kê giá ban đầu $p_1,\dots,p_n$. $q$ dòng truy vấn có dạng "1 $k$ $x$" (gán giá tại $k$) hoặc "2 $k$" (hỏi giá nhỏ nhất tại $k$).

## Kết quả
In kết quả mỗi truy vấn loại 2.

## Ràng buộc
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le p_i, x \le 10^9$
- $1 \le k \le n$
