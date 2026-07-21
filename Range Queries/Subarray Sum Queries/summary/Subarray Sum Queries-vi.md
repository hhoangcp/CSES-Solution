# Subarray Sum Queries

**CSES ID:** 1190  
**Đề bài gốc:** https://cses.fi/problemset/task/1190  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bạn duy trì mảng số nguyên với cập nhật một phần tử. Sau mỗi lần cập nhật, hãy báo cáo tổng mảng con liên tiếp lớn nhất trên toàn mảng (mảng con rỗng, tổng 0, được phép).

## Đầu vào
Dòng đầu chứa $n$ (kích thước) và $m$ (số cập nhật). Dòng hai liệt kê mảng ban đầu. $m$ dòng tiếp theo mỗi dòng cho vị trí $k$ và giá trị mới $x$.

## Kết quả
Sau mỗi lần cập nhật, in tổng mảng con lớn nhất.

## Ràng buộc
- $1 \le n, m \le 2 \cdot 10^5$
- $-10^9 \le x_i \le 10^9$
- $1 \le k \le n$
- $-10^9 \le x \le 10^9$
