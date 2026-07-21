# Pizza Khổng Lồ - Lời giải

**ID:** 1684 | **URL:** https://cses.fi/problemset/task/1684

## Hướng tiếp cận

### Tóm tắt bài toán

Có $n$ thành viên và $m$ loại nhân. Mỗi thành viên đưa ra hai mong muốn dạng "+x" (nhân $x$ là tốt) hoặc "-x" (nhân $x$ là xấu). Chọn nhân sao cho ít nhất một mong muốn của mỗi người được thỏa mãn. Nếu không thể, in "IMPOSSIBLE".

### Ý tưởng chính

Mô hình hóa thành bài toán **2-SAT**: mỗi nhân $i$ là biến boolean ($x_i = $ true nghĩa là chọn). Mỗi thành viên đưa ra mệnh đề $(a \lor b)$. Mệnh đề $(a \lor b)$ tương đương hai hệ quả: $\neg a \implies b$ và $\neg b \implies a$.

Xây **đồ thị hệ quả** với $2m$ đỉnh: đỉnh $i$ cho $x_i = \text{true}$, đỉnh $i+m$ cho $\neg x_i$. Với mỗi mệnh đề, thêm hai cạnh hệ quả.

Dùng **thuật toán Kosaraju** tìm tất cả SCC. Công thức 2-SAT thỏa mãn được khi và chỉ khi không có biến nào có $x_i$ và $\neg x_i$ cùng SCC. Nếu $x_i$ và $\neg x_i$ cùng SCC, thì $x_i \implies \neg x_i$ và $\neg x_i \implies x_i$, dẫn đến vô lý $x_i \iff \neg x_i$.

Nếu thỏa mãn, gán trị theo so sánh chỉ số SCC: $x_i = \text{true}$ nếu $\text{scc}[i] > \text{scc}[i+m]$, ngược lại $x_i = \text{false}$. Cách gán đúng vì Kosaraju xử lý SCC theo thứ tự tô-pô ngược — nếu $\text{scc}[x_i] > \text{scc}[\neg x_i]$ thì SCC của $\neg x_i$ được xử lý trước, không có hệ quả buộc $x_i$ sai. Mọi hệ quả $x_i \implies \neg x_i$ sẽ đặt $\neg x_i$ cùng SCC hoặc SCC xử lý sau (scc lớn hơn), mâu thuẫn với $\text{scc}[x_i] > \text{scc}[\neg x_i]$.

### Thuật toán

1. **Xây đồ thị hệ quả:** Với mỗi mệnh đề $(a \lor b)$, thêm cạnh $\neg a \to b$ và $\neg b \to a$. Đỉnh $i$ biểu diễn $x_i$; đỉnh $i+m$ biểu diễn $\neg x_i$. Phủ định: đỉnh $j$ ánh xạ sang $j+m$ nếu $j \leq m$, ngược lại $j-m$.
2. **Kosaraju:** DFS trên đồ thị gốc, ghi thứ tự hoàn thành. DFS trên đồ thị chuyển vị theo thứ tự ngược — mỗi cây DFS là một SCC.
3. **Kiểm tra:** Nếu $\text{scc}[i] = \text{scc}[i+m]$ với bất kỳ $i$, xuất "IMPOSSIBLE".
4. **Gán trị:** Với mỗi nhân $i$: nếu $\text{scc}[i] > \text{scc}[i+m]$, xuất "+"; ngược lại xuất "-".

### Ví dụ minh họa

Đầu vào:
```
3 5
+ 1 + 2
- 1 + 3
+ 4 - 2
```

3 thành viên, 5 nhân. Mệnh đề: $x_1 \lor x_2$, $\neg x_1 \lor x_3$, $x_4 \lor \neg x_2$.

Cạnh hệ quả (10 đỉnh: 1–5 cho true, 6–10 cho false):
- Mệnh đề 1: $\neg x_1 \to x_2$ (6→2), $\neg x_2 \to x_1$ (7→1)
- Mệnh đề 2: $x_1 \to x_3$ (1→3), $\neg x_3 \to \neg x_1$ (8→6)
- Mệnh đề 3: $\neg x_4 \to \neg x_2$ (9→7), $x_2 \to x_4$ (2→4)

Kosaraju: không có biến nào có $x_i$ và $\neg x_i$ cùng SCC. Gán trị: scc[1] < scc[6] → $x_1 = -$; scc[2] > scc[7] → $x_2 = +$; scc[3] > scc[8] → $x_3 = +$; scc[4] > scc[9] → $x_4 = +$; scc[5] < scc[10] → $x_5 = -$.

Kết quả:
```
- + + + -
```

Kiểm tra: thành viên 1 (+1 hoặc +2) = (S hoặc Đ) ✓; thành viên 2 (-1 hoặc +3) = (Đ hoặc Đ) ✓; thành viên 3 (+4 hoặc -2) = (Đ hoặc S) ✓.

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — hai lần DFS trên đồ thị $2m$ đỉnh và $2n$ cạnh.
- **Không gian:** $O(n + m)$

## Mã nguồn (C++)

[Mã nguồn](../code/Giant%20Pizza.cpp)
