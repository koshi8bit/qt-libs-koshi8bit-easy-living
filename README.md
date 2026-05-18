# easy-living

В данной либе реализованы методы, которых нет из коробки в Qt. Но часто используются для работы с:
- числами (форматирование; `crop`; `sign`; `isBetween`)
- временем (вычисление дельты; форматирования под ISO8601 и кастом, `isBetween`)
- файлами (`isWritable`; `createDir`; `dirExists`; `fileExists`; `writeFile`; `readFile`)
- действия с ОС (`pathConcat`; `exec`)
- JSON (`readJson`; `writeJson`)

## Как использовать

Для использования с `Qt6` с `CMakeList` можно ознакомиться с примером в папке `how-to-use`.

Скомпилировать пример можно двумя способами: через DLL (быстрее компил) или использовать сорцы (легче дебажить). В обоих случаях нужно положить из папки
```
libs\koshi8bit\easy-living
```

в папку 
```
how-to-use\libs\koshi8bit\easy-living
```

файлы из списка:
```
easyliving.h
koshi8bit-easy-living_global.h
operationresult.h
```

И дополнительно добавить (в зависимости от способа компила):

- для DLL скопировать файл из папки
    ```
    build\Desktop_Qt_6_11_0_MinGW_64_bit-Release\libkoshi8bit-easy-living.dll
    ```

- для исходников
    ```
    easyliving.cpp
    operationresult.cpp
    ```


