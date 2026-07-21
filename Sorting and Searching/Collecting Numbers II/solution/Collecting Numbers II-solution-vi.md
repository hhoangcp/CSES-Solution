# Collecting Numbers II - Lời giải

**ID:** 2217 | **URL:** https://cses.fi/problemset/task/2217

## Phương pháp

### Tóm tắt bài toán

Cho mảng gồm $n$ số nguyên, mỗi số từ $1$ đến $n$ xuất hiện đúng một lần. Cho $m$ phép hoán đổi hai phần tử trong mảng. Sau mỗi phép hoán đổi, in ra số vòng tối thiểu để thu thập tất cả các số theo thứ tự tăng dần (mỗi vòng duyệt mảng từ trái sang phải).

### Ý tưởng chính

Từ bài *Collecting Numbers*, ta biết số vòng bằng $1 + \sum_{i=1}^{n-1} [\text{pos}[i+1] < \text{pos}[i]]$, với $\text{pos}[v]$ là vị trí của giá trị $v$. Khi hoán đổi hai phần tử tại vị trí $a$ và $b$, chỉ có $\text{pos}[x]$ và $\text{pos}[y]$ thay đổi (với $x$, $y$ là hai giá trị bị hoán đổi). Do đó, chỉ các cặp liền kề giá trị có chứa $x$ hoặc $y$ — tức $(x-1, x)$, $(x, x+1)$, $(y-1, y)$, $(y, y+1)$ — có thể thay đổi trạng thái, tối đa 4 cặp. Tổng toàn cục phân tách thành phần không đổi và phần biến thiên cục bộ, nên ta chỉ cần: trừ đi đóng góp cũ của các cặp bị ảnh hưởng, thực hiện hoán đổi, rồi cộng lại đóng góp mới. Khi $|x - y| = 1$, cặp giao thoa chỉ xuất hiện một lần nên cần tránh đếm kép.

### Thuật toán

1. Khởi tạo: xây dựng mảng $\text{pos}$, tính số vòng ban đầu.
2. Với mỗi truy vấn hoán đổi vị trí $a$ và $b$:
   - Gọi $x$, $y$ là giá trị tại hai vị trí (đảm bảo $x < y$).
   - **Trừ cũ:** với mỗi cặp bị ảnh hưởng, nếu $\text{pos}[v+1] < \text{pos}[v]$ thì giảm Round.
   - **Hoán đổi:** cập nhật mảng giá trị và $\text{pos}[x]$, $\text{pos}[y]$.
   - **Cộng mới:** với mỗi cặp bị ảnh hưởng, nếu $\text{pos}[v+1] < \text{pos}[v]$ thì tăng Round.
   - In Round.

### Ví dụ minh họa

Mảng ban đầu $[4, 2, 1, 5, 3]$, $n = 5$.

$\text{pos}[1]=3$, $\text{pos}[2]=2$, $\text{pos}[3]=5$, $\text{pos}[4]=1$, $\text{pos}[5]=4$.

Cặp vi phạm: $(1,2)$ vì $\text{pos}[2]=2 < \text{pos}[1]=3$; $(3,4)$ vì $\text{pos}[4]=1 < \text{pos}[3]=5$. Round = $1 + 2 = 3$.

**Truy vấn 1:** hoán đổi vị trí 2 và 3 ($x=1, y=2$, $|x-y|=1$).

Cặp cần quản lý: $(1,2)$ (duy nhất vì giao thoa). Trước: vi phạm → trừ 1, Round = 2. Hoán đổi: pos[1]=2, pos[2]=3. Sau: $\text{pos}[2]=3 > \text{pos}[1]=2$ → không vi phạm. Kết quả: **2**.

Mảng sau: $[4, 1, 2, 5, 3]$.

**Truy vấn 2:** hoán đổi vị trí 1 và 5 ($x=3, y=4$, $|x-y|=1$).

Cặp cần quản lý: $(3,4)$, $(2,3)$, $(4,5)$. Trước: chỉ $(3,4)$ vi phạm → trừ 1, Round = 1. Hoán đổi: pos[3]=1, pos[4]=5. Sau: $(2,3)$ vi phạm, $(4,5)$ vi phạm → cộng 2, Round = 3. Kết quả: **3**.

Mảng sau: $[3, 1, 2, 5, 4]$.

**Truy vấn 3:** hoán đổi vị trí 2 và 3 ($x=1, y=2$, $|x-y|=1$).

Cặp cần quản lý: $(1,2)$, $(2,3)$. Trước: $(2,3)$ vi phạm → trừ 1, Round = 2. Hoán đổi: pos[1]=3, pos[2]=2. Sau: $(1,2)$ vi phạm, $(2,3)$ vi phạm → cộng 2, Round = 4. Kết quả: **4**.

## Độ phức tạp

- **Thời gian:** $O(n + m)$ — khởi tạo $O(n)$, mỗi hoán đổi $O(1)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Collecting%20Numbers%20II.cpp)
