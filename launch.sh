[ -f ~/.prefx/app/launcher.sh ] && {
	bash ~/.prefx/app/launcher.sh
	exit
}

repo="http://github.com/AshleyTheCatgirl/prefx"

pud() {
	pushd $@ >/dev/null
}

pod() {
	popd >/dev/null
}

echo "[Starting prefx]"
mkdir ~/.prefx/ 2>/dev/null
pud ~/.prefx/
[ -d ~/.prefx/app/.git ] && {
	echo "[Checking updates...]"
	pud ~/.prefx/app/
	git pull -f
	pod
} || {
	echo "[Downloading app...]"
	pud ~/.prefx/
	git clone "$repo" app
	pod
}
echo "[Okay]"
echo "[Launching...]"
pod
bash ~/.prefx/app/main.sh