# Substring Distribution - Lời giải

**ID:** 2110 | **URL:** https://cses.fi/problemset/task/2110

## Đề bài

Cho chuỗi $s$ độ dài $n$ (ký tự 'a'–'z'). Với mỗi độ dài $k = 1..n$, in số chuỗi con phân biệt có độ dài đúng $k$.

## Hướng tiếp cận

### Bước 1: Mảng hậu tố, LCP và đóng góp mỗi hậu tố

Mọi chuỗi con là tiền tố của một hậu tố. Sắp xếp các hậu tố theo thứ tự từ điển (mảng hậu tố $sa$), và dùng $lcp[i] = \text{LCP}(sa[i-1], sa[i])$ để loại trùng. Hậu tố $sa[i]$ có $n - sa[i]$ tiền tố (chuỗi con); trong đó $lcp[i]$ tiền tố đầu tiên đã chung với hậu tố ngay trước, nên nó chỉ đóng góp **chuỗi con mới** có độ dài:

$$[lcp[i]+1, n - sa[i]] \quad (i \ge 1); \qquad [1, n - sa[0]] \quad (i = 0)$$

**Tính đúng (mỗi chuỗi con phân biệt đếm đúng 1 lần):** một chuỗi con $w$ xuất hiện tại nhiều vị trí thì trong $sa$ các hậu tố tương ứng tạo thành một đoạn liên tiếp cùng chung tiền tố $w$; hậu tố đầu đoạn (nhỏ nhất theo $sa$) là hậu tố đầu tiên có $w$ làm tiền tố và đóng góp độ dài $|w|$, các hậu tố sau có $lcp \ge |w|$ nên không đóng góp độ dài này. Vậy $w$ được đếm đúng một lần. (Đoạn đóng góp luôn hợp lệ, không rỗng: một hậu tố không thể là tiền tố của hậu tố đứng ngay trước nó trong thứ tự từ điển — nếu thế thì nó sẽ nhỏ hơn, mâu thuẫn với thứ tự sắp xếp — nên $lcp[i] < n - sa[i]$.)

### Bước 2: Mảng hiệu và khôi phục kết quả

Thay vì tăng từng độ dài một, dùng mảng hiệu $\text{ans}$ để cộng 1 vào cả đoạn đóng góp trong $O(1)$:

- $i = 0$: $\text{ans}[1]\mathrel{+}=1$, $\text{ans}[n - sa[0] + 1]\mathrel{-}=1$.
- $i \ge 1$: $\text{ans}[lcp[i]+1]\mathrel{+}=1$, $\text{ans}[n - sa[i] + 1]\mathrel{-}=1$.

Sau khi xử lý hết $n$ hậu tố, khôi phục kết quả bằng tổng tiền tố tích lũy:

$$\text{result}[k] = \sum_{j=1}^{k} \text{ans}[j]$$

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"abab"}$ ($n = 4$).

| $i$ | $sa[i]$ | hậu tố | $n - sa[i]$ | $lcp[i]$ | đoạn đóng góp |
|---|---|---|---|---|---|
| 0 | 2 | ab | 2 | — | $[1, 2]$ |
| 1 | 0 | abab | 4 | 2 | $[3, 4]$ |
| 2 | 3 | b | 1 | 0 | $[1, 1]$ |
| 3 | 1 | bab | 3 | 1 | $[2, 3]$ |

Đoạn đóng góp tương ứng các chuỗi con mới: `ab` $\to$ {`a`, `ab`}; `abab` $\to$ {`aba`, `abab`} (`ab` đã chung); `b` $\to$ {`b`}; `bab` $\to$ {`ba`, `bab`} (`b` đã chung).

Mảng hiệu (cập nhật theo các đoạn trên): $\text{ans}[1..5] = [2, 0, 0, -1, -1]$.

Tổng tiền tố: $\text{result}[1..4] = [2, 2, 2, 1]$.

Theo độ dài: độ dài 1 có $\{$`a`, `b`$\}$ (2); độ dài 2 có $\{$`ab`, `ba`$\}$ (2); độ dài 3 có $\{$`aba`, `bab`$\}$ (2); độ dài 4 có $\{$`abab`$\}$ (1).

Kết quả:
```
2 2 2 1
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ xây dựng $sa$ bằng SA-IS, tính $lcp$ bằng Kasai, cập nhật mảng hiệu và quét tổng tiền tố đều tuyến tính.
- **Bộ nhớ:** $O(n)$ $\textemdash$ lưu mảng hậu tố, mảng LCP và mảng hiệu.

## Mã nguồn (C++)

[Mã nguồn](../code/Substring%20Distribution.cpp)
