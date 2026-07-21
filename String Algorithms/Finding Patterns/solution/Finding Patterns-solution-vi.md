# Finding Patterns - Lời giải

**ID:** 2102 | **URL:** https://cses.fi/problemset/task/2102

## Đề bài

Cho một chuỗi $s$ độ dài $n$ và $k$ mẫu. Với mỗi mẫu, hãy xác định xem nó có xuất hiện dưới dạng chuỗi con trong $s$ hay không.

## Hướng tiếp cận

### Bước 1: Automaton hậu tố (SAM)

Automaton hậu tố của chuỗi $s$ là một DFA tối tiểu nhận biết **đúng** tập tất cả các chuỗi con của $s$. Nó được xây dựng trực tuyến (online) bằng cách thêm từng ký tự của $s$ vào.

Mỗi trạng thái $v$ lưu:
- $\text{len}[v]$: độ dài chuỗi dài nhất kết thúc tại $v$;
- $\text{link}[v]$: liên kết hậu tố, trỏ tới trạng thái đại diện cho hậu tố riêng dài nhất của chuỗi thuộc $v$.

SAM có tối đa $2n - 1$ trạng thái.

**Tính chất cốt lõi:** Một chuỗi $p$ là chuỗi con của $s$ khi và chỉ khi, xuất phát từ trạng thái gốc và chuyển trạng thái theo lần lượt các ký tự của $p$, ta không bao giờ bị kẹt.

*Sự tương đương này* là cơ sở của lời giải: ($\Leftarrow$) mọi chuỗi con của $s$ là tiền tố của một hậu tố; trong quá trình xây dựng trực tuyến, trạng thái cuối $\text{last}$ luôn đại diện hậu tố $s[1..i]$, và qua các liên kết hậu tố mọi hậu tố đều có đường đi từ gốc, nên mọi tiền tố của hậu tố (tức mọi chuỗi con) đều được nhận biết. ($\Rightarrow$) mỗi cạnh chuyển $v \xrightarrow{c} u$ chỉ được thêm khi ký tự $c$ thực sự xuất hiện ngay sau chuỗi đại diện bởi $v$ tại một vị trí nào đó trong $s$, nên mọi đường đi từ gốc tương ứng với một chuỗi con của $s$.

### Bước 2: Xây dựng SAM

Khi thêm ký tự $c$ vào cuối chuỗi hiện tại ($\text{last}$ là trạng thái sau ký tự trước đó):

1. Tạo trạng thái mới $\text{cur}$ với $\text{len}[\text{cur}] = \text{len}[\text{last}] + 1$.
2. Duyệt ngược theo liên kết hậu tố từ $\text{last}$; tại mỗi trạng thái $p$ chưa có cạnh chuyển theo $c$, thêm cạnh $p \xrightarrow{c} \text{cur}$.
3. Nếu đi hết mà không gặp trạng thái nào đã có cạnh $c$ ($p = -1$), đặt $\text{link}[\text{cur}] = 0$.
4. Ngược lại, gặp trạng thái $p$ đã có cạnh $p \xrightarrow{c} q$:
   - Nếu $\text{len}[q] = \text{len}[p] + 1$: đặt $\text{link}[\text{cur}] = q$.
   - Nếu $\text{len}[q] > \text{len}[p] + 1$: **sao chép** $q$ thành trạng thái $\text{clone}$ với $\text{len}[\text{clone}] = \text{len}[p]+1$, $\text{link}[\text{clone}] = \text{link}[q]$, kế thừa toàn bộ cạnh chuyển của $q$; rồi đặt $\text{link}[q] = \text{link}[\text{cur}] = \text{clone}$, và điều hướng các cạnh $c$ từ các tổ tiên của $p$ đang trỏ tới $q$ sang trỏ tới $\text{clone}$.
5. Cập nhật $\text{last} = \text{cur}$.

### Bước 3: Kiểm tra mẫu

Với mỗi mẫu $p$: xuất phát từ trạng thái gốc, chuyển trạng thái lần lượt theo các ký tự của $p$.

- Nếu tại trạng thái hiện tại không có cạnh chuyển chứa ký tự tiếp theo của $p$ $\to$ mẫu không xuất hiện, in `NO`.
- Nếu duyệt hết toàn bộ $p$ mà không bị kẹt $\to$ mẫu là chuỗi con của $s$, in `YES`.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"aybabtu"}$ ($n = 7$), các mẫu $\text{"bab"}$, $\text{"abc"}$, $\text{"ayba"}$.

SAM có 9 trạng thái (trạng thái 6 là bản sao). Bảng trạng thái và cạnh chuyển:

| trạng thái | $\text{len}$ | $\text{link}$ | cạnh chuyển |
|---|---|---|---|
| 0 | 0 | $-1$ | a→1, b→6, t→7, u→8, y→2 |
| 1 | 1 | 0 | b→5, y→2 |
| 2 | 2 | 0 | b→3 |
| 3 | 3 | 6 | a→4 |
| 4 | 4 | 1 | b→5 |
| 5 | 5 | 6 | t→7 |
| 6 | 1 | 0 (bản sao) | a→4, t→7 |
| 7 | 6 | 0 | u→8 |
| 8 | 7 | 0 | — |

Duyệt từng mẫu trong SAM:

| mẫu | đường đi | kết quả | vị trí xuất hiện |
|---|---|---|---|
| $\text{"bab"}$ | $0 \xrightarrow{b} 6 \xrightarrow{a} 4 \xrightarrow{b} 5$ | `YES` | $s[3..5]$ |
| $\text{"abc"}$ | $0 \xrightarrow{a} 1 \xrightarrow{b} 5 \xrightarrow{c}\ \text{(không có)}$ | `NO` | — |
| $\text{"ayba"}$ | $0 \xrightarrow{a} 1 \xrightarrow{y} 2 \xrightarrow{b} 3 \xrightarrow{a} 4$ | `YES` | $s[1..4]$ |

Kết quả:
```
YES
NO
YES
```

## Độ phức tạp

- **Thời gian:** $O(n \log \sigma + \sum |p_i| \log \sigma)$ $\textemdash$ xây dựng SAM và duyệt các mẫu ($\sigma = 26$ là kích thước bảng chữ cái; hệ số $\log\sigma$ do dùng bản đồ chuyển trạng thái).
- **Bộ nhớ:** $O(n)$ $\textemdash$ SAM có tối đa $O(n)$ trạng thái và $O(n)$ cạnh chuyển.

## Mã nguồn (C++)

[Mã nguồn](../code/Finding%20Patterns.cpp)
