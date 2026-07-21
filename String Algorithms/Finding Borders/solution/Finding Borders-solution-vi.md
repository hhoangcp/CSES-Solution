# Finding Borders - Lời giải

**ID:** 1732 | **URL:** https://cses.fi/problemset/task/1732

## Đề bài

Cho một chuỗi $s$ độ dài $n$ gồm các ký tự 'a'–'z'. Một đường viền (border) của chuỗi là một tiền tố đồng thời cũng là hậu tố của chuỗi, nhưng không phải toàn bộ chuỗi. Hãy in tất cả các độ dài border theo thứ tự tăng dần.

## Hướng tiếp cận

### Bước 1: Hàm Z

Với chuỗi $s$ độ dài $n$ (đánh số từ 1), $Z[i]$ là độ dài chuỗi con dài nhất bắt đầu tại vị trí $i$ và khớp với tiền tố của $s$: $Z[i] = \max\{k : s[i..i+k-1] = s[1..k]\}$. Theo quy ước $Z[1] = 0$.

### Bước 2: Liên hệ giữa hàm Z và border

Một chuỗi con bắt đầu tại $i$ ($2 \le i \le n$) là một border khi và chỉ khi nó khớp với tiền tố (đã được $Z[i]$ đo) **và** đoạn khớp đó kéo dài đúng đến ký tự cuối cùng của chuỗi. Điều kiện cần và đủ là:

$$i + Z[i] - 1 = n$$

Thật vậy, $Z[i]$ cho biết đoạn khớp với tiền tố tính từ $i$ kéo dài bao xa; đoạn này trở thành một hậu tố (kết thúc tại $n$) đúng khi $i + Z[i] - 1 = n$. Khi đó $s[i..n]$ vừa khớp tiền tố $s[1..Z[i]]$ vừa là hậu tố, nên là một border độ dài $Z[i]$.

**Đầy đủ và không trùng:** Mọi border độ dài $k$ ứng với $i = n - k + 1$ và thỏa mãn điều kiện trên (vì $Z[i] = k$ đúng bằng số ký tự còn lại đến cuối chuỗi); ngược lại mỗi $i$ thỏa mãn cho đúng một độ dài $Z[i] = n - i + 1$, phụ thuộc đơn ánh theo $i$, nên không có border bị sót hay bị đếm hai lần.

### Bước 3: Đảm bảo thứ tự đầu ra

Duyệt $i$ tăng dần từ $2$ đến $n$ và đẩy mỗi độ dài border thỏa mãn vào một ngăn xếp (stack). Vì border độ dài $k$ ứng với $i = n - k + 1$, $i$ càng lớn thì $k$ càng nhỏ; nên các border dài (phát hiện trước) nằm dưới, các border ngắn (phát hiện sau) nằm trên. Lấy từ đỉnh ngăn xếp ra để in sẽ tự động cho dãy kết quả tăng dần, không cần sắp xếp thêm.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"abcababcab"}$ ($n = 10$).

| $i$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---|---|---|---|---|---|---|---|---|---|
| $s[i]$ | a | b | c | a | b | a | b | c | a | b |
| $Z[i]$ | 0 | 0 | 0 | 2 | 0 | 5 | 0 | 0 | 2 | 0 |

Kiểm tra điều kiện $i + Z[i] - 1 = n = 10$:

| $i$ | $Z[i]$ | $i + Z[i] - 1$ | border? |
|---|---|---|---|
| 4 | 2 | 5 | không |
| 6 | 5 | 10 | có, độ dài 5: $\text{"abcab"}$ |
| 9 | 2 | 10 | có, độ dài 2: $\text{"ab"}$ |

(Các $i$ còn lại có $Z[i] = 0$ nên $i + Z[i] - 1 < n$.)

Khi duyệt $i$ tăng dần: tại $i = 6$ đẩy độ dài $5$ vào ngăn xếp, tại $i = 9$ đẩy độ dài $2$ (nằm trên đỉnh). Lấy từ đỉnh ra in được $2$ rồi $5$.

Kết quả:
```
2 5
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ tính hàm Z bằng phương pháp hai con trỏ tuyến tính, và duyệt kiểm tra điều kiện border cũng $O(n)$.
- **Bộ nhớ:** $O(n)$ $\textemdash$ lưu mảng $Z$ và ngăn xếp kết quả.

## Mã nguồn (C++)

[Mã nguồn](../code/Finding%20Borders.cpp)
