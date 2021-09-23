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
  title=$(dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.freedesktop.DBus.Properties.Get string:org.mpris.MediaPlayer2.Player string:Metadata 2>/dev/null | awk '/artist/{getline;getline;print;}' | cut -d '"' -f 2)

  if [ ! -z "$title" ] ; then
    name=$(dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.freedesktop.DBus.Properties.Get string:org.mpris.MediaPlayer2.Player string:Metadata 2>/dev/null | sed -n '/title/{n;p}' | cut -d '"' -f 2)

    status=$(dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.freedesktop.DBus.Properties.Get string:'org.mpris.MediaPlayer2.Player' string:'PlaybackStatus'|egrep -A 1 "string"|cut -b 26-|cut -d '"' -f 1|egrep -v ^$)

    if [ "$status" = "Playing" ] ; then
      symbol_="🎧"
    elif [ "$status" = "Paused" ] ; then
      symbol_=""
    fi

    # music_="$title  $name"

    # printf "^c#b084f5^ $symbol_ ^c#81A1C1^『$title ^c#abb2bf^ ^c#81A1C1^$name』"
    printf "^c#b084f5^ $symbol_ ^c#545862^『^c#4a6a8a^$title ^c#abb2bf^ ^c#4a6a8a^$name^c#545862^』^b#161a22^"

  else
    m_symbol_=$(mpc 2>/dev/null | head -n2 | tail -n1| cut -f 1 | sed "/^volume:/d;s/\\&/&amp;/g;s/\\[paused\\].*//g;s/\\[playing\\].*/🎧/g;/^ERROR/Q" | paste -sd ' ' -;)
    # m_symbol_=$(mpc | head -n2 | tail -n1| cut -f 1 | sed "/^volume:/d;s/\\&/&amp;/g;s/\\[paused\\].*/⏸/g;s/\\[playing\\].*/🎧/g;/^ERROR/Q" | paste -sd ' ' -;)

    if [ ! -z "$m_symbol_" ] ; then
      music_=$(mpc 2>/dev/null | sed "/^volume:/d;s/\\&/&amp;/g;/\\[paused\\].*/d;/\\[playing\\].*/d;/^ERROR/Q" | paste -sd ' ' -;)

      if [ ${#music_} -gt 39 ] ; then
        music_="『$(echo $music_|cut -c1-39)...』"
      else
        music_="『$music_』"
      fi

      # [ X"$m_symbol_" = X"" ] && pause_cache_timeout || cache_timeout=

      # printf "^c#b084f5^^b#11141e^ $music_  $m_symbol_ ^b#1e222a^"
      # printf "^c#81A1C1^$music_ ^c#b084f5^$m_symbol_  ^b#11141e^"
      printf "^c#b084f5^$m_symbol_ ^c#4a6a8a^$music_^b#161a22^"
    else
      music_=
    fi

  fi
}

cpu() {
  cpu_val=$(grep -o "^[^ ]*" /proc/loadavg)

  # # printf "^c#3b414d^ ^b#7ec7a2^ CPU"
  # printf "^c#3b414d^ ^b#668ee3^ CPU"
  # printf "^c#abb2bf^ ^b#353b45^ $cpu_val"
  printf "^c#bf616a^^b#10121b^  ^c#7797b7^$cpu_val"
}

disk_usage() {
	disk_root=$(df -h|awk '{if ($6 == "/") {print}}'|awk '{print "/" $5}'|sed 's/\%//')
	disk_home=$(df -h|awk '{if ($6 == "/home") {print}}'|awk '{print "~" $5}'|sed 's/\%//')

  printf "^c#ebcb8b^^b#121521^ 💾 ^c#7797b7^$disk_root%% ^b#11131b^- $disk_home%%"
}

update_icon() {
  printf "^c#7ec7a2^ ^b#132121^"
  # printf "^c#81A1C1^ "
}

pkg_updates() {
  # updates=$(doas xbps-install -un | wc -l) # void
  updates=$(checkupdates | wc -l)   # arch , needs pacman contrib
  # updates=$(aptitude search '~U' | wc -l)  # apt (ubuntu,debian etc)

  if [ -z "$updates" ]; then
    printf "^c#7797b7^ fully updated"
  else
    printf "^c#7797b7^$updates""^b#121921^u"
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
  # printf "^c#7797b7^^b#0f131b^ "
  # printf "^c#ebcb8b^^b#2E3440^ "
  printf "^c#69ccff^^b#10121a^ "
  printf "^c#7797b7^ $(free -h | awk '/^Mem/ { print $3 }' | sed s/i//g) ^c#545862^^b#0d1113^| ^c#7797b7^$(free -h | awk '/^Mem/ { print $6 }' | sed s/i//g) ^c#545869^^b#0c0e13^- $(free -h | awk '/^Swap/ { print $3 }' | sed s/i//g)"
}

wlan() {
  # net_icon=`printf "%s%s%s\n" "$wifiicon" "$(sed "s/down//;s/up//" /sys/class/net/e*/operstate 2>/dev/null)" "$(sed "s/.*/🔒/" /sys/class/net/tun*/operstate 2>/dev/null)"`
  net_icon=`printf "%s%s%s\n" "$wifiicon" "$(sed "s/down//;s/up/🌐/" /sys/class/net/e*/operstate 2>/dev/null)" "$(sed "s/.*/🔒/" /sys/class/net/tun*/operstate 2>/dev/null)"`

  if [ X"$net_icon" = X"" ]; then
    printf "^c#bd93f9^^b#0f1113^ $net_icon"
  else
    # printf "^c#9266d7^^b#0f1113^ $net_icon"
    printf "^c#9266d7^^b#071309^ $net_icon"
    # printf "^c#7797b7^^b#11141e^ $net_icon"
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
  # printf "^c#0f131b^^b#6282a2^ 󱑆 "
  # printf "^c#1e222a^^b#7c9cbc^ $(date '+%a, %I:%M %p') "
  
  # purple scheme
  printf "^c#121419^^b#9a62dd^ 󱑆 "
  # printf "^c#121419^^b#9266d7^$(date '+╷%m.%d.%y╷ %H:%M')"
  printf "^c#121419^^b#9266d7^$(date '+%H:%M ╷ %m.%d.%y')"

  # blue scheme
  # printf "^c#2E3440^^b#828dd1^ 󱑆 "
  # printf "^c#2E3440^^b#6c77bb^ $(date '+%a, %I:%M %p') "
}

while true; do

  [ $interval == 0 ] || [ $(($interval % 3600)) == 0 ] && updates=$(pkg_updates) && disk_u=$(disk_usage) && interval=0
  interval=$((interval + 1))

  # sleep 1 && xsetroot -name "$(update_icon) $updates $(batt) $(brightness) $(cpu) $(mem) $(wlan) $(clock)"
  sleep 1 && xsetroot -name "                     $(music) $(update_icon) $updates  $disk_u  $(cpu)  $(mem) $(clock) $(wlan) "

done
