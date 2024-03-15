@echo off

setlocal enabledelayedexpansion

set base=c:\commons\c\dev-cpp
path=%base%\bin;%path%

del /Q /S .\work\*.o .\work\*.exe >nul

set sorg=C:\\Users\\Molinari\\Documents\\lavoro\\C_Tests\\Sw4\\

rem Compila tutti i file sorgente .c nella directory src
for %%i in (".\Sw4\*.c") do (
    gcc -pipe -std=c11 -w -ggdb -c -fpermissive -malign-double -O%2 "%%i" -o ".\work\%%~ni.o"
)

if errorlevel 1 goto end

set obj=C:\\Users\\Molinari\\Documents\\lavoro\\C_Tests\\Sw4\\work\\

rem Ottieni tutti i nomi dei file .o nella directory work
set files=
for %%f in (".\work\*.o") do (
    set files=!files! ".\work\%%~nf.o"
)

echo %files%

rem Controlla se ci sono errori nella compilazione
if errorlevel 1 goto end

rem Compila il programma utilizzando tutti i file .o trovati
gcc -pipe -std=c11 -O%2 -ggdb -mconsole -lole32 -lwinmm -lws2_32 -liphlpapi -lddraw -ldxguid -ldxerr8 %files% -o .\work\%1
rem gcc -pipe -std=c11 -O%2 -ggdb -mconsole -lole32 -lwinmm -lws2_32 -liphlpapi -lddraw -ldxguid -ldxerr8 ".\work\main.o" ".\work\complex.o" -o .\work\%1

if errorlevel 1 goto end
@echo Errors: 0 errors
@goto fine

:end
@echo Errors: 1 errors
:fine