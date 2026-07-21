# Distinct Colors - Lời giải

**ID:** 1139 | **URL:** https://cses.fi/problemset/task/1139

## Phương pháp

### Tóm tắt bài toán

Cho một cây có gốc gồm $n$ đỉnh (gốc là đỉnh $1$). Mỗi đỉnh $u$ được tô một màu $c_u$. Tính với mỗi đỉnh $u$ số lượng màu khác nhau trong cây con gốc $u$.

**Ràng buộc:** $1 \le n \le 2 \cdot 10^5$, $1 \le c_i \le 10^9$.

### Ý tưởng chính

**Phẳng hóa cây bằng Euler Tour:** DFS từ gốc, gán $Start[u]$ là thời điểm vào và ghi $color[Start[u]] = c_u$. Sau khi duyệt xong cây con $u$, thời điểm hiện tại chính là $End[u]$. Khi đó cây con gốc $u$ ứng với đoạn liên tiếp $[Start[u], End[u]]$ trên mảng Euler $color[1..n]$. Bài toán quy về: với mỗi đoạn $[Start[u], End[u]]$, đếm số giá trị phân biệt.

**Đếm giá trị phân biệt offline bằng BIT:** Nén tọa độ màu về $[1, n]$ (vì $c_i \le 10^9$ nhưng chỉ có $\le n$ màu khác nhau). Quét mảng Euler từ trái sang phải, trên BIT luôn giữ giá trị $1$ tại **vị trí xuất hiện cuối cùng** (bên phải nhất) của mỗi màu tính đến thời điểm hiện tại, và $0$ ở các vị trí cũ. Cụ thể, với mỗi $i$:

- Gọi $pre[i]$ là vị trí xuất hiện trước của $color[i]$ (lấy từ $link[color[i]]$). Nếu $pre[i] > 0$, xóa vị trí cũ bằng $\text{Update}(pre[i], -1)$ rồi đánh dấu vị trí mới bằng $\text{Update}(i, +1)$; nếu $pre[i] = 0$ chỉ cần $\text{Update}(i, +1)$. Cập nhật $link[color[i]] = i$.
- Khi $i = End[u]$ (đã duyệt hết cây con $u$), số màu phân biệt trong cây con $u$ là tổng số điểm $1$ trong đoạn $[Start[u], End[u]]$:

$$ans[u] = \text{Query}(End[u]) - \text{Query}(Start[u] - 1)$$

**Tính đúng đắn:** Quy nạp theo $i$: sau bước xử lý $i$, BIT mang $1$ đúng tại vị trí xuất hiện cuối cùng của mỗi màu trong $[1, i]$, vì mỗi lần gặp lại màu $c$ ta gỡ dấu cũ và đặt dấu mới tại $i$. Do cây con $u$ chiếm đoạn $[Start[u], End[u]]$ và mọi vị trí trong đoạn đều $\le End[u]$, mỗi màu xuất hiện trong cây con có đúng một vị trí "cuối cùng" nằm trong đoạn này (đó là lần xuất hiện cuối của màu đó trước hoặc tại $End[u]$, và vì màu có mặt trong cây con nên lần cuối này $\ge Start[u]$). Tổng số điểm $1$ trong đoạn đúng bằng số màu phân biệt trong cây con.

### Thuật toán

1. Đọc $n$, mảng màu $c[1..n]$ và $n-1$ cạnh; dựng danh sách kề.
2. Nén tọa độ: sắp xếp và unique mảng $c$, rồi ánh xạ mỗi $c[i]$ về chỉ số trong $[1, n]$ bằng `lower_bound`.
3. DFS từ gốc $1$ (dùng `lab[v] = u` tránh quay lên cha): $Start[u] = ++Time$, $color[Time] = c[u]$; sau khi duyệt hết con, đẩy cặp $\{Start[u], u\}$ vào danh sách $L[Time]$ (tức $Time$ lúc này $= End[u]$).
4. Vòng lặp khởi tạo $i = 1..n$: $pre[i] = link[color[i]]$; nếu $pre[i] = 0$ thì $\text{Update}(i, +1)$; gán $link[color[i]] = i$.
5. Vòng lặp chính $i = 1..n$:
   - Nếu $pre[i] > 0$: $\text{Update}(pre[i], -1)$ rồi $\text{Update}(i, +1)$.
   - Với mỗi cặp $\{Start[u], u\} \in L[i]$: $ans[u] = \text{Query}(i) - \text{Query}(Start[u] - 1)$.
6. In $ans[1..n]$.

### Ví dụ minh họa

Đề bài cho $n = 5$, màu $c = [2,\ 3,\ 2,\ 2,\ 1]$ (theo thứ tự đỉnh $1..5$); cạnh `1-2, 1-3, 3-4, 3-5`. Gốc là $1$.

Cây: con của $1$ là $\{2, 3\}$; con của $3$ là $\{4, 5\}$.

Nén tọa độ: sorted unique $= [1, 2, 3]$, ánh xạ $\Rightarrow c = [2,\ 3,\ 2,\ 2,\ 1]$.

Euler Tour (theo thứ tự kề `V[1]=[2,3]`, `V[3]=[1,4,5]`):

| $u$ | $Start[u]$ | $End[u]$ | $color[Start[u]]$ |
|---|---|---|---|
| $1$ | $1$ | $5$ | $2$ |
| $2$ | $2$ | $2$ | $3$ |
| $3$ | $3$ | $5$ | $2$ |
| $4$ | $4$ | $4$ | $2$ |
| $5$ | $5$ | $5$ | $1$ |

Mảng Euler: $color[1..5] = [2,\ 3,\ 2,\ 2,\ 1]$. Liên kết xuất hiện trước: $pre = [,\ 0,\ 0,\ 1,\ 3,\ 0]$ (màu $2$ xuất hiện tại vị trí $1, 3, 4$).

Khởi tạo BIT (đặt $1$ tại lần đầu xuất hiện mỗi màu): vị trí $1$ (màu $2$), $2$ (màu $3$), $5$ (màu $1$). $BIT = [1, 1, 0, 0, 1]$.

Quét chính:

| $i$ | Thao tác | BIT sau | Truy vấn tại $End = i$ |
|---|---|---|---|
| $1$ | $pre[1]=0$, không đổi | $[1,1,0,0,1]$ | — |
| $2$ | $pre[2]=0$, không đổi | $[1,1,0,0,1]$ | $End[2]=2$: $ans[2]=Q(2)-Q(1)=2-1=\mathbf{1}$ |
| $3$ | $pre[3]=1$: $Up(1,-1),Up(3,+1)$ | $[0,1,1,0,1]$ | — |
| $4$ | $pre[4]=3$: $Up(3,-1),Up(4,+1)$ | $[0,1,0,1,1]$ | $End[4]=4$: $ans[4]=Q(4)-Q(3)=2-1=\mathbf{1}$ |
| $5$ | $pre[5]=0$, không đổi | $[0,1,0,1,1]$ | $End[5]=5$: $ans[5]=Q(5)-Q(4)=3-2=\mathbf{1}$; $End[3]=5$: $ans[3]=Q(5)-Q(2)=3-1=\mathbf{2}$; $End[1]=5$: $ans[1]=Q(5)-Q(0)=\mathbf{3}$ |

Kết quả: `3 1 2 1 1` — khớp với ví dụ đề bài.

## Độ phức tạp

- **Thời gian:** $O(n \log n)$ — nén tọa độ $O(n \log n)$; DFS và mỗi thao tác BIT $O(\log n)$.
- **Bộ nhớ:** $O(n)$ — danh sách kề, mảng Euler/`Start`/`pre`/`link`, danh sách $L$ và BIT.

## Mã nguồn (C++)

[Mã nguồn](../code/Distinct%20Colors.cpp)
