# ArenaOS v9.0.0 "Reality"

Это полноценная 64-битная операционная система, написанная с нуля.

## Как собрать (Windows + GitHub)
1. Залей этот проект в свой GitHub репозиторий.
2. GitHub Actions автоматически соберет файл `ArenaOS-Reality.iso`.
3. Скачай его из вкладки **Actions** -> **Artifacts**.

## Как запустить на Windows
1. Установи [QEMU](https://www.qemu.org/download/#windows).
2. Положи скачанный `ArenaOS-Reality.iso` в папку с проектом.
3. Запусти `run_windows.bat`.

## Разработка
- Ядро: `kernel/main.c`
- Драйверы: `kernel/drivers/`
- Файловая система: `kernel/fs/`
