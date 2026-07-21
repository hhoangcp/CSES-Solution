# Tree Isomorphism II - Lời giải

**ID:** 1701 | **URL:** https://cses.fi/problemset/task/1701

## Phương pháp

### Tóm tắt bài toán

Cho hai cây không có gốc, xác định chúng có đẳng cấu không — tức cùng cấu trúc khi bỏ qua nhãn đỉnh.

### Ý tưởng chính

Với cây không gốc, quy về bài toán cây có gốc bằng cách gốc hóa tại **trọng tâm (centroid)**. Trọng tâm là đỉnh mà khi loại bỏ nó, không có thành phần nào lớn hơn $\lfloor n/2 \rfloor$; mỗi cây có đúng 1 hoặc 2 trọng tâm kề nhau. Mọi phép đẳng cấu phải ánh xạ trọng tâm sang trọng tâm (vì tính trọng tâm là tính cấu trúc), nên chỉ cần thử ghép cặp trọng tâm. Gốc hóa cây 1 tại trọng tâm đầu tiên, thử gốc hóa cây 2 tại từng trọng tâm — nếu băm cây có gốc (như Tree Isomorphism I) khớp ở bất kỳ cặp nào, hai cây đẳng cấu.

### Thuật toán

1. **Tìm trọng tâm** cả hai cây bằng DFS (tính kích thước cây con; đỉnh $u$ là trọng tâm iff mọi $\text{sz}[v] \leq n/2$ và $n - \text{sz}[u] \leq n/2$).
2. Gốc hóa cây 1 tại trọng tâm đầu tiên, tính băm (ID cấu trúc).
3. Với mỗi trọng tâm của cây 2, gốc hóa và tính băm. Nếu khớp, xuất YES.
4. Ngược lại, xuất NO.

### Ví dụ minh họa

$n=3$. Cây 1: đường 1-2-3 (trọng tâm {2}). Cây 2: sao 1-{2,3} (trọng tâm {1}). Gốc tại trọng tâm: mỗi cây có 2 con lá → cùng băm → YES.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — tìm trọng tâm $O(n)$, băm $O(n \log n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Tree%20Isomorphism%20II.cpp)
