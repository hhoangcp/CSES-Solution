# Bus Companies

**CSES ID:** 3158  
**Đề bài gốc:** https://cses.fi/problemset/task/3158  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ thành phố và $m$ công ty xe buýt, mỗi công ty phục vụ một tập thành phố cố định và bán một loại vé với giá cho trước. Mua một vé cho phép di chuyển tự do giữa hai thành phố mà công ty đó phục vụ. Tìm chi phí rẻ nhất để đến mọi thành phố từ thành phố 1 (Syrjälä).

## Đầu vào
Dòng đầu: $n$ và $m$. Dòng hai: $m$ giá vé $c_i$. Sau đó với mỗi công ty, một dòng chứa $k$ rồi một dòng liệt kê $k$ thành phố. Đảm bảo đến được mọi thành phố khác từ thành phố 1.

## Kết quả
In ra $n$ số nguyên: chi phí nhỏ nhất để đến các thành phố $1,2,\dots,n$ từ Syrjälä.

## Ràng buộc
- $1 \le n, m \le 10^5$
- $1 \le c \le 10^9$
- $2 \le k \le n$
- $1 \le a \le n$
- tổng tất cả $k$ không vượt quá $2 \cdot 10^5$
