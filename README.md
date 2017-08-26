

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
1.  `git submodule update --init`
2.  `./runner.sh -f`

Full release will be put in releases/geo-viewer, then copied to /opt/

The symlink is to allow the shell script to load any required environment variables before calling the binary.

