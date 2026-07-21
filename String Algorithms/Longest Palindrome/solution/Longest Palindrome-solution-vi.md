# Longest Palindrome - Lời giải

**ID:** 1111 | **URL:** https://cses.fi/problemset/task/1111

## Đề bài

Cho một chuỗi $s$ độ dài $n$ gồm các ký tự 'a'–'z'. Hãy tìm chuỗi con đối xứng (palindrome) dài nhất trong $s$. Nếu có nhiều đáp án, có thể in bất kỳ.

## Hướng tiếp cận

### Bước 1: Biến đổi chuỗi để xử lý thống nhất

Một chuỗi đối xứng có thể có độ dài lẻ (ví dụ $\text{"aba"}$) hoặc chẵn (ví dụ $\text{"abba"}$). Để xử lý đồng bộ cả hai, chèn ký tự sentinel `#` giữa mọi cặp ký tự liên tiếp và ở cả hai đầu, tạo chuỗi $t$ độ dài $2n+1$. Khi đó mọi chuỗi đối xứng của $s$ — dù lẻ hay chẵn — đều trở thành chuỗi đối xứng có độ dài lẻ trong $t$ (tâm tại một ký tự thực cho palindrome lẻ, tại một ký tự `#` cho palindrome chẵn).

### Bước 2: Thuật toán Manacher

Với mỗi vị trí $i$ trong $t$, tính $M[i]$ = bán kính chuỗi đối xứng dài nhất nhận $i$ làm tâm, tức $t[i-M[i]..i+M[i]]$ là chuỗi đối xứng và $M[i]$ là giá trị lớn nhất thỏa mãn.

Thuật toán duy trì cửa sổ đối xứng $[L, R]$ mở rộng xa nhất về bên phải ($L$ là tâm, $R = L + M[L]$). Với mỗi vị trí $i$:

1. **Khởi tạo:** Nếu $i \le R$, tận dụng đối xứng gương qua tâm $L$ (vị trí đối xứng của $i$ là $2L - i$). Bán kính tại $i$ ít nhất bằng $\min(R - i, M[2L-i])$: giá trị đối xứng đã biết $M[2L-i]$ bị chặn bởi biên phải $R - i$ (vì chưa kiểm tra quá $R$). Đặt $M[i] = \min(R - i, M[2L-i])$. Nếu $i > R$, đặt $M[i] = 0$.
2. **Mở rộng:** Tăng $M[i]$ khi $t[i-M[i]-1] = t[i+M[i]+1]$ (so sánh cặp ký tự ngay ngoài biên đối xứng), cho đến khi khác nhau hoặc chạm biên chuỗi.
3. **Cập nhật:** Nếu $i + M[i] > R$, dịch cửa sổ sang tâm mới $L = i$, $R = i + M[i]$.

**Tính đúng của khởi tạo đối xứng:** do $t[2L-R..R]$ đối xứng qua $L$, mọi cặp ký tự đối xứng qua $L$ trong đoạn này đều bằng nhau; vậy chuỗi đối xứng tâm $2L-i$ (bán kính $M[2L-i]$) có ảnh gương tại $i$ với cùng bán kính, chỉ bị chặn bởi biên phải $R$. Khởi tạo $\min(R-i, M[2L-i])$ là chặn dưới đúng; phần còn lại do bước mở rộng kiểm tra trực tiếp.

Quét trái sang phải và chỉ cập nhật đáp án khi $M[i]$ lớn hơn nghiêm ngặt, nên giữ lại tâm đầu tiên đạt bán kính lớn nhất — tương đương chuỗi xuất hiện sớm nhất.

### Bước 3: Trích xuất kết quả

Gọi $\text{res} = M[c]$ là bán kính lớn nhất và $c$ là tâm tương ứng. Độ dài chuỗi đối xứng dài nhất trong $s$ đúng bằng $\text{res}$ (số ký tự thực trong đoạn đối xứng). Chuỗi kết quả được trích từ $t[c-\text{res}+1..c+\text{res}-1]$, chỉ lấy các ký tự thực (chỉ số chẵn), bỏ các `#` ở hai biên.

### Ví dụ minh họa

Lấy ví dụ trong đề bài: $s = \text{"aybabtu"}$ ($n = 7$), chuỗi biến đổi $t = \text{"\#a\#y\#b\#a\#b\#t\#u\#"}$ ($|t| = 15$).

| $i$ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| $t[i]$ | # | a | # | y | # | b | # | a | # | b | # | t | # | u | # |
| $M[i]$ | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 3 | 0 | 1 | 0 | 1 | 0 | 1 | 0 |

Bán kính lớn nhất $\text{res} = 3$ tại tâm $c = 8$ (ký tự $\text{a}$). Đoạn đối xứng trong $t$: $t[5..11] = \text{"\#b\#a\#b\#"}$; trích các ký tự thực ở chỉ số chẵn (6, 8, 10) được $\text{"bab"}$, độ dài $3 = \text{res}$.

Kết quả:
```
bab
```

## Độ phức tạp

- **Thời gian:** $O(n)$ $\textemdash$ mỗi bước mở rộng thành công tăng biên phải $R$ lên ít nhất 1; $R$ chỉ tăng từ 0 đến tối đa $2n+1$ nên tổng số bước mở rộng là $O(n)$.
- **Bộ nhớ:** $O(n)$ $\textemdash$ lưu mảng $M$ và chuỗi biến đổi $t$.

## Mã nguồn (C++)

[Mã nguồn](../code/Longest%20Palindrome.cpp)
