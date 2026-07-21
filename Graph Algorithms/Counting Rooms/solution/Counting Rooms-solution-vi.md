# Đếm Phòng - Lời giải

**ID:** 1192 | **URL:** https://cses.fi/problemset/task/1192

## Hướng tiếp cận

### Tóm tắt bài toán

Cho lưới $n \times m$, mỗi ô là sàn (`.`) hoặc tường (`#`). Hai ô sàn thuộc cùng phòng nếu nối nhau bằng các bước lên/xuống/trái/phải qua ô sàn. Đếm số phòng.

### Ý tưởng chính

Mô hình hóa mỗi ô sàn thành một đỉnh đồ thị, cạnh nối giữa hai ô sàn kề nhau. Mỗi phòng chính là một **thành phần liên thông** của đồ thị. Đếm phòng tương đương với đếm thành phần liên thông.

Chạy BFS/DFS loang từ mỗi ô sàn chưa thăm: mỗi lần BFS phát hiện toàn bộ một phòng và đánh dấu tất cả ô trong phòng đã thăm. Cách làm này đúng vì:
- **Không đếm trùng:** BFS từ ô $u$ đánh dấu tất cả ô cùng phòng đã thăm, nên chúng không tăng đếm lần nữa.
- **Không bỏ sót:** Mọi ô sàn đều được xét; ô chưa thăm chắc chắn thuộc phòng chưa đếm, nên ta tăng đếm và chạy BFS.

### Thuật toán

1. Duyệt qua tất cả $n \times m$ ô.
2. Khi gặp ô sàn chưa thăm: tăng biến đếm lên 1 và chạy BFS từ ô đó.
3. BFS: đẩy ô xuất phát vào hàng đợi, đánh dấu đã thăm. Lấy ô khỏi hàng đợi, xét 4 ô kề — nếu trong biên lưới, là sàn và chưa thăm, đánh dấu đã thăm và đẩy vào hàng đợi.
4. Khi BFS kết thúc, tất cả ô trong phòng đã được đánh dấu. Tiếp tục duyệt.

### Ví dụ minh họa

Đầu vào:
```
5 8
########
#..#...#
####.#.#
#..#...#
########
```

Duyệt theo hàng:
- Ô $(2,2)$: sàn chưa thăm → đếm = 1, BFS đánh dấu $(2,2), (2,3)$.
- Ô $(2,5)$: sàn chưa thăm → đếm = 2, BFS đánh dấu $(2,5), (2,6), (2,7), (3,6), (4,6), (4,7)$.
- Ô $(4,2)$: sàn chưa thăm → đếm = 3, BFS đánh dấu $(4,2), (4,3)$.

Kết quả: `3`

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$ — mỗi ô được thăm đúng một lần.
- **Không gian:** $O(n \cdot m)$ — mảng `visited` và hàng đợi BFS.

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Rooms.cpp)
