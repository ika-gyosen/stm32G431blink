#read me

## STM32G431KB nucleo blink
まだ動きません。(not run)

```
make
```
でコンパイルしますが、arm-none-eabi-gcc等へパスが通ってないと動きません。  
パスを通さない場合は、
```
TARGET := arm-none-eabi
```
をフルパスに書き換えてください