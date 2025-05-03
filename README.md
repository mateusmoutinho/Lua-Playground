# Lua-Playground
A lua Playground using web assembly

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