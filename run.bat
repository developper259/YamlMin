@echo off
color 07

:main
cls
if exist yaml.exe del yaml.exe
g++ yaml.cpp -o yaml.exe
if exist yaml.exe yaml.exe
pause
goto:main