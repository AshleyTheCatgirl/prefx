repo="http://github.com/AshleyTheCatgirl/prefx"

pud() {
	pushd $@ >/dev/null
}

pod() {
	popd >/dev/null
}

echo "[Starting prefx]"
echo "[Checking updates...]"
mkdir ~/.prefx/ 2>/dev/null
pud ~/.prefx/
[ -d ~/.prefx/app/.git ] && {
	pud ~/.prefx/app/
	git pull -f
	pod
} || {
	pud ~/.prefx/
	echo $repo repo
	git clone "$repo" app
	pod
}
echo "[Okay]"
echo "[Launching...]"
pod
bash ~/.prefx/app/main.sh