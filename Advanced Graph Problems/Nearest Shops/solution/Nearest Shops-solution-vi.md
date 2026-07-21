# Nearest Shops - Lời giải

**ID:** 3303 | **URL:** https://cses.fi/problemset/task/3303

## Phương pháp

### Tóm tắt bài toán

Cho $n$ thành phố, $m$ đường hai chiều, $k$ thành phố có cửa hàng anime. Với mỗi thành phố, tìm khoảng cách tối thiểu đến một thành phố **khác** có cửa hàng. Nếu thành phố đã có cửa hàng, phải tìm cửa hàng gần nhất *khác*. Nếu không tồn tại, xuất $-1$.

### Ý tưởng chính

Chạy BFS đa nguồn từ tất cả cửa hàng, lưu `dist[v]` (khoảng cách đến cửa hàng gần nhất) và `src[v]` (cửa hàng đó). Các thành phố cùng `src` tạo thành vùng ảnh hưởng.

- **Thành phố không có cửa hàng:** `ans = dist[v]` (cửa hàng gần nhất chắc chắn ở thành phố khác).
- **Thành phố có cửa hàng $s$:** đường đi ngắn nhất đến cửa hàng khác phải qua cạnh biên giới $(u,v)$ nơi `src[u] != src[v]`. Mọi đường đi từ $s$ đến cửa hàng khác đều phải qua cạnh đổi nguồn, và đường đi ngắn nhất đi từ $s$ đến $u$ (khoảng cách `dist[u]`), qua cạnh (+1), từ $v$ đến cửa hàng (khoảng cách `dist[v]`), tổng `dist[u] + dist[v] + 1`. Lấy min trên tất cả cạnh biên giới.

### Thuật toán

1. BFS đa nguồn từ tất cả cửa hàng. Lưu `dist[v]` và `src[v]`.
2. Khởi tạo `ans[i] = dist[i]` cho thành phố không có cửa hàng, `ans[i] = INF` cho thành phố có cửa hàng.
3. Với mỗi cạnh $(u, v)$ nơi `src[u] != src[v]`:
   - $d = \text{dist}[u] + \text{dist}[v] + 1$
   - Cập nhật `ans[src[u]] = min(ans[src[u]], d)` và `ans[src[v]] = min(ans[src[v]], d)`.
4. Với mỗi thành phố: nếu `ans[i] == INF`, xuất $-1$; ngược lại xuất `ans[i]`.

### Ví dụ minh họa

$n=9, m=6, k=4$, cửa hàng: {2,4,5,7}.

Cửa hàng 2 và 4 liền kề: cạnh (2,4) cho $d = 0+0+1=1$. `ans[2]=1, ans[4]=1`. Cửa hàng 5 và 7 cô lập: `ans[5]=-1, ans[7]=-1`.

Kết quả: `1 1 1 1 -1 1 -1 2 -1`

## Độ phức tạp

- **Thời gian:** $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Nearest%20Shops.cpp)
