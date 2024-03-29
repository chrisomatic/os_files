/* See LICENSE file for copyright and license details. */

#include "/home/chris/.cache/wal/colors-wal-dwm.h"

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 7;        /* vertical padding for statusbar */
//static const char *fonts[]          = {"JetBrainsMono:pixelsize=14:antialias=true:autohint=true"};
//static const char dmenufont[]       = "JetBrainsMono:pixelsize=14:antialias=true:autohint=true";
static const char *fonts[]          = { "Font Awesome 5 Free:size=15", "Font Awesome 5 Free:size=12" };
static const char dmenufont[]       = "Font Awesome 5 Free:size=15";
//static const char col_gray1[]       = "#3f3a41";
//static const char col_gray2[]       = "#444444";
//static const char col_gray3[]       = "#dddddd";
//static const char col_gray4[]       = "#f0f0f0";
//static const char col_darkgreen[]   = "#525e4a";
//static const char col_green[]       = "#64735a";
//static const char urgbordercolor[]  = "#ff0000";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;

#if 0
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_darkgreen,  col_green  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};
#endif

/* tagging */
//static const char *tags[] = { "dev", "web", "chat", "misc", "play"};
static const char *tags[] = { "₁", "₂", "₃", "₄", "₅"};
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     iscentered     isfloating   monitor */
	{ "Glimpse"         , NULL , NULL                , 0      , 1 , 1 , -1 } ,
	{ "pavucontrol"     , NULL , NULL                , 0      , 1 , 1 , -1 } ,
	{ NULL              , NULL , "Volume Control"    , 0      , 1 , 1 , -1 } ,
	{ "blueman-manager" , NULL , NULL                , 0      , 1 , 1 , -1 } ,
	{ NULL              , NULL , "Bluetooth Devices" , 0      , 1 , 1 , -1 } ,
	{ "Firefox"         , NULL , NULL                , 1 << 8 , 0 , 0 , -1 } ,
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	//{ "[]=",      tile },    /* first entry is default */
	//{ "><>",      NULL },    /* no layout function means floating behavior */
	//{ "[M]",      monocle },
	{ "ₖ",      tile },    /* first entry is default */
	{ "ₙ",      NULL },    /* no layout function means floating behavior */
	{ "ₘ",      monocle },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[]   = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_darkgreen, "-sf", col_gray4, NULL };
static const char *dmenucmd[]   = { "rofi", "-show", "run", NULL };
static const char *termcmd[]    = { "kitty", NULL };
static const char *editorcmd[]  = { "kitty", "-e", "vim", NULL };
static const char *webcmd[]     = { "firefox", NULL };
static const char *fmcmd[]      = { "thunar", NULL };
static const char *lockcmd[]    = { "slock", NULL };
static const char *printcmd[]   = { "flameshot", "gui", NULL };
static const char *volumecmd[]  = { "pavucontrol", NULL };
static const char *btcmd[]      = { "blueman-manager", NULL };
static const char *processcmd[] = { "kitty","-e","htop", NULL };
static const char *voldwncmd[]  = { "pactl","set-sink-volume", "1", "-5%", NULL };
static const char *volupcmd[]   = { "pactl","set-sink-volume", "1", "+5%", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_F2,     spawn,          {.v = webcmd } },
	{ MODKEY,                       XK_F3,     spawn,          {.v = fmcmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = editorcmd } },
	{ MODKEY|ShiftMask,             XK_l,      spawn,          {.v = lockcmd } },
	{ MODKEY,                       XK_Print,  spawn,          {.v = printcmd } },
	{ MODKEY,                       XK_v,      spawn,          {.v = volumecmd } },
	{ MODKEY|ShiftMask,             XK_b,      spawn,          {.v = btcmd } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = processcmd } },
	{ MODKEY|ShiftMask,             XK_a,      spawn,          {.v = voldwncmd } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = volupcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_z,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_Escape,      quit,     {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

