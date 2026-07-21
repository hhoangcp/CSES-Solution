# Room Allocation

**CSES ID:** 1164  
**Đề bài gốc:** https://cses.fi/problemset/task/1164  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Với $n$ khách có ngày đến và ngày đi, tìm số phòng ít nhất và cách gán mỗi khách vào một phòng. Hai khách dùng chung phòng chỉ khi khách trước đi trước khi khách kia đến.

## Đầu vào
Dòng đầu: số nguyên $n$. Sau đó $n$ dòng, mỗi dòng ngày đến $a$ và ngày đi $b$.

## Kết quả
In số phòng ít nhất $k$, sau đó một dòng ghi số phòng (từ 1 đến $k$) được gán cho từng khách theo thứ tự đầu vào.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le a \le b \le 10^9$
