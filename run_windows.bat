@echo off
set QEMU_PATH="C:\Program Files\qemu\qemu-system-x86_64.exe"
if not exist %QEMU_PATH% (
    echo QEMU not found at %QEMU_PATH%. Please install it or update the path in this .bat file.
    pause
    exit /b
)
echo Starting ArenaOS Reality v9.0.0...
%QEMU_PATH% -cdrom ArenaOS-Reality.iso -m 1G -accel whpx -display sdl -serial stdio
pause
