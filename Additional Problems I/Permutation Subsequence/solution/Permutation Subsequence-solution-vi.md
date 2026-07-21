# Permutation Subsequence - Lời giải

**ID:** 3404 | **URL:** https://cses.fi/problemset/task/3404

## Đề bài

Cho hai mảng $a$ (kích thước $n$) và $b$ (kích thước $m$) đều là các hoán vị. Tìm dãy con chung dài nhất (LCS) của chúng và in ra một dãy con thỏa mãn.

## Hướng tiếp cận

### 1. Quy đổi bài toán LCS sang LIS

Thông thường, bài toán LCS có độ phức tạp $O(N \cdot M)$, quá chậm cho $N, M = 2 \cdot 10^5$. Tuy nhiên, vì cả hai mảng là **hoán vị**, mỗi giá trị chỉ xuất hiện đúng một lần.

- **Bước 1:** Xây dựng mảng vị trí `pos[v]` lưu vị trí của giá trị $v$ trong mảng $b$.
- **Bước 2:** Duyệt qua mảng $a$, với mỗi phần tử $a[i]$, nếu $a[i]$ có tồn tại trong $b$, ta ghi lại vị trí của nó: $c[k] = pos[a[i]]$.
- **Bước 3:** Một dãy con chung của $a$ và $b$ tương ứng với một **dãy con tăng (Increasing Subsequence)** của dãy $c$ vừa tạo. Do đó, LCS của $a$ và $b$ chính là **dãy con tăng dài nhất (LIS)** của $c$.

### 2. Tìm LIS bằng Cây Fenwick (BIT)

Ta sử dụng Cây Fenwick để tối ưu hóa việc tìm LIS trong $O(N \log M)$:

- Cây Fenwick sẽ lưu trữ giá trị $\{max\_length, index\}$.
- Khi xét phần tử $c[i]$, ta truy vấn trên BIT để tìm độ dài LIS lớn nhất kết thúc bằng một giá trị nhỏ hơn $c[i]$.
- Cập nhật độ dài mới $dp[i] = max\_length + 1$ và lưu vết $pre[i] = index$ để phục vụ việc tái tạo dãy.

### 3. Tái tạo dãy con (Reconstruction)

Sau khi tìm được độ dài LIS lớn nhất, ta bắt đầu từ vị trí có $dp$ lớn nhất và sử dụng mảng $pre$ để truy vết ngược lại các phần tử đã chọn. Cuối cùng, đảo ngược dãy kết quả để có thứ tự đúng.

## Ví dụ mô phỏng

$a = [3, 1, 2, 8, 5, 7, 6, 4]$, $b = [6, 5, 1, 2, 3, 4]$.

1. Vị trí trong $b$: $6 \to 1, 5 \to 2, 1 \to 3, 2 \to 4, 3 \to 5, 4 \to 6$.
2. Mảng $c$ (vị trí của $a[i]$ trong $b$): $[5, 3, 4, \dots, 2, \dots, 1, 6]$ (bỏ phần tử không trong $b$: 8, 7).
3. LIS của $c$: $[3, 4, 6]$ (độ dài 3).
4. Giá trị tương ứng: $b[3]=1, b[4]=2, b[6]=4 \to$ Dãy con: `1 2 4`.

## Độ phức tạp

- **Thời gian:** $O((n+m) \log m)$ — Do các thao tác xây mảng vị trí và truy vấn BIT.
- **Bộ nhớ:** $O(n+m)$ — Lưu trữ mảng $a, b, c, pos, dp$ và $pre$.

## Mã nguồn (C++)

[Mã nguồn](../code/Permutation%20Subsequence.cpp)
