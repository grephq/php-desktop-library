How to compile?
---------------

- Install [swig](https://www.swig.org) from official site or via package manager. e.g.
  ```bash
  # Debian based distributions
  apt install swig
  ```
- Install GTK library. e.g.
  ```bash
  # Debian based distributions
  apt install libgtk-3-dev
  ```
- Install PHP development package. e.g.
  ```bash
  # Debian based distributions
  apt install php7.4-dev
  ```
- Execute the following commands
  ```bash
  swig -php Source.i
  gcc `php-config --includes` `pkg-config --cflags gtk+-3.0` -fpic -c Source_wrap.c Source.c `pkg-config --libs gtk+-3.0`
  gcc `pkg-config --cflags gtk+-3.0` --shared Source_wrap.o Source.o -o <filename>.so `pkg-config --libs gtk+-3.0`
  ```
- Move the generated file to the ```php-config``` installation directory
  ```bash
  mv <filename>.so $(php-config --extension-dir)/
  ```
- Copy ```Source.php``` to ```PHP-Desktop/util/ ```

Windows Support
---------------
Well, in theory it should work on windows after
- Installing swig on windows
- Installing windows version of the gtk library
- Compiling this library to a dll. You might have to download php source code and manually add/edit/remove references to libraries. Goodluck trying to get this to work. 
- Move the dll to ```<PHP_INSTALLATION_PATH>/ext/
