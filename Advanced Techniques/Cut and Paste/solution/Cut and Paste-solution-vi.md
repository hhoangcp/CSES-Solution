# Cut and Paste - Lời giải

**ID:** 2072 | **URL:** https://cses.fi/problemset/task/2072

## Phương pháp

### Tóm tắt bài toán

Cho chuỗi dài $n$ và $m$ thao tác, mỗi thao tác chỉ định đoạn $[a, b]$ (đánh số từ 1). Cắt chuỗi con từ vị trí $a$ đến $b$ rồi dán vào cuối chuỗi. Xuất chuỗi cuối cùng.

### Ý tưởng chính

Thực hiện từng thao tác cắt-dán thông thường mất $O(n)$, tổng $O(nm)$ — quá chậm. Ta cần cấu trúc dữ liệu hỗ trợ tách và nối dãy trong $O(\log n)$ kỳ vọng. **Treap** (BST ngẫu nhiên) cung cấp chính xác các thao tác này qua `Split` và `Merge`.

Mỗi thao tác "cắt $[a,b]$ dán cuối" phân rã thành hai lần tách và hai lần nối. Tách tại $b+1$ tách tiền tố $[1,b]$ khỏi hậu tố $[b+1,\text{cuối}]$. Tách tiếp tiền tố tại $a$ chia thành $[1,a-1]$ và $[a,b]$. Nối $[1,a-1]$ với $[b+1,\text{cuối}]$ tái tạo chuỗi không chứa đoạn cắt, rồi nối tiếp với $[a,b]$ đưa đoạn cắt xuống cuối. Kết quả đúng theo cấu trúc: đoạn giữa bị loại khỏi vị trí cũ và đặt ở cuối, các ký tự còn lại giữ nguyên thứ tự tương đối.

### Thuật toán

1. Xây treap từ chuỗi: chèn từng ký tự vào vị trí tương ứng.
2. Với mỗi thao tác $(a, b)$:
   - Tách treap tại vị trí $b+1$ → $T_{\text{prefix}}$ (vị trí 1 đến $b$), $T_{\text{suffix}}$ (vị trí $b+1$ đến cuối).
   - Tách $T_{\text{prefix}}$ tại vị trí $a$ → $T_{\text{left}}$ (vị trí 1 đến $a-1$), $T_{\text{cut}}$ (vị trí $a$ đến $b$).
   - Nối $T_{\text{left}}$ và $T_{\text{suffix}}$, rồi nối kết quả với $T_{\text{cut}}$.
3. Duyệt treap theo thứ tự giữa để xuất chuỗi cuối cùng.

### Ví dụ minh họa

Chuỗi: `AYBABTU`, thao tác: $(3,5)$, $(3,5)$.

**Thao tác 1 — cắt [3,5] (`BAB`), dán cuối:**
- Tách tại 6: `T_prefix` = `[A,Y,B,A,B]`, `T_suffix` = `[T,U]`
- Tách `T_prefix` tại 3: `T_left` = `[A,Y]`, `T_cut` = `[B,A,B]`
- Nối `T_left` + `T_suffix` = `[A,Y,T,U]`, rồi + `T_cut` = `[A,Y,T,U,B,A,B]`

Kết quả: `AYTUBAB`

**Thao tác 2 — cắt [3,5] (`TUB`), dán cuối:**
- Tách tại 6: `T_prefix` = `[A,Y,T,U,B]`, `T_suffix` = `[A,B]`
- Tách `T_prefix` tại 3: `T_left` = `[A,Y]`, `T_cut` = `[T,U,B]`
- Nối `T_left` + `T_suffix` = `[A,Y,A,B]`, rồi + `T_cut` = `[A,Y,A,B,T,U,B]`

Kết quả: `AYABTUB`

## Độ phức tạp

- **Thời gian:** $O((n + m) \log n)$ — mỗi tách/nối mất $O(\log n)$ kỳ vọng.
- **Không gian:** $O(n)$ — một nút treap mỗi ký tự.

## Mã nguồn (C++)

[Mã nguồn](../code/Cut%20and%20Paste.cpp)
