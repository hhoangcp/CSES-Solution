# Stair Game

**CSES ID:** 1099  
**Đề bài gốc:** https://cses.fi/problemset/task/1099  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cầu thang $n$ bậc, mỗi bậc có một số bóng. Mỗi lượt chọn bậc $k>1$ có ít nhất một bóng và chuyển bất kỳ số bóng dương từ bậc $k$ sang bậc $k-1$; ai đi cuối thắng. Xác định người thắng khi chơi tối ưu.

## Đầu vào
Dòng đầu là $t$. Mỗi test gồm $n$ rồi đến $n$ số $p_1, \dots, p_n$ (số bóng mỗi bậc).

## Kết quả
Với mỗi test in `first` hoặc `second` (thứ hai thắng nếu không có nước đi).

## Ràng buộc
- $1 \le t \le 2 \cdot 10^5$
- $1 \le n \le 2 \cdot 10^5$
- $0 \le p_i \le 10^9$
- $\sum n \le 2 \cdot 10^5$
