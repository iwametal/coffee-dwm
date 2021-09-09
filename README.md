# COFFEE's DWM

## <sup>layer 1</sup> ABOUT
This is my coffee's DWM, with all resources I value, mostly efficiency and performance, but also with a simplistic beauty look. I made these configs thinking in optimize both my work and daily usage the maximum as possible, with functions, rules and shortcuts for all considerable and frequently used programs, applications, tools and even personal scripts. It took a while, but I'm really happy with the result and probably will never get used to another interface again.

`some looks:`
<p align="center">Clean<p/>

![Interface Looks](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/looks/interface_look_clean.png "Interface Looks")

<p align="center">Beautiful<p/>

![Interface Looks](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/looks/interface_look_lainfetch.png "Interface Looks")

<p align="center">Efficient<p/>

![Interface Looks](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/looks/interface_look_apps.png "Interface Looks")

<p align="center">Flexible<p/>

![Interface Looks](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/looks/interface_look_apps0.png "Interface Looks")

<p align="center">Extensible<p/>

![Interface Looks](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/looks/interface_look_apps1.png "Interface Looks")

<p align="center">last update: Feb 1<sup>st</sup>, 2021</p>

## <sup>layer 2</sup> INSTALLATION

```
$ git clone https://github.com/chown-coffee/dwm.git
$ cd dwm
$ cp -R .dwm ~
$ chmod -R 755 ~/.dwm/*.sh
$ ln -s ~/.dwm/layoutmenu.sh /usr/bin/layoutmenu.sh # might need sudo
$ mkdir -p ~/.local/share/fonts
$ cp fonts/* ~/.local/share/fonts
$ cd dwm
$ make clean install # might need sudo
```

## <sup>layer 3</sup> INFO
I'll let all the important things about the interface below, for you to get into it, however you may check the [config.h](https://github.com/chown-coffee/dwm/blob/master/config.h) file yourself and make your own configurations (actually, you should do that). Also, I'd like to say I got some really useful resources from [Luke Smith](https://github.com/LukeSmithxyz/dwm)'s config, which saved me a lot of time for build my own. So, a special thanks to him.

## <sup>layer 4</sup> USAGE
I use xorg as display server and xinitrc as my dwm launcher. If you want to check, there is my [~/.xinirc](https://github.com/chown-coffee/linux-config/blob/master/.xinitrc) file. If you opt for the same method, then you just need to type `startx` in your tty, and voilá, your DWM is launched.

So, without further ado, there are all the important things/notes about my DWM:
### <sup>layer 4.1</sup> DEPENDENCIES
Well, of course, after so many configurations, some external programs were used in a couple parts of the code, such as in keyboard shortcuts definitions, for example. So, I made a list of all the dependencies needed for my DWM works 100%. And [there it is](https://github.com/chown-coffee/dwm/blob/master/dependencies.md).

### <sup>layer 4.2</sup> SHORTCUTS
Actually, to see all the shortcuts defined in my DWM, you may just go to my [config.h](https://github.com/chown-coffee/dwm/blob/master/config.h) file and see the keys list. But, to make it easier (and more readable too), I created a separated file with all the shortcuts I set [right here](https://github.com/chown-coffee/dwm/blob/master/keyboard_shortcuts.md). So, you may follow this file to get into my k.s.

### <sup>layer 4.3</sup> SCRIPTS
Some of the commands I use in DWM, calls a script in my machine. So, for you to have fully access to my DWM commands, you also need those. Oh, but look at that, they are luckily also in my github, right [here](https://github.com/chown-coffee/.scripts). Just clone that in your $HOME directory and be happy.
#### <sup>layer 4.3.1</sup> IMPORTANT
These scripts must be present in you $HOME directory, otherwise, you'll need to change the call for them inside DWM's [config.h](https://github.com/chown-coffee/dwm/blob/master/config.h). Your choice.

### <sup>layer 4.4</sup> DWM BAR
Last but not least, my DWM bar is completely made by personal scripts. I used dwmblocks for a while, but, with the desire to put something more simplistic (my likes), I made some simple scripts to launch in it. They are also in the [.scripts](https://github.com/chown-coffee/.scripts) directory I put previously. So, if you clone that, and put in your home directory like mentioned, you should be good. Or you can just adventure yourself in your own scripts or dwmblocks.

## <sup>layer 5</sup> NOTES
Well, that is pretty much it. I'd just like to put some important notes here:
* All my interface initialization is being handle by my [~/.xinirc](https://github.com/chown-coffee/linux-config/blob/master/.xinitrc) file, so it is interesting you take a look at it, as the scripts I have for initialization are being called there. For example, my dwm status bar is launch there, so, if you do not have it, your dwm bar will not have the scripts running. Another example is the wallpaper, that is also set there. So, look the end of the file and manage which lines you do or do not want in it.

* Talking about wallpaper... Like said, my wallpaper is set by my [~/.xinirc](https://github.com/chown-coffee/linux-config/blob/master/.xinitrc) file, and for that it searches for an image called wall.jpeg, wall.jpg or wall.png inside a directory called wallpaper. So, to set your wallpaper, just create a directory with the same name in your $HOME and put the image you want inside it with the name "wall.jpeg", "wall.jpg" or "wall.png". -"Hey Leo, but the image I want have neither of those extensions, what do I do? :confused:". No problem, just add your image extension in [this script](https://github.com/chown-coffee/.scripts/blob/master/dwm/setwallpaper.sh), just like below:

`actual line:`
```
aux=`[[ -d "$HOME/wallpaper" ]] && cd "$HOME/wallpaper" && ls "wall."{"jpeg","jpg","png"} 2>/dev/null`
```

`modified line, with .tiff extension added:`
```
aux=`[[ -d "$HOME/wallpaper" ]] && cd "$HOME/wallpaper" && ls "wall."{"jpeg","jpg","png","tiff"} 2>/dev/null`
```
#### <sup>layer 5.1</sup> IMPORTANT
This script automatically sets a wallpaper called "wall" with any extension previously set/added. However, you must have only one wallpaper called "wall". If you have 2 files, one called wall.jpg and other called wall.png, the script will not set any wallpaper as a conflict had been detected.

#### <sup>layer 5.2</sup> IMPORTANT...2
You may already have noticed, but even my [~/.xinirc](https://github.com/chown-coffee/linux-config/blob/master/.xinitrc) file being the one that loads my wallpaper, internally it is just calling a script called `setwallpaper.sh` inside my [.scripts](https://github.com/chown-coffee/.scripts) directory. So, if you're not using my script folder, you need either to paste the script code directly in .xinitrc or implement your own wallpaper setting.

* * If you want the wallpaper of prints above, it's just [here](https://github.com/chown-coffee/linux-config/tree/master/wallpaper).

### <sup>layer 6</sup> EXTRAS/PERSONAL STUFFS

#### <sup>layer 6.1</sup>TAGS
My tags are all identified by icons, and each one has its purpose. So, for those interested, I'll let my daily workflow below:

| Tag | Icon                                                                                                                    | Title         | Description                                                                                                                                             |
|-----|-------------------------------------------------------------------------------------------------------------------------|---------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1   | ![tag 1 - terminal](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/icons/tag1.svg)             | Terminal      | General terminal stuffs and applications                                                                                                                |
| 2   | ![tag 2 - Web](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/icons/tag2.svg)                  | Web           | Web stuffs, mainly browsers                                                                                                                             |
| 3   | ![tag 3 - Games](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/icons/tag3.svg)                | Games         | Games, game applications and fun time                                                                                                                   |
| 4   | ![tag 4 - Communication](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/icons/tag4.svg)        | Communication | Multiple communication channels, for any purpose. Discord, Slack, Telegram, WeeChat and etc.                                                            |
| 5   | ![tag 5 - Music](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/icons/tag5.svg)                | Music         | Music players, music lists, equalizers and any music stuff                                                                                              |
| 6   | ![tag 6 - Extras](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/icons/tag6.svg)               | Extras        | Tag to test things, either created by me or a new tool/application. It is also a tag where I put any app that does not fit in any other tag description |
| 7   | ![tag 7 - Code](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/icons/tag7.svg)                 | Code          | This is my main code tag, where I put my actual codification.                                                                                           |
| 8   | ![tag 8 - Code Stuffs](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/icons/tag8.svg)          | Code stuffs   | This is my secondary code tag, where I put any resource, app or tool related to my code.                                                                |
| 9   | ![tag 9 - Server/Databases](https://raw.githubusercontent.com/chown-coffee/dwm/master/resources/img/icons/tag9.svg)     | Server        | Server/Database tag. Here I run my server and database stuffs of any kind                                                                               |

#### <sup>layer 6.1.2 </sup>LICENSE
© All icons used are free and made available by [Font Awesome](https://fontawesome.com/license).

So, I think it's it. Thank you for the visit and have a good day.
