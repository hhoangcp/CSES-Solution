# Creating Strings - Lời giải

**ID:** 1622 | **URL:** https://cses.fi/problemset/task/1622

## Phương pháp

### Tóm tắt bài toán

Cho xâu độ dài $n$ ($1 \le n \le 8$). Liệt kê tất cả hoán vị khác nhau theo thứ tự từ điển và đếm số lượng.

### Ý tưởng chính

**Công thức đếm:** Nếu xâu có $k$ ký tự phân biệt với tần suất $c_1, c_2, \ldots, c_k$, số hoán vị khác nhau là $\frac{n!}{c_1! \cdot c_2! \cdot \ldots \cdot c_k!}$. Lý do: $n!$ đếm tất cả cách sắp xếp, nhưng hoán vị các ký tự giống nhau ($c_i!$ cách mỗi loại) không tạo xâu mới.

**Sinh hoán vị bằng `std::next_permutation`:** Bắt đầu từ hoán vị nhỏ nhất theo từ điển (nhờ sắp xếp), liên tục gọi `next_permutation` để sinh hoán vị lớn hơn tiếp theo. Hàm hoạt động bằng cách: (1) tìm cặp tăng cuối cùng từ phải sang, (2) đổi chỗ với phần tử nhỏ nhất lớn hơn ở bên phải, (3) đảo ngược hậu tố. Cách này tự động bỏ qua trùng lặp — đổi chỗ hai ký tự giống nhau cho cùng kết quả, nên không sinh hoán vị trùng.

**Tính đúng đắn:** Xuất phát từ hoán vị nhỏ nhất, liên tục sinh hoán vị lớn hơn nghiêm ngặt đảm bảo sinh đủ tất cả hoán vị phân biệt theo thứ tự từ điển, không bỏ sót và không lặp lại, cho đến khi đạt hoán vị lớn nhất.

### Thuật toán

1. Sắp xếp xâu theo thứ tự từ điển.
2. Lưu xâu đã sắp xếp là hoán vị đầu tiên.
3. Trong khi `next_permutation` trả về `true`, lưu mỗi hoán vị mới.
4. Xuất số lượng và tất cả hoán vị đã lưu.

### Ví dụ minh họa

Đầu vào: `aabac` ($n=5$, tần suất: a=3, b=1, c=1). Số hoán vị khác nhau: $\frac{5!}{3! \cdot 1! \cdot 1!} = 20$. 20 hoán vị từ `aaabc` đến `cbaaa`.

## Độ phức tạp

- **Thời gian:** $O(P \cdot n)$, với $P$ là số hoán vị phân biệt (tối đa $n!$)
- **Không gian:** $O(P \cdot n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Creating%20Strings.cpp)
