# Knuth Division

**CSES ID:** 2088  
**Đề bài gốc:** https://cses.fi/problemset/task/2088  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bắt đầu từ mảng $n$ số, mỗi bước chọn một mảng con và chia thành hai cho đến khi mọi mảnh chỉ còn một phần tử. Chi phí mỗi lần chia bằng tổng các giá trị trong mảng con được chọn. Tìm tổng chi phí nhỏ nhất để chia hết.

## Đầu vào
Dòng đầu: $n$. Dòng hai: $n$ số nguyên $x_1,\ldots,x_n$.

## Kết quả
In tổng chi phí nhỏ nhất.

## Ràng buộc
- $1 \le n \le 5000$
- $1 \le x_i \le 10^9$
