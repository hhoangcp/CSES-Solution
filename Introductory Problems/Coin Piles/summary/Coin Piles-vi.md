# Coin Piles

**CSES ID:** 1754  
**Đề bài gốc:** https://cses.fi/problemset/task/1754  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Hai đống xu có $a$ và $b$ đồng. Mỗi bước lấy hoặc $(1,2)$ hoặc $(2,1)$ đồng từ hai đống. Với mỗi truy vấn, hãy xác định xem có thể làm rỗng cả hai đống hay không.

## Đầu vào
Dòng đầu: số nguyên $t$. Tiếp theo $t$ dòng, mỗi dòng hai số nguyên $a$ và $b$.

## Kết quả
Với mỗi truy vấn in `YES` nếu có thể làm rỗng cả hai đống, ngược lại in `NO`.

## Ràng buộc
- $1 \le t \le 10^5$
- $0 \le a, b \le 10^9$
