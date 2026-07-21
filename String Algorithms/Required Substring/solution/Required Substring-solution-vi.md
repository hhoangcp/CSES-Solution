# Required Substring - Lời giải

**ID:** 1112 | **URL:** https://cses.fi/problemset/task/1112

## Đề bài

Cho mẫu $S$ độ dài $m$ (các ký tự 'A'–'Z'). Đếm số chuỗi độ dài $n$ trên bảng chữ cái 26 ký tự chứa $S$ làm chuỗi con, lấy modulo $10^9+7$.

## Hướng tiếp cận

### Bước 1: Đếm bù

Đếm số chuỗi độ dài $n$ **không** chứa $S$ làm chuỗi con, rồi lấy $26^n$ trừ đi:

$$\text{Đáp án} = 26^n - (\text{số chuỗi độ dài } n \text{ không chứa } S) \pmod{10^9+7}$$

### Bước 2: Trạng thái QHĐ

Gọi $dp[i][j]$ = số chuỗi độ dài $i$ không chứa $S$, và hậu tố dài nhất của chuỗi đó khớp với đúng $j$ ký tự đầu của $S$ ($0 \le j < m$). Trường hợp cơ sở $dp[0][0] = 1$.

**Tại sao chỉ cần theo dõi hậu tố dài nhất khớp?** Khi xây chuỗi từng ký tự, khả năng xuất hiện $S$ chỉ phụ thuộc vào hậu tố dài nhất đang trùng với tiền tố của $S$: nếu nó dài $j$, việc thêm ký tự tiếp theo chỉ có thể kéo dài sự khớp hoặc thu ngắn lại về một tiền tố ngắn hơn của $S$. Mọi hậu tố ngắn hơn đã nằm gọn trong $j$ (vì $S[0..j-1]$ khớp thì mọi tiền tố ngắn hơn cũng khớp), nên $j$ chứa đủ thông tin để tiếp tục. Quy nạp theo $i$: mỗi chuỗi độ dài $i$ ở trạng thái $j$ mở rộng bằng 26 ký tự, chuyển đúng sang trạng thái $j'$ ứng với hậu tố dài nhất mới, không trùng lặp và không sót; trạng thái $j'=m$ (đã chứa $S$) bị loại.

### Bước 3: Tính chuyển trạng thái bằng hàm Z

Khi đang ở trạng thái $j$ (đã khớp $S[0..j-1]$) và thêm ký tự $c$, trạng thái mới $j' = \text{longest}[j][c]$ là độ dài tiền tố dài nhất của $S$ đồng thời là hậu tố của $S[0..j-1]+c$. Bảng $\text{longest}$ tính trước bằng hàm Z:

1. Nối $T = S + \text{`.`} + S[0..j-1] + c$ (dấu `.` ngăn cách, không thuộc bảng chữ cái).
2. Tính hàm Z trên $T$; $Z[p]$ là độ dài khớp của $T[p..]$ với tiền tố $T$ (tức $S$).
3. Trong đoạn ứng với $S[0..j-1]+c$, tìm vị trí $p$ sớm nhất mà khớp kéo dài đến cuối ($Z[p]+p-1 = |T|-1$). Khi đó $Z[p]$ chính là $\text{longest}[j][c]$ — hậu tố dài nhất của $S[0..j-1]+c$ bằng tiền tố dài nhất của $S$.

(Vì dấu `.` không có trong $S$ hay $c$, sự khớp không vượt qua `.`; vị trí $p$ sớm nhất cho hậu tố dài nhất, đúng bằng giá trị lớn nhất cần tìm.)

### Bước 4: Công thức truy hồi và đáp án

Với $i = 1..n$, $j = 0..m-1$, mỗi ký tự $c$:

$$dp[i][\text{longest}[j][c]] \mathrel{+}= dp[i-1][j] \pmod{10^9+7}$$

Nếu $\text{longest}[j][c] = m$ (thêm $c$ làm xuất hiện $S$), chuyển đó đi vào trạng thái $m$ — bị loại vì vòng sau chỉ duyệt $j < m$ và tổng cuối chỉ lấy $j < m$. Vậy số chuỗi không chứa $S$ là $\sum_{j=0}^{m-1} dp[n][j]$, và đáp án là $26^n$ trừ đi lượng này (cộng modulo để tránh âm).

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $n = 6$, $S = \text{"ABCDB"}$ ($m = 5$).

Bảng chuyển $\text{longest}[j][c]$ (chỉ liệt kê các chuyển khác 0):

| trạng thái $j$ | chuyển khi thêm ký tự |
|---|---|
| 0 | A→1 (còn lại →0) |
| 1 | A→1, B→2 (còn lại →0) |
| 2 | A→1, C→3 (còn lại →0) |
| 3 | A→1, D→4 (còn lại →0) |
| 4 | A→1, B→5 (=m, loại) (còn lại →0) |

Bảng QHĐ $dp[i][j]$ (cột "tổng" = số chuỗi độ dài $i$ không chứa $S$):

| $i \backslash j$ | 0 | 1 | 2 | 3 | 4 | tổng |
|---|---|---|---|---|---|---|
| 0 | 1 | 0 | 0 | 0 | 0 | 1 |
| 1 | 25 | 1 | 0 | 0 | 0 | 26 |
| 2 | 649 | 26 | 1 | 0 | 0 | 676 |
| 3 | 16873 | 676 | 26 | 1 | 0 | 17576 |
| 4 | 438697 | 17576 | 676 | 26 | 1 | 456976 |
| 5 | 11406121 | 456976 | 17576 | 676 | 26 | 11881375 |
| 6 | 296559121 | 11881375 | 456976 | 17576 | 676 | 308915724 |

Tổng tại $i=6$ là $308915724 = 26^6 - 52$. Đáp án: $26^6 - 308915724 = 52$.

Kiểm tra trực quan: chuỗi độ dài 6 chứa $\text{"ABCDB"}$ phải có dạng $\text{"ABCDB}x\text{"}$ (26 chuỗi) hoặc $x\text{"ABCDB"}$ (26 chuỗi); hai dạng không giao (vì ở vị trí trùng, một dạng yêu cầu `B` còn dạng kia yêu cầu `A`), nên đúng $52$.

Kết quả:
```
52
```

## Độ phức tạp

- **Thời gian:** $O(n \cdot m \cdot 26 + m^2 \cdot 26)$ $\textemdash$ tính bảng $\text{longest}$ bằng hàm Z mất $O(m^2 \cdot 26)$, vòng QHĐ mất $O(n \cdot m \cdot 26)$.
- **Bộ nhớ:** $O(n \cdot m)$ $\textemdash$ bảng QHĐ kích thước $(n+1) \times m$ và bảng chuyển $O(m \cdot 26)$.

## Mã nguồn (C++)

[Mã nguồn](../code/Required%20Substring.cpp)
