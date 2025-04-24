Compile with:
```
emcc graphe.c main.c -sASYNCIFY -sASYNCIFY_IMPORTS='["emscripten_asm_const_int"]' -sEXPORTED_FUNCTIONS='["_main"]' -sEXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' -o main.js --preload-file test.txt
```
Launch with:
```
live-server .
```
or with:
```
npx serve
```
then click on the html file to play