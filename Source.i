%module Source

extern void add_button(char label[], int x, int y);
extern void add_check_button(char label[], int x, int y);
extern void add_entry(char defaultText[], int x, int y);
extern void show_message_box(char title[], char message[]);
extern void add_menu_bar();
extern void add_radio();
extern void add_link_button(char link[], char label[], int x, int y);
extern void add_switch(int active, int x, int y);
extern void add_label(char text[], int x, int y);
extern void add_image(char file[], int x, int y);
extern int start(char title[], int width, int height);
