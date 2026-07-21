# Gửi Thư - Lời giải

**ID:** 1691 | **URL:** https://cses.fi/problemset/task/1691

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng $n$ đỉnh và $m$ cạnh, tìm chu trình Euler xuất phát và kết thúc tại đỉnh 1 (đi qua mỗi cạnh đúng một lần), hoặc kết luận "IMPOSSIBLE".

### Ý tưởng chính

Theo định lý Euler, đồ thị vô hướng liên thông có chu trình Euler nếu và chỉ nếu mọi đỉnh có bậc chẵn. Tính cần hiển nhiên: trong chu trình Euler, mỗi lần đi qua một đỉnh dùng một cạnh vào và một cạnh ra, nên bậc mỗi đỉnh bằng hai lần số lần đi qua. Tính đủ: bắt đầu từ đỉnh bất kỳ, theo các cạnh chưa đi — bậc chẵn đảm bảo luôn có cạnh ra cho đến khi quay lại đỉnh xuất phát. Nếu còn cạnh chưa dùng, ghép chu trình con vào chu trình chính tại đỉnh còn cạnh.

**Thuật toán Hierholzer** thực hiện hiệu quả bằng ngăn xếp. Bắt đầu từ đỉnh 1, tham lam theo các cạnh chưa dùng, đẩy mỗi đỉnh mới lên ngăn xếp. Khi một đỉnh không còn cạnh, lấy ra đưa vào đường đi kết quả. Tính bậc chẵn đảm bảo đỉnh duy nhất bị "kẹt" không có cạnh ra là đỉnh 1 ở bước cuối — kết quả là chu trình Euler hợp lệ.

Tối ưu cung hiện tại (`start[u]`) bỏ qua cạnh đã xóa, đảm bảo mỗi cạnh chỉ được xét $O(1)$ lần. Sau thuật toán, nếu đường đi có ít hơn $m + 1$ đỉnh thì đồ thị không liên thông (một số cạnh nằm ở thành phần khác).

### Thuật toán

1. Nếu bất kỳ đỉnh nào có bậc lẻ, in "IMPOSSIBLE".
2. Chạy Hierholzer lặp từ đỉnh 1:
   - Duy trì ngăn xếp $S = [1]$ và mảng `start[u]` cho tối ưu cung hiện tại.
   - Khi $S$ không rỗng: lấy đỉnh $u$ trên đỉnh ngăn xếp. Tìm cạnh chưa dùng $(u, v)$ (bỏ qua cạnh đã xóa qua `start[u]`). Nếu tìm được, đánh dấu cạnh đã xóa và đẩy $v$ lên. Ngược lại, lấy $u$ ra khỏi ngăn xếp đưa vào `Path`.
3. Nếu `Path` có ít hơn $m + 1$ đỉnh, in "IMPOSSIBLE" (đồ thị rời rạc). Ngược lại, in `Path`.

### Ví dụ minh họa

Input:
```
6 8
1 2
1 3
2 3
2 4
2 6
3 5
3 6
4 5
```

Tất cả bậc chẵn (1→2, 2→4, 3→4, 4→2, 5→2, 6→2). Hierholzer tạo chu trình Euler, ví dụ:

```
1 2 3 5 4 2 6 3 1
```

(Bất kỳ chu trình Euler hợp lệ nào đều được chấp nhận.)

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Mail%20Delivery.cpp)
