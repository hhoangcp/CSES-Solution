# Robot Path

**CSES ID:** 1742  
**Đề bài gốc:** https://cses.fi/problemset/task/1742  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Một robot xuất phát tại $(0,0)$ và thực hiện $n$ lệnh bước, mỗi lệnh di chuyển một khoảng nguyên theo một trong bốn hướng chính. Robot dừng sớm ngay khi bước vào một điểm đã đi qua. Cần in ra tổng khoảng cách thực tế đã di chuyển.

## Đầu vào
Dòng đầu là số nguyên $n$, sau đó $n$ dòng mỗi dòng một ký tự $d \in \{U,D,L,R\}$ và một số nguyên $x$ là khoảng di chuyển theo hướng đó.

## Kết quả
In ra tổng khoảng cách robot đã di chuyển trước khi dừng.

## Ràng buộc
- $1 \le n \le 10^5$
- $1 \le x \le 10^6$
