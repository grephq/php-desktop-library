How to compile?
---------------

- Install [swig](https://www.swig.org) from official site or via package manager. e.g.
  ```bash
  # Debian based distributions
  apt install swig
  ```
- Install X11 library. e.g.
  ```bash
  # Debian based distributions
  apt install libx11-dev
  ```
- Install PHP development package. e.g.
  ```bash
  # Debian based distributions
  apt install php7.4-dev
  ```
- Execute the following commands
  ```bash
  swig -php Source.i
  gcc `php-config --includes` -fpic -c Source_wrap.c Source.c -lX11
  gcc --shared Source_wrap.o Source.o -o Source.so
   ```
 - Move the generated file to the ```php-config``` installation directory
   ```bash
   mv Source.so $(php-config --extension-dir)/
   ```
