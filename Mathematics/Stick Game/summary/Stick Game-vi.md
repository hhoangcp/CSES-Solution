# Stick Game

**CSES ID:** 1729  
**Đề bài gốc:** https://cses.fi/problemset/task/1729  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Trò chơi lấy que: tập cố định $P$ các số nước đi được phép, hai người luân phiên lấy một giá trị trong $P$ que từ một đống, ai lấy que cuối cùng thắng. Với mỗi kích thước đống $1 \dots n$, phân loại vị thế thắng (`W`) hay thua (`L`) cho người đi đầu.

## Đầu vào
Dòng đầu chứa $n$ và $k$. Dòng tiếp theo chứa $k$ nước đi khác nhau $p_i$ (một trong số đó là $1$).

## Kết quả
In chuỗi $n$ ký tự, `W` cho vị thế thắng, `L` cho vị thế thua.

## Ràng buộc
- $1 \le n \le 10^6$
- $1 \le k \le 100$
- $1 \le p_i \le n$
