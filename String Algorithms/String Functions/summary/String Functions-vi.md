# Hàm chuỗi

**CSES ID:** 2107  
**Đề bài gốc:** https://cses.fi/problemset/task/2107  
**Giới hạn thời gian:** 1.00s | **Giới hạn bộ nhớ:** 512MB

> Tóm tắt đề bài.

Với chuỗi đánh số $1,2,\dots,n$, hãy tính hai mảng. Mảng Z $z(i)$ là chuỗi con dài nhất bắt đầu tại vị trí $i$ đồng thời là tiền tố của cả chuỗi, với $z(1)=0$. Mảng hàm tiền tố $\pi(i)$ là tiền tố đúng dài nhất của chuỗi đồng thời là hậu tố của tiền tố kết thúc tại vị trí $i$.

## Đầu vào
Một dòng duy nhất chứa chuỗi độ dài $n$ gồm các ký tự a–z.

## Kết quả
In hai dòng: dòng đầu là các giá trị $z$, dòng sau là các giá trị $\pi$, cách nhau bởi khoảng trắng.

## Ràng buộc
- $1 \le n \le 10^6$
