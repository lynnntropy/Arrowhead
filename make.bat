@ECHO OFF

rem This is the Windows makefile for Arrowhead.
rem You need PDCurses installed to compile properly.
rem I've only tested it on MinGW. I can't guarantee it'll compile on other toolkits.

gcc main_win.c -o main.exe -lpdcurses
