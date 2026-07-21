# Water Containers Moves

**CSES ID:** 3213  
**Đề bài gốc:** https://cses.fi/problemset/task/3213  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Hai bình dung tích $a$ và $b$ ban đầu rỗng. Cho phép đổ đầy, rót rỗng, hoặc rót từ bình này sang bình kia (phải làm đầy hoặc rỗng ít nhất một bình). Đưa ra dãy bước kết thúc với đúng $x$ đơn vị trong bình $A$ sao cho tổng lượng nước di chuyển tối thiểu, hoặc báo vô nghiệm.

## Đầu vào
Ba số nguyên $a$, $b$ và $x$.

## Kết quả
In ra số bước và tổng nước di chuyển, rồi các bước (`FILL A`, `FILL B`, `EMPTY A`, `EMPTY B`, `MOVE A B`, `MOVE B A`), hoặc `-1`.

## Ràng buộc
- $1 \le a, b, x \le 1000$
