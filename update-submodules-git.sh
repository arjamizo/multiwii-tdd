set -e

ls multiwii-firmware || git submodule add --depth 100 https://github.com/multiwii/multiwii-firmware.git
git submodule update --depth 100 -- multiwii-firmware

git submodule foreach 'pwd; git checkout `git config --file ../.gitmodules --get "submodule.$name.commitid"`'