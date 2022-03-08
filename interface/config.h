/* See LICENSE file for copyright and license details. */

#define TERMINAL "st"
#define TERMCLASS "St"

#define XF86MonBrightnessDown 0x1008ff03
#define XF86MonBrightnessUp 0x1008ff02

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int default_border = 0;  // to switch back to default border after dynamic border resizing via keybinds
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 0;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 0;       /* vert inner gap between windows */
static const unsigned int gappoh    = 0;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 0;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails,display systray on the 1st monitor,False: display systray on last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always };
static const int showtab            = showtab_auto;
static const int toptab             = True;
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 5;
static const int vertpadbar         = 11;
static const int vertpadtab         = 33;
static const int horizpadtabi       = 15;
static const int horizpadtabo       = 15;
static const int scalepreview       = 4;
static const char *fonts[]          = { "JetBrainsMono Nerd Font:style:medium:size=9",
  "Material Design Icons-Regular:size=9",
  "noto-cjk:style:medium:size=9",
};
static const char dmenufont[]       = "monospace:size=9";
static const int colorfultag        = 1;  /* 0 means use SchemeSel for selected non vacant tag */

// theme
#include "themes/onedark.h"

static const char *colors[][3]      = {
  /*               fg         bg         border   */
  [SchemeNorm]       = { gray3, black, gray2 },
  [SchemeSel]        = { gray4, blue,  purple9  },
  [TabSel]           = { blue, gray2,  black  },
  [TabNorm]          = { gray3, black, black },
  [SchemeTag]        = { gray3, black, black },
  [SchemeTag1]       = { purple0,  black, black },
  [SchemeTag2]       = { purple1,   black, black },
  [SchemeTag3]       = { purple2, black,black },
  [SchemeTag4]       = { purple3, black, black },
  [SchemeTag5]       = { purple4,  black, black },
  [SchemeTag6]       = { purple5,  black, black },
  [SchemeTag7]       = { purple6,  black, black },
  [SchemeTag8]       = { purple7,  black, black },
  [SchemeTag9]       = { purple8,  black, black },
  [SchemeLayout]     = { blue, black, black }, 
  [SchemeBtnPrev]    = { green, black, black }, 
  [SchemeBtnNext]    = { yellow, black, black }, 
  [SchemeBtnClose]   = { red, black, black }, 
};

typedef struct {
  const char *name;
  const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "spterm", "-g", "121x34", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
  /* name          cmd  */
  {"spterm", spcmd1},
  {"spcalc", spcmd2},
};

/* tagging */
/* static const char *tags[] = {" ", " ", " ", " ", " "}; */
/* static const char *tags[] = { " ", " ", " ", " ", " ", " ", " ", " ", " " }; */
static const char *tags[] = { " ", " ", " ", " ", " ", " ", " ", " ", " " };

static const int tagschemes[] = { SchemeTag1, SchemeTag2, SchemeTag3,
  SchemeTag4, SchemeTag5, SchemeTag6,
  SchemeTag7, SchemeTag8, SchemeTag9,
};

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
  /* class            instance     title       	    tags mask     isfloating   isterminal noswallow monitor */

  /* class            instance     title            tags mask     iscentered   isfloating isterminal monitor */
  { "soapui",         NULL,        NULL,       	    1 << 7,       0,           0,         0,         -1 },
  { "android-studio", NULL,        NULL,       	    1 << 6,       0,           0,         0,         -1 },
  { "idea",           NULL,        NULL,       	    1 << 6,       0,           0,         0,         -1 },
  { "Gimp",           NULL,        NULL,       	    1 << 5,       0,           0,         0,         -1 },
  { "krita",          NULL,        NULL,       	    1 << 5,       0,           0,         0,         -1 },
  { "obs",            NULL,        NULL,       	    1 << 5,       0,           0,         0,         -1 },
  { "ncmpcpp",        NULL,        "ncmpcpp",  	    1 << 4,       0,           0,         1,         -1 },
  { "Spotify",        NULL,        "spotify",  	    1 << 4,       0,           0,         1,         -1 },
  { "discord",        NULL,        NULL,            1 << 3,       0,           0,         0,         -1 },
  { "slack",          NULL,        "Slack",    	    1 << 3,       0,           0,         0,         -1 },
  { "lutris",         NULL,        "Lutris",   	    1 << 2,       0,           0,         0,         -1 },
  { "steam",          NULL,        "Steam",    	    1 << 2,       0,           0,         0,         -1 },
  { "brave",          NULL,        NULL,       	    1 << 1,       0,           0,         0,         -1 },
  { "chromium",       NULL,        NULL,       	    1 << 1,       0,           0,         0,         -1 },
  { "firefox",        NULL,        NULL,       	    1 << 1,       0,           0,         0,         -1 },
  { "opera",          NULL,        NULL,       	    1 << 1,       0,           0,         0,         -1 },
  { "qutebrowser",    NULL,        NULL,       	    1 << 1,       0,           0,         0,         -1 },
  { "vivaldi",        NULL,        NULL,       	    1 << 1,       0,           0,         0,         -1 },
  { TERMCLASS,        NULL,        NULL,       	    0,            0,           0,         1,         -1 },
  { NULL,             NULL,        "Event Tester",  0,            0,           1,         0,         -1 },
  { "eww",            NULL,        NULL,            0,            0,           1,         0,         -1 },
  { NULL,             "spterm",		 NULL,            SPTAG(0),     0,           1,         1,         -1 },
  { NULL,             "spcalc",    NULL,            SPTAG(1),     0,           1,         1,         -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "functions.h"

static const Layout layouts[] = {
  /* symbol     arrange function */
  { "|M|",      centeredmaster }, /* first entry is default */
  { ">M>",      centeredfloatingmaster },
  { "[]=",      tile },
  { "TTT",      bstack },
  { "[@]",      spiral },
  { "[\\]",     dwindle },
  { "[M]",      monocle },
  { "H[]",      deck },
  { "===",      bstackhoriz },
  { "HHH",      grid },
  { "###",      nrowgrid },
  { "---",      horizgrid },
  { ":::",      gaplessgrid },
  { "|+|",      tatami },
  { "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG) \
{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define STACKKEYS(MOD,ACTION) \
{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = {  "st", NULL }; // change this to your term
/* static const char *rofi[] = {"rofi", "-show", "drun", NULL }; */
static const char *layoutmenu_cmd = "/home/coffee/.dwm/layoutmenu.sh";
/* static const char *xi[] = {"xbacklight", "-inc", "7", NULL}; */
/* static const char *xd[] = {"xbacklight", "-dec", "7", NULL}; */

static Key keys[] = {
  /* modifier                     key        function        argument */
  /* { MODKEY,                       XK_c,      spawn,          {.v = rofi } }, */

  /* {MODKEY | ControlMask, XK_u, spawn, SHCMD("maim | xclip -selection clipboard -t image/png")}, */
  /* {MODKEY, XK_u, spawn,   SHCMD("maim --select | xclip -selection clipboard -t image/png")}, */
  /* {0,                            XF86MonBrightnessDown, spawn, {.v = xd}}, */
  /* {0,                            XF86MonBrightnessUp, spawn, {.v = xi}}, */
  { MODKEY,                      XK_b,      togglebar,  {0} },
  { MODKEY|Mod1Mask|ControlMask, XK_b,      spawn,      SHCMD("[ X\"\" = X\"$(ps ax|grep toggle_statusbar|grep -v grep)\" ] && $HOME/.dwm/bars/toggle_statusbar.sh onedark") },
  /* { MODKEY|ControlMask,          XK_w,      tabmode,    { -1 } }, */
  { MODKEY|Mod1Mask|ControlMask, XK_i,      incnmaster, {.i = +1 } },
  { MODKEY|Mod1Mask|ControlMask, XK_d,      incnmaster, {.i = -1 } },
  { MODKEY,                      XK_h,      setmfact,   {.f = -0.05} },
  { MODKEY,                      XK_l,      setmfact,   {.f = +0.05} },
  { MODKEY|ShiftMask,            XK_h,      setcfact,   {.f = +0.25} },
  { MODKEY|ShiftMask,            XK_l,      setcfact,   {.f = -0.25} },
  { MODKEY|ShiftMask,            XK_o,      setcfact,   {.f =  0.00} },
  { MODKEY|ShiftMask,            XK_j,      movestack,  {.i = +1 } },
  { MODKEY|ShiftMask,            XK_k,      movestack,  {.i = -1 } },
  { MODKEY,                      XK_Return, zoom,       {0} },

  // view
  STACKKEYS(MODKEY,           focus)
	STACKKEYS(MODKEY|ShiftMask, push)
  { MODKEY,                       XK_Tab,       view,       {0} },
  { MODKEY,                       XK_backslash, view,       {0} },
  { Mod1Mask,		                  XK_Tab,	      shiftview,  {.i = 1} },
  { Mod1Mask|ShiftMask,           XK_Tab,       shiftview,  {.i = -1} },
  { MODKEY,			                  XK_g,		      shiftview,  {.i = -1} },
  { MODKEY|ShiftMask,		          XK_g,		      shifttag,	  {.i = -1} },
  { MODKEY,			                  XK_semicolon, shiftview,  {.i = 1} },
  { MODKEY|ShiftMask,		          XK_semicolon, shifttag,	  {.i = 1} },
  { MODKEY,                       XK_e,         togglewin,  {0} },
  { MODKEY|ShiftMask,             XK_e,         hidewin,    {0} },
  { MODKEY|ShiftMask|ControlMask, XK_e,         restorewin, {0} },
  { MODKEY,                       XK_space,     zoom,       {0} },

  // browser
  { MODKEY,			        XK_w,	spawn, SHCMD("$BROWSER") },
  /* { MODKEY|ControlMask, XK_w,	spawn, SHCMD("brave") }, */
  { MODKEY|ControlMask, XK_w,	spawn, SHCMD("vivaldi-stable") },

  // internet
  { MODKEY|ShiftMask, XK_w, spawn, SHCMD(TERMINAL " -e sudo nmtui") },

  // games
  { MODKEY|ControlMask, XK_g, spawn, SHCMD("steam") },
  { MODKEY|Mod1Mask,    XK_g, spawn, SHCMD("lutris") },

  // overall gaps
  { MODKEY|ShiftMask|ControlMask, XK_i, incrgaps, {.i = +1 } },
  { MODKEY|ShiftMask|ControlMask, XK_d, incrgaps, {.i = -1 } },

  // inner gaps
  /* { MODKEY|ShiftMask,             XK_i,      incrigaps,      {.i = +1 } }, */
  /* { MODKEY|ControlMask|ShiftMask, XK_i,      incrigaps,      {.i = -1 } }, */

  // outer gaps
  { MODKEY|ControlMask,           XK_o, incrogaps,  {.i = +1 } },
  { MODKEY|ControlMask|ShiftMask, XK_o, incrogaps,  {.i = -1 } },

  { MODKEY|ControlMask,           XK_6, incrihgaps, {.i = +1 } },
  { MODKEY|ControlMask|ShiftMask, XK_6, incrihgaps, {.i = -1 } },
  { MODKEY|ControlMask,           XK_7, incrivgaps, {.i = +1 } },
  { MODKEY|ControlMask|ShiftMask, XK_7, incrivgaps, {.i = -1 } },
  { MODKEY|ControlMask,           XK_8, incrohgaps, {.i = +1 } },
  { MODKEY|ControlMask|ShiftMask, XK_8, incrohgaps, {.i = -1 } },
  { MODKEY|ControlMask,           XK_9, incrovgaps, {.i = +1 } },
  { MODKEY|ControlMask|ShiftMask, XK_9, incrovgaps, {.i = -1 } },

  { MODKEY|ControlMask,                    XK_t, togglegaps,  {0} },
  { MODKEY|ControlMask|ShiftMask|Mod1Mask, XK_d, defaultgaps, {0} },

  // volume
  /* { 0,                XF86XK_AudioLowerVolume, spawn, SHCMD("$HOME/.scripts/shell/volume.sh -b -d 1") }, */
  { MODKEY,           XK_minus, spawn, SHCMD("$HOME/.scripts/shell/volume.sh -b -d 2") },
  { MODKEY|ShiftMask, XK_minus,	spawn, SHCMD("$HOME/.scripts/shell/volume.sh -b -d 5") },
  /* { 0,                XF86XK_AudioRaiseVolume, spawn, SHCMD("$HOME/.scripts/shell/volume.sh -b -i 1") }, */
  { MODKEY,           XK_equal, spawn, SHCMD("$HOME/.scripts/shell/volume.sh -b -i 2") },
  { MODKEY|ShiftMask, XK_equal, spawn, SHCMD("$HOME/.scripts/shell/volume.sh -b -i 5") },
  { MODKEY|ShiftMask, XK_m,	spawn, SHCMD("$HOME/.scripts/shell/volume.sh -m") },
  { MODKEY,           XK_v,	spawn, SHCMD("$HOME/.scripts/shell/volume.sh -s") },

  // brightness
  { MODKEY|Mod1Mask,           XK_minus, spawn, SHCMD("$HOME/.scripts/dwm/backlight/brightness.sh -") },
  { MODKEY|Mod1Mask|ShiftMask, XK_minus, spawn, SHCMD("$HOME/.scripts/dwm/backlight/brightness.sh --") },
  { MODKEY|Mod1Mask,           XK_equal, spawn, SHCMD("$HOME/.scripts/dwm/backlight/brightness.sh +") },
  { MODKEY|Mod1Mask|ShiftMask, XK_equal, spawn, SHCMD("$HOME/.scripts/dwm/backlight/brightness.sh ++") },
  { MODKEY|Mod1Mask,           XK_b,     spawn, SHCMD("$HOME/.scripts/dwm/backlight/brightness.sh g") },

  // music
  { MODKEY|ControlMask, XK_p,            spawn,	SHCMD("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.PlayPause") },
  { MODKEY|ControlMask, XK_comma,        spawn,	SHCMD("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Previous") },
  { MODKEY|ControlMask, XK_period,       spawn,	SHCMD("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Next") },
  { MODKEY|ControlMask, XK_m,            spawn,	SHCMD("spotify") },
  { MODKEY,          	  XK_p,			         spawn,	SHCMD("mpc toggle") },
  { MODKEY,			        XK_bracketleft,  spawn,	SHCMD("mpc seek -10") },
  { MODKEY|ShiftMask,	  XK_bracketleft,  spawn,	SHCMD("mpc seek -60") },
  { MODKEY,			        XK_bracketright, spawn,	SHCMD("mpc seek +10") },
  { MODKEY|ShiftMask,	  XK_bracketright, spawn,	SHCMD("mpc seek +60") },
  { MODKEY,			        XK_comma,	       spawn,	SHCMD("mpc prev") },
  { MODKEY|ShiftMask,	  XK_comma,	       spawn,	SHCMD("mpc seek 0%") },
  { MODKEY,			        XK_period,	     spawn,	SHCMD("mpc next") },
  { MODKEY|ShiftMask,	  XK_period,	     spawn,	SHCMD("mpc repeat") },
  { MODKEY,			        XK_m,		         spawn,	SHCMD(TERMINAL " $HOME/.scripts/dwm/music/launch_ncmpcpp.sh") },
  /* { 0,                XF86XK_AudioMute,        spawn, SHCMD("pamixer -t") }, */
  /* { 0,                XF86XK_AudioPrev,		     spawn, SHCMD("mpc prev") }, */
  /* { 0,                XF86XK_AudioNext,		     spawn, SHCMD("mpc next") }, */
  /* { 0,                XF86XK_AudioPause,		   spawn, SHCMD("mpc pause") }, */
  /* { 0,                XF86XK_AudioPlay,		     spawn, SHCMD("mpc play") }, */
  /* { 0,                XF86XK_AudioStop,		     spawn, SHCMD("mpc stop") }, */
  /* { 0,                XF86XK_AudioRewind,	     spawn, SHCMD("mpc seek -10") }, */
  /* { 0,                XF86XK_AudioForward,	   spawn, SHCMD("mpc seek +10") }, */
  /* { 0,                XF86XK_AudioMedia,		   spawn, SHCMD(TERMINAL " -e ncmpcpp") }, */

  // terminal
  { MODKEY,			                           XK_r,		  spawn,         SHCMD(TERMINAL " -e ranger") },
  { MODKEY|ControlMask,                    XK_r,		  spawn,         SHCMD(TERMINAL " -e vifm") },
  { MODKEY|ShiftMask,		                   XK_r,		  spawn,         SHCMD(TERMINAL " -e htop") },
  { MODKEY|ControlMask|Mod1Mask|ShiftMask, XK_Return,	togglescratch, {.ui = 1} },
  { MODKEY|ShiftMask,                      XK_Return, togglescratch, {.ui = 0} },
  { MODKEY,                                XK_Return, spawn,         {.v = termcmd }}, 
  /* { MODKEY,                                XK_Return, spawn,         SHCMD("~/.local/bin/./st_settings && st")}, */ 

  // search
  { MODKEY,			                  XK_d,		   spawn,          SHCMD("dmenu_run") },

  // layouts
  { MODKEY,			      XK_i,	setlayout, {.v = &layouts[0]} }, /* centeredmaster */
  { MODKEY|ShiftMask, XK_i,	setlayout, {.v = &layouts[1]} }, /* centeredfloatingmaster */
  { MODKEY,			      XK_t,	setlayout, {.v = &layouts[2]} }, /* tile */
  { MODKEY|ShiftMask, XK_t,	setlayout, {.v = &layouts[3]} }, /* bstack */
  { MODKEY,			      XK_y,	setlayout, {.v = &layouts[4]} }, /* spiral */
  { MODKEY|ShiftMask, XK_y,	setlayout, {.v = &layouts[5]} }, /* dwindle */
  { MODKEY,			      XK_u,	setlayout, {.v = &layouts[6]} }, /* monocle */
  { MODKEY|ShiftMask, XK_u,	setlayout, {.v = &layouts[7]} }, /* deck */

  { MODKEY,                                XK_q,      killclient,     {0} },
  { MODKEY|ShiftMask,                      XK_f,      setlayout,      {.v = &layouts[1]} },
  /* { MODKEY,                                XK_m,      setlayout,      {.v = &layouts[2]} }, */
  /* { MODKEY|ControlMask,                    XK_g,      setlayout,      {.v = &layouts[10]} }, */
  { MODKEY|ControlMask|ShiftMask,          XK_t,            setlayout,      {.v = &layouts[13]} },
  { MODKEY|ControlMask,		                 XK_bracketleft,  cyclelayout,    {.i = -1 } },
  { MODKEY|ControlMask,                    XK_bracketright, cyclelayout,    {.i = +1 } },
  { MODKEY|ShiftMask,                      XK_space,        togglefloating, {0} },
  { MODKEY,                                XK_f,            togglefullscr,  {0} },
  { MODKEY,                                XK_0,            view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,                      XK_0,            tag,            {.ui = ~0 } },
  /* { MODKEY,                                XK_comma,        focusmon,       {.i = -1 } }, */
  /* { MODKEY,                                XK_period,       focusmon,       {.i = +1 } }, */
  /* { MODKEY|ShiftMask,                      XK_comma,        tagmon,         {.i = -1 } }, */
  /* { MODKEY|ShiftMask,                      XK_period,       tagmon,         {.i = +1 } }, */
  { MODKEY|ShiftMask|ControlMask|Mod1Mask, XK_minus, 	      setborderpx,    {.i = -1 } },
  { MODKEY|ShiftMask|ControlMask|Mod1Mask, XK_p, 	          setborderpx,    {.i = +1 } },
  /* { MODKEY|ShiftMask,                      XK_w, 	          setborderpx,    {.i = default_border } }, */

  TAGKEYS(           XK_1, 0)
  TAGKEYS(           XK_2, 1)
  TAGKEYS(           XK_3, 2)
  TAGKEYS(           XK_4, 3)
  TAGKEYS(           XK_5, 4)
  TAGKEYS(           XK_6, 5)
  TAGKEYS(           XK_7, 6)
  TAGKEYS(           XK_8, 7)
  TAGKEYS(           XK_9, 8)
  { MODKEY|ShiftMask|Mod1Mask, XK_q, spawn, SHCMD("$HOME/.dwm/bars/kill_statusbar.sh onedark") },
  { MODKEY|ShiftMask|Mod1Mask, XK_q, quit,  {0} },

// programs
  { MODKEY|ControlMask, XK_d, spawn, SHCMD("discord") },
  { MODKEY|ControlMask, XK_s, spawn, SHCMD("slack") },

  // notification
  { ControlMask,                    XK_space, spawn, SHCMD("dunstctl close") },
  { ControlMask|ShiftMask,          XK_space, spawn, SHCMD("dunstctl close-all") },
  { ControlMask|ShiftMask|Mod1Mask, XK_space, spawn, SHCMD("dunstctl set-paused toggle") },

  // scripts
  { MODKEY|Mod1Mask|ControlMask,           XK_c,     spawn,	SHCMD(TERMINAL " -ig 120x35+640+200 sudo $HOME/.scripts/cache/drop_cache_full") },
  { MODKEY|Mod1Mask|ControlMask,           XK_s,     spawn,	SHCMD(TERMINAL " -ig 120x35+640+200 sudo $HOME/.scripts/swap/drop_swap.sh") },
  { MODKEY|Mod1Mask|ControlMask,           XK_j,     spawn,	SHCMD("$HOME/.scripts/dwm/java/change_java_version.sh") },
  { MODKEY|Mod1Mask|ControlMask,           XK_v,     spawn,	SHCMD("$HOME/.scripts/vpn/cisco/vpnmenu.sh") },
  { MODKEY|Mod1Mask|ControlMask,           XK_p,     spawn,	SHCMD("$HOME/.scripts/dwm/pacman/pacmenu.sh") },
  { MODKEY|ShiftMask,		                   XK_q,     spawn, SHCMD("$HOME/.scripts/dwm/halt/opt_slock") },
  { MODKEY|Mod1Mask|ControlMask|ShiftMask, XK_q,     spawn, SHCMD("$HOME/.scripts/dwm/halt/opt_halt") },
  { MODKEY|Mod1Mask|ControlMask|ShiftMask, XK_r,     spawn, SHCMD("$HOME/.scripts/dwm/halt/opt_reboot") },
  { MODKEY|Mod1Mask|ControlMask|ShiftMask, XK_h,     spawn, SHCMD("$HOME/.scripts/dwm/halt/halt.sh") },
  { MODKEY|Mod1Mask|ControlMask|ShiftMask, XK_k,     spawn, SHCMD("$HOME/.scripts/dwm/process/kill_process.sh") },
  { MODKEY|Mod1Mask|ControlMask,           XK_n,     spawn,	SHCMD("$HOME/.scripts/notification/send/run_notify_send_test.sh") },
  { ControlMask|ShiftMask,                 XK_space, spawn, SHCMD("dunstctl close-all") },
  { ControlMask|ShiftMask|Mod1Mask,        XK_space, spawn, SHCMD("dunstctl set-paused toggle") },

  // print
  { 0,           XK_Print, spawn, SHCMD("flameshot full -c") },
  { ControlMask, XK_Print, spawn, SHCMD("[[ ! -d \"$HOME/Pictures/screenshot\" ]] && mkdir -p \"$HOME/Pictures/screenshot\" && flameshot full -p $HOME/Pictures/screenshot || flameshot full -p $HOME/Pictures/screenshot") },
  { ShiftMask,   XK_Print, spawn, SHCMD("flameshot gui") },

  /* { MODKEY|ShiftMask,             XK_r,      quit,           {1} }, */

  // extras
  { MODKEY, XK_F9,          spawn, SHCMD("gromit-mpx") },
  { MODKEY, XK_Scroll_Lock, spawn, SHCMD("killall screenkey || screenkey &") },
  /* { 0,                  XF86XK_AudioMicMute,      spawn, SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") }, */
  /* { 0,                  XF86XK_PowerOff,		      spawn, SHCMD("sysact") }, */
  /* { 0,                  XF86XK_Calculator,	      spawn, SHCMD(TERMINAL " -e bc -l") }, */
  /* { 0,                  XF86XK_WWW,		            spawn, SHCMD("$BROWSER") }, */
  /* { 0,                  XF86XK_DOS,		            spawn, SHCMD(TERMINAL) }, */
  /* { 0,                  XF86XK_ScreenSaver,	      spawn, SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") }, */
  /* { 0,                  XF86XK_TaskPane,		      spawn, SHCMD(TERMINAL " -e htop") }, */
  /* { 0,                  XF86XK_Mail,		          spawn, SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") }, */
  /* { 0,                  XF86XK_MyComputer,	      spawn, SHCMD(TERMINAL " -e lf /") }, */
  /* { 0,                  XF86XK_Launch1,		        spawn, SHCMD("xset dpms force off") }, */
  /* { 0,                  XF86XK_TouchpadToggle,    spawn, SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") }, */
  /* { 0,                  XF86XK_TouchpadOff,	      spawn, SHCMD("synclient TouchpadOff=1") }, */
  /* { 0,                  XF86XK_TouchpadOn,		    spawn, SHCMD("synclient TouchpadOff=0") }, */
  /* { 0,                  XF86XK_MonBrightnessUp,	  spawn, SHCMD("xbacklight -inc 15") }, */
  /* { 0,                  XF86XK_MonBrightnessDown, spawn, SHCMD("xbacklight -dec 15") }, */
  /* { 0,                                     XF86XK_Sleep, spawn,         SHCMD("sudo -A zzz") }, */
  /* { 0, XF86XK_Battery,		spawn,		SHCMD("") }, */

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkLtSymbol,          0,              Button3,        layoutmenu,     {0} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },

  /* Keep movemouse? */
  /* { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} }, */

  /* placemouse options, choose which feels more natural:
   *    0 - tiled position is relative to mouse cursor
   *    1 - tiled postiion is relative to window center
   *    2 - mouse pointer warps to window center
   *
   * The moveorplace uses movemouse or placemouse depending on the floating state
   * of the selected client. Set up individual keybindings for the two if you want
   * to control these separately (i.e. to retain the feature to move a tiled window
   * into a floating position).
   */
  /* { ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 0} }, */
  { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
  /* { ClkClientWin,         ControlMask,    Button1,        dragmfact,      {0} }, */
  /* { ClkClientWin,         ControlMask,    Button3,        dragcfact,      {0} }, */
  /* { ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} }, */
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
  { ClkTabBar,            0,              Button1,        focuswin,       {0} },
  { ClkTabBar,            0,              Button1,        focuswin,       {0} },
  { ClkTagBar,		        0,		          Button4,	      shiftview,      {.i = -1} },
  { ClkTagBar,		        0,		          Button5,	      shiftview,      {.i = 1} },
  { ClkTabPrev,           0,              Button1,        movestack,      {.i = -1} },
  { ClkTabNext,           0,              Button1,        movestack,      {.i = +1} },
  { ClkTabClose,          0,              Button1,        killclient,     {0} },
};
