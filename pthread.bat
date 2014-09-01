echo This script automatically downloads pthreads libs from ftp.linux.ee
SET mypath=%~dp0
cd %mypath:~0,-1%
mkdir tmp
cd tmp
cmd /c "echo cd & dir pthread.lib pthread.h sched.h semaphore.h || (ftp -s:..\pthread.txt)"