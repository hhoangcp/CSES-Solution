# Visible Buildings Queries - Lời giải

**ID:** 3304 | **URL:** https://cses.fi/problemset/task/3304

## Hướng tiếp cận

### Tóm tắt đề bài

Cho $n$ tòa nhà có chiều cao $h_1, \ldots, h_n$, xử lý $q$ truy vấn: nếu chỉ có các tòa nhà trong đoạn $[a, b]$ tồn tại, bạn nhìn thấy bao nhiêu tòa nhà từ bên trái? Tòa nhà nhìn thấy được nếu nó cao hơn tất cả các tòa nhà bên trái nó.

### Ý tưởng cốt lõi

Tòa nhà $i$ nhìn thấy trong đoạn $[a, b]$ khi và chỉ khi $h_i > \max_{j \in [a, i-1]} h_j$. Các tòa nhà nhìn thấy được tạo thành dãy có chiều cao tăng nghiêm ngặt, bắt đầu từ vị trí $a$.

Xử lý truy vấn offline, sắp xếp theo biên trái $l$ **giảm dần**. Quét vị trí $i$ từ $n$ xuống $1$, duy trì **ngăn xếp đơn điệu** $S$ chứa các vị trí có chiều cao giảm nghiêm ngặt từ đáy lên đỉnh:

1. Loại tất cả vị trí $j$ khỏi đỉnh ngăn xếp với $h_j \le h_i$ (tòa nhà $j$ bị che bởi $i$ vì $i < j$ và $h_i \ge h_j$).
2. Đẩy $i$ vào đỉnh ngăn xếp.

**Bất biến:** Sau khi xử lý vị trí $i$, ngăn xếp chứa đúng các tòa nhà nhìn thấy từ bên trái $i$ trong phạm vi $[i, n]$.

*Chứng minh bằng quy nạp:* Khi $i = n$, đẩy $n$ vào ngăn xếp rỗng, kết quả đúng. Giả sử bất biến đúng sau khi xử lý $i+1$. Khi xử lý $i$: mọi vị trí $j$ bị loại có $h_j \le h_i$, nên $j$ bị tòa nhà $i$ che khuất, không thể nhìn thấy từ bên trái $i$. Vị trí $i$ luôn nhìn thấy (là tòa nhà đầu tiên). Các vị trí còn lại có chiều cao $> h_i$ và theo giả thiết quy nạp đã nhìn thấy từ $i+1$; chúng vẫn nhìn thấy từ $i$ vì $i$ không che được chúng, và không có tòa nhà nào giữa $i$ và chúng đủ cao để che — nếu có, tòa nhà đó đã không bị $i$ loại bỏ (vì cao hơn $h_i$) và vẫn còn trong ngăn xếp nằm giữa $i$ và chúng, mâu thuẫn với tính chất ngăn xếp liên tục.

Để trả lời truy vấn $[l, r]$ khi $i = l$: ngăn xếp chứa các tòa nhà nhìn thấy trong $[l, n]$. Vì các vị trí trong ngăn xếp giảm dần từ đáy lên đỉnh, dùng tìm kiếm nhị phân tìm vị trí đầu tiên $\le r$; tất cả phần tử từ đó đến đỉnh đều có vị trí $\le r$ và nằm trong $[l, r]$. Đáp án bằng số phần tử thỏa mãn.

### Thuật toán

1. Đọc tất cả truy vấn, nhóm theo biên trái $l$.
2. Quét $i$ từ $n$ xuống $1$:
   - Loại tất cả vị trí $j$ khỏi ngăn xếp với $h_j \le h_i$.
   - Đẩy $i$ vào ngăn xếp.
   - Với mỗi truy vấn $[l, r]$ có $l = i$: tìm kiếm nhị phân trên ngăn xếp vị trí đầu tiên $\le r$; đáp án = kích thước ngăn xếp trừ đi chỉ số tìm được.
3. Xuất đáp án theo thứ tự truy vấn ban đầu.

### Ví dụ

Đầu vào:
```
5 3
4 1 2 2 3
1 5
2 5
3 4
```

Chiều cao: $[4, 1, 2, 2, 3]$.

Quét từ $i = 5$ xuống $1$:

- $i = 5$ ($h = 3$): Đẩy 5. $S = [5]$.
- $i = 4$ ($h = 2$): $h[5] = 3 > 2$, không loại. Đẩy 4. $S = [5, 4]$.
- $i = 3$ ($h = 2$): $h[4] = 2 \le 2$, loại 4. $h[5] = 3 > 2$, dừng. Đẩy 3. $S = [5, 3]$.
- $i = 2$ ($h = 1$): $h[3] = 2 > 1$, không loại. Đẩy 2. $S = [5, 3, 2]$.
- $i = 1$ ($h = 4$): Loại 2, 3, 5 ($h \le 4$). Đẩy 1. $S = [1]$.

Truy vấn (xử lý khi quét đến $l$):

- **$[3, 4]$** tại $i = 3$: $S = [5, 3]$. Vị trí đầu tiên $\le 4$ là 3 tại chỉ số 1. Đáp án $= 2 - 1 = 1$. Đúng: đoạn $[2, 2]$, chỉ thấy tòa nhà 3.
- **$[2, 5]$** tại $i = 2$: $S = [5, 3, 2]$. Vị trí đầu tiên $\le 5$ là 5 tại chỉ số 0. Đáp án $= 3 - 0 = 3$. Đúng: đoạn $[1, 2, 2, 3]$, thấy tòa nhà 2, 3, 5.
- **$[1, 5]$** tại $i = 1$: $S = [1]$. Vị trí đầu tiên $\le 5$ là 1 tại chỉ số 0. Đáp án $= 1 - 0 = 1$. Đúng: tòa nhà 1 cao 4 che hết các tòa nhà khác.

Kết quả:
```
1
3
1
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$ — mỗi vị trí vào và ra ngăn xếp tối đa 1 lần ($O(n)$ tổng), mỗi truy vấn tìm kiếm nhị phân $O(\log n)$.
- **Bộ nhớ:** $O(n + q)$

## Mã nguồn (C++)

[Mã nguồn](../code/Visible%20Buildings%20Queries.cpp)
