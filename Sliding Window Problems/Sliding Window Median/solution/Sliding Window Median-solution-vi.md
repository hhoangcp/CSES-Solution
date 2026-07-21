# Sliding Window Median - Lời giải

**ID:** 1076 | **URL:** https://cses.fi/problemset/task/1076

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, với mỗi cửa sổ trượt gồm $k$ phần tử liên tiếp, tìm trung vị — phần tử nhỏ thứ $\lfloor(k+1)/2\rfloor$ (trung vị dưới khi $k$ chẵn).

### Ý tưởng chính

Sử dụng cây phân đoạn thống kê thứ tự trên miền giá trị đã nén tọa độ. Mỗi nút lưu số phần tử thuộc khoảng giá trị tương ứng, hỗ trợ chèn/xóa và tìm kiếm theo thứ hạng trong $O(\log n)$. Khi cửa sổ trượt, xóa phần tử rời đi và thêm phần tử mới, rồi truy vấn phần tử nhỏ thứ $\lfloor(k+1)/2\rfloor$.

### Thuật toán

**Bước 1: Nén tọa độ.** Sắp xếp và loại trùng tất cả giá trị, ánh xạ mỗi phần tử thành thứ hạng trong $[0, n-1]$. Điều này cho phép xây dựng cây phân đoạn trên $[0, n-1]$ thay vì $[0, 10^9]$.

**Bước 2: Cây phân đoạn thống kê thứ tự.** Mỗi nút lưu số phần tử thuộc khoảng giá trị tương ứng. Hai thao tác:
- **Update** $(p, val)$: Thêm ($val = 1$) hoặc xóa ($val = -1$) phần tử tại vị trí nén $p$.
- **Tìm theo thứ hạng** $(pos)$: Duyệt từ gốc xuống. Nếu con trái có $\ge pos$ phần tử, phần tử nhỏ thứ $pos$ chắc chắn nằm ở nhánh trái (vì mọi giá trị trái đều nhỏ hơn). Ngược lại, đệ quy phải với $pos - \text{count\_left}$. Tại nút lá, trả về giá trị gốc.

**Bước 3: Trượt cửa sổ.** Với mỗi vị trí $i$:
1. Xóa phần tử rời đi: `Update(a[i-k], -1)` khi $i > k$.
2. Thêm phần tử mới: `Update(a[i], 1)`.
3. Truy vấn trung vị khi $i \ge k$: `Find((k+1)/2)`. Phép chia nguyên tự động cho trung vị dưới khi $k$ chẵn.

### Ví dụ minh họa

Với $n=8$, $k=3$, mảng $[2, 4, 3, 5, 8, 1, 2, 1]$:

Giá trị nén: $\{1,2,3,4,5,8\}$ → thứ hạng $0,1,2,3,4,5$.

- Cửa sổ $[2,4,3]$: phần tử nhỏ thứ 2 = **3**
- Cửa sổ $[4,3,5]$: phần tử nhỏ thứ 2 = **4**
- Cửa sổ $[3,5,8]$: phần tử nhỏ thứ 2 = **5**
- Cửa sổ $[5,8,1]$: phần tử nhỏ thứ 2 = **5**
- Cửa sổ $[8,1,2]$: phần tử nhỏ thứ 2 = **2**
- Cửa sổ $[1,2,1]$: phần tử nhỏ thứ 2 = **1**

Kết quả: `3 4 5 5 2 1`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Median.cpp)
