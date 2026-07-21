# Task Assignment

**CSES ID:** 2129  
**Đề bài gốc:** https://cses.fi/problemset/task/2129  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Có $n$ nhân viên và $n$ nhiệm vụ, chi phí $c_{ij}$ khi gán nhiệm vụ $j$ cho nhân viên $i$. Phân công mỗi nhân viên đúng một nhiệm vụ sao cho tổng chi phí nhỏ nhất, và in một phân công tối ưu.

## Đầu vào
Dòng đầu: $n$. Sau đó $n$ dòng, mỗi dòng $n$ số nguyên là chi phí của một nhân viên.

## Kết quả
In tổng chi phí nhỏ nhất, sau đó $n$ dòng dạng `$a$ $b$` nghĩa nhân viên $a$ nhận nhiệm vụ $b$. Bất kỳ phân công tối ưu nào cũng được.

## Ràng buộc
- $1 \le n \le 200$
- $1 \le c_{ij} \le 1000$
