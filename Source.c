#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

static Display *display;
static Window root;
static int screen;

Window createWindow(int x, int y, int width, int height, int border, long borderColor, long rgb) {
	Window window = XCreateSimpleWindow(display, root, x, y, width, height, border, borderColor, rgb);
	return window;
}

long rgb(int r, int g, int b) {
	return b + (g<<8) + (r<<16);
}

int start(int x, int y, int width, int height, int border, long borderColor, long rgb, char[] windowTitle) {
	Window window;

	if((display = XOpenDisplay(NULL)) == NULL) {
		printf("%s\n", "Couldn't open display");
		return 1;
	}

	/* Get default screen and root window */
	screen = DefaultScreen(display);
	root = RootWindow(display, screen);

	window = createWindow(x, y, width, height, border, borderColor, rgb);
	XSetStandardProperties(display, window, windowTitle, "", None, NULL, 0, NULL);
	/* Map window to display server */
	XMapWindow(display, window);

	/* Unmap window */
	XUnmapWindow(display, window);
	XDestroyWindow(display, window);
	/* Close connection with display server */
	XCloseDisplay(display);
	return 0;
}
