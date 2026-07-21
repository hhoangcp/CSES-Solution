# Counting Patterns - Lời giải

**ID:** 2103 | **URL:** https://cses.fi/problemset/task/2103

## Đề bài

Cho một chuỗi $s$ độ dài $n$ và $k$ mẫu. Với mỗi mẫu, hãy đếm số vị trí mà mẫu đó xuất hiện trong $s$.

## Hướng tiếp cận

### Bước 1: Xây dựng automaton hậu tố (SAM)

Xây dựng automaton hậu tố cho chuỗi $s$. Mỗi trạng thái $v$ trong SAM đại diện cho một tập các chuỗi con có cùng tập vị trí kết thúc (**endpos**); độ dài các chuỗi con này nằm trong khoảng $(\text{len}[\text{link}[v]], \text{len}[v]]$, trong đó $\text{link}[v]$ là liên kết hậu tố, trỏ tới trạng thái đại diện cho hậu tố riêng dài nhất.

Mỗi vị trí kết thúc trong $s$ tương ứng với một trạng thái được tạo mới (không phải bản sao) khi nạp ký tự vào SAM; các trạng thái sao chép (clone) không gắn với một vị trí cụ thể. Do đó ta khởi tạo:

$$\text{cnt}[v] = \begin{cases} 1 & v \text{ là trạng thái tạo mới} \\ 0 & v \text{ là trạng thái sao chép hoặc gốc} \end{cases}$$

### Bước 2: Lan truyền số lần xuất hiện trên cây liên kết hậu tố

Nếu $u$ là con của $v$ trong cây liên kết hậu tố ngược (tức $\text{link}[u] = v$) thì mọi vị trí kết thúc của chuỗi tại $u$ cũng là vị trí kết thúc của chuỗi tại $v$ (vì chuỗi tại $v$ là hậu tố của chuỗi tại $u$). Vậy tập endpos của $v$ là hợp của các tập endpos của con, nên số lần xuất hiện của chuỗi tại $v$ bằng tổng số lần xuất hiện của các con:

$$\text{cnt}[\text{link}[v]] \mathrel{+}= \text{cnt}[v]$$

Thực hiện bằng cách duyệt các trạng thái theo $\text{len}$ giảm dần (thứ tự tô-pô trên cây liên kết hậu tố ngược) và cộng dồn từ con lên cha. Sau bước này, $\text{cnt}[v]$ chính là số vị trí kết thúc — tức số lần xuất hiện — của mọi chuỗi con thuộc trạng thái $v$.

### Bước 3: Xử lý truy vấn mẫu

Với mỗi mẫu $p$:

- Bắt đầu từ trạng thái gốc và chuyển trạng thái lần lượt theo các ký tự của $p$.
- Nếu thiếu cạnh chuyển trạng thái cho một ký tự, mẫu $p$ không xuất hiện $\to$ kết quả $0$.
- Nếu duyệt hết $p$ và dừng tại trạng thái $v$, kết quả chính là $\text{cnt}[v]$ đã lan truyền. Điều này đúng vì mọi chuỗi con trong cùng trạng thái $v$ có cùng tập endpos, nên $p$ (nếu dẫn tới $v$) xuất hiện đúng $\text{cnt}[v]$ lần.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"aybabtu"}$ ($n = 7$), các mẫu $\text{"bab"}$, $\text{"abc"}$, $\text{"a"}$.

SAM có 9 trạng thái (trạng thái 6 là bản sao). Bảng trạng thái (chỉ số từ 0; $\text{cnt}$ khởi tạo và sau khi lan truyền):

| trạng thái | $\text{len}$ | $\text{link}$ | $\text{cnt}$ khởi tạo | $\text{cnt}$ sau lan truyền | cạnh chuyển |
|---|---|---|---|---|---|
| 0 | 0 | $-1$ | 0 | 7 | a→1, b→6, t→7, u→8, y→2 |
| 1 | 1 | 0 | 1 | 2 | b→5, y→2 |
| 2 | 2 | 0 | 1 | 1 | b→3 |
| 3 | 3 | 6 | 1 | 1 | a→4 |
| 4 | 4 | 1 | 1 | 1 | b→5 |
| 5 | 5 | 6 | 1 | 1 | t→7 |
| 6 | 1 | 0 | 0 (bản sao) | 2 | a→4, t→7 |
| 7 | 6 | 0 | 1 | 1 | u→8 |
| 8 | 7 | 0 | 1 | 1 | — |

Cây liên kết hậu tố ngược (cha $\to$ con) và quá trình lan truyền $\text{cnt}$ từ lá lên gốc:

- $0 \to \{1,2,6,7,8\}$, trong đó $1 \to \{4\}$ và $6 \to \{3,5\}$.
- Các lá $4,3,5,2,7,8$ giữ $\text{cnt}=1$; $1$ nhận thêm $\text{cnt}[4]$ $\to 2$; bản sao $6$ nhận $\text{cnt}[3]+\text{cnt}[5]$ $\to 2$; gốc $0$ nhận $2+1+2+1+1 \to 7$.

Duyệt từng mẫu trong SAM:

| mẫu | đường đi | trạng thái dừng | $\text{cnt}$ | kết quả |
|---|---|---|---|---|
| $\text{"bab"}$ | $0 \xrightarrow{b} 6 \xrightarrow{a} 4 \xrightarrow{b} 5$ | 5 | 1 | 1 |
| $\text{"abc"}$ | $0 \xrightarrow{a} 1 \xrightarrow{b} 5 \xrightarrow{c}\ \text{(không có)}$ | — | — | 0 |
| $\text{"a"}$ | $0 \xrightarrow{a} 1$ | 1 | 2 | 2 |

Giải thích: $\text{"bab"}$ chỉ xuất hiện tại $s[3..5]$ nên $\text{cnt}=1$; $\text{"a"}$ xuất hiện tại $s[1]$ và $s[4]$ nên $\text{cnt}=2$; $\text{"abc"}$ không có trong $s$ nên $0$.

Kết quả (mỗi mẫu một dòng):
```
1
0
2
```

## Độ phức tạp

- **Thời gian:** $O(n \log \sigma + \sum |p_i| \log \sigma)$ $\textemdash$ xây dựng SAM, lan truyền trên cây liên kết hậu tố, và duyệt các mẫu ($\sigma = 26$ là kích thước bảng chữ cái; hệ số $\log\sigma$ do dùng bản đồ chuyển trạng thái).
- **Bộ nhớ:** $O(n)$ $\textemdash$ SAM có tối đa $O(n)$ trạng thái và $O(n)$ cạnh chuyển trạng thái.

## Mã nguồn (C++)

[Mã nguồn](../code/Counting%20Patterns.cpp)
