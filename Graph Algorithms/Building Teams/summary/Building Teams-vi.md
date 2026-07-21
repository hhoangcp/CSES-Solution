# Xây Đội

**CSES ID:** 1668  
**Đề bài gốc:** https://cses.fi/problemset/task/1668  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho $n$ học sinh và $m$ cặp bạn, hãy xếp mỗi học sinh vào một trong hai đội sao cho không có bạn bè nào cùng đội. Báo cáo cách xếp hoặc thông báo không khả thi.

## Đầu vào
Hai số $n, m$, rồi $m$ dòng mỗi dòng ghi hai chỉ số học sinh là bạn bè.

## Kết quả
Một dòng gồm $n$ giá trị `1` hoặc `2` là đội của mỗi học sinh, hoặc `IMPOSSIBLE`.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
