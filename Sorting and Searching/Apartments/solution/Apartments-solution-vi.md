# Apartments - Lời giải

**ID:** 1084 | **URL:** https://cses.fi/problemset/task/1084

## Phương pháp

### Tóm tắt bài toán

Có $n$ người thuê và $m$ căn hộ. Người $i$ chấp nhận căn hộ có kích thước trong $[a_i - k, a_i + k]$. Căn hộ $j$ có kích thước $b_j$. Mỗi người thuê tối đa một căn hộ, mỗi căn hộ chỉ phân cho tối đa một người. Tìm số cặp ghép tối đa.

### Ý tưởng chính

Cách duyệt mọi cặp người–căn hộ sẽ mất $O(nm)$ — quá chậm. Thay vào đó, sắp xếp cả hai mảng rồi áp dụng **tham lam hai con trỏ**: luôn ghép người có yêu cầu nhỏ nhất với căn hộ nhỏ nhất phù hợp. Chiến lược này tối ưu vì phân căn hộ nhỏ cho người có nhu cầu nhỏ giúp giữ lại căn hộ lớn cho những người có yêu cầu lớn hơn.

Quan sát chính giúp hai con trỏ tịnh tiến mà không cần quay lui:

- Nếu $b_j < a_i - k$ (căn hộ quá nhỏ), thì $b_j$ cũng quá nhỏ cho mọi người sau (do $a$ đã sắp tăng), nên bỏ qua $b_j$ là an toàn.
- Nếu $b_j > a_i + k$ (căn hộ quá lớn), thì mọi căn hộ phía sau cũng quá lớn cho người $i$ (do $b$ đã sắp tăng), nên bỏ qua người $i$ là an toàn.
- Ngược lại $b_j$ nằm trong $[a_i - k, a_i + k]$: ghép ngay. Việc này không làm giảm tổng số cặp ghép vì bất kỳ nghiệm tối ưu nào phân căn hộ lớn hơn $b_{j^*}$ ($j^* > j$) cho người $i$ đều có thể đổi: lấy $b_j$ cho người $i$ (vẫn hợp lệ vì $b_j \le b_{j^*} \le a_i + k$), giải phóng $b_{j^*}$ cho người sau có khoảng chấp nhận dịch về bên phải.

### Thuật toán

1. Sắp xếp $a$ và $b$ theo thứ tự tăng dần.
2. Khởi tạo $i = 1$, $j = 1$, $\text{res} = 0$.
3. Trong khi $i \le n$ và $j \le m$:
   - Nếu $a_i - b_j > k$: tăng $j$ (căn hộ quá nhỏ, bỏ qua).
   - Ngược lại nếu $b_j - a_i > k$: tăng $i$ (căn hộ quá lớn, bỏ qua người thuê).
   - Ngược lại: tăng $\text{res}$, $i$, và $j$ (ghép cặp thành công).

### Ví dụ minh họa

Đầu vào: $n = 4$, $m = 3$, $k = 5$, $a = [60, 45, 80, 60]$, $b = [30, 60, 75]$.

Sau khi sắp xếp: $a = [45, 60, 60, 80]$, $b = [30, 60, 75]$.

| Bước | $i$ | $a_i$ | $j$ | $b_j$ | Điều kiện | Hành động |
|------|-----|-------|-----|-------|-----------|-----------|
| 1 | 1 | 45 | 1 | 30 | $45 - 30 = 15 > 5$ | $j \to 2$ |
| 2 | 1 | 45 | 2 | 60 | $60 - 45 = 15 > 5$ | $i \to 2$ |
| 3 | 2 | 60 | 2 | 60 | $\|60 - 60\| = 0 \le 5$ | ghép, res = 1, $i \to 3$, $j \to 3$ |
| 4 | 3 | 60 | 3 | 75 | $75 - 60 = 15 > 5$ | $i \to 4$ |
| 5 | 4 | 80 | 3 | 75 | $\|80 - 75\| = 5 \le 5$ | ghép, res = 2, $i \to 5$, $j \to 4$ |

Kết quả: **2**.

## Độ phức tạp

- **Thời gian:** $O(n \log n + m \log m)$ — sắp xếp chiếm phần chính; hai con trỏ duyệt tuyến tính $O(n + m)$.
- **Không gian:** $O(n + m)$ — lưu hai mảng.

## Mã nguồn (C++)

[Mã nguồn](../code/Apartments.cpp)
