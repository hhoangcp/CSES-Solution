# Number of Subset Xors - Lời giải

**ID:** 3211 | **URL:** https://cses.fi/problemset/task/3211

## Phương pháp

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, tìm số lượng giá trị XOR tập con phân biệt (bao gồm XOR của tập rỗng bằng 0).

### Ý tưởng chính

Tập hợp tất cả XOR tập con tạo thành một không gian vector con trên GF(2). Một tập hợp các vector độc lập tuyến tính tối đại — **cơ sở XOR** — sinh ra toàn bộ không gian này. Nếu cơ sở có kích thước $sz$, số giá trị XOR phân biệt là $2^{sz}$. Điều này vì mỗi vector cơ sở có thể độc lập được chọn hoặc không chọn, và nhờ tính độc lập tuyến tính, mỗi trong $2^{sz}$ cách chọn cho một giá trị duy nhất: nếu hai tập con khác nhau của cơ sở cho cùng XOR, thì phần đối xứng của chúng là một tổ hợp không tầm thường bằng 0, mâu thuẫn với tính độc lập.

### Thuật toán

Duy trì `basis[30]` với `basis[i]` lưu vector có bit $i$ là bit cao nhất (hoặc 0 nếu trống). Với mỗi phần tử đầu vào `mask`:

1. Duyệt các bit $i$ từ 0 đến 29.
2. Nếu bit $i$ được đặt trong `mask`:
   - Nếu `basis[i]` ≠ 0: XOR `mask` với `basis[i]` để khử bit $i$, tiếp tục.
   - Nếu `basis[i]` = 0: đặt `basis[i] = mask`, tăng `sz`, dừng.
3. Nếu `mask` trở thành 0, phần tử phụ thuộc tuyến tính.

Thứ tự duyệt bit từ thấp lên cao đảm bảo khi đặt `basis[i] = mask`, mọi bit $j < i$ đã được khử, nên bit $i$ là bit cao nhất duy nhất của `basis[i]`. Điều này đảm bảo độc lập tuyến tính: trong bất kỳ tổ hợp XOR không tầm thường $\bigoplus_{j \in S} \text{basis}[j] = 0$, chỉ số lớn nhất $i \in S$ đóng góp bit $i$ không bị khử bởi vector nào khác — mâu thuẫn.

Kết quả: $2^{sz}$.

### Ví dụ minh họa

Đầu vào: $n = 3$, mảng $[3, 6, 5]$ (nhị phân: 011, 110, 101).

| Phần tử | Xử lý | Kết quả |
|---|---|---|
| 3 (011) | bit 0 đặt, `basis[0]` trống → `basis[0]=3`, $sz=1$ | Thêm |
| 6 (110) | bit 0 tắt; bit 1 đặt, `basis[1]` trống → `basis[1]=6`, $sz=2$ | Thêm |
| 5 (101) | bit 0 đặt, `basis[0]=3` → $5 \oplus 3 = 6$; bit 1 đặt, `basis[1]=6` → $6 \oplus 6 = 0$ | Phụ thuộc |

Cơ sở: $\{3, 6\}$, $sz = 2$. Đáp án: $2^2 = 4$.

Các giá trị phân biệt: $\{0,\ 3,\ 6,\ 3 \oplus 6 = 5\}$.

## Độ phức tạp

- **Thời gian:** $O(n \cdot 30)$
- **Không gian:** $O(30)$

## Mã nguồn (C++)

[Mã nguồn](../code/Number%20of%20Subset%20Xors.cpp)
