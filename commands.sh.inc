cmd_backup() {
	description="Wykonuje kopie zapasową ustawień, w razie gdyby coś poszło nie tak."
	run_backup() {
		echo "Tworzę katalog ~/.backup_PFIX"
		mkdir ~/.backup_PFIX
		echo "Wykonuję kopię /etc/pulse"
		cp -R /etc/pulse ~/.backup_PFIX/etc_pulse
		echo "Wykonuję kopię ~/.pulse"
		cp -R ~/.pulse ~/.backup_PFIX/dot_pulse
		echo "Gotowe."
	}
}

cmd_show() {
	description="Pokazuje zawartość /etc/pulse"
	run_show() {
		ls /etc/pulse;
	}
}

cmd_fix_laggy_sound() {
	description="Naprawia problem z opóźnieniem dźwięku"
	run_fix_laggy_sound() {
		echo "Dodawanie wpisów do /etc/pulse/deamon.conf"

		echo 'default-fragments = 8'
		echo 'default-fragments = 8' >> /etc/pulse/daemon.conf

		echo 'default-fragment-size-msec = 5'
		echo 'default-fragment-size-msec = 5' >> /etc/pulse/daemon.conf
	}
}

cmd_autorestart() {
	description="Włącza/wyłącza autouruchamianie pulseaudio w razie crasha."
	usage="Użycie: autorestart <yes/no>"
	run_autorestart() {
		case "$1" in
			yes) (echo Okay.; echo 'autospawn = yes' > ~/.config/pulse/client.conf) ;;
			no) (echo Okay.; echo 'autospawn = no' > ~/.config/pulse/client.conf) ;;
			*) echo $usage;
		esac
	}
}