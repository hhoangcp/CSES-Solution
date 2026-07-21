# Sliding Window Inversions - Lời giải

**ID:** 3223 | **URL:** https://cses.fi/problemset/task/3223

## Hướng tiếp cận

### Tóm tắt bài toán

Cho mảng $n$ số nguyên, với mỗi cửa sổ trượt gồm $k$ phần tử liên tiếp, đếm số nghịch thế (cặp $(i,j)$ với $i < j$ và $a_i > a_j$).

### Ý tưởng chính

Khi cửa sổ trượt sang phải một bước, chỉ có một phần tử bước vào và một phần tử rời đi. Duy trì biến đếm nghịch thế chạy liên tục và cập nhật tịnh tiến bằng cây Fenwick (BIT). Mỗi nghịch thế $(p,q)$ được thêm khi $q$ vào cửa sổ và bị xóa khi $p$ rời cửa sổ — không trùng không lọt.

### Thuật toán

**Bước 1: Nén tọa độ.** Vì giá trị có thể lên tới $10^9$, sắp xếp và loại trùng tất cả giá trị, ánh xạ mỗi phần tử thành thứ hạng trong $[1, sz]$. Điều này cho phép sử dụng BIT trên phạm vi $[1, n]$.

**Bước 2: Cập nhật tịnh tiến bằng BIT.** Duy trì biến `tot`. Xử lý từng vị trí $i$ từ trái sang phải:

1. **Thêm** $a[i]$: nghịch thế mới là số phần tử đã có trong cửa sổ lớn hơn $a[i]$. $\Delta_+ = \min(i-1, k) - \text{query}(a[i])$, với $\text{query}(v)$ trả về số phần tử $\le v$. Sau đó $\text{update}(a[i], 1)$.
2. **Xóa** $a[i-k]$ (khi $i > k$): nghịch thế bị mất là số phần tử còn trong cửa sổ nhỏ hơn $a[i-k]$. $\Delta_- = \text{query}(a[i-k] - 1)$. Sau đó $\text{update}(a[i-k], -1)$.
3. **Xuất** `tot` khi $i \ge k$.

Mỗi nghịch thế $(p,q)$ chỉ tồn tại khi cả $p$ và $q$ đều trong cửa sổ. Nó được thêm khi $q$ vào (đếm bởi $\Delta_+$) và bị xóa khi $p$ rời (đếm bởi $\Delta_-$). Do đó `tot` luôn đúng bằng số nghịch thế hiện tại.

### Ví dụ minh họa

Với $n=8$, $k=3$, mảng $[1, 2, 3, 2, 5, 2, 4, 4]$ (nén thành $[1, 2, 3, 2, 5, 2, 4, 4]$):

- $i=1$: thêm 1, tot=0
- $i=2$: thêm 2, $\Delta_+ = 1 - 1 = 0$. tot=0
- $i=3$: thêm 3, $\Delta_+ = 2 - 2 = 0$. tot=0. Xuất **0**
- $i=4$: thêm 2, $\Delta_+ = 3 - 2 = 1$. Xóa $a[1]=1$, $\Delta_- = \text{query}(0) = 0$. tot=1. Xuất **1**
- $i=5$: thêm 5, $\Delta_+ = 3 - 3 = 0$. Xóa $a[2]=2$, $\Delta_- = \text{query}(1) = 0$. tot=1. Xuất **1**
- $i=6$: thêm 2, $\Delta_+ = 3 - 1 = 2$. Xóa $a[3]=3$, $\Delta_- = \text{query}(2) = 2$. tot=1. Xuất **1**
- $i=7$: thêm 4, $\Delta_+ = 3 - 2 = 1$. Xóa $a[4]=2$, $\Delta_- = \text{query}(1) = 0$. tot=2. Xuất **2**
- $i=8$: thêm 4, $\Delta_+ = 3 - 2 = 1$. Xóa $a[5]=5$, $\Delta_- = \text{query}(4) = 3$. tot=0. Xuất **0**

Kết quả: `0 1 1 1 2 0`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sliding%20Window%20Inversions.cpp)
