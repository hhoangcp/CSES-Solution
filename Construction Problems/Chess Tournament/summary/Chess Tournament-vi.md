# Chess Tournament

**CSES ID:** 1697  
**Đề bài gốc:** https://cses.fi/problemset/task/1697  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trong một giải cờ vua, mỗi trong $n$ người chơi tuyên bố số ván họ muốn đấu, và mỗi cặp người chơi chỉ được gặp nhau nhiều nhất một lần. Bạn cần xếp lịch các ván đấu sao cho đúng bằng số lượng yêu cầu của mỗi người.

## Đầu vào
Dòng đầu: số nguyên $n$. Dòng thứ hai: $n$ số nguyên $x_1,\dots,x_n$ là số ván mong muốn.

## Kết quả
In số ván $k$, sau đó $k$ dòng mỗi dòng ghi chỉ số hai người chơi, hoặc `IMPOSSIBLE` nếu không có cách xếp.

## Ràng buộc
- $1 \le n \le 10^5$
- $\sum_{i=1}^{n} x_i \le 2 \cdot 10^5$
