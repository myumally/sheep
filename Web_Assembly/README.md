### Requirements

- git
- Emscripten sdk
- live-server or Node.js

### How to install Emscripten sdk
Check the [emsdk repo](https://github.com/emscripten-core/emsdk)

### How to install 
You can get it on the [nodejs website](https://nodejs.org/en)

### How to install live-server
```
npm install -g live-server
```

## Compile and Launch
- Compile with:
```
emcc graphe.c main.c -sASYNCIFY -sASYNCIFY_IMPORTS='["emscripten_asm_const_int"]' -sEXPORTED_FUNCTIONS='["_main"]' -sEXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' -o main.js --preload-file test.txt
```

- Launch with `live-server .` or with `npx serve`. Then click on the html file.