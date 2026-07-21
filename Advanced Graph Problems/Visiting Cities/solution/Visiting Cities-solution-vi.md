# Visiting Cities - Lời giải

**ID:** 1203 | **URL:** https://cses.fi/problemset/task/1203

## Phương pháp

### Tóm tắt bài toán

Tìm tất cả thành phố nằm trên mọi đường đi ngắn nhất từ thành phố 1 đến thành phố $n$.

### Ý tưởng chính

Chạy Dijkstra từ 1, giữ lại chỉ các cạnh $(u, v, c)$ thỏa $\text{dist}[v] = \text{dist}[u] + c$ — tạo DAG đường đi ngắn nhất chứa mọi tuyến tối ưu. Một thành phố chắc chắn đi qua khi và chỉ khi nó **dominate** $n$ trong DAG này (mọi đường từ 1 đến $n$ đều qua nó). Xây **cây dominator** bằng Lengauer-Tarjan: $u$ dominate $v$ iff $u$ là tổ tiên $v$ trong cây, nên đáp án chính là các đỉnh trên đường đi từ 1 đến $n$ trong cây dominator.

### Thuật toán

1. **Dijkstra** từ 1, tính $\text{dist}[u]$.
2. **Xây DAG đường đi ngắn nhất:** giữ cạnh $(u, v, c)$ iff $\text{dist}[v] = \text{dist}[u] + c$.
3. **Lengauer-Tarjan** trên DAG:
   - DFS từ 1, đánh số thứ tự DFS.
   - Xử lý ngược thứ tự DFS, tính semi-dominator ($sdom$) bằng DSU nén đường.
   - Với mỗi đỉnh $w$: nếu $sdom[w] = sdom[\text{Find}(w)]$ thì $\text{dom}[w] = sdom[w]$, ngược lại $\text{dom}[w] = \text{Find}(w)$.
   - Bước cuối: nếu $sdom[w] \ne \text{dom}[w]$, đặt $\text{dom}[w] = \text{dom}[\text{dom}[w]]$.
4. **Xây cây dominator** từ các cạnh $(\text{dom}[w], w)$.
5. **Truy vết** đường đi từ $n$ về 1 trong cây dominator — đây là các thành phố chắc chắn đi qua.

### Ví dụ minh họa

5 thành phố, chuyến bay: 1→2 (3), 1→3 (4), 2→3 (1), 2→4 (5), 3→4 (1), 4→5 (8).

Dijkstra: dist = [0, 3, 4, 5, 13]. Cạnh 2→4 bị loại (dist[2]+5=8≠5). DAG: 1→2, 1→3, 2→3, 3→4, 4→5.

Cây dominator: 1→2, 1→3, 3→4, 4→5. Đường 1→5: {1, 3, 4, 5}. Thành phố 2 không chắc chắn (có thể đi 1→3).

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$ — Dijkstra $O(m \log n)$, Lengauer-Tarjan $O(n + m)$
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Visiting%20Cities.cpp)
