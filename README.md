# 机房预约系统 🖥️

一个基于 C++ 控制台的多用户机房预约管理系统，支持学生、教师和管理员三种角色，实现机房的在线预约、审核和管理功能。

## ✨ 题目
一、	实验目的
初步了解Windows程序设计。
二、	实验课时
2学时
三、	实验任务
练习使用VC++的AppWizard(应用程序向导)生成一个最简单的Windows应用程序。
四、	实验步骤
1．创建一个项目。
1）单击File|New，显示New对话框（如图1－1所示）。
2）在Project选项卡中，选择MFC AppWizard(exe)。在Location文本框中指定一个路径，在Project Name文本框中为项目输入一个名字lab11_1，单击OK。
2．在出现的对话框中选择Miltiple Document、Document/View Architecture support、中文［中国］，单击Next按钮。
3．在选择提供项目所需要的数据库支持种类时，选择None，即不使用数据库，单击Next按钮。
4．设置程序的OLE和ActiveX支持类型，选择None，单击Next按钮。
5．在设置用户界面特征的对话框中，不做任何改变，单击Next按钮。
6．设置使用MFC库的方式，接受缺少的选项。
7．设置类和文件名，不做任何修改。
8．单击Finish按钮后，AppWizard显示一个摘要表，其中列出了所选的项目特征。单击OK创建项目。
9．编译、运行lab11_1。
10．试着分析其框架结构，试着修改程序实现某些简单功能。


## ✨ 功能特性

### 👨‍🎓 学生功能
- **申请预约**：选择日期、时间段和机房进行预约
- **查看个人预约**：查询自己的所有预约记录
- **查看所有预约**：浏览系统中所有的预约信息
- **取消预约**：取消自己已提交的预约

### 👨‍🏫 教师功能
- **查看所有预约**：查看学生的预约申请
- **审核预约**：对学生的预约进行审核（通过/拒绝）

### 👨‍💼 管理员功能
- **添加账号**：创建新的学生或教师账号
- **查看账号**：浏览所有注册用户信息
- **查看机房**：查看系统中所有机房的信息
- **清空预约**：清除所有预约记录

## 🛠️ 技术栈

- **编程语言**: C++17
- **编译器**: GCC (MinGW)
- **开发环境**: Windows
- **数据存储**: 文本文件持久化

## 📁 项目结构

```
lab11/
├── 机房预约系统.cpp      # 主程序入口
├── identity.h            # 身份抽象基类
├── student.h/cpp         # 学生类实现
├── techer.h/cpp          # 教师类实现
├── manager.h/cpp         # 管理员类实现
├── computerRoom.h/cpp    # 机房类实现
├── orderFile.h/cpp       # 订单文件管理类
├── globalFile.h          # 全局配置文件
├── run.ps1              # PowerShell 编译运行脚本
└── README.md            # 项目说明文档
```

## 🚀 快速开始

### 前置要求

- Windows 操作系统
- GCC (MinGW) 编译器
- PowerShell

### 编译和运行

#### 方法一：使用自动化脚本（推荐）

在项目根目录下执行：

```powershell
.\run.ps1
```

该脚本会自动：
1. 编译所有源文件
2. 生成可执行文件
3. 启动程序

#### 方法二：手动编译

```powershell
# 设置编译器路径（根据实际情况修改）
$GCC_PATH = "E:/github_dowmload/x86_64-8.1.0-release-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe"

# 编译所有源文件
& $GCC_PATH -std=c++17 -g -Wall -static *.cpp -o 机房预约系统.exe

# 运行程序
& .\机房预约系统.exe
```

### 编译参数说明

- `-std=c++17`: 使用 C++17 标准
- `-g`: 生成调试信息
- `-Wall`: 启用所有警告
- `-static`: 静态链接，避免 DLL 依赖问题

## 📖 使用说明

### 登录流程

1. 运行程序后，选择身份类型：
   - 输入 `1` - 学生登录
   - 输入 `2` - 教师登录
   - 输入 `3` - 管理员登录
   - 输入 `0` - 退出系统

2. 根据提示输入账号信息：
   - **学生/教师**：需要输入 ID、用户名和密码
   - **管理员**：只需输入用户名和密码

3. 验证成功后进入对应角色的功能菜单

### 默认管理员账号

首次使用时，需要确保存在管理员账号。管理员信息存储在 `admin.txt` 文件中。

## 📝 数据文件说明

系统使用以下文本文件存储数据：

- `student.txt` - 学生账号信息
- `teacher.txt` - 教师账号信息
- `admin.txt` - 管理员账号信息
- `computerRoom.txt` - 机房信息
- `order.txt` - 预约记录

## ⚙️ 配置说明

在 `globalFile.h` 中可以修改文件路径配置：

```cpp
#define STUDENT_FILE    "student.txt"
#define TEACHER_FILE    "teacher.txt"
#define ADMIN_FILE      "admin.txt"
#define COMPUTER_FILE   "computerRoom.txt"
#define ORDER_FILE      "order.txt"
```

## 🔧 常见问题

### 1. 中文显示乱码

程序已内置 UTF-8 编码支持，如果仍出现乱码，请确保：
- 终端支持 UTF-8 编码
- 源代码文件保存为 UTF-8 格式

### 2. 缺少 DLL 文件

如果出现 `libgcc_s_seh-1.dll` 或 `libstdc++-6.dll` 缺失错误：
- 确保编译时使用了 `-static` 参数
- 或者将 MinGW 的 bin 目录添加到系统 PATH

### 3. 编译失败

- 确认 GCC 编译器路径正确
- 检查是否安装了 MinGW
- 确保所有 `.cpp` 和 `.h` 文件在同一目录

## 📄 许可证

本项目仅用于学习和教学目的。

## 🤝 贡献

欢迎提交 Issue 和 Pull Request！

## 📧 联系方式

如有问题或建议，欢迎通过 GitHub Issues 联系。

---

**注意**: 本项目是一个教学用的 C++ 控制台应用程序，展示了面向对象编程、文件操作、多态等核心技术。