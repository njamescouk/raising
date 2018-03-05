pushd ..\source
call compile.bat
popd
rpal -t 10 can.csv > can.svg
rpal -i -t 10  can.csv > canInfo.txt
rpal -d -t 10  can.csv > canDump.csv
