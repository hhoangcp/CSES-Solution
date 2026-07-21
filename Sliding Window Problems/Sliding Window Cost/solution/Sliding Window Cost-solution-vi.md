# Sliding Window Cost - Lời giải

**ID:** 1077 | **URL:** https://cses.fi/problemset/task/1077

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, với mỗi cửa sổ trượt gồm $k$ phần tử liên tiếp, tính chi phí tối thiểu để làm cho tất cả phần tử bằng nhau, với chi phí bằng $\sum |a_i - m|$.

### Ý tưởng chính

Chi phí $\sum |a_i - m|$ đạt tối thiểu khi $m$ là trung vị. Duy trì trung vị động khi cửa sổ trượt bằng cây phân đoạn thống kê thứ tự trên miền giá trị đã nén tọa độ. Cập nhật tổng chi phí tịnh tiến thay vì tính lại từ đầu.

### Thuật toán

**Bước 1: Trung vị tối ưu hóa chi phí.** Hàm $f(m) = \sum |a_i - m|$ là hàm lồi tuyến tính phân khúc, đạt cực tiểu tại trung vị. Di chuyển $m$ khỏi trung vị làm tăng số phần tử bên "nặng" hơn, làm tăng tổng chi phí. Bài toán quy về việc duy trì trung vị động.

**Bước 2: Cây phân đoạn thống kê thứ tự kết hợp nén tọa độ.** Vì giá trị có thể lên tới $10^9$, trước tiên nén tất cả giá trị về đoạn $[0, n-1]$. Xây dựng cây phân đoạn mà mỗi nút lưu số lượng phần tử thuộc khoảng giá trị tương ứng. Cấu trúc hỗ trợ:
- Chèn/xóa một phần tử trong $O(\log n)$
- Tìm phần tử nhỏ thứ $\lfloor(k+1)/2\rfloor$ (trung vị dưới) trong $O(\log n)$

**Bước 3: Cập nhật chi phí tịnh tiến.** Duy trì biến chi phí chạy `res`. Khi cửa sổ trượt sang phải — xóa $r$ và thêm $s$, trung vị thay đổi từ $pre$ sang $now$ — lượng biến đổi chi phí gồm hai thành phần:

1. **Thay thế phần tử:** Thêm $s$ tốn $|pre - s|$ so với trung vị cũ; xóa $r$ tiết kiệm $|now - r|$ so với trung vị mới.
2. **Dịch chuyển trung vị:** $k-1$ phần tử còn lại dịch mốc tham chiếu từ $pre$ sang $now$. Với $k$ lẻ, lượng này tự triệt tiêu do đối xứng (số phần tử hai bên trung vị bằng nhau). Với $k$ chẵn, trung vị dưới tạo bất đối xứng (bên phải nhiều hơn bên trái đúng 1 phần tử), cần điều chỉnh thêm $pre - now$.

Công thức tổng hợp:
$$\text{res} \mathrel{+}= |pre - s| - |now - r|$$
Nếu $k$ chẵn, thêm: $\text{res} \mathrel{+}= pre - now$.

### Ví dụ minh họa

Với $n=8$, $k=3$, mảng $[2, 4, 3, 5, 8, 1, 2, 1]$:

- Cửa sổ $[2,4,3]$: trung vị = 3, chi phí = $|2-3|+|4-3|+|3-3| = 2$
- Cửa sổ $[4,3,5]$: xóa $r=2$, thêm $s=5$, trung vị $3 \to 4$. $\text{res} = 2 + |3-5| - |4-2| = 2+2-2 = 2$
- Cửa sổ $[3,5,8]$: xóa $r=4$, thêm $s=8$, trung vị $4 \to 5$. $\text{res} = 2 + |4-8| - |5-4| = 2+4-1 = 5$
- Cửa sổ $[5,8,1]$: xóa $r=3$, thêm $s=1$, trung vị $5 \to 5$. $\text{res} = 5 + |5-1| - |5-3| = 5+4-2 = 7$
- Cửa sổ $[8,1,2]$: xóa $r=5$, thêm $s=2$, trung vị $5 \to 2$. $\text{res} = 7 + |5-2| - |2-5| = 7+3-3 = 7$
- Cửa sổ $[1,2,1]$: xóa $r=8$, thêm $s=1$, trung vị $2 \to 1$. $\text{res} = 7 + |2-1| - |1-8| = 7+1-7 = 1$

Kết quả: `2 2 5 7 7 1`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Cost.cpp)
