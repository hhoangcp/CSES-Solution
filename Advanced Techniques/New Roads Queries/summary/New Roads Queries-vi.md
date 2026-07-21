# New Roads Queries

**CSES ID:** 2101  
**Đề bài gốc:** https://cses.fi/problemset/task/2101  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Byteland có $n$ thành phố và ban đầu không có đường; mỗi ngày thêm đúng một con đường trong $m$ ngày. Trả lời $q$ truy vấn hỏi ngày sớm nhất mà sau đó hai thành phố $a$ và $b$ kết nối được (hoặc $-1$ nếu không bao giờ).

## Đầu vào
Dòng đầu: $n,m,q$. Sau đó $m$ dòng cho các con đường theo thứ tự xây, mỗi dòng hai số nguyên $a,b$. Cuối cùng $q$ dòng truy vấn, mỗi dòng hai số nguyên $a,b$.

## Kết quả
Với mỗi truy vấn, in số ngày, hoặc $-1$ nếu hai thành phố không bao giờ kết nối.

## Ràng buộc
- $1 \le n,m,q \le 2 \cdot 10^5$
- $1 \le a,b \le n$
