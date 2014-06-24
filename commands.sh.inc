cmd_backup() {
	description="Wykonuje kopie zapasową ustawień, w razie gdyby coś poszło nie tak."
	run_backup() {
		echo "Tworzę katalog ~/.backup_PFIX"
		mkdir ~/.prefx/backup -p 2>/dev/null
		echo "Wykonuję kopię /etc/pulse"
		cp -R /etc/pulse ~/.prefx/backup/etc_pulse
		echo "Wykonuję kopię ~/.pulse"
		cp -R ~/.pulse ~/.prefx/backup/dot_pulse
		echo "Gotowe."
	}
}

cmd_restore() {
	description="Przywraca z ustawienia z uprzednio wykonanej kopii zapasowej."
	run_restore() {
		restored=0
		[ -d ~/.prefx/backup/etc_pulse ] && {
			echo "Przywracanie /etc/pulse"
			sudo rm -rf /etc/pulse 2>/dev/null
			sudo cp -R ~/.prefx/backup/etc_pulse /etc/pulse
			restored=1
		}
		[ -d ~/.prefx/backup/dot_pulse ] && {
			echo "Przywracanie ~/.pulse"
			rm -rf ~/.pulse 2>/dev/null
			cp -R ~/.prefx/backup/dot_pulse ~/.pulse
			restored=1
		}
		[ $restored = 1 ] && echo "Gotowe." || echo "Nie znaleziono kopii zapasowej."
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

