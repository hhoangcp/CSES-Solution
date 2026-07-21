# Monster Game II

**CSES ID:** 2085  
**Đề bài gốc:** https://cses.fi/problemset/task/2085  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Tương tự Monster Game I, đi qua $n$ màn với quái vật sức mạnh $s_i$; giết quái vật $i$ mất thời gian $s_i \cdot f_{\text{hiện tại}}$ và đổi hệ số kỹ năng thành $f_i$ (càng nhỏ càng tốt). Có thể bỏ qua các màn $1\ldots n-1$ nhưng phải giết quái vật màn $n$. Khác bản I, sức mạnh và hệ số kỹ năng là tùy ý. Tìm tổng thời gian nhỏ nhất để thắng.

## Đầu vào
Dòng đầu: $n$ và $x$. Dòng hai: $n$ số nguyên $s_1,\ldots,s_n$. Dòng ba: $n$ số nguyên $f_1,\ldots,f_n$.

## Kết quả
In tổng thời gian nhỏ nhất để thắng.

## Ràng buộc
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x \le 10^6$
- $1 \le s_i,f_i \le 10^6$
