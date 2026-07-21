# Tree Isomorphism I - Lời giải

**ID:** 1700 | **URL:** https://cses.fi/problemset/task/1700

## Phương pháp

### Tóm tắt bài toán

Cho hai cây có gốc (gốc tại đỉnh 1), xác định chúng có đẳng cấu không — tức cùng cấu trúc khi bỏ qua nhãn đỉnh.

### Ý tưởng chính

Hai cây có gốc đẳng cấu khi và chỉ khi các cây con con ghép cặp đẳng cấu được. Từ đó xây dựng băm đệ quy: tính ID duy nhất cho mỗi cây con dựa trên danh sách sắp xếp ID các con. Hai cây con cùng ID khi và chỉ khi đẳng cấu (chứng minh bằng quy nạp cấu trúc: lá dùng danh sách rỗng chung; nút nội, đa tập ID con bằng nhau ↔ ghép cặp song ánh các con đẳng cấu). Thứ tự con không quan trọng nên sắp xếp trước khi tra. Dùng `map<vector<int>, int>` toàn cục gán ID — cùng danh sách sắp xếp luôn cho cùng ID.

### Thuật toán

1. Với mỗi cây, chạy DFS từ gốc.
2. Tại mỗi nút: thu thập ID các con vào vector, sắp xếp, tra hoặc cấp ID mới trong map toàn cục.
3. Hai cây đẳng cấu khi và chỉ khi gốc cùng ID.

### Ví dụ minh họa

Cây 1: đường 1-2-3. Cây 2: sao 1-{2,3}. Nút 2 trong cây 1 là nút trong (có con), nút 2 trong cây 2 là lá — ID gốc khác → KHÔNG.

Cây 1: đường 1-2-3. Cây 2: đường 1-3-2. Cùng cấu trúc → CÓ.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — sắp xếp ID con mỗi nút; tổng $\sum O(d_u \log d_u) \leq O(n \log n)$
- **Không gian:** $O(n)$ cho cây và map băm

## Mã nguồn (C++)

[Mã nguồn](../code/Tree%20Isomorphism%20I.cpp)
