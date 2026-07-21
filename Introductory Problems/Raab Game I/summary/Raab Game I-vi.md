# Raab Game I

**CSES ID:** 3399  
**Đề bài gốc:** https://cses.fi/problemset/task/3399  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Hai người chơi mỗi người có bài đánh số $1$ đến $n$; mỗi vòng họ lật một lá, lá lớn hơn được một điểm (bằng nhau không ai được điểm). Cho $n$ và điểm cuối $a$, $b$, hãy xác định xem có thể có trò chơi như vậy không, và nếu có thì đưa ra thứ tự bài của hai người cho ra điểm số đó.

## Đầu vào
Dòng đầu: số nguyên $t$. Sau đó $t$ dòng mỗi dòng ba số nguyên $n$, $a$, $b$.

## Kết quả
Với mỗi test in `YES`/`NO`. Khi `YES`, in thêm hai dòng là thứ tự bài của hai người. Bất kỳ ví dụ hợp lệ nào cũng được.

## Ràng buộc
- $1 \le t \le 1000$
- $1 \le n \le 100$
- $0 \le a, b \le n$
