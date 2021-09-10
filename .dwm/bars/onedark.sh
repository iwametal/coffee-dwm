#!/bin/bash

interval=0

pause_cache_timeout()
{
	if [ X"$cache_timeout" = X"" ] ; then
		cache_timeout=0
	else
		[ $cache_timeout -ge 5 ] && music_= || cache_timeout=$(($cache_timeout + 1))
	fi
}

music()
{
	# m_symbol_=$(mpc | head -n2 | tail -n1| cut -f 1 | sed "/^volume:/d;s/\\&/&amp;/g;s/\\[paused\\].*/⏸/g;s/\\[playing\\].*/🎧/g;/^ERROR/Q" | paste -sd ' ' -;)
	m_symbol_=$(mpc 2>/dev/null | head -n2 | tail -n1| cut -f 1 | sed "/^volume:/d;s/\\&/&amp;/g;s/\\[paused\\].*//g;s/\\[playing\\].*/🎧/g;/^ERROR/Q" | paste -sd ' ' -;)

	if [ ! -z "$m_symbol_" ] ; then
		music_=$(mpc 2>/dev/null | sed "/^volume:/d;s/\\&/&amp;/g;/\\[paused\\].*/d;/\\[playing\\].*/d;/^ERROR/Q" | paste -sd ' ' -;)

		if [ ${#music_} -gt 39 ] ; then
			music_="『$(echo $music_|cut -c1-39)...』"
		else
			music_="『$music_』"
		fi

		# [ X"$m_symbol_" = X"" ] && pause_cache_timeout || cache_timeout=

    # printf "^c#b084f5^^b#11141e^ $music_  $m_symbol_ ^b#1e222a^"
    # printf "^c#81A1C1^$music_ ^c#b084f5^$m_symbol_  ^b#11141e^"
    printf "^c#b084f5^$m_symbol_ ^c#81A1C1^$music_"
	else
		music_=
	fi
}

cpu() {
  cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)

  # # printf "^c#3b414d^ ^b#7ec7a2^ CPU"
  # printf "^c#3b414d^ ^b#668ee3^ CPU"
  # printf "^c#abb2bf^ ^b#353b45^ $cpu_val"
  printf "^c#81A1C1^  $cpu_val"
}

update_icon() {
  printf "^c#7ec7a2^ "
  # printf "^c#81A1C1^ "
}

pkg_updates() {
  # updates=$(doas xbps-install -un | wc -l) # void
  updates=$(checkupdates | wc -l)   # arch , needs pacman contrib
  # updates=$(aptitude search '~U' | wc -l)  # apt (ubuntu,debian etc)

  if [ -z "$updates" ]; then
    printf "^c#7797b7^ fully updated"
  else
    printf "^c#7797b7^$updates""u"
  fi
  # if [ -z "$updates" ]; then
  #   printf "^c#7ec7a2^ Fully Updated"
  # else
  #   printf "^c#7ec7a2^ $updates"" updates"
  # fi
}

# battery
batt() {
  printf "^c#81A1C1^  "
  printf "^c#81A1C1^ $(acpi | sed "s/,//g" | awk '{if ($3 == "Discharging"){print $4; exit} else {print $4""}}' | tr -d "\n")"
}

brightness() {

  backlight() {
    backlight="$(xbacklight -get)"
    echo -e "$backlight"
  }

  printf "^c#BF616A^   "
  printf "^c#BF616A^%.0f\n" $(backlight)
}

mem() {
  printf "^c#7797b7^^b#0f131b^ "
  printf "^c#7797b7^ $(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g) | $(free -h | awk '/^Mem/ { print $6 }' | sed s/i//g)"
}

wlan() {
  # net_icon=`printf "%s%s%s\n" "$wifiicon" "$(sed "s/down//;s/up//" /sys/class/net/e*/operstate 2>/dev/null)" "$(sed "s/.*/🔒/" /sys/class/net/tun*/operstate 2>/dev/null)"`
  net_icon=`printf "%s%s%s\n" "$wifiicon" "$(sed "s/down//;s/up/🌐/" /sys/class/net/e*/operstate 2>/dev/null)" "$(sed "s/.*/🔒/" /sys/class/net/tun*/operstate 2>/dev/null)"`

  if [ X"$net_icon" = X"" ]; then
    printf "^c#bf616a^^b#11141e^ $net_icon"
  else
    printf "^c#7797b7^^b#11141e^ $net_icon"
  fi

  case "$(cat /sys/class/net/w*/operstate 2>/dev/null)" in
    up)
      # printf "^c#3b414d^ ^b#7aa2f7^ 󰤨 ^d^%s" " ^c#7aa2f7^Connected"
      printf "^c#7797b7^ ^b#11141e^ 󰤨 ^d^%s"
      ;;
    down)
      # printf "^c#3b414d^ ^b#7aa2f7^ 󰤭 ^d^%s" " ^c#7aa2f7^Disconnected"
      printf "^c#bf616a^ ^b#11141e^ 󰤭 ^d^%s"
      ;;
  esac
}

clock() {

  # marine blue scheme
  printf "^c#0f131b^^b#6282a2^ 󱑆 "
  printf "^c#1e222a^^b#7c9cbc^ $(date '+%a, %I:%M %p') "
  
  # purple scheme
  # printf "^c#000000^^b#9a62dd^ 󱑆 "
  # printf "^c#000000^^b#b084f5^ $(date '+%a, %I:%M %p') "

  # blue scheme
  # printf "^c#1e222a^ ^b#668ee3^ 󱑆 "
  # printf "^c#1e222a^^b#7aa2f7^ $(date '+%a, %I:%M %p') "
}

while true; do

  [ $interval == 0 ] || [ $(($interval % 3600)) == 0 ] && updates=$(pkg_updates) && interval=0
  interval=$((interval + 1))

  # sleep 1 && xsetroot -name "$(update_icon) $updates $(batt) $(brightness) $(cpu) $(mem) $(wlan) $(clock)"
  sleep 1 && xsetroot -name "$(music) $(update_icon) $updates $(mem) $(clock) $(wlan) "

done
