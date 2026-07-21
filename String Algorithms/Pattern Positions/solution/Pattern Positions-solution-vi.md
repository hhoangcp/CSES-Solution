# Pattern Positions - Lời giải

**ID:** 2104 | **URL:** https://cses.fi/problemset/task/2104

## Đề bài

Cho một chuỗi $s$ độ dài $n$ và $k$ mẫu (vị trí đánh số từ 1). Với mỗi mẫu, hãy tìm vị trí xuất hiện đầu tiên của nó trong $s$; nếu không xuất hiện, in $-1$.

## Hướng tiếp cận

### Bước 1: Automaton hậu tố tích hợp vị trí kết thúc sớm nhất

Xây dựng automaton hậu tố (SAM) cho $s$, đồng thời cho mỗi trạng thái $v$ lưu $\text{first\_pos}[v]$ = vị trí kết thúc **nhỏ nhất** trong tập endpos của $v$ (tức lần kết thúc sớm nhất của các chuỗi con thuộc $v$).

Cách thiết lập trong quá trình xây dựng trực tuyến:
- Khi tạo trạng thái gốc mới $\text{cur}$ lúc thêm $s[i]$: $\text{first\_pos}[\text{cur}] = \text{len}[\text{cur}] = i$.
- Khi sao chép $\text{clone}$ từ trạng thái $q$: $\text{first\_pos}[\text{clone}] = \text{first\_pos}[q]$.

**Tính đúng:** Một trạng thái gốc $\text{cur}$ được tạo tại vị trí $i$ thì chuỗi dài nhất của nó (tiền tố $s[1..i]$) lần đầu kết thúc đúng tại $i$; các lần xuất hiện sau (nếu có) đều ở vị trí $> i$, nên $i$ chính là vị trí kết thúc nhỏ nhất. Khi clone, endpos của clone chứa toàn bộ endpos cũ của $q$ cộng với vị trí mới $i$ (lớn hơn mọi vị trí cũ), nên vị trí nhỏ nhất không đổi và bằng $\text{first\_pos}[q]$. Vậy $\text{first\_pos}[v]$ luôn là vị trí kết thúc nhỏ nhất của trạng thái $v$.

### Bước 2: Xử lý truy vấn mẫu

Với mỗi mẫu $p$ độ dài $m$: xuất phát từ trạng thái gốc, chuyển trạng thái lần lượt theo các ký tự của $p$.

- Nếu thiếu cạnh chuyển ở một bước $\to$ $p$ không xuất hiện, in $-1$.
- Nếu duyệt hết $p$ và dừng ở trạng thái $v$, lần xuất hiện đầu tiên kết thúc tại $\text{first\_pos}[v]$, nên vị trí bắt đầu là:

$$\text{vị trí bắt đầu} = \text{first\_pos}[v] - m + 1$$

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"aybabtu"}$ ($n = 7$, vị trí $1=\text{a}, 2=\text{y}, 3=\text{b}, 4=\text{a}, 5=\text{b}, 6=\text{t}, 7=\text{u}$), ba mẫu $\text{"bab"}, \text{"abc"}, \text{"a"}$. SAM có 9 trạng thái; bảng dưới chỉ liệt kê các trạng thái và cạnh liên quan:

| trạng thái | $\text{len}$ | $\text{link}$ | $\text{first\_pos}$ | cạnh chuyển (liên quan) |
|---|---|---|---|---|
| 0 | 0 | $-1$ | 0 | a→1, b→6 |
| 1 | 1 | 0 | 1 | b→5 |
| 4 | 4 | 1 | 4 | b→5 |
| 5 | 5 | 6 | 5 | t→7 |
| 6 | 1 | 0 (bản sao) | 3 | a→4 |

(Trạng thái 6 là bản sao đại diện cho $\text{"b"}$; $\text{first\_pos}=3$ là vị trí 'b' đầu tiên.)

Duyệt từng mẫu:

| mẫu | đường đi | trạng thái dừng | $\text{first\_pos}$ | vị trí bắt đầu | kết quả |
|---|---|---|---|---|---|
| $\text{"bab"}$ | $0 \xrightarrow{b} 6 \xrightarrow{a} 4 \xrightarrow{b} 5$ | 5 | 5 | $5-3+1=3$ | 3 |
| $\text{"abc"}$ | $0 \xrightarrow{a} 1 \xrightarrow{b} 5 \xrightarrow{c}\ \text{(không có)}$ | — | — | — | $-1$ |
| $\text{"a"}$ | $0 \xrightarrow{a} 1$ | 1 | 1 | $1-1+1=1$ | 1 |

Giải thích: $\text{"bab"}$ kết thúc sớm nhất tại vị trí 5 ($s[3..5]$), nên bắt đầu tại 3; $\text{"a"}$ kết thúc sớm nhất tại vị trí 1 ($s[1]$), nên bắt đầu tại 1; $\text{"abc"}$ không có trong $s$.

Kết quả:
```
3
-1
1
```

## Độ phức tạp

- **Thời gian:** $O(n \log \sigma + \sum |p_i| \log \sigma)$ $\textemdash$ xây dựng SAM và duyệt các mẫu ($\sigma = 26$; hệ số $\log\sigma$ do dùng bản đồ chuyển trạng thái).
- **Bộ nhớ:** $O(n)$ $\textemdash$ SAM có tối đa $O(n)$ trạng thái và $O(n)$ cạnh chuyển, cộng mảng $\text{first\_pos}$.

## Mã nguồn (C++)

[Mã nguồn](../code/Pattern%20Positions.cpp)
