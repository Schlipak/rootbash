# Rootbash
Rootbash is a no-password alternative to `su`.<br />
... Yeah, don't actually use that unless you know what you're doing and no one else can touch your computer.

### Installation
You need a temporary root access to use Rootbash. Look into single-user mode, if your distro allows it. If it doesn't and you have no other way to be root, too bad!

``` sh
git clone https://github.com/Schlipak/rootbash
sudo make
```

If you can't `make` as root, the ownership or sticky bits of the program won't be set properly and it won't do its job!

No `make install` for you, because this is a risky program, so put it in your `$PATH` yourself if you're *really* sure.

### Usage
``` sh
rootbash [SHELL_PATH]
```

### Disclaimer
I am not responsible of the damage that you can cause to your system through the misuse of this program, please be carefull what you type in your terminal!
