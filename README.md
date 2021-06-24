# Xanadu.Database

*A cross-platform generic database processing class (currently only SQLite3 supported)*


## Explain

This project is used to encapsulate some database processing for easy use.


## Note

If you want to commit any changes, write the code in the following format.

set encoding=utf-8

set tabstop=8

set shiftwidth=8


## Comment format

*Consistent with XanaduAPI/XanaduCore*


## Installation / Getting started

### Ubuntu Linux

First install all required dependencies and build tools:
```shell
sudo apt install XanaduCore
```

Then clone the actual project repository:
```shell
git clone https://github.com/XanaduAPI/XanaduDatabase.git
svn checkout https://github.com/XanaduAPI/XanaduDatabase/trunk
cd XanaduDatabase
```

Now you can build and install it:
```shell
cmake .
make
sudo make install
```

## License

This library is licensed under the [GNU Lesser General Public License v2.1](https://www.gnu.org/licenses/lgpl-2.1.en.html),
also included in the repository in the `COPYING` file.

README Updated on: 2021-06-24
