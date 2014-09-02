set PATH=%PATH%;%programfiles(x86)%\Code blocks\mingw\bin;d:\codeblocks\mingw\bin

cmd /c "(echo open ftp.floorchan.org& echo anonymous& echo anonymous& echo bin& echo cd /vipre&ls& echo get libeay32.dll&echo get libiconv2.dll&echo get libintl3.dll&echo get libssl32.dll& echo quit) > %temp%\f.txt & ftp -s:%temp%\f.txt

cmd /c "(echo open ftp.psu.ac.th& echo anonymous& echo anonymous& echo bin& echo cd /pub/wget/&ls& echo get wget.exe& echo quit) > %temp%\f.txt & ftp -s:%temp%\f.txt

cmd /c "wget http://www.hwaci.com/sw/mkhdr/makeheaders.c"

gcc makeheaders.c -o mkhdr.exe -s -O2
del makeheaders.c