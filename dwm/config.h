/* See LICENSE file for copyright and license details. */

#include "layouts.c"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "DeJaVu Sans Mono:size=9", "Font Awesome:size=9", "Noto Color Emoji:pixelsize=9:antialias=true:autohint=true" };
static const char dmenufont[]       = "DeJaVu Sans Mono:size=9";
/* Background Color */
static const char col_gray1[]       = "#232629";
/* Inactive Window Border */
static const char col_gray2[]       = "#586e75";
/* Font Color */
static const char col_gray3[]       = "#f8f8f2";
/* Current Tag and Windo Font Color */
static const char col_gray4[]       = "#f8f8f2";
/* Top Bar Color */
static const char col_cyan[]        = "#1e4a81";
/* Focus Window Border Color */
static const char col_focus[]		="#268bd2";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_cyan },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
/*static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };*/
//APPLE
//static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

//ARCH
//static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

//DESKTOP
//static const char *tags[] = { "", "", "", "", "", "", "", "", "" }; Firefox Logo is broken in bar and IDK why
static const char *tags[] = { "", "", "", "", "", "", "", "", "" }; 

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */

//IDK how to make mgba-qt work, 0 is NOT floating right now firefox launches auto on tag 2 in tiled mode but mgba-qt does not work idk why

	/* class      instance    title       tags mask     isfloating   monitor */
	{ "gimp",     NULL,       NULL,       1 << 7,       0,           -1 },
	{ "firefox",  NULL,       NULL,       2,            0,           -1 },
	{ "mgba-qt",  NULL,       NULL,       6,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "HHH",      grid },
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
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *webcmd[] = { "firefox", NULL };
static const char *clipcmd[] = { "clipmenu", NULL };
static const char *dwmmute[] = {"dwmmute", NULL };
static const char *dwmvolup[] = {"dwmvolup", NULL };
static const char *dwmvoldown[] = {"dwmvoldown", NULL };
//static const char *brightdown[] = {"brightdown", NULL };
//static const char *brightup[] = {"brightup", NULL };
//static const char *keybdown[] = {"keybdown", NULL };
//static const char *keybup[] = {"keybup", NULL };
static const char *dwmscrot[] = {"dwmscrot", NULL };
static const char *dwmslock[] = {"slock", NULL};
static const char *dwmsuspend[] = {"dwmsuspend", NULL };
static const char *dwmpoweroff[] = {"dwmpoweroff", NULL };



#include "movestack.c"
#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,         spawn,       {.v = dmenucmd } },
	{ MODKEY,             			XK_Return,    spawn,       {.v = termcmd } },
	{ MODKEY,						XK_w,	      spawn,	   {.v = webcmd } },
	{ MODKEY, 						XK_semicolon, spawn,       {.v = clipcmd } },
	{ 0,							0xffc6,       spawn,       {.v = dwmmute } },
	{ 0,							0xffc7,       spawn,       {.v = dwmvoldown } },
	{ 0,							0xffc8,       spawn,       {.v = dwmvolup } },
	//{ 0,							0x1008ff03,   spawn,	   {.v = brightdown } },
	//{ 0,							0x1008ff02,	  spawn,       {.v = brightup } },
	//{ 0,							0x1008ff05,	  spawn,   	   {.v = keybup } },
	//{ 0,							0x1008ff06,	  spawn,       {.v = keybdown } },
	{ MODKEY|ShiftMask,				XK_s,		  spawn,       {.v = dwmscrot } },
	{ MODKEY|ControlMask|Mod1Mask,  XK_l,         spawn,       {.v = dwmslock } },
	{ MODKEY|ControlMask|Mod1Mask,  XK_s,         spawn,       {.v = dwmsuspend} },
	{ MODKEY|ControlMask|Mod1Mask,  XK_Escape,    spawn,       {.v = dwmpoweroff} },



	{ MODKEY,                     	XK_f,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ Mod1Mask,                     XK_h,      setmfact,       {.f = -0.06} },
	{ Mod1Mask,                     XK_l,      setmfact,       {.f = +0.06} },
	{ Mod1Mask|ShiftMask,           XK_h,      setmfact,       {.f = -0.0025} },
	{ Mod1Mask|ShiftMask,           XK_l,      setmfact,       {.f = +0.0025} },
	

    { Mod1Mask|ShiftMask,           XK_j,      setcfact,       {.f = +0.1} },
    { Mod1Mask|ShiftMask,           XK_k,      setcfact,       {.f = -0.1} },
    { Mod1Mask|ShiftMask,           XK_o,      setcfact,       {.f =  0.00} },



 	{ Mod1Mask, 					XK_k,	   movestack,	   {.i = -1} },
	{ Mod1Mask, 					XK_j,	   movestack,	   {.i = +1} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,  			    		XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ Mod1Mask,                     XK_f,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,						XK_Left,   shiftview,	   {.i = -1 } },
	{ MODKEY,						XK_Right,  shiftview,	   {.i = +1 } },
	{ MODKEY,                       0x2d,  setgaps,        {.i = -1 } },
	{ MODKEY,                       0x3d,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             0x3d,  setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ControlMask|Mod1Mask,  XK_q,      quit,           {0} },
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
	{ ClkClientWin,         MODKEY | ShiftMask,         Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

