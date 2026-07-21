# Sorting Methods - Lời giải

**ID:** 1162 | **URL:** https://cses.fi/problemset/task/1162

## Đề bài

Cho hoán vị của $1, 2, \ldots, n$, tính số bước tối thiểu để sắp xếp bằng 4 phương pháp: (1) đổi chỗ liền kề, (2) đổi chỗ bất kỳ, (3) di chuyển phần tử đến vị trí bất kỳ, (4) di chuyển phần tử lên đầu.

## Hướng tiếp cận

### Phương pháp 1: Đổi chỗ hai phần tử kề nhau → Số nghịch đảo

**Số bước tối thiểu = Số nghịch đảo (Inversions).**

Mỗi phép đổi chỗ $a[i], a[i+1]$ làm thay đổi số nghịch đảo đúng $\pm 1$: giảm 1 nếu $a[i] > a[i+1]$ (loại bỏ cặp nghịch đảo đó), tăng 1 nếu $a[i] < a[i+1]$ (tạo thêm 1 nghịch đảo mới). Vì mảng sắp xếp có 0 nghịch đảo, số phép đổi liền kề tối thiểu bằng đúng số nghịch đảo ban đầu.

Tính bằng BIT: với mỗi phần tử $a[i]$, đếm số phần tử lớn hơn nó đã xuất hiện phía trước.

$$\text{inv} = \sum_{i=1}^{n} (i - 1 - \text{Query}(n - a[i]))$$

### Phương pháp 2: Đổi chỗ bất kỳ hai phần tử → Phân tích chu trình

**Số bước tối thiểu = $n$ - (Số chu trình của hoán vị).**

Hoán vị phân tích thành các chu trình rời nhau. Chu trình độ dài $k$ cần đúng $k-1$ phép đổi (đổi phần tử đầu với phần tử đúng vị trí, lặp lại). Tổng: $\sum (k_i - 1) = n - c$.

**Tính tối ưu:** Mỗi phép đổi tối đa tạo thêm 1 điểm cố định (chu trình độ dài 1), nên cần ít nhất $n - c$ phép.

### Phương pháp 3: Di chuyển phần tử đến vị trí bất kỳ → LIS

**Số bước tối thiểu = $n$ - (Độ dài dãy con tăng dài nhất).**

Các phần tử thuộc LIS đã ở đúng thứ tự tương đối, giữ nguyên. Các phần tử còn lại ($n - |LIS|$) mỗi phần tử cần đúng 1 phép di chuyển.

**Tính tối ưu:** Mọi phần tử chưa ở đúng vị trí cần ít nhất 1 phép di chuyển. Vì LIS là tập lớn nhất các phần tử đã đúng thứ tự tương đối, cần ít nhất $n - |LIS|$ phép.

Tính LIS bằng BIT: với mỗi $a[i]$, $dp[a[i]] = \max_{j < a[i]} dp[j] + 1$.

### Phương pháp 4: Di chuyển phần tử lên đầu → Hậu tố dãy con dài nhất

**Số bước tối thiểu = $n$ - (Độ dài hậu tố dài nhất của $[1..n]$ xuất hiện như dãy con).**

Tìm $k$ lớn nhất sao cho $\{k, k+1, \ldots, n\}$ xuất hiện đúng thứ tự trái→phải trong mảng. Các phần tử này giữ nguyên; các phần tử từ $1$ đến $k-1$ đưa lên đầu theo thứ tự ngược: $k-1, k-2, \ldots, 1$.

**Tính tối ưu:** Mỗi phép di chuyển lên đầu chỉ cố định đúng 1 phần tử ở vị trí 1, nên cần ít nhất $n - |\text{hậu tố}|$ phép.

Duyệt từ phải sang trái: theo dõi $ans$ bắt đầu từ $n$, giảm khi $a[i] = ans$.

### Ví dụ minh họa

Mảng: `7 8 2 6 5 1 3 4`

| Phương pháp | Cách tính | Kết quả |
| :--- | :--- | :--- |
| **P1** | Đếm cặp $(i, j)$ mà $i < j$ và $a[i] > a[j]$ | **20** |
| **P2** | 2 chu trình: $(1 \to 7 \to 3 \to 2 \to 8 \to 4 \to 6)$, $(5)$. Bước: $8 - 2$ | **6** |
| **P3** | LIS = $\{1, 3, 4\}$ hoặc $\{2, 3, 4\}$, độ dài 3. Bước: $8 - 3$ | **5** |
| **P4** | Hậu tố $\{7, 8\}$ đúng thứ tự. Bước: $8 - 2$ | **6** |

Kết quả đúng: `20 6 5 6`

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ cho cả 4 phương pháp (BIT trong P1 và P3)
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Sorting%20Methods.cpp)
