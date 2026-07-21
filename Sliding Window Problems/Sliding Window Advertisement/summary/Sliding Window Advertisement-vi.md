# Sliding Window Advertisement

**CSES ID:** 3227  
**Đề bài gốc:** https://cses.fi/problemset/task/3227  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một hàng rào gồm $n$ tấm ván đứng rộng 1 đơn vị với các chiều cao cho trước. Với mỗi đoạn liên tiếp $k$ tấm ván, cần tìm hình chữ nhật (quảng cáo) lớn nhất vừa khít trong đoạn đó, dùng chiều cao các ván làm giới hạn trên. Mỗi cửa sổ in ra một giá trị.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng sau: $n$ chiều cao ván $x_1,\dots,x_n$.

## Kết quả
In ra $n-k+1$ số nguyên, diện tích quảng cáo lớn nhất mỗi cửa sổ.

## Ràng buộc
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
