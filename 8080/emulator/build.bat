#for windows exe with win32 support

gcc -c emu.c -I../disassembler -Wl',--subsystem,windows' -lgdi32

gcc emu.o dw_io.o -Wl',--subsystem,windows' -lgdi32 -o emu.exe

#to allow printing directly to console, change --subsystem,windows to --subsystem,console


#updated for ncurses
gcc -c emu.c -I../disassembler -lncurses
gcc emu.o dw_io.o -lncurses -o emu.exe