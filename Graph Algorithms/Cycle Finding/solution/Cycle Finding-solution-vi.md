# Tìm Chu Trình - Lời giải

**ID:** 1197 | **URL:** https://cses.fi/problemset/task/1197

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng có trọng số (có thể âm) với $n$ đỉnh và $m$ cạnh. Kiểm tra đồ thị có chứa chu trình âm hay không. Nếu có, xuất "YES" và in ra một chu trình âm bất kỳ. Nếu không, xuất "NO".

### Ý tưởng chính

Sử dụng **SPFA** (Shortest Path Faster Algorithm) — biến thể dựa trên hàng đợi của Bellman-Ford — để phát hiện và tái thiết chu trình âm. Áp dụng kỹ thuật **đỉnh ảo**: thay vì chạy SPFA từ từng đỉnh nguồn riêng biệt, khởi tạo `dist[i] = 0` cho mọi đỉnh và đẩy tất cả vào hàng đợi ngay từ đầu. Điều này tương đương với việc thêm một đỉnh ảo nối đến mọi đỉnh với trọng số 0, nên SPFA chỉ cần chạy một lần, tự động bao quát mọi thành phần liên thông.

Trong quá trình SPFA, duy trì `cnt[v]` đếm số lần đỉnh $v$ được relax. Theo định lý Bellman-Ford, trong đồ thị không có chu trình âm, đường đi ngắn nhất giữa hai đỉnh bất kỳ chỉ chứa tối đa $n - 1$ cạnh, nên không đỉnh nào được relax quá $n - 1$ lần. Nếu `cnt[v] >= n`, tồn tại chu trình âm.

Khi `cnt[v] >= n`, đỉnh $v$ có thể nằm trong chu trình âm hoặc chỉ đến được từ chu trình âm. Để tìm chính xác chu trình, đi lùi $n$ bước theo `trace` từ $v$ — điều này chắc chắn đưa ta vào trong chu trình (vì đường đi dài $n$ cạnh phải đi qua lại một đỉnh trên chu trình). Sau đó truy vết chu trình từ điểm đó.

**Tính đúng đắn.** Trong đồ thị không có chu trình âm, đường đi ngắn nhất đến bất kỳ đỉnh nào chỉ dùng tối đa $n - 1$ cạnh, nên sau $n - 1$ vòng relax mọi khoảng cách đã tối ưu và không còn cập nhật. Ngược lại, nếu tồn tại chu trình âm, đi qua chu trình luôn làm giảm khoảng cách, nên một số đỉnh trên hoặc đến được từ chu trình sẽ bị relax không giới hạn. SPFA phát hiện điều này khi `cnt[v] >= n`.

### Thuật toán

1. **Kiểm tra cạnh tự vòng:** Nếu có cạnh $u \to u$ trọng số âm, xuất chu trình 1 đỉnh này và dừng.
2. **Khởi tạo SPFA:** Đặt `dist[i] = 0` cho mọi đỉnh, đẩy tất cả vào hàng đợi.
3. **Phát hiện chu trình:** Khi relax cạnh $u \to v$ trọng số $c$: nếu `dist[v] > dist[u] + c`, cập nhật `dist[v]`, đặt `trace[v] = u`, tăng `cnt[v]`. Nếu `cnt[v] >= n`:
   - Đi lùi $n$ bước theo `trace` từ $v$ để đến một đỉnh nằm trong chu trình.
   - Truy vết chu trình và xuất kết quả.
4. Nếu SPFA kết thúc mà không phát hiện chu trình, xuất "NO".

### Ví dụ minh họa

Input:
```
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2
```

Các cạnh: $1 \to 2$ (1), $2 \to 4$ (1), $3 \to 1$ (1), $4 \to 1$ ($-3$), $4 \to 3$ ($-2$).

Tất cả đỉnh bắt đầu với `dist = 0` trong hàng đợi.
- Xử lý đỉnh 4: relax $4 \to 1$ → `dist[1] = -3`, `trace[1] = 4`; relax $4 \to 3$ → `dist[3] = -2`, `trace[3] = 4`.
- Xử lý đỉnh 1: relax $1 \to 2$ → `dist[2] = -2`, `trace[2] = 1`.
- Xử lý đỉnh 2: relax $2 \to 4$ → `dist[4] = -1`, `trace[4] = 2`.
- Xử lý đỉnh 4 lần nữa: relax $4 \to 1$ → `dist[1] = -4`, `cnt[1] = 2`; relax $4 \to 3$ → `dist[3] = -3`, `cnt[3] = 2`.

Mỗi vòng qua chu trình $1 \to 2 \to 4 \to 1$ làm giảm mọi khoảng cách đi 1. Sau 4 vòng, `cnt[1] = 4 >= n`. Đi lùi 4 bước từ đỉnh 1: $1 \to 4 \to 2 \to 1 \to 4$ → hiện tại ở đỉnh 4, nằm trong chu trình. Truy vết: $4 \to 2 \to 1 \to 4$. Đảo ngược: $1 \to 2 \to 4 \to 1$.

Kết quả:
```
YES
1 2 4 1
```

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$ trong trường hợp xấu nhất — SPFA thường nhanh hơn trên thực tế.
- **Bộ nhớ:** $O(n + m)$ — danh sách kề, mảng khoảng cách/truy vết, và hàng đợi.

## Mã nguồn (C++)

[Mã nguồn](../code/Cycle%20Finding.cpp)
