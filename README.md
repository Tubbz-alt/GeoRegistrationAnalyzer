

Dependencies
------------

### Linux

- Qt5
  - QtWidgets
  - QtWebSockets
  - QtWebEngine
  - QtWebEngineWidgets
 
- Boost
- GDAL


Build Instructions (Linux/MacOS)
--------------------------------

1.  `mkdir -r release`
2.  `pushd release`
3.  `cmake ..`
4.  `make -j4`
5.  `popd`
6.  `./scripts/builder.py`
7.  `cp -r releases/geo-registration-utility   /opt/`
8.  `ln -s /opt/geo-registration-utility/scripts/geo-registration-utility.sh /usr/local/bin/geo-registration-utility`

Full release will be put in releases/geo-registration-utility, then copied to /opt/

The symlink is to allow the shell script to load any required environment variables before calling the binary.


