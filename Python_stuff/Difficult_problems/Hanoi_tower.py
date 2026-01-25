import turtle
import time

# --- 1. CẤU HÌNH VÀ HẰNG SỐ ---
PEG_POSITIONS = {
    'A': -200,  # Cọc nguồn (trái)
    'B': 0,     # Cọc trung gian (giữa)
    'C': 200    # Cọc đích (phải)
}
DISK_HEIGHT = 20
BASE_WIDTH = 40

# --- 2. CÁC HÀM VẼ (GRAPHICS) ---

def draw_peg(pen, x, name):
    """Vẽ một cọc và tên cọc tại vị trí x"""
    pen.penup()
    pen.goto(x, -100)   # Chân cọc
    pen.pendown()
    pen.color("black")
    pen.pensize(5)
    pen.goto(x, 150)    # Đỉnh cọc
    
    # Viết tên cọc
    pen.penup()
    pen.goto(x, -130)
    pen.write(name, align="center", font=("Arial", 16, "bold"))

def draw_disk(pen, peg, disk_size, level):
    """Vẽ một đĩa tại cọc 'peg' ở tầng 'level'"""
    x_center = PEG_POSITIONS[peg]
    y_bottom = -90 + level * DISK_HEIGHT  # Tính toán độ cao y
    width = BASE_WIDTH + disk_size * 30   # Đĩa lớn thì rộng hơn
    
    pen.penup()
    pen.goto(x_center - width // 2, y_bottom) # Góc trái dưới
    pen.pendown()
    
    # Chọn màu cho đĩa dựa trên kích thước
    colors = ["red", "orange", "yellow", "green", "blue", "purple", "violet"]
    color = colors[(disk_size - 1) % len(colors)]
    
    pen.fillcolor(color)
    pen.pencolor("black")
    pen.pensize(1)
    
    pen.begin_fill()
    for _ in range(2):
        pen.forward(width)
        pen.left(90)
        pen.forward(DISK_HEIGHT)
        pen.left(90)
    pen.end_fill()

def draw_state(pen, state):
    """Xóa màn hình và vẽ lại toàn bộ trạng thái hiện tại"""
    pen.clear()  # Xóa hình cũ
    
    # 1. Vẽ 3 cọc
    for name in ['A', 'B', 'C']:
        draw_peg(pen, PEG_POSITIONS[name], name)
        
    # 2. Vẽ các đĩa trên từng cọc
    for peg in ['A', 'B', 'C']:
        disks_on_peg = state[peg]
        for level, disk_size in enumerate(disks_on_peg):
            draw_disk(pen, peg, disk_size, level)
            
    pen.getscreen().update() # Cập nhật màn hình (do đã tắt tracer)

# --- 3. LOGIC THUẬT TOÁN ---

def move_disk_state(state, source, target):
    """Cập nhật dữ liệu trạng thái: Chuyển đĩa từ source sang target"""
    if len(state[source]) > 0:
        disk = state[source].pop() # Lấy đĩa trên cùng cọc nguồn
        state[target].append(disk) # Đặt lên đỉnh cọc đích

def hanoi_graphic(n, source, target, auxiliary, state, pen):
    """Thuật toán đệ quy kết hợp vẽ đồ họa"""
    if n == 1:
        # Di chuyển logic
        move_disk_state(state, source, target)
        # Vẽ lại hình
        draw_state(pen, state)
        # Tạm dừng để mắt người kịp nhìn
        time.sleep(0.5)
        return

    # Bước 1: Chuyển n-1 đĩa sang cọc phụ
    hanoi_graphic(n - 1, source, auxiliary, target, state, pen)
    
    # Bước 2: Chuyển đĩa lớn nhất sang đích
    move_disk_state(state, source, target)
    draw_state(pen, state)
    time.sleep(0.5)
    
    # Bước 3: Chuyển n-1 đĩa từ cọc phụ về đích
    hanoi_graphic(n - 1, auxiliary, target, source, state, pen)

# --- 4. CHƯƠNG TRÌNH CHÍNH (MAIN) ---

def main():
    # Cấu hình màn hình Turtle
    screen = turtle.Screen()
    screen.title("Mô phỏng Tháp Hà Nội - Đệ quy")
    screen.setup(width=800, height=600)
    screen.tracer(0) # Tắt chế độ vẽ chậm (animation) để vẽ tức thì
    
    # Tạo bút vẽ
    pen = turtle.Turtle()
    pen.hideturtle()
    pen.speed(0)
    
    # Nhập số lượng đĩa
    num_disks = int(screen.numinput("Cài đặt", "Nhập số lượng đĩa (1-8):", 3, minval=1, maxval=8))
    
    # Khởi tạo trạng thái ban đầu
    # Cọc A chứa tất cả đĩa (từ lớn đến nhỏ: [3, 2, 1])
    initial_state = {
        'A': list(range(num_disks, 0, -1)), 
        'B': [],
        'C': []
    }
    
    # Vẽ trạng thái ban đầu
    draw_state(pen, initial_state)
    time.sleep(1) # Chờ 1 giây trước khi bắt đầu
    
    # Bắt đầu thuật toán đệ quy
    hanoi_graphic(num_disks, 'A', 'C', 'B', initial_state, pen)
    
    # Kết thúc
    pen.penup()
    pen.goto(0, -200)
    pen.write("HOÀN THÀNH!", align="center", font=("Arial", 20, "bold"))
    screen.mainloop()

if __name__ == "__main__":
    main()