#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// ==========================================
// 1. LỚP CƠ SỞ TRỪU TƯỢNG: TaiLieu
// ==========================================
class TaiLieu {
protected:
    string maTL;
    string tenTL;
    string nxb;
    int namXB;

public:
    // Constructors
    TaiLieu() : maTL(""), tenTL(""), nxb(""), namXB(0) {}
    TaiLieu(string ma, string ten, string n, int nam) 
        : maTL(ma), tenTL(ten), nxb(n), namXB(nam) {}
    virtual ~TaiLieu() {}

    // Getters & Setters
    string getMaTL() const { return maTL; }
    void setMaTL(string ma) { maTL = ma; }

    string getTenTL() const { return tenTL; }
    void setTenTL(string ten) { tenTL = ten; }

    string getNxb() const { return nxb; }
    void setNxb(string n) { nxb = n; }

    int getNamXB() const { return namXB; }
    void setNamXB(int nam) { namXB = nam; }

    // Phương thức thuần ảo: Tính tiền dựa theo đặc thù từng loại
    virtual double TinhTien() const = 0; 

    // Phương thức ảo hỗ trợ đa hình khi nhập/xuất
    virtual void Nhap(istream& in) {
        cout << "  Nhap Ma tai lieu: ";
        getline(in, maTL);
        cout << "  Nhap Ten tai lieu: ";
        getline(in, tenTL);
        cout << "  Nhap Nha xuat ban: ";
        getline(in, nxb);
        cout << "  Nhap Nam xuat ban: ";
        in >> namXB;
        in.ignore();
    }

    virtual void Xuat(ostream& out) const {
        out << left << setw(10) << maTL 
            << setw(25) << tenTL 
            << setw(18) << nxb 
            << setw(8) << namXB;
    }

    // Quá tải toán tử Nhập / Xuất
    friend istream& operator>>(istream& in, TaiLieu& tl) {
        tl.Nhap(in);
        return in;
    }

    friend ostream& operator<<(ostream& out, const TaiLieu& tl) {
        tl.Xuat(out);
        return out;
    }
};

// ==========================================
// 2. LỚP KẾ THỪA: Sach
// ==========================================
class Sach : public TaiLieu {
private:
    string tacGia;
    int soTrang;

public:
    Sach() : TaiLieu(), tacGia(""), soTrang(0) {}
    Sach(string ma, string ten, string n, int nam, string tg, int trang)
        : TaiLieu(ma, ten, n, nam), tacGia(tg), soTrang(trang) {}

    // Getters & Setters
    string getTacGia() const { return tacGia; }
    void setTacGia(string tg) { tacGia = tg; }

    int getSoTrang() const { return soTrang; }
    void setSoTrang(int trang) { soTrang = trang; }

    // Đa hình: Phí mượn = 10k cơ bản + 50đ/trang
    double TinhTien() const override {
        return 10000.0 + (soTrang * 50.0);
    }

    void Nhap(istream& in) override {
        TaiLieu::Nhap(in);
        cout << "  Nhap Tac gia: ";
        getline(in, tacGia);
        cout << "  Nhap So trang: ";
        in >> soTrang;
        in.ignore();
    }

    void Xuat(ostream& out) const override {
        TaiLieu::Xuat(out);
        string detail = "TG: " + tacGia + " (" + to_string(soTrang) + " tr)";
        out << left << setw(28) << detail
            << right << fixed << setprecision(0) << setw(12) << TinhTien() << " d";
    }
};

// ==========================================
// 3. LỚP KẾ THỪA: TapChi
// ==========================================
class TapChi : public TaiLieu {
private:
    int soPhatHanh;
    int thangPhatHanh;

public:
    TapChi() : TaiLieu(), soPhatHanh(0), thangPhatHanh(0) {}
    TapChi(string ma, string ten, string n, int nam, int soPH, int thangPH)
        : TaiLieu(ma, ten, n, nam), soPhatHanh(soPH), thangPhatHanh(thangPH) {}

    // Getters & Setters
    int getSoPhatHanh() const { return soPhatHanh; }
    void setSoPhatHanh(int so) { soPhatHanh = so; }

    int getThangPhatHanh() const { return thangPhatHanh; }
    void setThangPhatHanh(int thang) { thangPhatHanh = thang; }

    // Đa hình: Phí mượn cố định 15k
    double TinhTien() const override {
        return 15000.0;
    }

    void Nhap(istream& in) override {
        TaiLieu::Nhap(in);
        cout << "  Nhap So phat hanh: ";
        in >> soPhatHanh;
        cout << "  Nhap Thang phat hanh: ";
        in >> thangPhatHanh;
        in.ignore();
    }

    void Xuat(ostream& out) const override {
        TaiLieu::Xuat(out);
        string detail = "So: " + to_string(soPhatHanh) + " - Thang " + to_string(thangPhatHanh);
        out << left << setw(28) << detail
            << right << fixed << setprecision(0) << setw(12) << TinhTien() << " d";
    }
};

// ==========================================
// 4. LỚP KẾ THỪA: Bao
// ==========================================
class Bao : public TaiLieu {
private:
    string ngayPhatHanh; // Chuỗi ngày dd/mm/yyyy

public:
    Bao() : TaiLieu(), ngayPhatHanh("") {}
    Bao(string ma, string ten, string n, int nam, string ngay)
        : TaiLieu(ma, ten, n, nam), ngayPhatHanh(ngay) {}

    // Getters & Setters
    string getNgayPhatHanh() const { return ngayPhatHanh; }
    void setNgayPhatHanh(string ngay) { ngayPhatHanh = ngay; }

    // Đa hình: Phí mượn cố định 5k
    double TinhTien() const override {
        return 5000.0;
    }

    void Nhap(istream& in) override {
        TaiLieu::Nhap(in);
        cout << "  Nhap Ngay phat hanh (dd/mm/yyyy): ";
        getline(in, ngayPhatHanh);
    }

    void Xuat(ostream& out) const override {
        TaiLieu::Xuat(out);
        string detail = "Ngay: " + ngayPhatHanh;
        out << left << setw(28) << detail
            << right << fixed << setprecision(0) << setw(12) << TinhTien() << " d";
    }
};

// ==========================================
// 5. LỚP QUẢN LÝ THƯ VIỆN
// ==========================================
class QuanLyThuVien {
private:
    vector<TaiLieu*> dsTaiLieu;

public:
    ~QuanLyThuVien() {
        for (auto tl : dsTaiLieu) {
            delete tl;
        }
        dsTaiLieu.clear();
    }

    void ThemTaiLieu(TaiLieu* tl) {
        dsTaiLieu.push_back(tl);
    }

    void InTieuDeBang() const {
        cout << "\n" << string(97, '=') << "\n";
        cout << left << setw(10) << "Ma TL" 
             << setw(25) << "Ten Tai Lieu" 
             << setw(18) << "NXB" 
             << setw(8) << "Nam XB" 
             << setw(28) << "Thong Tin Rieng" 
             << right << setw(14) << "Phi Muon" << "\n";
        cout << string(97, '-') << "\n";
    }

    void HienThiDanhSach() const {
        if (dsTaiLieu.empty()) {
            cout << "\n[Thong bao] Danh sach hien dang trong!\n";
            return;
        }

        InTieuDeBang();
        for (const auto& tl : dsTaiLieu) {
            cout << *tl << "\n"; // Đa hình runtime qua operator<<
        }
        cout << string(97, '=') << "\n";
    }

    void TinhTongDoanhThu() const {
        double tong = 0;
        for (const auto& tl : dsTaiLieu) {
            tong += tl->TinhTien(); // Đa hình runtime
        }
        cout << "\n>>> TONG CHI PHI/DOANH THU MUON: " 
             << fixed << setprecision(0) << tong << " VND\n";
    }
};

// ==========================================
// 6. CHƯƠNG TRÌNH CHÍNH (Console Menu)
// ==========================================
int main() {
    QuanLyThuVien ql;
    int luaChon;

    do {
        cout << "\n============================================\n";
        cout << "      HE THONG QUAN LY THU VIEN (OOP)       \n";
        cout << "============================================\n";
        cout << " 1. Them moi Sach\n";
        cout << " 2. Them moi Tap chi\n";
        cout << " 3. Them moi Bao\n";
        cout << " 4. Hien thi toan bo danh sach tai lieu\n";
        cout << " 5. Tinh tong phi muon toan thu vien\n";
        cout << " 0. Thoat chuong trinh\n";
        cout << "--------------------------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
            case 1: {
                cout << "\n--- NHAP THONG TIN SACH ---\n";
                TaiLieu* s = new Sach();
                cin >> *s;
                ql.ThemTaiLieu(s);
                cout << "=> Da them Sach thanh cong!\n";
                break;
            }
            case 2: {
                cout << "\n--- NHAP THONG TIN TAP CHI ---\n";
                TaiLieu* tc = new TapChi();
                cin >> *tc;
                ql.ThemTaiLieu(tc);
                cout << "=> Da them Tap chi thanh cong!\n";
                break;
            }
            case 3: {
                cout << "\n--- NHAP THONG TIN BAO ---\n";
                TaiLieu* b = new Bao();
                cin >> *b;
                ql.ThemTaiLieu(b);
                cout << "=> Da them Bao thanh cong!\n";
                break;
            }
            case 4:
                ql.HienThiDanhSach();
                break;
            case 5:
                ql.TinhTongDoanhThu();
                break;
            case 0:
                cout << "\nDang thoat chuong trinh. Tam biet!\n";
                break;
            default:
                cout << "\n[Loi] Lua chon khong hop le! Vui long nhap lai.\n";
                break;
        }
    } while (luaChon != 0);

    return 0;
}