tmpdir="$(mktemp -d)" >/dev/null
pushd "$tmpdir" >/dev/null
wget https://raw.githubusercontent.com/AshleyTheCatgirl/prefx/master/launch.sh
rm -rf ~/.prefx 2>/dev/null
mkdir -p ~/.prefx/ 2>/dev/null
pushd ~/.prefx/ >/dev/null
git clone "$(cat "$tmpdir/launch.sh"  | grep repo= | sed 's/^......//;s/.$//g')" app
popd >/dev/null
mkdir ~/.bin 2>/dev/null
mv launch.sh ~/.bin/prefx >/dev/null
chmod +x ~/.bin/prefx >/dev/null
echo "Zainstalowano PreFX do ~/.bin/prefx. Możesz chcieć dodać ~/.bin/ do \$PATH."
popd >/dev/null
rm -rf "$tmpdir" >/dev/null