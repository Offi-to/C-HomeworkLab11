# 机房预约系统 - 编译和运行脚本
# 使用 PowerShell 执行

Write-Host "========================================" -ForegroundColor Cyan
Write-Host "   机房预约系统 - 编译和运行工具" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

$GCC_PATH = "E:/github_dowmload/x86_64-8.1.0-release-posix-seh-rt_v6-rev0/mingw64/bin/g++.exe"
$OUTPUT_EXE = ".\机房预约系统.exe"

# 检查编译器是否存在
if (-Not (Test-Path $GCC_PATH)) {
    Write-Host "错误: 找不到 GCC 编译器!" -ForegroundColor Red
    Write-Host "请检查路径: $GCC_PATH" -ForegroundColor Yellow
    exit 1
}

Write-Host "正在编译项目..." -ForegroundColor Green

# 编译所有cpp文件（使用静态链接，避免依赖DLL文件）
& $GCC_PATH -std=c++17 -g -Wall -static *.cpp -o $OUTPUT_EXE

if ($LASTEXITCODE -eq 0) {
    Write-Host "编译成功!" -ForegroundColor Green
    Write-Host ""
    Write-Host "正在启动程序..." -ForegroundColor Green
    Write-Host ""
    
    # 运行程序（等待程序执行完成）
    Start-Process -FilePath $OUTPUT_EXE -Wait
} else {
    Write-Host "编译失败! 请检查代码错误。" -ForegroundColor Red
    exit 1
}
