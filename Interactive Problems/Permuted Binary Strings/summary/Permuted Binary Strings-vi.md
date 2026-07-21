# Chuỗi nhị phân hoán vị

**CSES ID:** 3228  
**Đề bài gốc:** https://cses.fi/problemset/task/3228  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Bài tương tác. Cần khôi phục hoán vị ẩn $a$ của $1..n$. Bạn gửi chuỗi nhị phân $b$ độ dài $n$ và nhận chuỗi $b_{a_1}b_{a_2}\dots b_{a_n}$, tức $b$ bị hoán vị theo $a$.

## Đầu vào
Đọc $n$ trước. Giao thức: in `? b` (mỗi $b_i \in \{0,1\}$) để nhận chuỗi đã hoán vị; in `! a_1 ... a_n` để báo hoán vị rồi kết thúc.

## Kết quả
Các truy vấn chuỗi bit và dòng hoán vị cuối, flush sau mỗi dòng.

## Ràng buộc
- $1 \le n \le 1000$
- tối đa $10$ truy vấn `?`
