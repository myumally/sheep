## 🌐 Version Web

### 🛠️ Prérequis

- git
- Emscripten sdk
- live-server or Node.js

---

### 📦 Installation

#### Emscripten

Voir le [repo officiel d’emsdk](https://github.com/emscripten-core/emsdk)

####  Node.js 

Voir sur le [site officiel de Node.js](https://nodejs.org/en)

#### live-server

```
npm install -g live-server
```

---

## Compile and Launch

- Compile with:
```
emcc graphe.c main.c -sASYNCIFY -sASYNCIFY_IMPORTS='["emscripten_asm_const_int"]' -sEXPORTED_FUNCTIONS='["_main"]' -sEXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' -o main.js --preload-file test.txt
```

- Launch with `live-server .` or with `npx serve`. Then click on the html file.

## Test file

In this version the `test.txt` was writed with the help of [chatGPT](https://openai.com/chatgpt/overview/), and the story was inspired by the film [Revolver (Guy Ritchie - 2005)](https://en.wikipedia.org/wiki/Revolver_(2005_film)).
