cmd_backup() {
	description="Wykonuje kopie zapasową ustawień, w razie gdyby coś poszło nie tak."
	run_backup() {
		restored=0
		mkdir -p ~/.prefx/backup 2>/dev/null
		[ -d /etc/pulse ] && {
			echo "Wykonywanie kopii /etc/pulse"
			rm -rf ~/.prefx/backup/etc_pulse 2>/dev/null
			cp -R /etc/pulse ~/.prefx/backup/etc_pulse
			restored=1
		}
		[ -d ~/.prefx/backup/dot_pulse ] && {
			echo "Wykonywanie kopii ~/.pulse"
			rm -rf ~/.prefx/backup/dot_pulse 2>/dev/null
			cp -R ~/.pulse ~/.prefx/backup/dot_pulse
			restored=1
		}
		[ $restored = 1 ] && echo "Gotowe." || echo "Nie znaleziono plików konfiguracyjnych."
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

cmd_delete_cookies() {
	description="Usuwa ciasteczko pulse i ustawienia użytkownika."
	run_delete_cookies() {
		echo "Usuwanie ~/.pulse i ~/.pulse-cookie"
		rm -R ~/.pulse 2>/dev/null
		rm ~/.pulse-cookie 2>/dev/null
		echo "Gotowe."
	}
}

cmd_auto_bluetooth_usb() {
	description="Automatyczne przełączanie na zestaw bluetooth lub USB."
	run_auto_bluetooth_usb() {
		sudo sh -c "echo 'load-module module-switch-on-connect' >> /etc/pulse/default.pa"
		echo "Gotowe."
	}
}