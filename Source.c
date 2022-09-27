#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

static Display *display;
static Window root;
static int screen;

Window createWindow(int x, int y, int width, int height, int border, long borderColor, long rgb) {
	Window window = XCreateSimpleWindow(display, root, x, y, width, height, border, (long) borderColor, (long) rgb);
	return window;
}

Window getParentWindow() {
	return root;
}

long rgb(int r, int g, int b) {
	return b + (g<<8) + (r<<16);
}

long red() {
	return rgb(255, 0, 0);
}

long green() {
	return rgb(0, 255, 0);
}

long blue() {
	return rgb(0, 0, 255);
}

long white() {
	return rgb(255, 255, 255);
}

long black() {
	return rgb(0, 0, 0);
}

int start(int x, int y, int width, int height, int border, long borderColor, long rgb, char[] windowTitle) {
	XEvent xev;

	if((display = XOpenDisplay(NULL)) == NULL) {
		printf("%s\n", "Couldn't open display");
		return 1;
	}

	//  Get default screen and root window
	screen = DefaultScreen(display);

	root = XCreateSimpleWindow(display, RootWindow(display, screen), x, y, width, height, border, (long) borderColor, (long) rgb);
	XSetStandardProperties(display, root, windowTitle, "", None, NULL, 0, NULL);
	// Map window to display server
	XMapWindow(display, root);

	while(True) {
		XNextEvent(display, &xev);
	}

	// Unmap window
	XUnmapWindow(display, root);
	XDestroyWindow(display, root);
	// Close connection with display server
	XCloseDisplay(display);
	return 0;
}
