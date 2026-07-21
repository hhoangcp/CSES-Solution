# Raab Game II

**CSES ID:** 3400  
**Đề bài gốc:** https://cses.fi/problemset/task/3400  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Hai người chơi mỗi người giữ các lá bài $1,2,\dots,n$. Mỗi lượt cả hai mở một lá: lá cao hơn được một điểm, hòa không ai được điểm. Cho $n$ và điểm cuối $a$, $b$, hãy đếm số ván chơi khác nhau cho ra đúng kết quả đó, modulo $10^9+7$.

## Đầu vào
Dòng đầu chứa $t$, số test. Tiếp theo $t$ dòng, mỗi dòng chứa $n$, $a$ và $b$.

## Kết quả
Với mỗi test, in số ván chơi có thể modulo $10^9+7$.

## Ràng buộc
- $1 \le t \le 1000$
- $1 \le n \le 5000$
- $0 \le a,b \le n$
