# Even Outdegree Edges - Lời giải

**ID:** 2179 | **URL:** https://cses.fi/problemset/task/2179

## Phương pháp

### Tóm tắt bài toán

Cho đồ thị vô hướng, định hướng mỗi cạnh sao cho mọi đỉnh có bậc ra chẵn. Nếu không thể, xuất "IMPOSSIBLE".

### Điều kiện khả thi

Tổng tất cả bậc ra bằng số cạnh $m$. Nếu mọi bậc ra chẵn thì $m$ chẵn, nên mỗi thành phần liên thông phải có số cạnh chẵn. Ngược lại, nếu số cạnh mỗi thành phần chẵn, thuật toán DFS sẽ cho mọi bậc ra chẵn.

### Ý tưởng chính

Dùng DFS xử lý từ dưới lên trên cây DFS. Với mỗi con $v$ của cha $u$: nếu $v$ có bậc ra lẻ, định hướng cạnh cây $v \to u$ (sửa $v$ thành chẵn, đẩy trách nhiệm lên $u$); nếu $v$ có bậc ra chẵn, định hướng $u \to v$ (chỉ bật $u$). Với cạnh ngược, định hướng từ đỉnh sâu hơn sang nông hơn. Xử lý từ dưới lên đảm bảo mọi nút con được sửa thành chẵn trước khi đẩy điều chỉnh lên cha. Đỉnh duy nhất không có cha để đẩy lên là gốc; nếu thành phần liên thông có số cạnh chẵn, gốc cũng tự động chẵn.

### Thuật toán

1. Chạy DFS, xác định cạnh cây và cạnh ngược.
2. Xử lý cạnh ngược: định hướng từ đỉnh sâu hơn sang nông hơn.
3. Xử lý cạnh cây từ dưới lên: khi quay từ con $v$ lên cha $u$:
   - Nếu $v$ có bậc ra lẻ: thêm cạnh $v \to u$.
   - Nếu $v$ có bậc ra chẵn: thêm cạnh $u \to v$.
4. Nếu vẫn còn đỉnh có bậc ra lẻ, xuất "IMPOSSIBLE".

### Ví dụ minh họa

4 đỉnh, 4 cạnh: 1-2, 2-3, 3-4, 1-4.

DFS từ 1: cạnh cây 1-2, 2-3, 3-4. Cạnh ngược: 4-1.

- Cạnh ngược $4\to1$: odd[4] = lẻ.
- Cạnh cây 3-4: odd[4] lẻ $\to$ $4\to3$, odd[4] chẵn.
- Cạnh cây 2-3: odd[3] chẵn $\to$ $2\to3$, bật odd[2].
- Cạnh cây 1-2: odd[2] lẻ $\to$ $2\to1$, odd[2] chẵn.

Mọi đỉnh chẵn. Kết quả hợp lệ.

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Even%20Outdegree%20Edges.cpp)
