# OOP C++ - Hard as F LoL collections

This repository contains homework assignments and laboratory exercises for Object-Oriented Programming (OOP) course using C++.

## 📚 Repository Structure

### 🔬 Laboratory Exercises

- **Lab1** - Menu system implementation
  - Basic menu-driven program structure
  - User interface fundamentals

- **Lab2** - Point class implementation
  - Working with geometric points
  - File I/O operations with `data.txt`

- **Lab3 Series** - Fraction class implementation (5 variants)
  - **Lab3a** - Basic Fraction class
  - **Lab3b** - Extended Fraction operations
  - **Lab3c** - Advanced Fraction manipulation
  - **Lab3d** - Fraction refinements
  - **Lab3e** - Fraction with file I/O support

### 📝 Homework Assignments

#### **Baitapmenu** - Multiple Choice Exam Management System
- Quiz/exam management system
- File-based storage (`de_thi.TTN`, `deThi.TTN`)
- Multiple choice question handling
- Files: `quanlydethitracnghiem.cpp`, `sourcecode.cpp`, `header.h`

#### **baitapnangcaoCh2** - Advanced Chapter 2 Exercises
- Advanced OOP concepts
- Header and source file organization

#### **Chuong5** - Chapter 5: Expression & Operator Overloading
Contains three sub-projects demonstrating expression evaluation:

**a/** - Basic Expression Implementation
- `Bieuthuc.cpp/h` - Expression base class

**b/** - Exercise B
- `caub.cpp` - Specific implementation

**chuong5all/** - Complete Chapter 5 Implementation
- Expression hierarchy with multiple operations:
  - `BieuthucCong` - Addition expressions
  - `BieuthucTru` - Subtraction expressions
  - `BieuthucNhan` - Multiplication expressions
  - `BieuthucPS` - Division expressions (Phép Chia)
  - `BieuthucPT` - Power expressions (Phương Trình)
- `Fraction` class for fractional calculations
- `Dethi` class for exam management
- Complete implementation of operator overloading

#### **chuong6** - Chapter 6: Inheritance & Polymorphism
Employee payroll system demonstrating inheritance:
- `Employee` - Base employee class
- `SalariedEmployee` - Salaried employee implementation
- `CommissionEmployee` - Commission-based employee
- `BasePlusCommissionEmployee` - Base salary + commission employee
- Demonstrates virtual functions and polymorphism

#### **ktrgk** - Midterm Exam Project
Employee management system with Factory Pattern:
- **Employee Types:**
  - `LapTrinhVien` - Programmer
  - `KeToanVien` - Accountant
  - `ChuyenVienPhanTich` - Analyst
  - `NhanVienKiemThu` - Tester

- **Bonus/Reward System:**
  - `TienThuongNgoaiGio` - Overtime bonus
  - `TienThuongNgoaiTinh` - Out-of-town bonus
  - `TienThuongThongThuong` - Standard bonus

- **Design Patterns:**
  - Factory Pattern: `NhanVienFactory`, `INhanVienFactory`
  - Strategy Pattern for bonus calculation

#### **quanlydiemquatrinh** - Progress Grade Management
- Grade tracking system
- CSV file support (`danhsach.csv`)

#### **sudungSTL** - STL Usage Examples
- Standard Template Library demonstrations
- Container and algorithm examples

## 🛠️ Build & Compile

This project uses **TDM-GCC** compiler. Each subdirectory contains an `output/` folder for compiled executables.

### Build Command (VS Code Task)
```bash
g++ -fdiagnostics-color=always -g ${file} -o ${fileDirname}\${fileBasenameNoExtension}.exe
```

### Manual Compilation
Navigate to the desired project folder and run:
```powershell
g++ main.cpp -o output/program.exe
```

For projects with multiple source files (e.g., Chuong5, Chuong6):
```powershell
g++ *.cpp -o output/program.exe
```

## 📋 Key Concepts Covered

- ✅ **Classes and Objects** - Encapsulation, constructors, destructors
- ✅ **Operator Overloading** - Custom operators for user-defined types
- ✅ **Inheritance** - Base and derived classes, access specifiers
- ✅ **Polymorphism** - Virtual functions, abstract classes
- ✅ **File I/O** - Reading and writing data to files
- ✅ **STL Containers** - Vector, list, map usage
- ✅ **Design Patterns** - Factory pattern, Strategy pattern
- ✅ **Memory Management** - Dynamic allocation, pointers

## 📖 Course Information

**Course:** Object-Oriented Programming (Lập Trình Hướng Đối Tượng)  
**Language:** C++  
**Compiler:** TDM-GCC-64

## 🗂️ File Naming Conventions

- `.cpp` - C++ source files
- `.h` - Header files
- `.exe` - Compiled executables (in `output/` folders)
- `.txt` / `.csv` / `.TTN` - Data files

## 📌 Notes

- Each project folder typically contains:
  - Source files (`.cpp`)
  - Header files (`.h`)
  - `main.cpp` - Entry point
  - `output/` - Compiled executables and data files
  
- Some projects include test data files (`.txt`, `.csv`, `.TTN` format)

## 🎓 License

This repository contains educational materials for academic purposes.

---

**Author:** harrytien107  
**Repository:** OOPkindacringe
