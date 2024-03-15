@echo off
set base=c:\commons\c\dev-cpp
path=%base%\bin;%path%
del /Q /S .\work\*.o .\work\*.exe >nul
gcc -pipe -std=c11 -w -ggdb -c -fpermissive -malign-double -O%4 %1.c -o .\work\%1.o
gcc -pipe -std=c11 -w -ggdb -c -fpermissive -malign-double -O%4 %2.c -o .\work\%2.o
if errorlevel 1 goto end 
rem gcc -O%4 -ggdb -mwindows -lole32 -lwinmm -lws2_32 -liphlpapi -lddraw -ldxguid -ldxerr8 %1.o %2.o -o %3 
gcc -pipe -std=c11 -O%4 -ggdb -mconsole -lole32 -lwinmm -lws2_32 -liphlpapi -lddraw -ldxguid -ldxerr8 .\work\%1.o .\work\%2.o -o %3
if errorlevel 1 goto end
@echo Errors: 0 errors
@goto fine
:end
@echo Errors: 1 errors
:fine