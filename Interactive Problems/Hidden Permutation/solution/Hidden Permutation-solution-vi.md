# Hoán vị ẩn - Lời giải

**ID:** 3139 | **URL:** https://cses.fi/problemset/task/3139

## Phương pháp

### Tóm tắt bài toán

Có một hoán vị ẩn $P[1], P[2], \dots, P[n]$ của các số nguyên $1, 2, \dots, n$. Tìm hoán vị này bằng cách hỏi liệu $P[i] < P[j]$ hay không, với tối đa $10^4$ truy vấn.

### Ý tưởng chính

Mỗi truy vấn "? $i$ $j$" so sánh hai giá trị ẩn. Để xác định hoàn toàn hoán vị, ta cần thứ tự tương đối của tất cả $n$ giá trị — đây chính là **sắp xếp bằng so sánh**.

Ta sắp xếp mảng các chỉ số $a = [1, 2, \ldots, n]$ theo giá trị ẩn của chúng, dùng truy vấn làm phép so sánh. Sau khi sắp xếp, $a[k]$ là chỉ số của giá trị nhỏ thứ $k$, tức $P[a[k]] = k$. Ánh xạ ngược sẽ tái tạo hoán vị hoàn chỉnh.

Merge sort đảm bảo $O(n \log n)$ phép so sánh. Với $n = 1000$: $1000 \times \lceil\log_2 1000\rceil \approx 10000$, nằm trong giới hạn truy vấn. Cận dưới lý thuyết thông tin là $\log_2(n!) \approx 8530$ với $n = 1000$, nên merge sort gần tối ưu.

### Thuật toán

1. Khởi tạo $a[i] = i$ với mọi $i \in [1, n]$.
2. Thực hiện merge sort trên $a[1 \ldots n]$:
   - Trong bước trộn, để so sánh $a[i]$ và $a[j]$, hỏi "? $a[i]$ $a[j]$" (tức là $P[a[i]] < P[a[j]]$?).
   - Nếu `YES`, lấy $a[i]$; ngược lại lấy $a[j]$.
3. Sau khi sắp xếp, $a[k]$ là chỉ số của giá trị nhỏ thứ $k$. Đặt $b[a[i]] = i$ với mọi $i$.
4. Xuất "! $b[1]\ b[2]\ \ldots\ b[n]$".

### Ví dụ minh họa

$n = 3$, hoán vị ẩn $P = [3, 1, 2]$ (trùng ví dụ đề bài):

- Khởi tạo: $a = [1, 2, 3]$.
- Merge sort trên $a$:
  - Trộn $[1]$ và $[2]$: hỏi "? 1 2" → $P[1]=3 < P[2]=1$? **NO** → thứ tự: $[2, 1]$. Khi đó $a = [2, 1, 3]$.
  - Trộn $[2, 1]$ và $[3]$: hỏi "? 2 3" → $P[2]=1 < P[3]=2$? **YES** → lấy 2. Hỏi "? 1 3" → $P[1]=3 < P[3]=2$? **NO** → lấy 3. Lấy phần còn lại 1. Khi đó $a = [2, 3, 1]$.
- Ánh xạ ngược: $b[a[1]] = b[2] = 1$, $b[a[2]] = b[3] = 2$, $b[a[3]] = b[1] = 3$.
- Kết quả: $b = [3, 1, 2]$. Xuất "! 3 1 2".

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ truy vấn
- **Bộ nhớ:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Hidden%20Permutation.cpp)
