# Permutation Order

**CSES ID:** 3397  
**Đề bài gốc:** https://cses.fi/problemset/task/3397  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Gọi $p(n,k)$ là hoán vị thứ $k$ (theo từ điển) của $1 \dots n$. Xử lý hai loại truy vấn: cho $n$, $k$ in ra $p(n,k)$; hoặc cho $n$ và một hoán vị in ra thứ hạng từ điển $k$.

## Đầu vào
Dòng đầu là $t$. Mỗi test dạng `1 n k` hoặc `2 n` kèm hoán vị.

## Kết quả
Loại 1 in các phần tử hoán vị cách nhau bởi dấu cách; loại 2 in thứ hạng $k$.

## Ràng buộc
- $1 \le t \le 1000$
- $1 \le n \le 20$
- $1 \le k \le n!$
