@echo off
echo Hello World
echo wait 3 sec
timeout /t 3 >nul

@set @junk=1 /*
//echo ping
//ping -n 1 -w 1000 1.1.1.1 */
pause >nul
exit