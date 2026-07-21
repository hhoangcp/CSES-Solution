# String Matching - Lời giải

**ID:** 1753 | **URL:** https://cses.fi/problemset/task/1753

## Đề bài

Cho chuỗi văn bản $s$ độ dài $n$ và mẫu $t$ độ dài $m$ (ký tự 'a'–'z'). Đếm số vị trí mà $t$ xuất hiện trong $s$ (chấp nhận các lần xuất hiện chồng lấn).

## Hướng tiếp cận

### Bước 1: Kỹ thuật nối chuỗi

Nối thành chuỗi kết hợp $t' = t + \text{sep} + s$, trong đó $\text{sep}$ là một ký tự phân cách không thuộc 'a'–'z' (code dùng dấu cách). Chuỗi $t'$ có độ dài $m + 1 + n$, với mẫu $t$ ở vị trí $1..m$, $\text{sep}$ ở vị trí $m+1$, văn bản $s$ ở vị trí $m+2..m+1+n$.

### Bước 2: Hàm Z và giới hạn

Tính hàm Z trên $t'$ bằng phương pháp hai con trỏ (cửa sổ $[L,R]$ xa nhất về phải đang khớp tiền tố), trong $O(n+m)$. Vì tiền tố của $t'$ chính là mẫu $t$, nên tại mỗi vị trí $i$ thuộc phần văn bản ($i > m+1$), $Z[i]$ là độ dài khớp dài nhất của $s$ (từ vị trí tương ứng) với mẫu $t$.

**Giới hạn $Z[i] \le m$:** Nếu $Z[i] > m$ với $i > m+1$, thì tiền tố khớp $t'[1..Z[i]]$ phải chứa $\text{sep}$ ở vị trí $m+1$, tức $t'[i+m]$ cũng phải bằng $\text{sep}$; nhưng $t'[i+m]$ nằm trong phần văn bản (chỉ gồm 'a'–'z'), không thể là $\text{sep}$. Mâu thuẫn. Vậy $Z[i] \le m$.

### Bước 3: Đếm lần xuất hiện

Mẫu $t$ xuất hiện tại vị trí $j$ trong văn bản gốc ($1 \le j \le n$) khi và chỉ khi $Z[m+1+j] = m$:

- ($\Rightarrow$) Nếu $s[j..j+m-1] = t$ thì $t'[m+1+j..m+j+m] = t = t'[1..m]$, nên $Z[m+1+j] \ge m$; mà $Z \le m$ (Bước 2), vậy $= m$.
- ($\Leftarrow$) Nếu $Z[m+1+j] = m$ thì $t'[m+1+j..m+j+m] = t'[1..m] = t$, tức $s[j..j+m-1] = t$.

Vậy đếm số vị trí $j$ thỏa $Z[m+1+j] = m$ (tương đương duyệt $i$ từ $m+2$ đến $m+1+n$ và đếm các $Z[i] = m$).

### Ví dụ minh họa

Lấy ví dụ trong đề bài: văn bản $s = \text{"saippuakauppias"}$ ($n = 15$), mẫu $t = \text{"pp"}$ ($m = 2$).

Chuỗi kết hợp $t' = \text{"pp\#saippuakauppias"}$ ($\#$ là ký tự phân cách), độ dài $18$.

| vị trí trong $t'$ | $1..2$ | $3$ | $4..18$ |
|---|---|---|---|
| nội dung | mẫu `pp` | phân cách | văn bản `saippuakauppias` |

Duyệt phần văn bản ($i = 4..18$), các vị trí có $Z[i] = m = 2$:

| vị trí văn bản $j$ | chỉ số $t'$ $i = m+1+j$ | $Z[i]$ | đoạn khớp $s[j..j+1]$ |
|---|---|---|---|
| 4 | 7 | 2 | $\text{"pp"}$ ($s[4..5]$) |
| 11 | 14 | 2 | $\text{"pp"}$ ($s[11..12]$) |

(Các vị trí còn lại có $Z[i] < 2$.)

Số lần xuất hiện: $2$.

Kết quả:
```
2
```

## Độ phức tạp

- **Thời gian:** $O(n + m)$ $\textemdash$ xây chuỗi kết hợp và tính hàm Z bằng phương pháp hai con trỏ đều tuyến tính theo độ dài $m+1+n$.
- **Bộ nhớ:** $O(n + m)$ $\textemdash$ lưu chuỗi kết hợp độ dài $m+1+n$ và mảng $Z$.

## Mã nguồn (C++)

[Mã nguồn](../code/String%20Matching.cpp)
