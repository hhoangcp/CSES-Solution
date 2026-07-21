# Monster Game I

**CSES ID:** 2084  
**Đề bài gốc:** https://cses.fi/problemset/task/2084  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trò chơi có $n$ màn, mỗi màn một quái vật sức mạnh $s_i$. Hệ số kỹ năng ban đầu $x$; giết quái vật $i$ mất thời gian $s_i \cdot f_{\text{hiện tại}}$ và thay hệ số kỹ năng bằng $f_i$ (càng nhỏ càng tốt). Các màn $1\ldots n-1$ có thể bỏ qua, nhưng phải giết quái vật màn $n$. Tìm tổng thời gian nhỏ nhất để thắng. Sức mạnh không giảm và hệ số kỹ năng không tăng.

## Đầu vào
Dòng đầu: $n$ và $x$. Dòng hai: $n$ số nguyên $s_1,\ldots,s_n$. Dòng ba: $n$ số nguyên $f_1,\ldots,f_n$.

## Kết quả
In tổng thời gian nhỏ nhất để thắng.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x \le 10^6$
- $1 \le s_1 \le s_2 \le \ldots \le s_n \le 10^6$
- $x \ge f_1 \ge f_2 \ge \ldots \ge f_n \ge 1$
