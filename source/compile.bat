set COMPILE_SRCS=..\source\dependencies\csv\CsvParser.cpp ..\source\dependencies\csv\ParsedCsv.cpp ..\source\dependencies\csv\lex.yy.c ..\source\dependencies\csv\y.tab.c ..\source\dependencies\parseCmdline\source\lex.pcl.c ..\source\dependencies\parseCmdline\source\pcl.tab.c ..\source\dependencies\split_string\split_string.cpp I:\usr\NIK\dev\rpal\source\main.cpp
set COMPILE_INCLUDES=-I..\source\dependencies\csv -I..\source\dependencies\parseCmdline\source -I..\source\dependencies\split_string -I..\source\dependencies\yacc -II:\usr\NIK\dev\rpal\source
set COMPILE_DEFINES=-DSQLITE_CORE -DSQLITE_ENABLE_MD5
rem set these for your machine...
set YACCPATH="C:\Program Files (x86)\GnuWin32\bin\yacc.exe"
set SEDPATH="C:\Program Files (x86)\GnuWin32\bin\sed.exe"
set FLEXPATH="C:\Program Files (x86)\GnuWin32\bin\flex.exe"
set GPPPATH="c:\bin\MinGWNew\bin\g++.exe"
set GCCPATH="c:\bin\MinGWNew\bin\gcc.exe"
%GPPPATH% -o rpal.exe %COMPILE_INCLUDES% %COMPILE_DEFINES% %COMPILE_SRCS% 
