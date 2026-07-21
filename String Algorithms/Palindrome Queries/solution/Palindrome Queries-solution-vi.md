# Palindrome Queries - Lời giải

**ID:** 2420 | **URL:** https://cses.fi/problemset/task/2420

## Đề bài

Cho một chuỗi $s$ gồm $n$ ký tự (a–z), vị trí đánh số từ $1$. Hãy xử lý $m$ thao tác:
1. Đổi ký tự tại vị trí $k$ thành $x$.
2. Hỏi chuỗi con $s[a..b]$ có phải chuỗi đối xứng hay không.

## Hướng tiếp cận

### Bước 1: Băm đa thức

Để kiểm tra $s[l..r]$ đối xứng, ta so sánh mã băm của nó theo chiều thuận với mã băm theo chiều ngược. Dùng cơ số $B = 31$ và modulo nguyên tố $M = 10^9+8277$; đặt $v_i = s[i] - \text{'a'} + 1$.

- **Băm thuận** (trọng số giảm dần trái→phải): $H_f(l,r) = \sum_{i=l}^{r} v_i \cdot B^{n-i} \pmod M$.
- **Băm ngược** (trọng số tăng dần trái→phải): $H_b(l,r) = \sum_{i=l}^{r} v_i \cdot B^{i-1} \pmod M$.

Do hai băm dùng gốc mũ khác nhau, ta chuẩn hóa trước khi so sánh:

$$H_f(l,r) \cdot B^{-(n-r)} \equiv H_b(l,r) \cdot B^{-(l-1)} \pmod M$$

**Tính đúng:** Sau chuẩn hóa, băm thuận trở thành $\sum_{i=l}^{r} v_i B^{r-i}$ (hệ số cao→thấp là $v_l, v_{l+1}, \ldots, v_r$), còn băm ngược trở thành $\sum_{i=l}^{r} v_i B^{i-l}$ (hệ số cao→thấp là $v_r, \ldots, v_l$, tức dãy đảo). Hai đa thức bằng nhau khi và chỉ khi dãy $(v_l, \ldots, v_r)$ đúng bằng dãy đảo ngược, tức $s[l..r]$ là chuỗi đối xứng. Nếu chuỗi không đối xứng thì hai băm khác nhau, trừ khi xảy ra va chạm băm (xác suất mỗi truy vấn $\approx 1/M$, đủ nhỏ với $M \approx 10^9$).

### Bước 2: Cây chỉ số nhị phân (BIT) cho cập nhật động

Vì cần cập nhật ký tự tại từng vị trí, ta không thể dùng mảng cộng dồn tĩnh. Dùng hai BIT:
- BIT thứ nhất lưu tổng băm thuận: vị trí $i$ lưu $v_i \cdot B^{n-i}$.
- BIT thứ hai lưu tổng băm ngược: vị trí $i$ trong chuỗi gốc được phản chiếu sang vị trí $n-i+1$ trên BIT này, lưu $v_i \cdot B^{i-1}$.

Mỗi BIT hỗ trợ cập nhật điểm và truy vấn tổng tiền tố trong $O(\log n)$; tổng đoạn $[l,r]$ lấy hiệu hai truy vấn tiền tố. Khi đổi $s[u]$ từ cũ sang mới, lượng chênh lệch $\Delta = (v_{\text{mới}} - v_{\text{cũ}})$ nhân với trọng số tương ứng được cập nhật vào hai BIT. Để trả lời truy vấn loại 2 trên $[l,r]$: lấy $H_f(l,r)$ từ BIT thứ nhất, lấy $H_b(l,r)$ từ BIT thứ hai (với các chỉ số phản chiếu $n-l+1$ và $n-r$), chuẩn hóa và so sánh.

### Bước 3: Tính trước lũy thừa và nghịch đảo

Tính sẵn $B^i \pmod M$ và $B^{-i} \pmod M$ cho $i = 0..n$. Nghịch đảo lấy qua định lý Fermat nhỏ ($M$ nguyên tố nên $B^{-1} \equiv B^{M-2} \pmod M$, rồi nhân lũy tiến), đưa chi phí nhân chuẩn hóa về $O(1)$ mỗi lần.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $n=7$, $s = \text{"aybabtu"}$ ($1=\text{a}, 2=\text{y}, 3=\text{b}, 4=\text{a}, 5=\text{b}, 6=\text{t}, 7=\text{u}$), $5$ thao tác. Đặt $v(\text{c}) = \text{c}-\text{'a}+1$; băm chuẩn hóa của $s[l..r]$ là đa thức hệ số $(v_l, \ldots, v_r)$ (thuận) và $(v_r, \ldots, v_l)$ (ngược).

| # | thao tác | chuỗi liên quan | băm thuận chuẩn hóa | băm ngược chuẩn hóa | kết quả |
|---|---|---|---|---|---|
| 1 | `2 3 5` | $\text{"bab"}$ $(2,1,2)$ | $2B^2 + B + 2$ | $2B^2 + B + 2$ | YES |
| 2 | `1 3 x` | $s \to \text{"ayxabtu"}$ | — | — | (cập nhật) |
| 3 | `2 3 5` | $\text{"xab"}$ $(24,1,2)$ | $24B^2 + B + 2$ | $2B^2 + B + 24$ | NO |
| 4 | `1 5 x` | $s \to \text{"ayxaxtu"}$ | — | — | (cập nhật) |
| 5 | `2 3 5` | $\text{"xax"}$ $(24,1,24)$ | $24B^2 + B + 24$ | $24B^2 + B + 24$ | YES |

Hai băm chuẩn hóa bằng nhau ở truy vấn 1 và 5 (chuỗi đối xứng), khác nhau ở truy vấn 3 (hệ số $B^2$ là $24$ vs $2$).

Kết quả:
```
YES
NO
YES
```

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$ $\textemdash$ khởi tạo BIT $O(n \log n)$; mỗi cập nhật hoặc truy vấn đoạn trên BIT mất $O(\log n)$.
- **Bộ nhớ:** $O(n)$ $\textemdash$ hai BIT cùng các mảng lũy thừa và nghịch đảo.

## Mã nguồn (C++)

[Mã nguồn](../code/Palindrome%20Queries.cpp)
