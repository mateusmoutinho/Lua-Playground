#include "c2wasm.c"
#include "LuaCEmbedOne.c"
#include <stdlib.h>


c2wasm_js_var execute_lua_machine(){
    LuaCEmbed *lua_virtual_machine = newLuaCEmbedEvaluation();

    c2wasm_js_var id_collect_args  = c2wasm_create_array();
    c2wasm_append_array_string(id_collect_args, "codeEditor");
    c2wasm_js_var code = c2wasm_call_object_prop(c2wasm_document,"getElementById", id_collect_args);

    long size = c2wasm_get_string_len(code);
    char *code_buffer = malloc(size);
    c2wasm_memcpy_string(code,0,code_buffer,size);
    code_buffer[size] = '\0';
    
    printf("buffer: %s\n",code_buffer);
    return c2wasm_undefined;
}

int main(){
    c2wasm_start();
    c2wasm_set_object_prop_function(c2wasm_window,"execute_lua_machine",execute_lua_machine);
    return 0;

}