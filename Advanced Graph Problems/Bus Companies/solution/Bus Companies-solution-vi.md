# Bus Companies - Lời giải

**ID:** 3158 | **URL:** https://cses.fi/problemset/task/3158

## Phương pháp

### Tóm tắt bài toán

Có $n$ thành phố và $m$ công ty xe buýt. Công ty $i$ có giá vé $c_i$ và hoạt động tại $k_i$ thành phố. Mua vé từ công ty $i$ cho phép đi lại giữa bất kỳ hai thành phố mà công ty đó phục vụ. Tìm chi phí rẻ nhất từ thành phố 1 đến mọi thành phố khác.

### Ý tưởng chính

Thay vì tạo cạnh giữa mọi cặp thành phố của cùng một công ty (có thể lên tới $O(n^2)$ cạnh), dùng kỹ thuật **đỉnh trung gian**: xây đồ thị $n + m$ đỉnh, gồm $n$ đỉnh thành phố và $m$ đỉnh công ty. Mua vé công ty $i$ tương ứng với đường đi $u \to (n+i)$ (trả $c_i$) rồi $(n+i) \to v$ (chi phí 0), tổng chi phí khớp hoàn toàn bài toán gốc. Ngược lại, mọi đường đi trong đồ thị mở rộng xen kẽ giữa đỉnh thành phố và đỉnh công ty (đồ thị hai phần), mỗi lần thăm đỉnh công ty $n+i$ tốn đúng $c_i$, tương ứng việc mua và sử dụng vé. Vì Dijkstra tìm đường ngắn nhất trong đồ thị mở rộng, kết quả tương ứng với lộ trình tối ưu trong bài toán gốc.

### Thuật toán

1. Xây đồ thị $n + m$ đỉnh. Với mỗi công ty $i$ có chi phí $c_i$ phục vụ thành phố $a_1, \ldots, a_k$:
   - Thêm cạnh $a_j \to (n+i)$ trọng số $c_i$ (trả tiền mua vé).
   - Thêm cạnh $(n+i) \to a_j$ trọng số 0 (dùng vé để đến thành phố).
2. Chạy Dijkstra từ đỉnh 1.
3. Xuất `dist[1], dist[2], ..., dist[n]`.

### Ví dụ minh họa

$n=5$, $m=3$, chi phí $[4,3,2]$.

- Công ty 3 (chi phí 2) phục vụ $\{2,3,4,5\}$: cạnh $2 \to 8, 3 \to 8, 4 \to 8, 5 \to 8$ (trọng số 2) và $8 \to 2, 8 \to 3, 8 \to 4, 8 \to 5$ (trọng số 0).
- Từ thành phố 3 sang 2: $3 \xrightarrow{2} 8 \xrightarrow{0} 2$, tổng chi phí 2.

Kết quả Dijkstra từ đỉnh 1: `0 5 4 4 3`.

## Độ phức tạp

- **Thời gian:** $O((n + m + \sum k_i) \log(n + m))$
- **Không gian:** $O(n + m + \sum k_i)$

## Mã nguồn (C++)

[Mã nguồn](../code/Bus%20Companies.cpp)
