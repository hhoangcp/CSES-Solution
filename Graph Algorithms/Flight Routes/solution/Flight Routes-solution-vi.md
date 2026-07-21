# Các Tuyến Bay - Lời giải

**ID:** 1196 | **URL:** https://cses.fi/problemset/task/1196

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng có trọng số không âm. Tìm $k$ đường đi ngắn nhất từ đỉnh 1 đến đỉnh $n$. Đường đi có thể thăm lại cùng một thành phố. Hai đường đi khác nhau nếu sử dụng tập cạnh khác nhau.

### Ý tưởng chính

Mở rộng Dijkstra bằng cách lưu **$k$ khoảng cách ngắn nhất** tại mỗi đỉnh thay vì chỉ 1. Mỗi đỉnh $v$ duy trì max-heap `Best[v]` chứa tối đa $k$ giá trị. Khi xử lý cạnh $u \to v$ với ứng cử `tmp = dist + c`:
- Nếu `Best[v]` chưa đủ $k$ phần tử: thêm `tmp`.
- Nếu `tmp < Best[v].top()` (phần tử lớn nhất trong heap): thay thế bằng `tmp`.

Cách làm đúng vì: với trọng số không âm, ứng cử được sinh theo thứ tự không giảm (tính chất tham lam như Dijkstra). Mọi giá trị trong `Best[v]` tương ứng đường đi thực sự (quy nạp: mở rộng đường đến $u$ bằng cạnh $u \to v$). Không đường đi nào bị bỏ sót: nếu đường đi độ dài $d_P$ đến $n$ bị loại, thì `Best[n]` đã có $k$ giá trị $\leq d_P$, tức $k$ đường đi ngắn hơn đã được tìm.

Kiểm tra mục lỗi thời (`dist > Best[u].top()` → bỏ qua) đảm bảo chỉ xử lý ứng cử còn hiệu lực, tránh xử lý vô hạn.

### Thuật toán

1. Khởi tạo `Best[1] = {0}`, đẩy `(0, 1)` vào hàng đợi ưu tiên tối tiểu PQ.
2. Lặp khi PQ không rỗng:
   - Lấy `(dist, u)` có `dist` nhỏ nhất.
   - Nếu `dist > Best[u].top()`: bỏ qua (lỗi thời).
   - Với mỗi cạnh $u \to v$ trọng số $c$:
     - Tính `tmp = dist + c`.
     - Nếu `|Best[v]| < k`: thêm `tmp` vào `Best[v]`, đẩy `(tmp, v)` vào PQ.
     - Ngược lại nếu `tmp < Best[v].top()`: loại `Best[v].top()`, thêm `tmp`, đẩy `(tmp, v)` vào PQ.
3. Xuất $k$ giá trị trong `Best[n]` theo thứ tự tăng dần.

### Ví dụ minh họa

Đầu vào:
```
4 6 3
1 2 1
1 3 3
2 3 2
2 4 6
3 2 8
3 4 1
```

Các bước chính:
- Lấy `(0, 1)`: `Best[2] = {1}`, `Best[3] = {3}`. Đẩy `(1,2)`, `(3,3)`.
- Lấy `(1, 2)`: `tmp=3` cho cạnh $2\to3$, `Best[3]={3,3}`. `tmp=7` cho cạnh $2\to4$, `Best[4]={7}`. Đẩy `(3,3)`, `(7,4)`.
- Lấy `(3, 3)`: `tmp=4` cho cạnh $3\to4$, `Best[4]={7,4}`. Đẩy `(4,4)`.
- Lấy `(3, 3)`: `tmp=4` cho cạnh $3\to4$, `Best[4]={7,4,4}`. Đẩy `(4,4)`.
- Các lần lấy từ đỉnh 4 không có cạnh đi ra. Các mục từ đỉnh 2 với `dist=11` quá lớn.

`Best[4]` sắp xếp: `4, 4, 7` (đường: $1\to3\to4$, $1\to2\to3\to4$, $1\to2\to4$).

Kết quả: `4 4 7`

## Độ phức tạp

- **Thời gian:** $O(k \cdot m \log(k \cdot m))$ — mỗi cạnh có thể sinh tối đa $k$ mục trong PQ.
- **Không gian:** $O(k \cdot n)$ — $k$ khoảng cách cho mỗi đỉnh.

## Mã nguồn (C++)

[Mã nguồn](../code/Flight%20Routes.cpp)
