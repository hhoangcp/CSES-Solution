# Distinct Values Queries II - Lời giải

**ID:** 3356 | **URL:** https://cses.fi/problemset/task/3356

## Hướng tiếp cận

### Tóm tắt đề bài

Cho mảng $n$ số nguyên, xử lý $q$ truy vấn:
1. Cập nhật giá trị tại vị trí $k$ thành $u$.
2. Kiểm tra mọi giá trị trong đoạn $[a, b]$ có phân biệt hay không.

### Ý tưởng cốt lõi

Mọi giá trị trong $[a, b]$ phân biệt khi và chỉ khi không có hai vị trí nào trong $[a, b]$ chứa cùng một giá trị. Tương đương, với mỗi vị trí $i \in [a, b]$, lần xuất hiện tiếp theo của $a[i]$ bên phải phải nằm ngoài $[a, b]$.

Định nghĩa $\text{init}[i]$ = vị trí gần nhất bên phải $i$ có cùng giá trị (hoặc $n+1$ nếu không có). Khi đó:

$$\text{Mọi giá trị trong } [a, b] \text{ phân biệt} \iff \min_{i \in [a,b]} \text{init}[i] > b$$

Ta duy trì mảng $\text{init}$ bằng cây phân đoạn lưu giá trị nhỏ nhất trên đoạn. Truy vấn loại 2 tính `m = query(a, b)`; nếu $m > b$ thì trả về YES, ngược lại NO.

**Tính đúng của cập nhật:** Khi thay đổi $a[p]$ từ giá trị cũ sang giá trị mới, các vị trí có cùng giá trị tạo thành danh sách liên kết sắp xếp. Loại $p$ khỏi danh sách giá trị cũ sẽ nối tiền nhiệm $l$ trực tiếp với hậu nhiệm $r$ (đặt `init[l] = r`). Chèn $p$ vào danh sách giá trị mới thì đặt `init[l] = p` (nếu $l$ tồn tại) và `init[p] = r`. Chỉ có các vị trí này thay đổi giá trị `init`, và cây phân đoạn được cập nhật tương ứng. Không vị trí nào khác bị ảnh hưởng: `init[r]` không đổi vì lần xuất hiện gần nhất bên phải của $r$ không phụ thuộc vào các phần tử bên trái, và các vị trí ngoài các danh sách liên kết này hoàn toàn không liên quan.

### Thuật toán

1. **Nén tọa độ:** Nén tất cả giá trị (bao gồm cả các giá trị cập nhật tương lai) về $[1, m]$.
2. **Xây dựng init[] và cây phân đoạn:** Duyệt từ phải sang trái; với mỗi $i$, đặt `init[i]` bằng vị trí gần nhất bên phải có cùng giá trị (hoặc $n+1$), sau đó chèn $i$ vào tập giá trị tương ứng. Xây cây phân đoạn trên `init`.
3. **Xử lý truy vấn:**
   - Loại 2: Tính `m = query(a, b)`. Xuất YES nếu $m > b$, ngược lại NO.
   - Loại 1 (cập nhật vị trí $p$ thành giá trị mới):
     - Loại $p$ khỏi tập giá trị cũ. Nếu tiền nhiệm $l$ tồn tại, đặt `init[l] = hậu nhiệm` (hoặc $n+1$). Cập nhật cây phân đoạn tại $l$.
     - Chèn $p$ vào tập giá trị mới. Nếu tiền nhiệm $l$ tồn tại, đặt `init[l] = p`. Đặt `init[p] = hậu nhiệm` (hoặc $n+1$). Cập nhật cây phân đoạn tại $l$ và $p$.

### Ví dụ

Đầu vào:
```
5 4
3 2 7 2 8
2 3 5
2 2 5
1 2 9
2 2 5
```

Mảng: $[3, 2, 7, 2, 8]$, init: $[6, 4, 6, 6, 6]$ (vị trí 2 có init$=4$ vì $a[4]=2=a[2]$; các vị trí còn lại có init$=n{+}1=6$).

- Truy vấn $[3,5]$: $\min(\text{init}[3..5]) = 6 > 5$. **YES** ($\{7, 2, 8\}$ đôi một phân biệt).
- Truy vấn $[2,5]$: $\min(\text{init}[2..5]) = 4 \le 5$. **NO** ($a[2]=a[4]=2$).
- Cập nhật vị trí 2 thành 9: loại 2 khỏi tập giá trị 2 (không có tiền nhiệm; hậu nhiệm$=4$; không cần cập nhật). Chèn 2 vào tập giá trị 9 (không có tiền nhiệm, không có hậu nhiệm). `init[2]` trở thành $n{+}1=6$. init: $[6, 6, 6, 6, 6]$.
- Truy vấn $[2,5]$: $\min(\text{init}[2..5]) = 6 > 5$. **YES** ($\{9, 7, 2, 8\}$ đôi một phân biệt).

Kết quả:
```
YES
NO
YES
```

## Độ phức tạp

- **Thời gian:** $O((n + q) \log n)$
- **Bộ nhớ:** $O(n + q)$

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Values%20Queries%20II.cpp)
