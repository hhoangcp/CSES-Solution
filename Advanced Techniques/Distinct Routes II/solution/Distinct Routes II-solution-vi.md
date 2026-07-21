# Distinct Routes II - Lời giải

**ID:** 2130 | **URL:** https://cses.fi/problemset/task/2130

## Phương pháp

### Tóm tắt bài toán

Trò chơi có $n$ phòng và $m$ máy dịch chuyển có hướng. Chơi $k$ ngày, mỗi ngày phải đi từ phòng 1 đến phòng $n$. Mỗi máy dịch chuyển chỉ dùng tối đa 1 lần, mỗi lần dùng mất 1 đồng. Tìm tổng số đồng tối thiểu, hoặc $-1$ nếu không đủ $k$ đường đi không chung cạnh.

### Ý tưởng chính

Đây là bài toán **luồng chi phí tối thiểu**. Mỗi máy dịch chuyển được mô hình hóa bằng cạnh có hướng dung lượng 1, chi phí 1. Dung lượng 1 đảm bảo không chung cạnh (mỗi máy chỉ dùng tối đa 1 lần), chi phí 1 mỗi cạnh nên tối thiểu tổng đồng tương đương tối thiểu chi phí luồng. Cần gửi $k$ đơn vị luồng từ nút 1 đến nút $n$ với chi phí nhỏ nhất.

Ta dùng thuật toán **đường tăng ngắn nhất liên tiếp (SSAP)**: lặp lại việc tìm đường tăng chi phí nhỏ nhất trong đồ thị dư và đẩy 1 đơn vị luồng theo đường đó. Thuật toán cho luồng chi phí tối thiểu vì tăng theo đường ngắn nhất bảo toàn tối ưu — nếu tồn tại luồng cùng giá trị nhưng rẻ hơn, hiệu hai luồng tạo ra đường tăng rẻ hơn, mâu thuẫn với việc chọn đường ngắn nhất. Để xử lý cạnh ngược chi phí âm trong đồ thị dư, ta duy trì **thế vị** $\pi$ với chi phí rút gọn $c_\pi(e) = c(e) + \pi(u) - \pi(v)$, đảm bảo mọi chi phí rút gọn không âm để dùng Dijkstra.

Sau khi tìm được luồng chi phí tối thiểu giá trị $k$, truy vết $k$ tuyến đường bằng BFS trên các cạnh bão hòa, đánh dấu mỗi cạnh đã dùng để không lặp.

### Thuật toán

1. Xây mạng luồng: mỗi máy dịch chuyển là cạnh (dung lượng 1, chi phí 1) với cạnh ngược (dung lượng 0, chi phí −1). Thêm siêu nguồn → nút 1 và nút $n$ → siêu hội (dung lượng $k$, chi phí 0).
2. Chạy $k$ lần SSAP:
   - Tìm đường tăng ngắn nhất bằng Dijkstra với thế vị.
   - Nếu không tìm được đường, xuất $-1$.
   - Ngược lại, tăng 1 đơn vị luồng, cập nhật thế vị: $\pi(v) \mathrel{+}= \text{dist}(v)$.
3. Xuất tổng chi phí.
4. Truy vết $k$ tuyến đường bằng BFS trên cạnh bão hòa, đánh dấu cạnh đã dùng để tránh lặp.

### Ví dụ minh họa

$n=8$, $m=10$, $k=2$. Máy dịch chuyển: 1→2, 1→3, 2→5, 2→4, 3→5, 3→6, 4→8, 5→8, 6→7, 7→8.

- **Tăng luồng 1:** Đường ngắn nhất 1→2→4→8 (chi phí 3). Đẩy 1 đơn vị. Thêm cạnh ngược: 8→4, 4→2, 2→1 (chi phí −1 mỗi cạnh).
- **Tăng luồng 2:** Đường ngắn nhất 1→3→5→8 (chi phí 3). Đẩy 1 đơn vị.

Tổng chi phí: 6. Hai đường đi không chung cạnh:
```
6
4
1 2 4 8
4
1 3 5 8
```

## Độ phức tạp

- **Thời gian:** $O(k \cdot m \log n)$ — $k$ lần tăng, mỗi Dijkstra $O(m \log n)$.
- **Không gian:** $O(n + m)$ — danh sách kề và lưu trữ cạnh.

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Routes%20II.cpp)
