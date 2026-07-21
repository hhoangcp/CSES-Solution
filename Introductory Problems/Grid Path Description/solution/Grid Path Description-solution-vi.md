# Grid Path Description - Lời giải

**ID:** 1625 | **URL:** https://cses.fi/problemset/task/1625

## Phương pháp

### Tóm tắt bài toán

Đếm số đường đi trên lưới $7 \times 7$ từ $(1,1)$ đến $(1,7)$ khớp với mẫu 48 ký tự cho trước gồm 'U', 'D', 'L', 'R' và '?' (bất kỳ hướng). Đường đi phải thăm mỗi ô đúng 1 lần (đường Hamilton, 48 bước).

### Ý tưởng chính

Quay lui đơn giản với $4^{48} \approx 7.2 \times 10^{28}$ khả năng là không khả thi. Tối ưu then chốt là **tỉa nhánh theo quy tắc chia cắt**, phát hiện khi đường đi hiện tại chia vùng chưa thăm thành hai thành phần không kết nối — khiến không thể hoàn thành đường Hamilton.

**Quy tắc chia cắt:** Tại ô hiện tại $(x, y)$, tỉa nhánh ngay nếu một trong hai điều kiện sau đúng:
1. **Rào dọc:** Ô trên và dưới bị chặn (biên hoặc đã thăm), nhưng ô trái và phải đều mở.
2. **Rào ngang:** Ô trái và phải bị chặn, nhưng ô trên và dưới đều mở.

*Tính đúng đắn:* Giả sử ô trên bị chặn và cả trái/phải đều mở. Đi sang trái (hoặc phải) biến ô hiện tại thành tường, cách ly vùng mở ở phía đối diện — đường duy nhất nối hai bên đi qua ô hiện tại (đã thăm). Vùng cách ly không thể đến được mà không đi lại ô đã thăm, vi phạm điều kiện đường đi đơn. Do đó tỉa nhánh là an toàn.

Tỉa nhánh bổ sung: đến $(1,7)$ trước bước 49 là không hợp lệ (các ô còn lại không thể thăm); nếu khoảng cách Manhattan đến $(1,7)$ lớn hơn số bước còn lại thì không thể đến đích đúng lúc.

Với quy tắc chia cắt, hầu hết nhánh bị cắt rất sớm — trong lưới $7 \times 7$, tình huống chia cắt xuất hiện thường xuyên, giảm hệ số phân nhánh từ 4 xuống 1 trong nhiều trường hợp. Mẫu toàn '?' có đúng 88,418 đường đi hợp lệ và chạy dưới 1 giây.

### Thuật toán

```
Try(step, x, y):
    nếu (x, y) == (1, 7): count += (step == 49); trả về
    nếu quy tắc chia cắt đúng: trả về
    đánh dấu (x, y) đã thăm
    nếu mẫu[step] == '?': thử tất cả 4 hướng hợp lệ
    ngược lại: thử chỉ hướng được chỉ định
    bỏ đánh dấu (x, y)
```

### Ví dụ minh họa

Đầu vào: `??????R??????U??????????????????????????LD????D?` → Kết quả: 201.

## Độ phức tạp

- **Thời gian:** chạy dưới 1 giây với tỉa nhánh chia cắt
- **Không gian:** $O(1)$ — lưới cố định $7 \times 7$ và độ sâu đệ quy tối đa 48

## Mã nguồn (C++)

[Mã nguồn](../code/Grid%20Path%20Description.cpp)
