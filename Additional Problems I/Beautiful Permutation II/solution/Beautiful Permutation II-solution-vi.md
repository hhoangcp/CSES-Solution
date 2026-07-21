# Beautiful Permutation II - Lời giải

**ID:** 3175 | **URL:** https://cses.fi/problemset/task/3175

## Đề bài

Một hoán vị của các số nguyên $1,2,\ldots,n$ được gọi là đẹp nếu không có hai phần tử kề nhau nào có hiệu bằng $1$. Nhiệm vụ là tìm hoán vị đẹp có thứ tự từ điển nhỏ nhất. Nếu không tồn tại hoán vị như vậy, in ra "NO SOLUTION".

## Hướng tiếp cận

### 1. Phân tích tính tồn tại và chứng minh

- **$n = 1$:** Hoán vị $[1]$ hiển nhiên thỏa mãn vì không có cặp phần tử kề nhau.

- **$n = 2, 3$:** Với $n = 2$, tập các hoán vị là $\{[1,2], [2,1]\}$, cả hai đều chứa cặp số liên tiếp cạnh nhau. Với $n = 3$, mọi đường đi Hamilton trên đồ thị các số từ $1 \dots 3$ (với các cạnh nối hai số có hiệu khác $1$) đều không thể bao phủ hết 3 đỉnh (chỉ có duy nhất cạnh $1-3$). Do đó không tồn tại lời giải.

- **$n \geq 4$:** Luôn tồn tại lời giải. Chứng minh: Xét cấu trúc tách nhóm "Lẻ - Chẵn" — các số lẻ tăng dần được đặt trước, sau đó là các số chẵn tăng dần (ví dụ $n = 5 \to [1, 3, 5, 2, 4]$). Khoảng cách giữa hai số lẻ hoặc hai số chẵn liên tiếp luôn là $2$. Tại vị trí tiếp giáp giữa số lẻ cuối cùng và số chẵn đầu tiên ($2$), hiệu số là $|(2\lceil n/2 \rceil - 1) - 2|$. Với $n \geq 4$, giá trị này luôn $\geq 2$, đảm bảo tính "đẹp".

### 2. Thuật toán tìm thứ tự từ điển nhỏ nhất

Để tìm được kết quả nhỏ nhất về mặt từ điển, ta áp dụng phương pháp **Quay lui** (Backtracking) với các quy tắc sau:

- **Thứ tự ưu tiên:** Tại mỗi vị trí $i$ trong hoán vị (từ trái sang phải), ta luôn thử chọn số $x$ nhỏ nhất chưa sử dụng trong tập $\{1, 2, \dots, n\}$.
- **Ràng buộc cục bộ:** Số $x$ chỉ được chọn nếu $|x - \text{phần tử trước đó}| \neq 1$.
- **Chứng minh tính tối ưu:** Vì không gian tìm kiếm được duyệt theo thứ tự tăng dần của các giá trị tại từng vị trí, nên cấu hình hợp lệ đầu tiên mà thuật toán chạm đến chắc chắn là cấu hình nhỏ nhất theo thứ tự từ điển. Cụ thể: tại vị trí đầu tiên, thuật toán thử giá trị nhỏ nhất trước; nếu tồn tại hoán vị đẹp bắt đầu bằng giá trị này, thuật toán sẽ tìm thấy và hoán vị này nhỏ hơn mọi hoán vị bắt đầu bằng giá trị lớn hơn. Nếu không, thuật toán thử giá trị lớn hơn. Tương tự cho từng vị trí tiếp theo.
- **Cắt tỉa (Pruning):** Ngay khi một nhánh không thể chọn được số nào thỏa mãn điều kiện kề nhau, ta quay lui ngay lập tức. Do tính chất của bài toán hoán vị đẹp, các nhánh sai thường bị loại bỏ sớm, giúp thuật toán chạy hiệu quả.

### Ví dụ

$n = 5$: Hoán vị đẹp nhỏ nhất là $[1, 3, 5, 2, 4]$.

- $|1 - 3| = 2 \neq 1$ $\checkmark$
- $|3 - 5| = 2 \neq 1$ $\checkmark$
- $|5 - 2| = 3 \neq 1$ $\checkmark$
- $|2 - 4| = 2 \neq 1$ $\checkmark$

$n = 3$: Không tồn tại, xuất "NO SOLUTION".

## Độ phức tạp

- **Thời gian:** $O(n!)$ theo lý thuyết, nhưng thực tế thời gian thực thi rất nhanh nhờ các ràng buộc cắt tỉa mạnh mẽ của bài toán hoán vị.
- **Bộ nhớ:** $O(n)$ để lưu trữ mảng trạng thái các số đã dùng và ngăn xếp đệ quy.

## Mã nguồn (C++)

[Mã nguồn](../code/Beautiful%20Permutation%20II.cpp)
