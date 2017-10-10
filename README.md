

  / ___| |  _ \  / ___|          / ___|    ___   _ __  __   __   ___   _ __ 
 | |  _  | |_) | \___ \          \___ \   / _ \ | '__| \ \ / /  / _ \ | '__|
 | |_| | |  __/   ___) |          ___) | |  __/ | |     \ V /  |  __/ | |
  \____| |_|     |____/   _____  |____/   \___| |_|      \_/    \___| |_|
                         |_____|                                            

----------------------
Command Line Arguments
----------------------

Example:  ./gps_server

No argument are needed. The server will operate on the port number 13. You may need super user rights to launch the server.

Requirments
- libboost-all-dev
- google test framework 1.7.0

------------------------------- Google test suite ------------------------------
- Description :
	Google's C++ test framework

- Installation (from source) :
	On UNIX platforms:
	The following steps should install the Google test suite.

    1) Pick an installation folder (called "/my/installation/path/" below)
	  $ cd /my/installation/path/
	  $ wget http://googletest.googlecode.com/files/gtest-1.7.0.zip
	  $ unzip gtest-1.7.0.zip
	  $ cd gtest-1.7.0
	  $ mkdir mybuild
	  $ cd mybuild
	  $ cmake -DBUILD_SHARED_LIBS=ON -Dgtest_build_samples=ON -G"Unix Makefiles" ..
	  $ make
--------------------------------------------------------------------------------
