# Palindrome Reorder - Lời giải

**ID:** 1755 | **URL:** https://cses.fi/problemset/task/1755

## Phương pháp

### Tóm tắt bài toán

Cho xâu độ dài $n$ ($1 \le n \le 10^6$) gồm chữ cái hoa A–Z. Sắp xếp lại các ký tự để tạo xâu đối xứng (palindrome). Nếu không thể, in "NO SOLUTION".

### Ý tưởng chính

Xâu đối xứng đọc giống nhau từ hai phía, nên mọi ký tự không ở trung tâm phải xuất hiện thành cặp đối xứng. Điều này có nghĩa:
- Nếu $n$ chẵn: tần suất mọi ký tự phải chẵn.
- Nếu $n$ lẻ: đúng một ký tự có tần suất lẻ (đặt ở trung tâm); các ký tự còn lại phải chẵn.

Nếu số ký tự có tần suất lẻ vượt quá 0 ($n$ chẵn) hoặc 1 ($n$ lẻ), không thể tạo xâu đối xứng.

**Cách xây dựng:** Dùng hai con trỏ `L = 1` và `R = n`. Với mỗi ký tự có tần suất $\geq 2$, đặt một bản ở `L` và một ở `R`, rồi dịch hai con trỏ vào trong. Lặp lại cho đến khi tần suất ký tự đó dưới 2. Nếu còn một ký tự (tần suất lẻ, $n$ lẻ), đặt nó ở vị trí trung tâm $\lfloor(n+1)/2\rfloor$.

*Tính đúng đắn:* Mỗi cặp đặt tại vị trí $L$ và $R$ với $L + R = n + 1$, nên vị trí $i$ luôn khớp vị trí $n+1-i$. Ký tự trung tâm (nếu có) tự đối xứng. Mỗi ký tự được đặt đúng tần suất của nó, nên kết quả dùng đủ $n$ ký tự.

### Thuật toán

1. Đếm tần suất mỗi ký tự.
2. Kiểm tra hợp lệ: đếm số ký tự có tần suất lẻ. Nếu không hợp lệ, xuất "NO SOLUTION".
3. Xây xâu đối xứng bằng hai con trỏ, đặt ký tự theo cặp từ hai đầu.
4. Nếu $n$ lẻ, đặt ký tự có tần suất lẻ còn lại vào trung tâm.

### Ví dụ minh họa

Đầu vào: `AAAACACBA` ($n = 9$). Tần suất: A=6, C=2, B=1. Một tần suất lẻ (B), $n$ lẻ → hợp lệ.

| Bước | Ký tự | L | R | Xâu hiện tại |
|------|-------|---|---|--------------|
| 1 | A (cặp 1) | 1 | 9 | `A _ _ _ _ _ _ _ A` |
| 2 | A (cặp 2) | 2 | 8 | `A A _ _ _ _ _ A A` |
| 3 | A (cặp 3) | 3 | 7 | `A A A _ _ _ A A A` |
| 4 | C (cặp 1) | 4 | 6 | `A A A C _ C A A A` |
| 5 | B (trung tâm) | 5 | 5 | `A A A C B C A A A` |

Kết quả: `AAACBCAAA` (xâu đối xứng hợp lệ).

## Độ phức tạp

- **Thời gian:** $O(n)$
- **Không gian:** $O(n)$

## Mã nguồn (C++)

[Mã nguồn](../code/Palindrome%20Reorder.cpp)
