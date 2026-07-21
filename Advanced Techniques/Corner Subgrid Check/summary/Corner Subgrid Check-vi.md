# Corner Subgrid Check

**CSES ID:** 3360  
**Đề bài gốc:** https://cses.fi/problemset/task/3360  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Cho lưới $n \times n$ gồm $k$ chữ cái in hoa đầu tiên. Một lưới con hợp lệ nếu chiều cao và chiều rộng đều ít nhất hai và bốn góc chứa cùng một chữ cái. Với mỗi chữ cái, kiểm tra xem có lưới con hợp lệ nào có các góc chứa chữ cái đó hay không.

## Đầu vào
Dòng đầu: $n$ và $k$. Sau đó $n$ dòng, mỗi dòng một chuỗi $n$ chữ cái in hoa ($k$ chữ đầu).

## Kết quả
In $k$ dòng, mỗi dòng `YES` hoặc `NO` ứng với từng chữ cái.

## Ràng buộc
- $1 \le n \le 3000$
- $1 \le k \le 26$
