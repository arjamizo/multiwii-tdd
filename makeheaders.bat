SET mypath=%~dp0
cd %mypath:~0,-1%
echo %cd%
echo cd `dirname $0`; cd ..; cd multiwii-pc-cwrapper; pwd; ../mkhdr src/*.cpp; mkdir -p include; echo find . -not -path '*include*' -iname '*.hpp' -exec mv -f {} include \; > tmp/headers.sh
SET PATH=%programfiles(x86)%\git\bin;%PATH%
cmd /k "%programfiles(x86)%\git\bin\bash.exe" tmp/headers.sh