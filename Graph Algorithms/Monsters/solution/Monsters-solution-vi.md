# Quái Vật - Lời giải

**ID:** 1194 | **URL:** https://cses.fi/problemset/task/1194

## Phương pháp

### Tóm tắt bài toán

Bạn và một số quái vật ở trong mê cung $n \times m$. Mỗi bước, bạn và tất cả quái vật di chuyển đồng thời (4 hướng). Tìm đường đi từ `A` đến ô biên sao cho không bao giờ ở cùng ô với quái vật tại cùng thời điểm. Quái vật biết trước đường đi, nên phương án phải an toàn trong trường hợp xấu nhất.

### Ý tưởng chính

Gọi $d_A(v)$ là khoảng cách BFS từ `A` đến ô $v$, và $d_M(v)$ là khoảng cách BFS ngắn nhất từ bất kỳ quái vật nào đến $v$. Bạn an toàn đi qua ô $v$ tại bước $d_A(v)$ khi và chỉ khi $d_A(v) < d_M(v)$ — bạn đến trước quái vật gần nhất. Nếu $d_A(v) \geq d_M(v)$, quái vật đã ở đó hoặc đến cùng lúc, ô không an toàn.

Để thực hiện, chạy **BFS đa nguồn** với tất cả quái vật và người chơi trong cùng hàng đợi, nhưng đẩy tất cả quái vật vào trước. Vì BFS xử lý theo từng lớp, quái vật ở lớp $d$ luôn được xử lý trước người chơi ở cùng lớp. Ô bị đánh dấu `visited` bởi quái vật sẽ ngăn người chơi vào, đảm bảo $d_A(v) < d_M(v)$ với mọi ô người chơi đến được. Nếu người chơi đến được ô biên, tồn tại đường thoát an toàn; nếu hết ô đến được, không có đường đi hợp lệ.

### Thuật toán

1. Đẩy tất cả quái vật vào hàng đợi BFS, rồi đẩy `A`. Đánh dấu tất cả vị trí ban đầu là `visited`.
2. Xử lý hàng đợi: với mỗi ô, mở rộng 4 hướng.
   - Nếu ô thuộc quái vật: đánh dấu các ô kề `visited` (ngăn người chơi vào).
   - Nếu ô thuộc người chơi và ô kề là biên chưa thăm: **tìm thấy lối thoát**. Truy vết từ ô biên về `A` qua `trace`, thu thập hướng, đảo ngược và xuất kết quả.
   - Nếu ô thuộc người chơi và ô kề hợp lệ chưa thăm: đánh dấu, ghi `trace`, đẩy vào hàng đợi.
3. Nếu người chơi không còn ô đến được, xuất "NO".

### Ví dụ minh họa

Input:
```
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######
```

Quái vật tại $(2,2)$, $(3,5)$, $(4,2)$. Người chơi tại $(2,5)$. BFS đa nguồn: quái vật lan trước, người chơi chỉ vào ô chưa bị quái vật đánh dấu. Người chơi đến ô biên $(4,8)$ sau 5 bước.

Kết quả:
```
YES
5
RRDDR
```

## Độ phức tạp

- **Thời gian:** $O(n \cdot m)$
- **Không gian:** $O(n \cdot m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Monsters.cpp)
