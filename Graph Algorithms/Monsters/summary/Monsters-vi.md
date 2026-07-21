# Quái Vật

**CSES ID:** 1194  
**Đề bài gốc:** https://cses.fi/problemset/task/1194  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trên lưới $n \times m$ có tường, một ô xuất phát `A` và một số quái vật `M`, bạn và quái vật cùng di chuyển mỗi lượt một ô. Tìm đường từ `A` ra biên không bao giờ đứng chung ô với quái vật, với giả sử quái vật biết trước đường đi.

## Đầu vào
$n, m$, rồi $n$ dòng mỗi dòng $m$ ký tự (`.`, `#`, `A`, `M`).

## Kết quả
`YES` kèm độ dài đường đi và chuỗi `U/D/L/R`, hoặc `NO`.

## Ràng buộc
- $1 \le n,m \le 1000$
