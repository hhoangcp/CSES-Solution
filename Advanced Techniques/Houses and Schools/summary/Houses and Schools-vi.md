# Houses and Schools

**CSES ID:** 2087  
**Đề bài gốc:** https://cses.fi/problemset/task/2087  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Các ngôi nhà $1\ldots n$ nằm trên một đường thẳng; khoảng cách giữa nhà $a$ và $b$ là $|a-b|$, nhà $i$ có $c_i$ trẻ em. Đặt $k$ trường học tại các nhà đã chọn sao cho mỗi trẻ đi đến trường gần nhất, sao cho tổng khoảng cách đi bộ nhỏ nhất.

## Đầu vào
Dòng đầu: $n$ và $k$. Dòng hai: $n$ số nguyên $c_1,\ldots,c_n$.

## Kết quả
In tổng khoảng cách đi bộ nhỏ nhất.

## Ràng buộc
- $1 \le k \le n \le 3000$
- $1 \le c_i \le 10^9$
