%module Source

extern Window createWindow(int x, int y, int width, int height, int border, long borderColor, long rgb);
extern long rgb(int r, int g, int b);
extern int start(int x, int y, int width, int height, int border, long borderColor, long rgb, char[] windowTitle);
