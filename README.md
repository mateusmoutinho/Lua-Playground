# Lua-Playground
A lua Playground using web assembly, [available here](https://mateusmoutinho.github.io/Lua-Playground/)


### Build from scratch

### Step 1: Install Emscripten

Install [Emscripten](https://github.com/emscripten-core/emsdk) by following the official documentation.

Alternatively, you can use our [quick install setup](https://github.com/mateusmoutinho/emscripten-easy-install) for a simplified installation process.

### Step 2: Compile the [main.c](/main.c)

~~~bash
emcc main.c -o main.js
~~~

### Step 3: Set Up a Local Server

WebAssembly requires a server to work. You can use one of these methods:

#### Using Python

```bash
python3 -m http.server 8080
```

Then navigate to [http://localhost:8080/test.html](http://localhost:8080/test.html)

#### Using Yahr (Alternative)

If you don't have Python, you can use [Yahr](https://github.com/OUIsolutions/yahr):

```bash
yahr
```

### Project Dependencies

| lib                                                      | file                                               | used for                     | 
|----------------------------------------------------------|----------------------------------------------------|------------------------------|
|[c2wasm](https://github.com/OUIsolutions/C2Wasm)          | [c2wasm.c](/c2wasm.c)                              | manipulate the dom           |
|[LuaCEmbed](https://github.com/OUIsolutions/LuaCEmbed)    | [LuaCEmbedOne.c](/LuaCEmbedOne.c)                  | embeding lua virtual machine |
|[lua](https://www.lua.org/)                               |--- embed inside [LuaCEmbedOne.c](/LuaCEmbedOne.c)  | the lua programing language  | 
|[codemirror](https://codemirror.net/)                     | imported inside [index.html](/index.html)          | create the text editor       |
