# Pizza Khổng Lồ

**CSES ID:** 1684  
**Đề bài gốc:** https://cses.fi/problemset/task/1684  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $m$ loại nhân pizza và $n$ thành viên, mỗi người đưa ra hai mong muốn dạng "nhân $x$ tốt" hoặc "nhân $x$ xấu". Chọn nhân để mỗi thành viên có ít nhất một mong muốn được thỏa.

## Đầu vào
$n$ và $m$, rồi $n$ dòng mỗi dòng hai mong muốn `+ x` hoặc `- x`.

## Kết quả
Một dòng $m$ ký hiệu (`+`/`-`) cho biết nhân nào được chọn, hoặc `IMPOSSIBLE`.

## Ràng buộc
- $1 \le n,m \le 10^5$
- $1 \le x \le m$
