# Replace with Difference - Lời giải

**ID:** 3159 | **URL:** https://cses.fi/problemset/task/3159

## Hướng tiếp cận

### Tóm tắt bài toán
Cho $n$ số nguyên, thực hiện $n-1$ phép: mỗi phép chọn hai số $a, b$, xóa cả hai, chèn $|a-b|$. Tìm dãy phép cho kết quả cuối cùng là 0, hoặc $-1$ nếu không thể.

### Điều kiện cần và đủ
Kết quả 0 đạt được khi và chỉ khi:
1. **Tổng chẵn:** Sau mỗi phép, tổng mọi số mod 2 không đổi vì $a+b \equiv |a-b| \pmod{2}$. Đây là đại lượng bất biến, nên tổng ban đầu phải chẵn. Nếu tổng lẻ $\to$ $-1$.
2. **Tồn tại phân hoạch hai tập con tổng bằng:** Mỗi dãy phép hợp lệ tương ứng với việc gán dấu $+$/$-$ cho mỗi số ($+$ cho số bị giữ, $-$ cho số bị trừ). Kết quả 0 nghĩa là tổng nhóm $+$ bằng tổng nhóm $-$. Ngược lại, nếu phân hoạch tồn tại, gộp tham lam (lấy max mỗi nhóm, hiệu thuộc nhóm đúng) giảm dần về 0 vì hai nhóm có tổng bằng nhau.

### Thuật toán
1. Kiểm tra tổng chẵn. Nếu lẻ $\to$ $-1$.
2. Chạy DP tổng tập con bằng bitset: `dp[i+1] = dp[i] | (dp[i] << a[i])`. Nếu không tồn tại tập con tổng = tổng/2 $\to$ $-1$.
3. Truy vết ngược tìm phân hoạch hai nhóm $P$ (tổng = tổng/2) và $N$ (phần còn lại).
4. Đặt phần tử vào hai max-heap `pq_P` và `pq_N`.
5. Lặp lại: lấy max mỗi heap, xuất cặp, đẩy hiệu vào heap thích hợp (nếu $p \ge n$ thì đẩy vào `pq_P`, ngược lại đẩy vào `pq_N`).
6. Nếu một heap rỗng: lấy hai phần tử từ heap kia, xuất cặp, đẩy hiệu trở lại.

### Ví dụ minh họa
$[2,7,4,12,1]$. Tổng = 26. Phân hoạch: $\{2,4,7\}$ và $\{12,1\}$ (mỗi nhóm tổng 13). Gộp dần về 0.

## Độ phức tạp

- **Thời gian:** $O(n \cdot S / 64)$ cho bitset DP + $O(n \log n)$ gộp.
- **Bộ nhớ:** $O(n \cdot S / 64)$

## Mã nguồn (C++)

[Mã nguồn](../code/Replace%20with%20Difference.cpp)
