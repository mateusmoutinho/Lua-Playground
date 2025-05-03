# Lua-Playground

[![WebAssembly](https://img.shields.io/badge/WebAssembly-654FF0?style=flat&logo=webassembly&logoColor=white)](https://webassembly.org/)
[![Lua](https://img.shields.io/badge/Lua-2C2D72?style=flat&logo=lua&logoColor=white)](https://www.lua.org/)

## Overview

Lua-Playground is an interactive web-based environment for experimenting with the Lua programming language. Built with WebAssembly technology, it allows you to write and execute Lua code directly in your browser without any server-side processing.

**Live Demo:** [https://mateusmoutinho.github.io/Lua-Playground/](https://mateusmoutinho.github.io/Lua-Playground/)

## Features

- In-browser Lua execution via WebAssembly
- Syntax highlighting with CodeMirror
- No server-side dependencies required for execution
- Responsive interface

## Installation

### Prerequisites

- [Emscripten](https://github.com/emscripten-core/emsdk) - WebAssembly compiler toolchain

### Build Instructions

#### Step 1: Install Emscripten

Install [Emscripten](https://github.com/emscripten-core/emsdk) by following the official documentation.

Alternatively, you can use our [quick install setup](https://github.com/mateusmoutinho/emscripten-easy-install) for a simplified installation process.

#### Step 2: Compile the Source

```bash
emcc main.c -o main.js
```

#### Step 3: Set Up a Local Server

WebAssembly requires a local server for development. You can use one of these methods:

##### Using Python

```bash
python3 -m http.server 8080
```

Then navigate to [http://localhost:8080/test.html](http://localhost:8080/test.html)

##### Using Yahr

If you prefer an alternative server, you can use [Yahr](https://github.com/OUIsolutions/yahr):

```bash
yahr
```

## Project Architecture

### Dependencies

| Library | File | Purpose |
|---------|------|----------|
| [c2wasm](https://github.com/OUIsolutions/C2Wasm) | [`c2wasm.c`](/c2wasm.c) | DOM manipulation |
| [LuaCEmbed](https://github.com/OUIsolutions/LuaCEmbed) | [`LuaCEmbedOne.c`](/LuaCEmbedOne.c) | Lua VM embedding |
| [Lua](https://www.lua.org/) | Embedded in [`LuaCEmbedOne.c`](/LuaCEmbedOne.c) | Core language implementation |
| [CodeMirror](https://codemirror.net/) | Imported in [`index.html`](/index.html) | Text editor with syntax highlighting |
