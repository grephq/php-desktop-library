%module Source

extern Window createWindow(int x, int y, int width, int height, int border, long borderColor, long rgb);
extern Window getParentWindow();
extern void changeWindowBackground(Window window, long background);
extern void changeWindowBorderColor(Window window, long color);
extern void writeText(char[] text, int x, int y, Window window, long background, long foreground);
extern long rgb(int r, int g, int b);
extern long red();
extern long green();
extern long blue();
extern long white();
extern long black();
extern int start(int x, int y, int width, int height, int border, long borderColor, long rgb, char[] windowTitle);
