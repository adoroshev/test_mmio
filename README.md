1. Для вызова целей Makefile используется команда ```make <target>```
Реализованы цели: debug, release, all, install, clean, distclean, dist.

2. Для сборки проекта через CMake используется CMakeLists.txt и скрипт cmake-build.sh. 
Скрипт выполняет сборку release, debug в каталоге cmake-build и устанавливает release в систему.

3. Каталог testmmio-1.0 приведён к виду, в котором можно осуществить сборку deb-пакета через dpkg-buildpackage.
К такому виду он приведён с помощью утилиты dh_make с лежащем в корне CMakeLists.txt, что в последующем обеспечит сборку именно через CMake.
