/* user and group to drop privileges to */
static const char *user  = "chris";
static const char *group = "chris";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
};

static char full_quote[1024] = {0};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* default message */
static const char * message = "Abandon Hope All Ye Who Enter Here";

/* text color */
static const char * text_color = "#cccccc";

/* text size (must be a valid size) */
static const char * font_name = "-b&h-lucidatypewriter-bold-r-normal-sans-0-0-75-75-m-0-iso8859-1";
