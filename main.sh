#!/bin/bash
echo "[prefx pre 0.1 by 0x017]"
echo "Przepisane na basha przez Ashley"

cmd_help() {
	description="Wyświetla pomoc."
	run_help() {
		[[ $# > 0 ]] && {
			cmd_$1 2>/dev/null && (echo "$1 - $description"; [ -z "$usage" ] || echo "$usage"; exit 0) || echo "Nie znam komendy $1."
		} || {
			echo "Dostępne komendy: "
			for i in $(set | grep -Eo '^cmd_.* ()$' | sed 's/ ()//'); do
				$i
				echo "$(echo $i | sed 's/^cmd_//') - $description"
			done
		}
	}
}

cmd_exit() {
	description="Zamyka program."
	run_exit() {
		break;
	}
}
source commands.sh.inc

while read -p '>>> ' line; do
	argv=( $line )
	cmd_${argv[0]} 2>/dev/null || (exit_code=$?; echo "${argv[0]}: nieznana komenda (wpisz \"help\" aby uzyskać pomoc)."; exit $exit_code)
	[[ $? == 0 ]] && {
		run_$line
	}
	unset usage
	unset description
done
echo "Bye."
