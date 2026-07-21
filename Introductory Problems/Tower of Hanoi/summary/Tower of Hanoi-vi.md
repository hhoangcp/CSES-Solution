# Tower of Hanoi

**CSES ID:** 2165  
**Đề bài gốc:** https://cses.fi/problemset/task/2165  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Ba cọc chứa $n$ đĩa kích thước khác nhau, ban đầu đều xếp ở cọc 1 từ nhỏ (trên) đến lớn. Hãy di chuyển tất cả đĩa sang cọc 3 theo luật không đặt đĩa lớn lên đĩa nhỏ, với số bước tối thiểu. In ra số bước và mỗi bước là cặp cọc nguồn-đích.

## Đầu vào
Một dòng chứa số nguyên $n$.

## Kết quả
Dòng đầu: $k$ là số bước tối thiểu. Sau đó $k$ dòng, mỗi dòng hai số nguyên $a$ và $b$ (di chuyển đĩa trên cùng từ cọc $a$ sang cọc $b$).

## Ràng buộc
- $1 \le n \le 16$
