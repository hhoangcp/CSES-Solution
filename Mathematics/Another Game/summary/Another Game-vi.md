# Another Game

**CSES ID:** 2208  
**Đề bài gốc:** https://cses.fi/problemset/task/2208  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trò chơi hai người trên $n$ đống đồng xu. Mỗi lượt chọn một tập con bất kỳ các đống không rỗng và bỏ đi đúng một đồng từ mỗi đống đã chọn; ai lấy đồng cuối cùng thắng. Hãy xác định người thắng khi cả hai chơi tối ưu.

## Đầu vào
Dòng đầu chứa $t$ test. Mỗi test gồm $n$, rồi đến dòng chứa $n$ số là số lượng đồng mỗi đống.

## Kết quả
Với mỗi test in `first` hoặc `second` tuỳ theo người thắng.

## Ràng buộc
- $1 \le t \le 2 \cdot 10^5$
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
- $\sum n \le 2 \cdot 10^5$
