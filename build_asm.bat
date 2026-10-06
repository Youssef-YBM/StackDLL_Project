@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul
cd /d "%~dp0"
cl /nologo /c /EHsc /std:c++17 /D STACKDLL_SHARED /D STACKDLL_EXPORTS /FAs /Fa Stack.cpp
