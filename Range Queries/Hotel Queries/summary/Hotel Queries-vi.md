# Hotel Queries

**CSES ID:** 1143  
**Đề bài gốc:** https://cses.fi/problemset/task/1143  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ khách sạn mỗi khách sạn biết số phòng trống. Các nhóm du khách đến lần lượt, mỗi nhóm yêu cầu một số phòng; bạn phải xếp nhóm vào khách sạn đầu tiên còn đủ phòng rồi giảm số phòng khách sạn đó. Nếu không khách sạn nào đủ, in 0.

## Đầu vào
Dòng đầu chứa $n$ (khách sạn) và $m$ (nhóm). Dòng hai liệt kê số phòng trống $h_1,\dots,h_n$. Dòng ba liệt kê số phòng yêu cầu $r_1,\dots,r_m$.

## Kết quả
Với mỗi nhóm in chỉ số khách sạn được xếp, hoặc 0 nếu không có khách sạn nào đủ.

## Ràng buộc
- $1 \le n,m \le 2 \cdot 10^5$
- $1 \le h_i \le 10^9$
- $1 \le r_i \le 10^9$
