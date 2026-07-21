# Đường Đi Máy Dịch Chuyển - Lời giải

**ID:** 1693 | **URL:** https://cses.fi/problemset/task/1693

## Hướng tiếp cận

### Tóm tắt bài toán

Cho đồ thị có hướng $n$ đỉnh và $m$ cạnh, tìm đường Euler từ đỉnh 1 đến đỉnh $n$ — đường đi qua mỗi cạnh đúng một lần — hoặc kết luận "IMPOSSIBLE".

### Ý tưởng chính

Bài toán **đường Euler** trong đồ thị có hướng. Đường Euler từ đỉnh 1 đến đỉnh $n$ tồn tại khi và chỉ khi hai điều kiện sau thỏa mãn:

1. **Điều kiện bậc:** $\text{out}(1) - \text{in}(1) = 1$, $\text{in}(n) - \text{out}(n) = 1$, và $\text{in}(u) = \text{out}(u)$ với mọi đỉnh khác $u$.
2. **Điều kiện liên thông:** Tất cả các cạnh thuộc cùng một thành phần liên thông yếu.

Điều kiện bậc là cần thiết vì mỗi đỉnh trung gian phải được đi vào và đi ra số lần bằng nhau, đỉnh 1 bắt đầu đường đi (đi ra nhiều hơn 1 lần), đỉnh $n$ kết thúc (đi vào nhiều hơn 1 lần). Điều kiện cũng đủ: thêm cạnh ảo $n \to 1$ khiến mọi bậc cân bằng, đồ thị liên thông yếu nên tồn tại chu trình Euler; bỏ cạnh ảo thu được đường Euler từ 1 đến $n$.

Nếu thỏa mãn điều kiện, tìm đường Euler bằng **thuật toán Hierholzer**: bắt đầu DFS từ đỉnh 1, tại mỗi đỉnh đi theo một cạnh đi ra chưa dùng (loại khỏi danh sách kề), khi không còn cạnh đi ra thì thêm đỉnh vào kết quả. Kết quả được xây dựng theo hậu thứ tự, nên đảo ngược sẽ được đường đi từ 1 đến $n$.

**Tính đúng đắn của Hierholzer.** Đỉnh chỉ được thêm vào đường đi sau khi tất cả cạnh đi ra đã được duyệt. Đọc kết quả theo thứ tự ngược, mỗi đỉnh có đúng một cạnh đã dùng dẫn đến đỉnh tiếp theo. Đỉnh cuối cùng được thêm là 1 (đỉnh bắt đầu), đỉnh đầu tiên là $n$ (đỉnh kết thúc).

Sau khi tính đường đi, kiểm tra độ dài bằng $m + 1$ (tức đã duyệt hết $m$ cạnh). Nếu không, một số cạnh không đến được từ đỉnh 1, tức đồ thị không liên thông yếu, xuất "IMPOSSIBLE".

### Thuật toán

1. Đọc input, tính `in[u]` và `out[u]` cho mỗi đỉnh.
2. Kiểm tra điều kiện bậc: $\text{out}(1) - \text{in}(1) = 1$, $\text{in}(n) - \text{out}(n) = 1$, và $\text{in}(u) = \text{out}(u)$ với mọi $u \neq 1, n$. Nếu không thỏa mãn, xuất "IMPOSSIBLE".
3. Chạy thuật toán Hierholzer từ đỉnh 1, ghi nhận đỉnh theo hậu thứ tự.
4. Nếu độ dài đường đi không bằng $m + 1$, xuất "IMPOSSIBLE". Ngược lại, đảo ngược và xuất đường đi.

### Ví dụ minh họa

Input:
```
5 6
1 2
1 3
2 4
2 5
3 1
4 2
```

Kiểm tra bậc: out(1)−in(1) = 2−1 = 1 ✓, in(5)−out(5) = 1−0 = 1 ✓, các đỉnh còn lại cân bằng ✓.

DFS từ 1:
- Từ 1, đi cạnh 1→3. Từ 3, đi cạnh 3→1. Từ 1, đi cạnh 1→2. Từ 2, đi cạnh 2→5. Không còn cạnh từ 5 → thêm 5. Quay lại 2, đi cạnh 2→4. Từ 4, đi cạnh 4→2. Không còn cạnh từ 2 → thêm 2. Không còn cạnh từ 4 → thêm 4. Không còn cạnh từ 2 → thêm 2. Không còn cạnh từ 1 → thêm 1. Không còn cạnh từ 3 → thêm 3. Không còn cạnh từ 1 → thêm 1.

Hậu thứ tự: [5, 2, 4, 2, 1, 3, 1]. Đảo ngược: **1 3 1 2 4 2 5**.

Độ dài 7 = $m + 1$ ✓.

Kết quả:
```
1 3 1 2 4 2 5
```

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — mỗi cạnh được xử lý đúng một lần.
- **Bộ nhớ:** $O(n + m)$ — danh sách kề và mảng đường đi.

## Mã nguồn (C++)

[Mã nguồn](../code/Teleporters%20Path.cpp)
