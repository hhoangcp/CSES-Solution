# Kiểm Tra Tuyến Bay - Lời giải

**ID:** 1682 | **URL:** https://cses.fi/problemset/task/1682

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh, $m$ cạnh. Kiểm tra từ mọi thành phố có thể đến mọi thành phố khác hay không. Nếu có, in "YES". Nếu không, in "NO" và một cặp $(a, b)$ sao cho không thể đi từ $a$ đến $b$.

### Ý tưởng chính

Từ mọi đỉnh đến được mọi đỉnh khác khi và chỉ khi đồ thị có đúng **một thành phần liên thông mạnh (SCC)**. Sử dụng thuật toán Tarjan để tìm tất cả SCC, rồi kiểm tra:

- **Trường hợp 1 (không liên thông yếu):** Nếu DFS đầu tiên từ đỉnh $u_0$ không bao phủ tất cả đỉnh, tồn tại đỉnh $v$ chưa thăm. Khi đó $u_0$ không đến được $v$ (nếu có đường thì DFS sẽ thăm). Xuất $(u_0, v)$.

- **Trường hợp 2 (liên thông yếu nhưng không liên thông mạnh):** Nếu DFS bao phủ hết nhưng tồn tại cạnh liên SCC $u \to v$ với $\text{lab}[u] \neq \text{lab}[v]$, thì không có đường từ $v$ đến $u$ (nếu có thì $u$, $v$ cùng SCC). Xuất $(v, u)$.

Nếu cả hai trường hợp đều không xảy ra, đồ thị có đúng 1 SCC, đáp án "YES".

### Thuật toán

1. Chạy DFS Tarjan: tính `num[u]` (thứ tự thăm) và `low[u]` (giá trị `num` nhỏ nhất đến được qua cạnh cây và nhiều nhất một cạnh ngược). Khi `low[u] >= num[u]`, lấy tất cả đỉnh từ đỉnh ngăn xếp đến $u$ thành một SCC, gán nhãn `lab[v]`.
2. Trong lúc DFS, nếu bắt đầu cây DFS mới (tức DFS đầu không bao phủ hết), xuất đỉnh nguồn cây đầu tiên và đỉnh chưa thăm làm cặp vi phạm.
3. Sau DFS, nếu mọi đỉnh đã thăm, quét tất cả cạnh: nếu `lab[u] != lab[v]` trên cạnh $u \to v$, xuất $(v, u)$.
4. Nếu không có cạnh liên SCC, xuất "YES".

### Ví dụ minh họa

Đầu vào:
```
4 5
1 2
2 3
3 1
1 4
3 4
```

Tarjan tìm được: SCC 1 = $\{1, 2, 3\}$ (chu trình $1 \to 2 \to 3 \to 1$), SCC 2 = $\{4\}$.

DFS từ đỉnh 1 bao phủ hết (cạnh $1 \to 4$ đến được đỉnh 4). Kiểm tra cạnh liên SCC: cạnh $3 \to 4$ có $\text{lab}[3] \neq \text{lab}[4]$. Không có đường ngược từ 4 đến 3 (thành phố 4 không có cạnh đi ra).

Kết quả:
```
NO
4 3
```

Lưu ý: đề bài chấp nhận mọi cặp hợp lệ; $(4, 1)$ hoặc $(4, 2)$ cũng đúng vì thành phố 4 không thể đến bất kỳ thành phố nào trong SCC 1.

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — DFS Tarjan và quét cạnh liên SCC mỗi lần xử lý đúng một lần trên mỗi đỉnh và cạnh.
- **Không gian:** $O(n + m)$ — danh sách kề và các mảng phụ.

## Mã nguồn (C++)

[Mã nguồn](../code/Flight%20Routes%20Check.cpp)
