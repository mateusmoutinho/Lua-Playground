#include "c2wasm.c"
#include "LuaCEmbedOne.c"


c2wasm_js_var execute(){
    LuaCEmbed *lua_virtual_machine = newLuaCEmbedEvaluation();

    c2wasm_js_var id_collect_args  = c2wasm_create_array();
    c2wasm_append_array_string(id_collect_args, "codeEditor");
    c2wasm_js_var code = c2wasm_call_object_prop(c2wasm_document,"getElementById", id_collect_args);

    string_si
    return c2wasm_undefined;
}

int main(){
    c2wasm_start();
    return 0;

}